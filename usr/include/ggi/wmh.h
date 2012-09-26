/* $Id: wmh.h,v 1.5 2005/05/12 07:57:13 pekberg Exp $
******************************************************************************

   LibGGI WMH extension API header file

   Copyright (C) 2001 Andreas Beck	[becka@ggi-project.org]
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

#ifndef _GGI_WMH_H
#define _GGI_WMH_H

#include <ggi/ggi.h>
#include <ggi/wmh-defs.h>

__BEGIN_DECLS

/* Get the master config dir
 */
GGIWMHAPIFUNC const char *ggiWmhGetConfDir(void);

/* Enter and leave the library
 */
GGIWMHAPIFUNC int ggiWmhInit(void);
GGIWMHAPIFUNC int ggiWmhExit(void);

GGIWMHAPIFUNC int ggiWmhAttach(ggi_visual_t vis);
GGIWMHAPIFUNC int ggiWmhDetach(ggi_visual_t vis);

/* Moving/Resizing the window
 */
GGIWMHAPIFUNC int ggiWmhMove         (ggi_visual_t vis,int  x,int  y);
GGIWMHAPIFUNC int ggiWmhGetPos       (ggi_visual_t vis,int *x,int *y);
GGIWMHAPIFUNC int ggiWmhResize       (ggi_visual_t vis,int x,int y);
GGIWMHAPIFUNC int ggiWmhGetSize      (ggi_visual_t vis,int *x,int *y);
GGIWMHAPIFUNC int ggiWmhAllowResize  (ggi_visual_t vis,int xmin,int ymin,
				      int xmax,int ymax,int xstep,int ystep);
GGIWMHAPIFUNC int ggiWmhMaximize     (ggi_visual_t vis,int xperc,int yperc);

/* Set the window title
 */
GGIWMHAPIFUNC int ggiWmhSetTitle     (ggi_visual_t vis, const char *title);

/* Move the window in the window stack
 */
enum ggi_wmh_ordercmd {
	GGI_WMH_ZO_TOP,
	GGI_WMH_ZO_ONE_UP,
	GGI_WMH_ZO_ONE_DOWN,
	GGI_WMH_ZO_BOTTOM,
	/* deprecated stuff for retarded programs */
	ZO_TOP      = GGI_WMH_ZO_TOP,
	ZO_ONE_UP   = GGI_WMH_ZO_ONE_UP,
	ZO_ONE_DOWN = GGI_WMH_ZO_ONE_DOWN,
	ZO_BOTTOM   = GGI_WMH_ZO_BOTTOM
};
#define ordercmd ggi_wmh_ordercmd

GGIWMHAPIFUNC int ggiWmhZOrder       (ggi_visual_t vis,
				      enum ggi_wmh_ordercmd command);

/* Icon stuff.
 */
#define GGI_WMH_MAPSTATE_NORMAL		0
#define GGI_WMH_MAPSTATE_ICON		1
#define GGI_WMH_MAPSTATE_WITHDRAWN	2

GGIWMHAPIFUNC int ggiWmhIconify      (ggi_visual_t vis,int icon);
GGIWMHAPIFUNC int ggiWmhMoveIcon     (ggi_visual_t vis,int x,int y);
GGIWMHAPIFUNC int ggiWmhSetIconTitle (ggi_visual_t vis, const char *title);
/* Icon Pixmaps and flags ? */

__END_DECLS

#endif /* _GGI_WMH_H */
