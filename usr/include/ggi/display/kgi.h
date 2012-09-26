/* $Id: kgi.h,v 1.17 2005/07/31 15:30:38 soyt Exp $
******************************************************************************

   Headers for KGI target.

   Copyright (C) 2001 Filip Spacek

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   THE AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

******************************************************************************
*/

#ifndef _GGI_DISPLAY_KGI_H
#define _GGI_DISPLAY_KGI_H

#include <stdlib.h>

#ifndef __FreeBSD__
#  include <kgi/config.h>
#  include <kgi/system.h>
#  include <kgi/kgi.h>
#  include <kgi/cmd.h>
#else
#  include <kgi/kgi.h>
#endif

#include <ggi/internal/ggi-dl.h>

/*
 * KGI display options
 */
enum {
	KGI_OPT_DEVICE = 0,
	KGI_OPT_NO3D = 1,
	KGI_OPT_SWATCHSIZE = 2,
	KGI_OPT_NOINPUT = 3,
	KGI_NUM_OPTS
};

/*
 * KGI communication
 */
struct kgi_context_s
{
	struct
	{
		kgi_s_t		fd;
		kgi_u_t		resources;
		kgi_u_t		graphic;	/* unit of /dev/graphic */
	} mapper;
};

typedef struct kgi_context_s kgi_context_t;

kgi_error_t kgiInit(kgi_context_t *ctx, const char *client,
		    const kgi_version_t *version, const gg_option *options);
kgi_error_t kgiCheckMode(kgi_context_t *ctx);
kgi_error_t kgiSetImages(kgi_context_t *ctx, kgi_u_t images);
kgi_error_t kgiSetImageMode(kgi_context_t *ctx, kgi_u_t image,
			    const kgi_image_mode_t *mode);
kgi_error_t kgiGetImageMode(kgi_context_t *ctx, kgi_u_t image,
			    kgi_image_mode_t *mode);
kgi_error_t kgiSetMode(kgi_context_t *ctx);
kgi_error_t kgiUnsetMode(kgi_context_t *ctx);
void kgiPrintImageMode(kgi_image_mode_t *mode);
kgi_error_t kgiPrintResourceInfo(kgi_context_t *ctx, kgi_u_t resource);
const kgic_mapper_resource_info_result_t *
kgiGetResource(kgi_context_t *ctx, kgi_u_t start, kgi_resource_type_t type);
kgi_error_t kgiSetupMmapAccel(kgi_context_t *ctx, kgi_u_t resource,
	kgi_u_t min, kgi_u_t max, kgi_u_t buf, kgi_u_t priority);
kgi_error_t kgiSetupMmapFB(kgi_context_t *ctx, kgi_u_t resource);


typedef union ggi_accel ggi_accel_t;

typedef ggi_accel_t *ggifunc_map_accel(ggi_visual_t vis, kgi_u_t resource,
                                       kgi_u_t min, kgi_u_t max,
				       kgi_u_t buf, kgi_u_t priority);

ggifunc_getmode		GGI_kgi_getmode;
ggifunc_setmode		GGI_kgi_setmode;
ggifunc_checkmode	GGI_kgi_checkmode;
ggifunc_getapi		GGI_kgi_getapi;
ggifunc_setflags        GGI_kgi_setflags;

ggifunc_setPalette	GGI_kgi_setPalette;
size_t GGI_kgi_getPrivSize(ggi_visual_t);
ggifunc_map_accel       GGI_kgi_map_accelerator;

#define KGI_PRIV(vis) ((ggi_kgi_priv *)LIBGGI_PRIVATE(vis))
#define KGI_CTX(vis) (KGI_PRIV(vis)->ctx)
#define KGI_ACCEL_PRIV(vis) (KGI_PRIV(vis)->accel_priv)

typedef struct {
	/* KGI context used to communicate with KGI */
	kgi_context_t ctx;

	/* Framebuffer information */
	kgi_u8_t *fb;
	kgi_u8_t *swatch;
	kgi_u8_t *swatch_gp; /* address as seen from the gpu */
	kgi_u8_t *font;
	kgi_u8_t *font_gp;   /* address as seen from the gpu */
	kgi_size_t font_size;
	kgi_size_t fb_size;

	/* Options */
	int use3d;
	kgi_size_t swatch_size;

	/* Accelerator mapping functionality */
	ggifunc_map_accel *map_accel;

	/* Accelerator callbacks for frames/origin. */
	int (*origin_changed)(ggi_visual_t vis);
	int (*rwframes_changed)(ggi_visual_t vis);

	/* Accelerator target private data pointer */
	void *accel_priv;

	/* Flag set whenever palette is altered, for use by accel renderer. */
	int ilut_touched;

} ggi_kgi_priv;


/*
 * Accelerator
 */
union ggi_accel {

#define BUFFER_TYPE(t)                 \
	struct {                       \
		kgi_##t##_t *buffer;   \
		kgi_u_t current;       \
	} t

	BUFFER_TYPE(u32);
	BUFFER_TYPE(s32);
	BUFFER_TYPE(u16);
	BUFFER_TYPE(s16);
	BUFFER_TYPE(u8);
	BUFFER_TYPE(s8);

#undef BUFFER_TYPE

};

