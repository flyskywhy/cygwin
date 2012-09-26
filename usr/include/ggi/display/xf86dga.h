/* $Id: xf86dga.h,v 1.5 2005/02/03 18:10:17 orzo Exp $
******************************************************************************

   XFree86 Direct Graphics Access target for LibGGI

   Copyright (C) 1998 Steve Cheng	[steve@ggi-project.org]
   Copyright (C) 1999 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_DISPLAY_XF86DGA_H
#define _GGI_DISPLAY_XF86DGA_H

#include <ggi/internal/ggi-dl.h>
#include <ggi/input/xwin.h>
#include <ggi/display/xcommon.h>
#include <ggi/display/modelist.h>

#include <X11/extensions/xf86vmode.h>

/* Macros to gain and give up root privs, for mmapping /dev/mem. Note that
   they use the non-POSIX (but BSD 4.3 conformant) call seteuid() because
   regular setuid() does not allow regaining root privs when they have
   already been given up. */

#define GET_ROOT		seteuid(0)
#define GIVE_UP_ROOT		seteuid(getuid())
#define PERM_GIVE_UP_ROOT	setuid(getuid())

/* LIBGGI_PRIVATE info */

typedef struct {
	ggi_x_common x;

	XF86VidModeModeInfo **dgamodes;
	int num_modes;
	int dgafeat;
	unsigned width;
	unsigned height;
	unsigned depth;
	unsigned size;

	Colormap cmap2;		/* We need two colormaps to work around a bug
				   in XFree86 DGA... */
	int activecmap;
	int pixperframe;
	void *fb;
	int stride;
	int bank_size;
	int mem_size;
	int deinited;

	/* Non accelerated functions */
	ggifunc_drawbox *drawbox;
	ggifunc_copybox *copybox;
} ggidga_priv;

/* The XF86DGA functions */
#ifdef GGI_INTERNAL_XF86DGA
Bool _ggi_XF86DGAQueryExtension(Display * dpy, int *event_basep,
				int *error_basep);
Bool _ggi_XF86DGAQueryVersion(Display * dpy, int *majorVersion,
			      int *minorVersion);
Bool _ggi_XF86VidModeSetClientVersion(Display * dpy);
Bool _ggi_XF86DGASetViewPort(Display * dpy, int screen, int x, int y);
Bool _ggi_XF86DGAInstallColormap(Display * dpy, int screen, Colormap cmap);
Bool _ggi_XF86DGAQueryDirectVideo(Display * dpy, int screen, int *flags);
int _ggi_XF86DGADirectVideo(Display * dis, int screen, int enable);
int _ggi_XF86DGAGetVideo(Display * dis, int screen, char **addr,
			 int *width, int *bank, int *ram);
void _ggi_XF86DGAUnmap(void);
Bool _ggi_XF86DGACopyArea(Display * dpy, int screen, Drawable d, GC gc,
			  int src_x, int src_y,
			  unsigned int width, unsigned int height,
			  int dst_x, int dst_y);
Bool _ggi_XF86DGAFillRectangle(Display * dpy, int screen, Drawable d,
			       GC gc, int x, int y, unsigned int width,
			       unsigned int height);

Bool _ggi_XF86VidModeQueryExtension(Display * dpy, int *event_basep,
				    int *error_basep);
Bool _ggi_XF86VidModeQueryVersion(Display * dpy, int *majorVersion,
				  int *minorVersion);
Bool _ggi_XF86VidModeGetAllModeLines(Display * dpy, int screen,
				     int *modecount,
				     XF86VidModeModeInfo *** modelinesPtr);
Bool _ggi_XF86VidModeSwitchToMode(Display * dpy, int screen,
				  XF86VidModeModeInfo * modeline);
#else
#define _ggi_XF86DGAQueryExtension	XF86DGAQueryExtension
#define _ggi_XF86DGAQueryVersion	XF86DGAQueryVersion
#define _ggi_XF86DGASetViewPort		XF86DGASetViewPort
#define _ggi_XF86DGAInstallColormap	XF86DGAInstallColormap
#define _ggi_XF86DGAQueryDirectVideo	XF86DGAQueryDirectVideo
#define _ggi_XF86DGADirectVideo		XF86DGADirectVideo
#define _ggi_XF86DGAGetVideo		XF86DGAGetVideo
#define _ggi_XF86DGAUnmap()		do{}while(0)
#define _ggi_XF86DGACopyArea		XF86DGACopyArea
#define _ggi_XF86DGAFillRectangle	XF86DGAFillRectangle

#define _ggi_XF86VidModeQueryExtension	XF86VidModeQueryExtension
#define _ggi_XF86VidModeQueryVersion	XF86VidModeQueryVersion
#define _ggi_XF86VidModeGetAllModeLines	XF86VidModeGetAllModeLines
#define _ggi_XF86VidModeSwitchToMode	XF86VidModeSwitchToMode
#endif


/* prototypes
 */
ggifunc_getmode GGI_xf86dga_getmode;
ggifunc_setmode GGI_xf86dga_setmode;
ggifunc_checkmode GGI_xf86dga_checkmode;
ggifunc_getapi GGI_xf86dga_getapi;
ggifunc_setflags GGI_xf86dga_setflags;

ggifunc_setPalette GGI_xf86dga_setPalette;

ggifunc_drawbox GGI_xf86dga_drawbox;
ggifunc_copybox GGI_xf86dga_copybox;

void _GGI_xf86dga_freedbs(ggi_visual *);

#define DGA_PRIV(vis) ((ggidga_priv *)LIBGGI_PRIVATE(vis))

#define DGA_DOSYNC(priv) \
{ if (!(LIBGGI_FLAGS(vis) & GGIFLAG_ASYNC)) { \
	XFlush(priv->x.display); } }

#endif				/* _GGI_DISPLAY_XF86DGA_H */
