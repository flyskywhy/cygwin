/* $Id: xcommon.h,v 1.3 2004/02/14 22:30:47 cegger Exp $
******************************************************************************

   Common data for X based targets

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

#ifndef _GGI_DISPLAY_XCOMMON_H
#define _GGI_DISPLAY_XCOMMON_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

/* wintypes */
#define GGIX_NORMAL	0x01
#define GGIX_WIN	0x02
#define GGIX_ROOT	0x03

/* x/xlib/dga common data */
typedef struct {
	PHYSZ_DATA

	Display	   *display;
	int	    screen;
	GC          gc;
	Colormap    cmap;
	int         nocols;	/* Number of colors in the colormap */

	void       *xliblock;
	gii_input  *inp;

} ggi_x_common;

/* x/xlib common data */
typedef struct {
	ggi_x_common  x;
	XVisualInfo   visual;
	Window        window;
	Cursor        cursor;

	int           wintype;
	ggi_coord     defsize;

	int     cmap_first, cmap_last; /* Info for palettized modes */
} ggi_xwin_common;

#endif /* _GGI_DISPLAY_XCOMMON_H */
