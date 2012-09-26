/* $Id: glide.h,v 1.3 2005/07/31 15:30:38 soyt Exp $
******************************************************************************

   LibGGI GLIDE target

   Copyright (C) 1997		Jon Taylor	[taylorj@ecs.csus.edu]
   Copyright (C) 1998-1999	Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_DISPLAY_GLIDE_H
#define _GGI_DISPLAY_GLIDE_H

#include <ggi/internal/ggi-dl.h>

#ifdef HAVE_GLIDE_H
#include <glide.h>
#else
#ifdef HAVE_GLIDE_GLIDE_H
#include <glide/glide.h>
#endif
#endif

#define GGIGLIDE_DEFAULT_VFREQ	70
#define GGIGLIDE_DEFAULT_HFREQ	48

typedef struct {
	GrVertex	 fgvertex;
	GrVertex	 bgvertex;
	GrLfbSrcFmt_t	 src_format;
	GrLfbWriteMode_t write_mode;
	GrBuffer_t	 readbuf;
	GrBuffer_t	 writebuf;
	FxI32         bytes_per_pixel;
	int           maxvfreq;
	int           maxhfreq;
	int           currentcard;
	unsigned int  fbmem;
	GrHwConfiguration hwconf;
	int setmodesuccess;
	int		dohalt;
	int		autoswitch;
} glide_priv;

ggifunc_flush		GGI_glide_flush;
ggifunc_getmode		GGI_glide_getmode;
ggifunc_setmode		GGI_glide_setmode;
ggifunc_checkmode	GGI_glide_checkmode;
ggifunc_getapi		GGI_glide_getapi;
ggifunc_flush		GGI_glide_flush;

ggifunc_setreadframe	GGI_glide_setreadframe;
ggifunc_setwriteframe	GGI_glide_setwriteframe;
ggifunc_setdisplayframe	GGI_glide_setdisplayframe;

ggifunc_fillscreen	GGI_glide_fillscreen;

ggifunc_drawpixel	GGI_glide_drawpixel;
ggifunc_putpixel	GGI_glide_putpixel;
ggifunc_getpixel	GGI_glide_getpixel;

ggifunc_drawline	GGI_glide_drawline;
ggifunc_drawhline	GGI_glide_drawhline;
ggifunc_drawvline	GGI_glide_drawvline;
ggifunc_puthline	GGI_glide_puthline;
ggifunc_putvline	GGI_glide_putvline;
ggifunc_gethline	GGI_glide_gethline;
ggifunc_getvline	GGI_glide_getvline;

ggifunc_drawbox		GGI_glide_drawbox;
/*ggifunc_copybox	GGI_glide_copybox;*/
ggifunc_putbox		GGI_glide_putbox;
ggifunc_getbox		GGI_glide_getbox;

ggifunc_putc		GGI_glide16_putc;
ggifunc_putc		GGI_glide32_putc;

void _GGI_glide_freedbs(ggi_visual *vis);

#define GLIDE_PRIV(vis) ((glide_priv *)LIBGGI_PRIVATE(vis))

#endif /* _GGI_DISPLAY_GLIDE_H */
