/* $Id: wmh.h,v 1.3 2005/05/12 07:57:13 pekberg Exp $
******************************************************************************

   LibGGI WMH extension internals

   Copyright (C) 1999 Andreas Beck	[becka@ggi-project.org]
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

#ifndef _GGI_WMH_INT_H
#define _GGI_WMH_INT_H

#include <ggi/internal/internal.h>
#include <ggi/wmh.h>

__BEGIN_DECLS

/* Exported variables */
GGIWMHAPIVAR ggi_extid _WmhID;

__END_DECLS

typedef int (ggiwmhfunc_move)(ggi_visual *vis,int x,int y);
typedef int (ggiwmhfunc_resize)(ggi_visual *vis,int x,int y);
typedef int (ggiwmhfunc_getpos)(ggi_visual *vis,int *x,int *y);
typedef int (ggiwmhfunc_getsize)(ggi_visual *vis,int *x,int *y);
typedef int (ggiwmhfunc_settitle)(ggi_visual *vis,const char *title);
typedef int (ggiwmhfunc_maximize)(ggi_visual_t vis,int xperc,int yperc);
typedef int (ggiwmhfunc_zorder)(ggi_visual_t vis,enum ggi_wmh_ordercmd command);
typedef int (ggiwmhfunc_iconify)(ggi_visual_t vis,int icon);
typedef int (ggiwmhfunc_moveicon)(ggi_visual_t vis,int x,int y);
typedef int (ggiwmhfunc_seticontitle)(ggi_visual_t vis, const char *title);
typedef int (ggiwmhfunc_allowresize)(ggi_visual_t vis,int xmin,int ymin,int xmax,int ymax,int xstep,int ystep);

typedef struct wmhpriv {
	ggiwmhfunc_move		*move;
	ggiwmhfunc_resize	*resize;
	ggiwmhfunc_getpos	*getpos;
	ggiwmhfunc_getsize	*getsize;
	ggiwmhfunc_settitle	*settitle;
	ggiwmhfunc_maximize	*maximize;
	ggiwmhfunc_zorder	*zorder;
	ggiwmhfunc_iconify	*iconify;
	ggiwmhfunc_moveicon	*moveicon;
	ggiwmhfunc_seticontitle *seticontitle;
	ggiwmhfunc_allowresize	*allowresize;
	void *priv;
} wmhpriv;

#define LIBGGI_WMHEXT(vis) ((wmhpriv *)LIBGGI_EXT(vis,_WmhID))

#endif /* _GGI_WMH_INT_H */
