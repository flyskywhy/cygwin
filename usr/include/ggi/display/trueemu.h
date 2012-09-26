/* $Id: trueemu.h,v 1.5 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Display-trueemu: truecolor emulation target for GGI

   Copyright (C) 1998 Andrew Apted    [andrew@ggi-project.org]

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

#ifndef _GGI_DISPLAY_TRUEEMU_H
#define _GGI_DISPLAY_TRUEEMU_H

#include <ggi/internal/ggi-dl.h>
#include <ggi/display/mansync.h>


/**************************************************
 **
 **  Trueemu private defines
 **
 **************************************************/


#define TrueColor	int32_t

#define TC_RED(tc)	(((tc) >> 16) & 0xff)
#define TC_GREEN(tc)	(((tc) >>  8) & 0xff)
#define TC_BLUE(tc)	(((tc)      ) & 0xff)

#define T2GGI(tc)  { TC_RED(tc) << 8, TC_GREEN(tc) << 8, TC_BLUE(tc) << 8 }


#define BLITFUNC(def)	void def(struct ggi_trueemu_priv *priv,  \
				void *dest_raw, uint8_t *src, int width)

#ifndef MIN
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#endif

#define UPDATE_MOD(vis, _x1, _y1, w, h)  \
	do {                                                   \
		ggi_trueemu_priv *_priv = TRUEEMU_PRIV(vis);   \
		int _x2=(_x1)+(w);                             \
		int _y2=(_y1)+(h);                             \
                                                               \
		if ((_x1) < _priv->dirty_tl.x) _priv->dirty_tl.x =\
			MAX((_x1), (vis)->gc->cliptl.x);       \
		if ((_y1) < _priv->dirty_tl.y) _priv->dirty_tl.y =\
			MAX((_y1), (vis)->gc->cliptl.y);        \
		if ((_x2) > _priv->dirty_br.x) _priv->dirty_br.x =\
			MIN((_x2), (vis)->gc->clipbr.x);       \
		if ((_y2) > _priv->dirty_br.y) _priv->dirty_br.y =\
			MIN((_y2), (vis)->gc->clipbr.y);        \
	} while (0)


/****************************************************
 **
 **  TrueEmu private data
 **
 ****************************************************/

typedef struct ggi_trueemu_priv {
	int flags;

	ggi_visual_t parent;
	ggi_mode mode;

	/* framebuffer */

	void *fb_ptr;
	long  fb_size;
	long  frame_size;

	/* 2D operations on memory buffer */

	struct ggi_visual_opdraw *mem_opdraw;

	ggi_coord dirty_tl;	/* dirty region */
	ggi_coord dirty_br;

	/* blit information */

	BLITFUNC( (* blitter_even) );
	BLITFUNC( (* blitter_odd) );

	void *src_buf;
	void *dest_buf;

	/* hicolor dither tables */

	uint16_t (* R)[4];	/* actually [256][4] */
	uint16_t (* G)[4];
	uint16_t (* B)[4];

	/* palette dither table */

	uint8_t (* T)[4];	/* actually [32768][4] */

	/* mansync info */

	void *flush_lock;

	MANSYNC_DATA;
} ggi_trueemu_priv;

#define TRUEEMU_PRIV(vis)  ((ggi_trueemu_priv *) LIBGGI_PRIVATE(vis))


typedef struct trueemu_blits
{
	BLITFUNC( (* blitter_b32_d0) );

	BLITFUNC( (* blitter_b24_d0) );

	BLITFUNC( (* blitter_b16_d0) );
	BLITFUNC( (* blitter_b16_d2_ev) );
	BLITFUNC( (* blitter_b16_d2_od) );
	BLITFUNC( (* blitter_b16_d4_ev) );
	BLITFUNC( (* blitter_b16_d4_od) );

	BLITFUNC( (* blitter_b8_d0) );
	BLITFUNC( (* blitter_b8_d2_ev) );
	BLITFUNC( (* blitter_b8_d2_od) );
	BLITFUNC( (* blitter_b8_d4_ev) );
	BLITFUNC( (* blitter_b8_d4_od) );

	BLITFUNC( (* blitter_b4_d0) );
	BLITFUNC( (* blitter_b4_d2_ev) );
	BLITFUNC( (* blitter_b4_d2_od) );
	BLITFUNC( (* blitter_b4_d4_ev) );
	BLITFUNC( (* blitter_b4_d4_od) );

} TrueemuBlits;


/* flags */
#define TRUEEMU_F_DITHER_0	0x0001
#define TRUEEMU_F_DITHER_2	0x0002
#define TRUEEMU_F_DITHER_4	0x0004

#define TRUEEMU_F_RGB		0x0010
#define TRUEEMU_F_CUBE		0x0020
#define TRUEEMU_F_PASTEL	0x0040

