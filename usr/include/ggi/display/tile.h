/* $Id: tile.h,v 1.6 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Tile target for LibGGI, header.

   Copyright (C) 1998 Steve Cheng		[steve@ggi-project.org]
   Copyright (C) 1998-2000 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_DISPLAY_TILE_H
#define _GGI_DISPLAY_TILE_H

#include <ggi/internal/ggi-dl.h>
#include <ggi/display/mansync.h>


ggifunc_getmode		GGI_tile_getmode;
ggifunc_setmode		GGI_tile_setmode;
ggifunc_checkmode	GGI_tile_checkmode;
ggifunc_getapi		GGI_tile_getapi;
ggifunc_setflags	GGI_tile_setflags;

ggifunc_flush		GGI_tile_flush_db;
ggifunc_flush		GGI_tile_flush;

ggifunc_drawpixel	GGI_tile_drawpixel_nc;
ggifunc_drawpixel	GGI_tile_drawpixel;
ggifunc_putpixel	GGI_tile_putpixel_nc;
ggifunc_putpixel	GGI_tile_putpixel;
ggifunc_getpixel	GGI_tile_getpixel;

ggifunc_drawhline	GGI_tile_drawhline_nc;
ggifunc_drawhline	GGI_tile_drawhline;
ggifunc_puthline	GGI_tile_puthline;
ggifunc_gethline	GGI_tile_gethline;

ggifunc_drawvline	GGI_tile_drawvline_nc;
ggifunc_drawvline	GGI_tile_drawvline;
ggifunc_putvline	GGI_tile_putvline;
ggifunc_getvline	GGI_tile_getvline;

ggifunc_drawbox		GGI_tile_drawbox;
ggifunc_putbox		GGI_tile_putbox;
ggifunc_getbox		GGI_tile_getbox;

ggifunc_copybox		GGI_tile_copybox;
ggifunc_fillscreen	GGI_tile_fillscreen;

ggifunc_setdisplayframe	GGI_tile_setdisplayframe;
ggifunc_setreadframe	GGI_tile_setreadframe;
ggifunc_setwriteframe	GGI_tile_setwriteframe;

ggifunc_drawline	GGI_tile_drawline;

ggifunc_gcchanged	GGI_tile_gcchanged;

ggifunc_setdisplayframe	GGI_tile_setdisplayframe_db;
ggifunc_setorigin	GGI_tile_setorigin;

ggifunc_mapcolor	GGI_tile_mapcolor;
ggifunc_unmappixel	GGI_tile_unmappixel;

ggifunc_setpalvec	GGI_tile_setpalvec;
ggifunc_getpalvec	GGI_tile_getpalvec;

#define MAX_VISUALS 256		/* This is an outrage! */

typedef struct {
	int use_db;			/* Emulate DirectBuffer ? */

	int numvis;
	struct {
		ggi_visual_t vis;
		ggi_coord origin;	/* Start of tile. Also clip area topleft. */
		ggi_coord clipbr;	/* Clip area bottom right. */
		ggi_coord size;		/* Dimensions of tile. */
	} vislist[MAX_VISUALS];

	void *buf;			/* Blitting buffer */
	ggi_directbuffer *d_frame;	/* Current display frame */

	MANSYNC_DATA;
} ggi_tile_priv;

#define TILE_PRIV(vis)	((ggi_tile_priv *)LIBGGI_PRIVATE(vis))

#define MANSYNC_init(vis)   MANSYNC_DECL_INIT(TILE_PRIV(vis), vis)
#define MANSYNC_deinit(vis) MANSYNC_DECL_DEINIT(TILE_PRIV(vis), vis)
#define MANSYNC_start(vis)  MANSYNC_DECL_START(TILE_PRIV(vis), vis)
#define MANSYNC_stop(vis)   MANSYNC_DECL_STOP(TILE_PRIV(vis), vis)
#define MANSYNC_ignore(vis) MANSYNC_DECL_IGNORE(TILE_PRIV(vis), vis)
#define MANSYNC_cont(vis)   MANSYNC_DECL_CONT(TILE_PRIV(vis), vis)


/* Prototypes */
void _GGI_tile_freedbs(ggi_visual *vis);

#endif /* _GGI_DISPLAY_TILE_H */
