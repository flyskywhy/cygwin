/* $Id: dltypes.h,v 1.11 2005/07/30 10:57:04 cegger Exp $
******************************************************************************

   LibGGI - typedefs for internal API functions

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

#ifndef _GGI_INTERNAL_DLTYPES_H
#define _GGI_INTERNAL_DLTYPES_H

#include <ggi/types.h>

/*
******************************************************************************
 Typedef internal function types
******************************************************************************
*/

/* Sublib handling
 */

/* Sublib functions */
#define GGIFUNC_open	1
#define GGIFUNC_exit	2
#define GGIFUNC_close	3

typedef int (ggifunc_dlentry)(int func, void **funcptr);

typedef int (ggifunc_open)(struct ggi_visual *vis, struct ggi_dlhandle *dlh,
			   const char *args, void *argptr, uint32_t *dlret);
typedef int (ggifunc_exit)(struct ggi_visual *vis,
			   struct ggi_dlhandle *dlh);
typedef int (ggifunc_close)(struct ggi_visual *vis,
			    struct ggi_dlhandle *dlh);

/* Resource management */
typedef int (ggifunc_resacquire)(struct ggi_resource *res, uint32_t actype);
typedef int (ggifunc_resrelease)(struct ggi_resource *res);


/* Mode Setting routines */
typedef int (ggifunc_getmode)(struct ggi_visual *vis,ggi_mode *tm);
typedef int (ggifunc_setmode)(struct ggi_visual *vis,ggi_mode *tm);
typedef int (ggifunc_checkmode)(struct ggi_visual *vis,ggi_mode *tm);

/* Flag settings */
typedef int (ggifunc_setflags)(struct ggi_visual *vis,ggi_flags flags);

/* Flushing the display
 */
typedef int (ggifunc_flush)(struct ggi_visual *vis, int x, int y, int w, int h,
			    int tryflag);

/* Idle the accelerator */
typedef int (ggifunc_idleaccel)(struct ggi_visual *vis);

/* Sending events to a visual */
typedef int (ggifunc_sendevent)(struct ggi_visual *vis,	ggi_event *event);

/* Frame handling
 */
typedef int (ggifunc_setdisplayframe)(struct ggi_visual *vis, int num);
typedef int (ggifunc_setreadframe)(struct ggi_visual *vis, int num);
typedef int (ggifunc_setwriteframe)(struct ggi_visual *vis, int num);

typedef ggi_pixel (ggifunc_mapcolor)(struct ggi_visual *vis,const ggi_color *color);
typedef int (ggifunc_unmappixel)(struct ggi_visual *vis,ggi_pixel pixel,ggi_color *color);
typedef int (ggifunc_packcolors)(struct ggi_visual *vis,void *buf,const ggi_color *colors,int len);
typedef int (ggifunc_unpackpixels)(struct ggi_visual *vis,const void *buf,ggi_color *colors,int len);

typedef int (ggifunc_setpalvec)(struct ggi_visual *vis,int start,int len,const ggi_color *colormap);
typedef int (ggifunc_getpalvec)(struct ggi_visual *vis,int start,int len,ggi_color *colormap);

/* Colormap */
typedef int (ggifunc_setPalette)(ggi_visual_t vis, size_t start, size_t size, const ggi_color *cmap);

/* Gamma correction */
typedef int (ggifunc_getgamma)(struct ggi_visual *vis,ggi_float *r,ggi_float *g,ggi_float *b);
typedef int (ggifunc_setgamma)(struct ggi_visual *vis,ggi_float r,ggi_float g,ggi_float b);
typedef int (ggifunc_setgammamap)(struct ggi_visual *vis,int start,int len,const ggi_color *gammamap);
typedef int (ggifunc_getgammamap)(struct ggi_visual *vis,int start,int len,ggi_color *gammamap);

typedef int (ggifunc_setorigin)(struct ggi_visual *vis,int x,int y);

typedef int (ggifunc_putc)(struct ggi_visual *vis,int x,int y,char c);
typedef int (ggifunc_puts)(struct ggi_visual *vis,int x,int y,const char *str);
typedef int (ggifunc_getcharsize)(struct ggi_visual *vis,int *width,int *height);

/* Generic drawing routines
 */
typedef int (ggifunc_fillscreen)(struct ggi_visual *vis);

typedef int (ggifunc_drawpixel_nc)(struct ggi_visual *vis,int x,int y);
typedef int (ggifunc_drawpixel)(struct ggi_visual *vis,int x,int y);
typedef int (ggifunc_putpixel_nc)(struct ggi_visual *vis,int x,int y,ggi_pixel pixel);
typedef int (ggifunc_putpixel)(struct ggi_visual *vis,int x,int y,ggi_pixel pixel);
typedef int (ggifunc_getpixel)(struct ggi_visual *vis,int x,int y,ggi_pixel *pixel);

typedef int (ggifunc_drawline)(struct ggi_visual *vis,int x,int y,int xe,int ye);

typedef int (ggifunc_drawhline_nc)(struct ggi_visual *vis,int x,int y,int w);
typedef int (ggifunc_drawhline)(struct ggi_visual *vis,int x,int y,int w);
typedef int (ggifunc_puthline)(struct ggi_visual *vis,int x,int y,int w,const void *buf);
typedef int (ggifunc_gethline)(struct ggi_visual *vis,int x,int y,int w,void *buf);

typedef int (ggifunc_drawvline_nc)(struct ggi_visual *vis,int x,int y,int h);
typedef int (ggifunc_drawvline)(struct ggi_visual *vis,int x,int y,int h);
typedef int (ggifunc_putvline)(struct ggi_visual *vis,int x,int y,int h,const void *buf);
typedef int (ggifunc_getvline)(struct ggi_visual *vis,int x,int y,int h,void *buf);

typedef int (ggifunc_drawbox)(struct ggi_visual *vis,int x,int y,int w,int h);
typedef int (ggifunc_putbox)(struct ggi_visual *vis,int x,int y,int w,int h,const void *buf);
typedef int (ggifunc_getbox)(struct ggi_visual *vis,int x,int y,int w,int h,void *buf);

typedef int (ggifunc_copybox)(struct ggi_visual *vis,int x,int y,int w,int h,int nx,int ny);
typedef int (ggifunc_crossblit)(struct ggi_visual *src,int sx,int sy,int w,int h,
		 struct ggi_visual *dst,int dx,int dy);

typedef void (ggifunc_gcchanged)(struct ggi_visual *vis,int mask);
typedef int  (ggifunc_getapi)(struct ggi_visual *vis, int num, char *apiname, char *arguments);

typedef int (ggifunc_kgicommand)(struct ggi_visual *vis,int cmd,void *args);

#endif /* _GGI_INTERNAL_DLTYPES_H */