#define _GGI_ACCEL_FLUSH(t, a, bs, ts)                  \
{                                                       \
	if (a->t.current & (bs - 1)) {                  \
                                                        \
		kgi_u_t touch;                          \
		a->t.current += bs;                     \
		touch = a->t.current;                   \
		a->t.current &= ~(bs - 1);              \
		                                        \
		if (a->t.current >= ts) {               \
		                                        \
			a->t.current = 0;               \
			touch -= ts;                    \
		}                                       \
		DPRINT("touching 0x%.8x", touch*4);  \
		a->t.buffer[touch] = 1;                 \
	}                                               \
	else if (a->t.current >= ts) {                  \
	                                                \
		a->t.current = 0;                       \
	}                                               \
}

#define GGI_ACCEL_FLUSH_u32(a, bs, ts) _GGI_ACCEL_FLUSH(u32, a, bs, ts)
#define GGI_ACCEL_FLUSH_s32(a, bs, ts) _GGI_ACCEL_FLUSH(s32, a, bs, ts)
#define GGI_ACCEL_FLUSH_u16(a, bs, ts) _GGI_ACCEL_FLUSH(u16, a, bs, ts)
#define GGI_ACCEL_FLUSH_s16(a, bs, ts) _GGI_ACCEL_FLUSH(s16, a, bs, ts)
#define GGI_ACCEL_FLUSH_u8(a, bs, ts)  _GGI_ACCEL_FLUSH(u8, a, bs, ts)
#define GGI_ACCEL_FLUSH_s8(a, bs, ts)  _GGI_ACCEL_FLUSH(s8, a, bs, ts)


#define _GGI_ACCEL_CHECK_TOTAL(t, a, n, bs, ts)         \
	if(a->t.current + n >= ts)                      \
		GGI_ACCEL_FLUSH_##t(a, bs, ts);

#define GGI_ACCEL_CHECK_TOTAL_u32(a, n, bs, ts) _GGI_ACCEL_CHECK_TOTAL(u32, a, n, bs, ts)
#define GGI_ACCEL_CHECK_TOTAL_s32(a, n, bs, ts) _GGI_ACCEL_CHECK_TOTAL(s32, a, n, bs, ts)
#define GGI_ACCEL_CHECK_TOTAL_u16(a, n, bs, ts) _GGI_ACCEL_CHECK_TOTAL(u16, a, n, bs, ts)
#define GGI_ACCEL_CHECK_TOTAL_s16(a, n, bs, ts) _GGI_ACCEL_CHECK_TOTAL(s16, a, n, bs, ts)
#define GGI_ACCEL_CHECK_TOTAL_u8(a, n, bs, ts)  _GGI_ACCEL_CHECK_TOTAL(u8, a, n, bs, ts)
#define GGI_ACCEL_CHECK_TOTAL_s8(a, n, bs, ts)  _GGI_ACCEL_CHECK_TOTAL(s8, a, n, bs, ts)

#define _GGI_ACCEL_CHECK_BUFFER(t, a, n, bs, ts)        \
	if((a->t.current & (bs - 1)) + n >= bs)         \
		GGI_ACCEL_FLUSH_##t(a, bs, ts);

#define GGI_ACCEL_CHECK_BUFFER_u32(a, n, bs, ts) _GGI_ACCEL_CHECK_BUFFER(u32, a, n, bs, ts)
#define GGI_ACCEL_CHECK_BUFFER_s32(a, n, bs, ts) _GGI_ACCEL_CHECK_BUFFER(s32, a, n, bs, ts)
#define GGI_ACCEL_CHECK_BUFFER_u16(a, n, bs, ts) _GGI_ACCEL_CHECK_BUFFER(u16, a, n, bs, ts)
#define GGI_ACCEL_CHECK_BUFFER_s16(a, n, bs, ts) _GGI_ACCEL_CHECK_BUFFER(s16, a, n, bs, ts)
#define GGI_ACCEL_CHECK_BUFFER_u8(a, n, bs, ts)  _GGI_ACCEL_CHECK_BUFFER(u8, a, n, bs, ts)
#define GGI_ACCEL_CHECK_BUFFER_s8(a, n, bs, ts)  _GGI_ACCEL_CHECK_BUFFER(s8, a, n, bs, ts)

#define _GGI_ACCEL_WRITE(t, a, val)                     \
	a->t.buffer[a->t.current++] = val;

#define GGI_ACCEL_WRITE_u32(a, val) _GGI_ACCEL_WRITE(u32, a, val)
#define GGI_ACCEL_WRITE_s32(a, val) _GGI_ACCEL_WRITE(s32, a, val)
#define GGI_ACCEL_WRITE_u16(a, val) _GGI_ACCEL_WRITE(u16, a, val)
#define GGI_ACCEL_WRITE_s16(a, val) _GGI_ACCEL_WRITE(s16, a, val)
#define GGI_ACCEL_WRITE_u8(a, val)  _GGI_ACCEL_WRITE(u8, a, val)
#define GGI_ACCEL_WRITE_s8(a, val)  _GGI_ACCEL_WRITE(s8, a, val)

/* This allows 16 lines of swatch plus space for the font even in the
 * largest/deepest mode possible with Radeon's 3D accel (2048x2048)
 */
#define GGI_KGI_FONTSIZE 16320
#define GGI_KGI_MINSWATCH 131072

#endif /* _GGI_DISPLAY_KGI_H */
