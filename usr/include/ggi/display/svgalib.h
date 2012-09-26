/* $Id: svgalib.h,v 1.8 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   LibGGI SVGAlib target

   Copyright (C) 1998 Marcus Sundberg   [marcus@ggi-project.org]
   Copyright (C) 1998 Steve Cheng       [steve@ggi-project.org]

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

   ----------------------------------------------------------------------
   README:

   Programs need SUID root. You really should use KGI :-)

   See source for miscellaneous stuff.
   The SVGAlib target also supports banked and modeX modes.

******************************************************************************
*/

#ifndef _GGI_DISPLAY_SVGALIB_H
#define _GGI_DISPLAY_SVGALIB_H

#include <vga.h>

#include <ggi/internal/ggi-dl.h>
#include <ggi/display/linvtsw.h>
#include <ggi/display/modelist.h>

ggifunc_flush		GGI_svga_flush;
ggifunc_getmode		GGI_svga_getmode;
ggifunc_setmode		GGI_svga_setmode;
ggifunc_getapi		GGI_svga_getapi;
ggifunc_checkmode	GGI_svga_checkmode;
ggifunc_setflags	GGI_svga_setflags;

ggifunc_putpixel	GGI_svga_putpixel;
ggifunc_putpixel	GGI_svga_putpixel_nc;
ggifunc_getpixel	GGI_svga_getpixel;
ggifunc_drawpixel	GGI_svga_drawpixel;
ggifunc_drawpixel	GGI_svga_drawpixel_nc;
ggifunc_drawhline	GGI_svga_drawhline;
ggifunc_drawhline	GGI_svga_drawhline_nc;
ggifunc_drawvline	GGI_svga_drawvline;
ggifunc_drawvline	GGI_svga_drawvline_nc;
ggifunc_drawbox		GGI_svga_drawbox;
ggifunc_puthline	GGI_svga_puthline;
ggifunc_putbox		GGI_svga_putbox;

ggifunc_setreadframe	GGI_svga_setreadframe;
ggifunc_setwriteframe	GGI_svga_setwriteframe;
ggifunc_setdisplayframe	GGI_svga_setdisplayframe;

ggifunc_setPalette	GGI_svga_setPalette;
size_t GGI_svga_getPrivSize(ggi_visual_t);

/* We must use a wrapper around vga_setmode() because SVGAlib messes
   with terminal settings. */
int _ggi_svgalib_setmode(int mode);
void _GGI_svga_freedbs(ggi_visual *);

typedef struct svga_priv {
	PHYSZ_DATA

	ggi_modelistmode *availmodes;
	uint8_t	         *memorigin;
	uint32_t pixperframe;
	int	islinear;
	int	ismodex;
	int	isbanked;
	int	inputs;
	int	dohalt;
	int	autoswitch;
	int	switchpending;
	int	ismapped;
	ggi_linvtsw_func *doswitch;
	int	gfxmode;
	int	frame_size;
} svga_priv;

#define SVGA_PRIV(vis) ((svga_priv*)LIBGGI_PRIVATE(vis))

#define INP_KBD    0x01
#define INP_MOUSE  0x02
#define INP_VT     0x04   /* not really an input. too bad */

#endif /* _GGI_DISPLAY_SVGALIB_H */
