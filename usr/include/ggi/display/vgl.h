/* $Id: vgl.h,v 1.2 2005/07/30 10:57:03 cegger Exp $
******************************************************************************

   LibGGI FreeBSD vgl(3) target

   Copyright (C) 2000 Alcove - Nicolas Souchu <nsouch@freebsd.org>

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

#ifndef _GGI_DISPLAY_VGL_H
#define _GGI_DISPLAY_VGL_H

#include <sys/fbio.h>
#include <sys/consio.h>
#include <vgl.h>

#include <ggi/internal/ggi-dl.h>
#include <ggi/display/modelist.h>

ggifunc_flush		GGI_vgl_flush;
ggifunc_getmode		GGI_vgl_getmode;
ggifunc_setmode		GGI_vgl_setmode;
ggifunc_getapi		GGI_vgl_getapi;
ggifunc_checkmode	GGI_vgl_checkmode;
ggifunc_setflags	GGI_vgl_setflags;

ggifunc_putpixel	GGI_vgl_putpixel;
ggifunc_putpixel	GGI_vgl_putpixel_nc;
ggifunc_getpixel	GGI_vgl_getpixel;
ggifunc_drawpixel	GGI_vgl_drawpixel;
ggifunc_drawpixel	GGI_vgl_drawpixel_nc;
ggifunc_drawhline	GGI_vgl_drawhline;
ggifunc_drawhline	GGI_vgl_drawhline_nc;
ggifunc_drawvline	GGI_vgl_drawvline;
ggifunc_drawvline	GGI_vgl_drawvline_nc;
ggifunc_drawbox		GGI_vgl_drawbox;
ggifunc_drawline	GGI_vgl_drawline;

ggifunc_setpalvec	GGI_vgl_setpalvec;

ggifunc_puthline	GGI_vgl_puthline;
ggifunc_putbox		GGI_vgl_putbox;

ggifunc_setorigin	GGI_vgl_setorigin;

typedef struct vgl_priv {
	ggi_modelistmode *availmodes;
	uint8_t	         *memorigin;
	int		 *savepalette;
	uint32_t pixperframe;

	int	vgl_init_done;
	int	vgl_use_db;

#define VGL_RED_INDEX	0
#define VGL_GREEN_INDEX	1
#define VGL_BLUE_INDEX	2
	video_info_t modeinfo;

	byte vgl_palred[256];
	byte vgl_palgreen[256];
	byte vgl_palblue[256];

#define INP_KBD    0x01
#define INP_MOUSE  0x02
	int	inputs;

} vgl_priv;

#define VGL_PRIV(vis) ((vgl_priv*)LIBGGI_PRIVATE(vis))

#endif /* _GGI_DISPLAY_VGL_H */
