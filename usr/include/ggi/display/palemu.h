/* $Id: palemu.h,v 1.5 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Display-palemu: palette emulation on true color modes

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

#ifndef _GGI_DISPLAY_PALEMU_H
#define _GGI_DISPLAY_PALEMU_H

#include <ggi/internal/ggi-dl.h>
#include <ggi/display/mansync.h>


/**************************************************
 **
 **  PalEmu private defines
 **
 **************************************************/


#ifndef MIN
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#endif

#define UPDATE_MOD(vis, _x1, _y1, w, h)  \
	do {                                                   \
		ggi_palemu_priv *_priv = PALEMU_PRIV(vis);     \
		int _x2=(_x1)+(w);                             \
		int _y2=(_y1)+(h);                             \
                                                               \
		if ((_x1) < _priv->dirty_tl.x) _priv->dirty_tl.x =\
			MAX((_x1), (vis)->gc->cliptl.x);        \
		if ((_y1) < _priv->dirty_tl.y) _priv->dirty_tl.y =\
			MAX((_y1), (vis)->gc->cliptl.y);        \
		if ((_x2) > _priv->dirty_br.x) _priv->dirty_br.x =\
			MIN((_x2), (vis)->gc->clipbr.x);        \
		if ((_y2) > _priv->dirty_br.y) _priv->dirty_br.y =\
			MIN((_y2), (vis)->gc->clipbr.y);        \
	} while (0)


/****************************************************
 **
 **  PalEmu private data
 **
 ****************************************************/


typedef struct ggi_palemu_priv {
	int flags;

	ggi_visual_t parent;
	ggi_mode mode;

	/* framebuffer */
	void *fb_ptr;
	long  fb_size;
	long  frame_size;

	/* color info */
	ggi_pixel *lookup;
	ggi_color *palette;

	ggi_float red_gamma;
	ggi_float green_gamma;
	ggi_float blue_gamma;

	/* 2D operations on memory buffer */
	struct ggi_visual_opdraw *mem_opdraw;

	ggi_coord dirty_tl;
	ggi_coord dirty_br;

	/* blitter function */
	void (* do_blit) (struct ggi_palemu_priv *priv, void *dest,
			  void *src, int w);

	/* mansync info */
	void *flush_lock;
	MANSYNC_DATA;
} ggi_palemu_priv;

#define PALEMU_PRIV(vis)  ((ggi_palemu_priv *) LIBGGI_PRIVATE(vis))



/****************************************************
 **
 **  PalEmu private functions
 **
 ****************************************************/


extern int _ggi_palemu_Open(ggi_visual *vis);
extern int _ggi_palemu_Close(ggi_visual *vis);
extern int _ggi_palemu_Transfer(ggi_visual*vis, int x, int y, int w, int h);
extern int _ggi_palemu_Flush(ggi_visual*vis);


/****************************************************
 **
 **  PalEmu internal interfaces
 **
 ****************************************************/


ggifunc_getmode         GGI_palemu_getmode;
ggifunc_setmode         GGI_palemu_setmode;
ggifunc_checkmode       GGI_palemu_checkmode;
ggifunc_getapi          GGI_palemu_getapi;
ggifunc_flush           GGI_palemu_flush;
ggifunc_setflags        GGI_palemu_setflags;

ggifunc_drawpixel	GGI_palemu_drawpixel;
ggifunc_drawpixel_nc	GGI_palemu_drawpixel_nc;
ggifunc_drawhline_nc	GGI_palemu_drawhline_nc;
ggifunc_drawhline	GGI_palemu_drawhline;
ggifunc_drawvline_nc	GGI_palemu_drawvline_nc;
ggifunc_drawvline	GGI_palemu_drawvline;
ggifunc_drawline	GGI_palemu_drawline;

ggifunc_putc		GGI_palemu_putc;
ggifunc_getcharsize	GGI_palemu_getcharsize;
ggifunc_putpixel_nc	GGI_palemu_putpixel_nc;
ggifunc_putpixel	GGI_palemu_putpixel;
ggifunc_puthline	GGI_palemu_puthline;
ggifunc_putvline	GGI_palemu_putvline;

ggifunc_putbox		GGI_palemu_putbox;
ggifunc_drawbox		GGI_palemu_drawbox;
ggifunc_copybox		GGI_palemu_copybox;
ggifunc_crossblit	GGI_palemu_crossblit;
ggifunc_fillscreen	GGI_palemu_fillscreen;
ggifunc_setorigin	GGI_palemu_setorigin;
ggifunc_setPalette	GGI_palemu_setPalette;

ggifunc_setdisplayframe	GGI_palemu_setdisplayframe;
ggifunc_setreadframe	GGI_palemu_setreadframe;
ggifunc_setwriteframe	GGI_palemu_setwriteframe;

extern int GGI_palemu_resetmode(ggi_visual *vis);


#define MANSYNC_init(vis)   MANSYNC_DECL_INIT(PALEMU_PRIV(vis), vis)
#define MANSYNC_deinit(vis) MANSYNC_DECL_DEINIT(PALEMU_PRIV(vis), vis)
#define MANSYNC_start(vis)  MANSYNC_DECL_START(PALEMU_PRIV(vis), vis)
#define MANSYNC_stop(vis)   MANSYNC_DECL_STOP(PALEMU_PRIV(vis), vis)
#define MANSYNC_ignore(vis) MANSYNC_DECL_IGNORE(PALEMU_PRIV(vis), vis)
#define MANSYNC_cont(vis)   MANSYNC_DECL_CONT(PALEMU_PRIV(vis), vis)


#endif /* _GGI_DISPLAY_PALEMU_H */
