/* $Id: multi.h,v 1.4 2005/01/25 12:01:28 pekberg Exp $
******************************************************************************

   Display-multi: definitions

   Copyright (C) 1998 Andrew Apted		[andrew@ggi-project.org]
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

#ifndef _GGI_DISPLAY_MULTI_H
#define _GGI_DISPLAY_MULTI_H

#include <ggi/internal/ggi-dl.h>

ggifunc_getmode		GGI_multi_getmode;
ggifunc_setmode		GGI_multi_setmode;
ggifunc_checkmode	GGI_multi_checkmode;
ggifunc_flush		GGI_multi_flush;
ggifunc_setflags	GGI_multi_setflags;

ggifunc_gcchanged	GGI_multi_gcchanged;

ggifunc_fillscreen	GGI_multi_fillscreen;
ggifunc_setorigin	GGI_multi_setorigin;

ggifunc_putc		GGI_multi_putc;
ggifunc_puts		GGI_multi_puts;
ggifunc_getcharsize	GGI_multi_getcharsize;

ggifunc_drawpixel_nc	GGI_multi_drawpixel_nc;
ggifunc_drawpixel	GGI_multi_drawpixel;
ggifunc_putpixel_nc	GGI_multi_putpixel_nc;
ggifunc_putpixel	GGI_multi_putpixel;
ggifunc_getpixel	GGI_multi_getpixel;

ggifunc_drawline	GGI_multi_drawline;
ggifunc_drawhline	GGI_multi_drawhline;
ggifunc_puthline	GGI_multi_puthline;
ggifunc_gethline	GGI_multi_gethline;

ggifunc_drawvline	GGI_multi_drawvline;
ggifunc_putvline	GGI_multi_putvline;
ggifunc_getvline	GGI_multi_getvline;

ggifunc_drawbox		GGI_multi_drawbox;
ggifunc_putbox		GGI_multi_putbox;
ggifunc_getbox		GGI_multi_getbox;
ggifunc_copybox		GGI_multi_copybox;
ggifunc_crossblit	GGI_multi_crossblit;

ggifunc_getgamma	GGI_multi_getgamma;
ggifunc_setgamma	GGI_multi_setgamma;
ggifunc_getgammamap	GGI_multi_getgammamap;
ggifunc_setgammamap	GGI_multi_setgammamap;

ggifunc_mapcolor	GGI_multi_mapcolor;
ggifunc_unmappixel	GGI_multi_unmappixel;
ggifunc_packcolors	GGI_multi_packcolors;
ggifunc_unpackpixels	GGI_multi_unpackpixels;
ggifunc_setpalvec	GGI_multi_setpalvec;
ggifunc_getpalvec	GGI_multi_getpalvec;

typedef struct multi_vis
{
	GG_SLIST_ENTRY(multi_vis) visuals;

	ggi_visual *vis;

	/* ... visual-specific info here */

} MultiVis;

typedef struct {
	int vis_num;

	GG_SLIST_HEAD(vis_list, multi_vis) vis_list;

	/* ... global info here */

} ggi_multi_priv;

#define GGIMULTI_PRIV(vis) ((ggi_multi_priv *)LIBGGI_PRIVATE(vis))

#endif /* _GGI_DISPLAY_MULTI_H */
