/* $Id: libkgi.h,v 1.3 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Display-LibKGI private structures and internal values

   Copyright (C) 2001 Brian S. Julin	[bri@tull.umassp.edu]

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

#ifndef _GGI_DISPLAY_LIBKGI_H
#define _GGI_DISPLAY_LIBKGI_H

#include <ggi/internal/ggi-dl.h>
#include <ggi/galloc.h>
#include <ggi/mmutil.h>

ggifunc_flush		GGI_libkgi_flush;
ggifunc_kgicommand	GGI_libkgi_kgicommand;
ggifunc_getapi		GGI_libkgi_getapi;
ggifunc_setflags	GGI_libkgi_setflags;
ggifunc_idleaccel	GGI_libkgi_idleaccel;
ggifunc_getmode		GGI_libkgi_getmode;
ggifunc_checkmode	GGI_libkgi_checkmode;
ggifunc_setmode		GGI_libkgi_setmode;
ggifunc_sendevent	GGI_libkgi_sendevent;
ggifunc_gcchanged	GGI_libkgi_gcchanged;
ggifunc_setorigin	GGI_libkgi_setorigin;
ggifunc_setdisplayframe	GGI_libkgi_setdisplayframe;
ggifunc_setreadframe	GGI_libkgi_setreadframe;
ggifunc_setwriteframe	GGI_libkgi_setwriteframe;
ggifunc_fillscreen	GGI_libkgi_fillscreen;
ggifunc_putc		GGI_libkgi_putc;
ggifunc_puts		GGI_libkgi_puts;
ggifunc_getcharsize	GGI_libkgi_getcharsize;
ggifunc_drawpixel	GGI_libkgi_drawpixel;
ggifunc_putpixel	GGI_libkgi_putpixel;
ggifunc_getpixel	GGI_libkgi_getpixel;
ggifunc_drawline	GGI_libkgi_drawline;
ggifunc_drawhline	GGI_libkgi_drawhline;
ggifunc_puthline	GGI_libkgi_puthline;
ggifunc_gethline	GGI_libkgi_gethline;
ggifunc_drawvline	GGI_libkgi_drawvline;
ggifunc_putvline	GGI_libkgi_putvline;
ggifunc_getvline	GGI_libkgi_getvline;
ggifunc_drawbox		GGI_libkgi_drawbox;
ggifunc_putbox		GGI_libkgi_putbox;
ggifunc_getbox		GGI_libkgi_getbox;
ggifunc_copybox		GGI_libkgi_copybox;
ggifunc_crossblit	GGI_libkgi_crossblit;


/* Visual-specific private data */
typedef struct {
	PHYSZ_DATA

	/* Framebuffer info */
	char   *accel;
	int	have_accel;
	void   *accelpriv;		/* Accel lib private data */

	ggifunc_flush	  *flush;
	ggifunc_idleaccel *idleaccel;

	batchop_t	drawop_bo;

	/* Misc */
	int	galloc_loaded;  /* Have we loaded LibGAlloc sublib yet? */
	void	*lock;		/* Pointer to the libkgi common lock */
	int	*refcount;	/* Pointer to the refcount */

	char suggest [256 /* FIXME */];
} ggi_libkgi_priv;

#define LIBKGI_PRIV(vis) ((ggi_libkgi_priv *)LIBGGI_PRIVATE(vis))

#endif /* _GGI_DISPLAY_LIBKGI_H */
