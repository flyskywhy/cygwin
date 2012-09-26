/* $Id: lcd823.h,v 1.3 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Display-lcd823

   Copyright (C) 2000 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_DISPLAY_LCD823_H
#define _GGI_DISPLAY_LCD823_H

#include <ggi/internal/ggi-dl.h>

ggifunc_getmode		GGI_lcd823_getmode;
ggifunc_setmode		GGI_lcd823_setmode;
ggifunc_checkmode	GGI_lcd823_checkmode;
ggifunc_getapi		GGI_lcd823_getapi;
ggifunc_setflags	GGI_lcd823_setflags;

ggifunc_setPalette	GGI_lcd823_setPalette;
size_t GGI_lcd823_getPrivSize(ggi_visual_t);
ggifunc_setorigin	GGI_lcd823_setorigin;
ggifunc_setdisplayframe	GGI_lcd823_setdisplayframe;


/* Visual-specific private data */
typedef struct {
	/* Framebuffer info */
	void *fb_ptr;
	long  fb_size;
	long  frame_size;
} ggi_lcd823_priv;

#define LCD823_PRIV(vis) ((ggi_lcd823_priv *)LIBGGI_PRIVATE(vis))

#endif /* _GGI_DISPLAY_LCD823_H */
