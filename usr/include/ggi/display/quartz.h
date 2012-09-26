/* $Id: quartz.h,v 1.8 2005/07/30 10:57:03 cegger Exp $
******************************************************************************

   Display-quartz: headers

   Copyright (C) 2004 Christoph Egger

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

#ifndef _GGI_DISPLAY_QUARTZ_H
#define _GGI_DISPLAY_QUARTZ_H

#include <ggi/gii.h>

#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>

#include <ggi/display/mansync.h>


typedef struct {
	PHYSZ_DATA
	MANSYNC_DATA;	/* mansync helper hooks */

	int fullscreen;

	WindowRef theWindow;
	WindowGroupRef winGroup;

	Rect winRect;	/* size of the window containing the displayed image (including padding) */
	WindowAttributes windowAttrs;

	CGContextRef context;
	CGDataProviderRef dataProviderRef;
	CGImageRef image;

	ggi_visual *memvis;

	size_t stride;
	uint8_t *fb;
	size_t fb_size;

	/* 0 == main display (only support single display) */
	CGDirectDisplayID  display_id;

	/* current mode of the display */
	CFDictionaryRef    cur_mode;
	/* original mode of the display */
	CFDictionaryRef    save_mode;
	/* suggested mode from ggiCheckMode */
	CFDictionaryRef    suggest_mode;
	/* list of available fullscreen modes */
	CFArrayRef	   mode_list;

	/* palette of an 8-bit display */
	CGDirectPaletteRef palette;

	int		ncols;		/* Number of colors in the colormap */
	ggi_color	*gammamap;
	ggi_gammastate	gamma;

	gii_input	*inp;

	int enableUserResize;

	/* functions for use of extensions */
	int (*updateWindowContext)(ggi_visual *vis, int manualrefresh);
} ggi_quartz_priv;


#define QUARTZ_PRIV(vis) ((ggi_quartz_priv *)LIBGGI_PRIVATE(vis))


#define MANSYNC_init(vis)	MANSYNC_DECL_INIT(QUARTZ_PRIV(vis), vis)
#define MANSYNC_deinit(vis)	MANSYNC_DECL_DEINIT(QUARTZ_PRIV(vis), vis)
#define MANSYNC_start(vis)	MANSYNC_DECL_START(QUARTZ_PRIV(vis), vis)
#define MANSYNC_stop(vis)	MANSYNC_DECL_STOP(QUARTZ_PRIV(vis), vis)
#define MANSYNC_ignore(vis)	MANSYNC_DECL_IGNORE(QUARTZ_PRIV(vis), vis)
#define MANSYNC_cont(vis)	MANSYNC_DECL_CONT(QUARTZ_PRIV(vis), vis)


#define GGI_FULLSCREEN_TITLEBORDER	0
#define GGI_WINDOW_TITLEBORDER		15

/* functions for use of extensions */
#define GGI_quartz_updateWindowContext(vis, refresh)	\
		QUARTZ_PRIV(vis)->updateWindowContext(vis, refresh)


#endif /* _GGI_DISPLAY_QUARTZ_H */