#define TE_DITHER_MASK  \
	(TRUEEMU_F_DITHER_0 | TRUEEMU_F_DITHER_2 | TRUEEMU_F_DITHER_4)

#define TE_PALETTE_MASK  \
	(TRUEEMU_F_RGB | TRUEEMU_F_CUBE | TRUEEMU_F_PASTEL)

/* The meaning of the various modes:
 *
 *	Dithering:
 *
 *	TRUEEMU_M_DITHER_0 : Don't dither if possible.
 *	TRUEEMU_M_DITHER_2 : Use a two pixel dither if possible.
 *	TRUEEMU_M_DITHER_4 : Use a four pixel dither if possible.
 *
 *	two pixel:	four pixel:
 *
 *	--  o-  oo	--  o-  o-  oo  oo
 *	--  -o  oo	--  --  -o  -o  oo
 *
 *	Palette:
 *
 *	TRUEEMU_M_RGB    : Use a whole number of bits for red, green and
 *			   blue.  For an 8 bit mode, this is 3:3:2.  For
 *			   a 4 bit mode, this is 1:2:1.
 *	TRUEEMU_M_CUBE   : Use the same number of reds, greens and
 *			   blues.  For an 8 bit mode, this is 6x6x6.
 *	TRUEEMU_M_PASTEL : Use a shaded pastel scheme.
 */


/* blitter tables */

extern TrueemuBlits _ggi_trueemu_blit24_table;
extern TrueemuBlits _ggi_trueemu_blit32_table;


/****************************************************
 **
 **  TrueEmu private functions
 **
 ****************************************************/


extern int _ggi_trueemu_Open(ggi_visual *vis);
extern int _ggi_trueemu_Close(ggi_visual *vis);
extern int _ggi_trueemu_Transfer(ggi_visual*vis, int x, int y, int w, int h);
extern int _ggi_trueemu_Flush(ggi_visual*vis);
extern int _ggi_trueemu_NewMode(ggi_visual *vis);


/****************************************************
 **
 **  TrueEmu internal interfaces
 **
 ****************************************************/

ggifunc_getmode		GGI_trueemu_getmode;
ggifunc_setmode		GGI_trueemu_setmode;
ggifunc_checkmode	GGI_trueemu_checkmode;
ggifunc_getapi		GGI_trueemu_getapi;
ggifunc_flush		GGI_trueemu_flush;
ggifunc_setflags	GGI_trueemu_setflags;

ggifunc_drawpixel_nc	GGI_trueemu_drawpixel_nc;
ggifunc_drawpixel	GGI_trueemu_drawpixel;
ggifunc_drawhline_nc	GGI_trueemu_drawhline_nc;
ggifunc_drawhline	GGI_trueemu_drawhline;
ggifunc_drawvline_nc	GGI_trueemu_drawvline_nc;
ggifunc_drawvline	GGI_trueemu_drawvline;
ggifunc_drawline	GGI_trueemu_drawline;

ggifunc_putc		GGI_trueemu_putc;
ggifunc_putpixel_nc	GGI_trueemu_putpixel_nc;
ggifunc_putpixel	GGI_trueemu_putpixel;
ggifunc_puthline	GGI_trueemu_puthline;
ggifunc_putvline	GGI_trueemu_putvline;
ggifunc_putbox		GGI_trueemu_putbox;
ggifunc_drawbox		GGI_trueemu_drawbox;
ggifunc_copybox		GGI_trueemu_copybox;
ggifunc_crossblit	GGI_trueemu_crossblit;
ggifunc_fillscreen	GGI_trueemu_fillscreen;
ggifunc_setorigin	GGI_trueemu_setorigin;

ggifunc_setdisplayframe	GGI_trueemu_setdisplayframe;
ggifunc_setreadframe	GGI_trueemu_setreadframe;
ggifunc_setwriteframe	GGI_trueemu_setwriteframe;

extern int GGI_trueemu_resetmode(ggi_visual *vis);


#define MANSYNC_init(vis)   MANSYNC_DECL_INIT(TRUEEMU_PRIV(vis), vis)
#define MANSYNC_deinit(vis) MANSYNC_DECL_DEINIT(TRUEEMU_PRIV(vis), vis)
#define MANSYNC_start(vis)  MANSYNC_DECL_START(TRUEEMU_PRIV(vis), vis)
#define MANSYNC_stop(vis)   MANSYNC_DECL_STOP(TRUEEMU_PRIV(vis), vis)
#define MANSYNC_ignore(vis) MANSYNC_DECL_IGNORE(TRUEEMU_PRIV(vis), vis)
#define MANSYNC_cont(vis)   MANSYNC_DECL_CONT(TRUEEMU_PRIV(vis), vis)

#endif /* _GGI_DISPLAY_TRUEEMU_H */
