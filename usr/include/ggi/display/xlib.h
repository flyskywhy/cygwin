/* $Id: xlib.h,v 1.2 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Display-Xlib: data

   Copyright (C) 1997 Andreas Beck		[becka@ggi-project.org]
   Copyright (C) 1998-1999 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_DISPLAY_XLIB_H
#define _GGI_DISPLAY_XLIB_H

#include <ggi/internal/ggi-dl.h>
#include <ggi/input/xwin.h>


#include <ggi/display/xcommon.h>


ggifunc_flush		GGI_Xlib_flush;
ggifunc_getmode		GGI_Xlib_getmode;
ggifunc_setmode		GGI_Xlib_setmode;
ggifunc_checkmode	GGI_Xlib_checkmode;
ggifunc_getapi 		GGI_Xlib_getapi;
ggifunc_setflags	GGI_Xlib_setflags;

ggifunc_setpalvec	GGI_Xlib_setpalvec;

ggifunc_drawpixel	GGI_Xlib_drawpixel;
ggifunc_putpixel	GGI_Xlib_putpixel;
ggifunc_getpixel	GGI_Xlib_getpixel;

ggifunc_drawline	GGI_Xlib_drawline;
ggifunc_drawhline	GGI_Xlib_drawhline;
ggifunc_puthline	GGI_Xlib_puthline;
ggifunc_drawvline	GGI_Xlib_drawvline;
ggifunc_putvline	GGI_Xlib_putvline;

ggifunc_drawbox		GGI_Xlib_drawbox;
ggifunc_putbox		GGI_Xlib_putbox;
ggifunc_copybox		GGI_Xlib_copybox;
ggifunc_getbox		GGI_Xlib_getbox;
ggifunc_fillscreen	GGI_Xlib_fillscreen;

ggifunc_getcharsize	GGI_Xlib_getcharsize;
ggifunc_putc		GGI_Xlib_putc;

typedef struct {
	ggi_xwin_common	 xwin;

	/* xlib only data */
	GC           tempgc;
	XFontStruct *textfont;
} ggi_xlib_priv;

#define GGIXLIB_PRIV(vis) ((ggi_xlib_priv *)LIBGGI_PRIVATE(vis))

/* Defined in mode.c */
int _ggi_x_resize (ggi_visual_t vis, int w, int h, ggi_event *ev);

#define XLIB_DOSYNC(vis) \
{\
	if (!(LIBGGI_FLAGS(vis) & GGIFLAG_ASYNC))\
		GGI_Xlib_flush(vis, 0, 0, LIBGGI_X(vis), LIBGGI_Y(vis), 1);\
}

#endif /* _GGI_DISPLAY_XLIB_H */
