/* $Id: sub.h,v 1.3 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Display-sub: subwindows in a parent visual

   Copyright (C) 1998 Andreas Beck    [becka@ggi-project.org]

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

#ifndef _GGI_DISPLAY_SUB_H
#define _GGI_DISPLAY_SUB_H

#include <ggi/internal/ggi-dl.h>

typedef struct {
	ggi_visual	*parent;
	ggi_coord	position;
	ggi_coord	botright;
} ggi_sub_priv;

#define SUB_PRIV(vis) ((ggi_sub_priv *)LIBGGI_PRIVATE(vis))

/* prototypes
 */
ggifunc_checkmode	GGI_sub_checkmode;
ggifunc_copybox		GGI_sub_copybox;
ggifunc_crossblit	GGI_sub_crossblit;
ggifunc_drawbox		GGI_sub_drawbox;
ggifunc_drawhline	GGI_sub_drawhline;
ggifunc_drawline	GGI_sub_drawline;
ggifunc_drawpixel	GGI_sub_drawpixel;
ggifunc_drawvline	GGI_sub_drawvline;
ggifunc_fillscreen	GGI_sub_fillscreen;
ggifunc_flush		GGI_sub_flush;
ggifunc_getapi		GGI_sub_getapi;
ggifunc_getbox		GGI_sub_getbox;
ggifunc_getcharsize	GGI_sub_getcharsize;
ggifunc_getgamma	GGI_sub_getgamma;
ggifunc_getgammamap	GGI_sub_getgammamap;
ggifunc_gethline	GGI_sub_gethline;
ggifunc_getmode		GGI_sub_getmode;
ggifunc_getpalvec	GGI_sub_getpalvec;
ggifunc_getpixel	GGI_sub_getpixel;
ggifunc_getvline	GGI_sub_getvline;
ggifunc_mapcolor	GGI_sub_mapcolor;
ggifunc_putbox		GGI_sub_putbox;
ggifunc_putc		GGI_sub_putc;
ggifunc_puthline	GGI_sub_puthline;
ggifunc_putpixel	GGI_sub_putpixel;
ggifunc_puts		GGI_sub_puts;
ggifunc_putvline	GGI_sub_putvline;
ggifunc_setflags	GGI_sub_setflags;
ggifunc_setgamma	GGI_sub_setgamma;
ggifunc_setgammamap	GGI_sub_setgammamap;
ggifunc_setmode		GGI_sub_setmode;
ggifunc_setorigin	GGI_sub_setorigin;
ggifunc_setpalvec	GGI_sub_setpalvec;
ggifunc_unmappixel	GGI_sub_unmappixel;

#endif /* _GGI_DISPLAY_SUB_H */
