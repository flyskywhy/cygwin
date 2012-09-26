/* $Id: x.h,v 1.20 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Internal header for GGI display-X target

   Copyright (C) 1997 Andreas Beck		[becka@ggi-project.org]
   Copyright (C) 1998-1999 Marcus Sundberg	[marcus@ggi-project.org]
   Copyright (C) 2002 Brian S. Julin		[bri@tull.umassp.edu]

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

#ifndef _GGI_DISPLAY_X_H
#define _GGI_DISPLAY_X_H

#include <ggi/internal/ggi-dl.h>
#include <ggi/input/xwin.h>
#include <ggi/display/mansync.h>
#include <ggi/display/modelist.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

/* These may later be moved into an improved modelist.inc to allow
 * targets that have more then one option for getting modelists
 * to overload the default behavior.
 */
typedef int (*ggi_modelist_getlist)(ggi_visual *vis);
typedef int (*ggi_modelist_restore)(ggi_visual *vis);
typedef int (*ggi_modelist_enter)(ggi_visual *vis, int num);

/* Validate the 'num's mode, if it fits into the 'maxed' mode.
 * If 'num' is negative, then search for the best mode that
 * fits into the 'maxed' mode.
 * Return the 'num's mode from the modelist indicating success.
 * Negative return code indicates an error or GGI_ENOTFOUND.
 */
typedef int (*ggi_modelist_validate)(ggi_visual *vis, intptr_t num,
				     ggi_mode *maxed);

typedef struct {
  ggi_modelist_getlist	getlist;  /* Get/sort modelist, store original mode. */
  ggi_modelist_restore	restore;  /* Restore original mode and free list.    */
  ggi_modelist_enter		enter;	  /* Enter given mode (called by setmode).   */
  ggi_modelist_validate validate; /* Check/complete a ggi_mode structure
				     												 based on a given mode. */
} ggi_modelist_funcs;

/* A structure for management of visual information */
typedef struct {
  XVisualInfo					*vi;
  void								*evi;		/* ExtendedVisualInfo if Xevi found */
  XPixmapFormatValues	*buf;		/* Buffer/wire format               */
  unsigned int 				 flags;
#define GGI_X_VI_NON_FB 1
} ggi_x_vi;

typedef int  (*ggi_x_createfb)(ggi_visual *vis);	/* MMAP/alloc fb/db  */
typedef void (*ggi_x_freefb)(ggi_visual *vis);		/* clean up fb/db    */
typedef int  (*ggi_x_createdrawable)(ggi_visual *vis);	/* prepare renderer  */
typedef void (*ggi_x_createcursor)(ggi_visual *vis);	/* load mouse sprite */

struct ggi_x_priv;

typedef void (*ggi_x_checkmode_adapt)( ggi_mode * m,
				       ggi_x_vi * vi,
				       struct ggi_x_priv * priv );
typedef void (*ggi_x_checkmode_adjust)( ggi_mode *req,
			      ggi_mode *sug,
			      struct ggi_x_priv *priv );

typedef struct ggi_x_priv {
	PHYSZ_DATA

	Display	*disp;		/* One display per instance  */

	MANSYNC_DATA;			/* mansync helper hooks     */
	ggi_coord  dirtytl,dirtybr;	/* Simple dirty region */
	int fullflush;			/* Flush all visible area?  */

	/* Pixelformat and colorspace management */
	int viidx;			/* currently active visual   */
	ggi_x_vi *vilist;		/* Sorted list of visuals    */
	void *evilist;			/* master handle for XFree() */
	XVisualInfo *visual;		/* master handle for XFree() */
	int nvisuals;
	XPixmapFormatValues     *buflist;	/* master handle for XFree() */
	int                     nbufs;

	unsigned int		use_Xext;	/* Extensions available/used */
#define GGI_X_USE_SHM		1
#define GGI_X_USE_DBE		2
#define GGI_X_USE_DGA		4
#define GGI_X_USE_EVI		8
#define GGI_X_USE_VIDMODE	16

	Colormap    cmap, cmap2;/* Need second for DGA bug workaround */
	int         activecmap;
	int         ncols;		/* Number of colors in the colormap */
	XColor      *gammamap;
	ggi_gammastate gamma;

	GC           gc, tempgc;

	Cursor      oldcursor, cursor;
	ggi_x_createcursor	createcursor;	/* overload init .drawable */
	XFontStruct *textfont;
	XImage	    *fontimg;

	void        *xliblock;
	void        (*lock_xlib)(ggi_visual *vis);
	void        (*unlock_xlib)(ggi_visual *vis);
	void        *flushlock;

	int         wintype;
	Window      parentwin, win;

	unsigned char		*fb;	/* direct access */
	Drawable	 drawable;	/* Xlib/accel access */

	/* Overloadables: */
	ggi_x_createdrawable	createdrawable;	/* overload init .drawable */
	ggi_x_createfb	 createfb;	/* overload init .fb */
	ggi_x_freefb	 freefb;	/* overload init .fb */
	ggi_x_checkmode_adapt cm_adapt; /* visual to ggi_mode conversion */
	ggi_x_checkmode_adjust cm_adjust; /* adjust ggi_mode to meet request */

	XImage	    *ximage;
	ggi_visual	*slave;

	/* Modelist management */
	ggi_modelist_funcs	mlfuncs;	/* modelist helper overloads */
	ggi_modelistmode	*modes;		/* modelist helper modes     */
	void		 	*modes_priv;	/* DGA or VideoMode modelist */
	int	cur_mode;			/* Current used mode from the modelist */
	int	 modes_num;			/* number of modes in list.  */

	gii_input   *inp;

	void	*priv; 		/* for extra handles (dga) */

	/* Hooks to ferry a few core ops w/o using symbol tables */
	ggifunc_resacquire	*acquire;
	ggifunc_resrelease	*release;
	int			(*flush_cmap)(ggi_visual *vis);

	/* This boolean tells whether or not we are managing the window
	 * size.  Its true unless we have -inwin= or -fullscreen. */
	int			ok_to_resize;

	ggifunc_checkmode	*shmhack_checkmode_fixed;

	/* We shouldn't have to ferry this, but will until we figure out
	   how to unhook MIT-SHM's XCloseDisplay hook so we can close it
	   gracefully.
	*/
	void			(*shmhack_free_cmaps)(ggi_visual *vis);

} ggi_x_priv;

#define GGIX_PRIV(vis) ((ggi_x_priv *)LIBGGI_PRIVATE(vis))

#define GGI_X_LOCK_XLIB(vis)   (GGIX_PRIV(vis)->lock_xlib(vis))
#define GGI_X_UNLOCK_XLIB(vis) (GGIX_PRIV(vis)->unlock_xlib(vis))

/* Defined in mode.c */
int _ggi_x_do_blit(ggi_visual_t vis, int x, int y, int w, int h);
int _ggi_x_resize (ggi_visual_t vis, int w, int h, ggi_event *ev);

/* Defined in visual.c */
void _GGI_X_freedbs(ggi_visual *, ggi_x_priv *);

#define MANSYNC_init(vis)   MANSYNC_DECL_INIT(GGIX_PRIV(vis), vis)
#define MANSYNC_deinit(vis) MANSYNC_DECL_DEINIT(GGIX_PRIV(vis), vis)
#define MANSYNC_start(vis)  MANSYNC_DECL_START(GGIX_PRIV(vis), vis)
#define MANSYNC_stop(vis)   MANSYNC_DECL_STOP(GGIX_PRIV(vis), vis)
#define MANSYNC_ignore(vis) MANSYNC_DECL_IGNORE(GGIX_PRIV(vis), vis)
#define MANSYNC_cont(vis)   MANSYNC_DECL_CONT(GGIX_PRIV(vis), vis)

/* Protos for utility functions in misc.c */
void _ggi_x_build_vilist(ggi_visual *vis);
ggi_graphtype _ggi_x_scheme_vs_class(ggi_graphtype gt, ggi_x_vi *vi);
int _ggi_x_fit_geometry(ggi_visual *vis, ggi_mode *tm,
			ggi_x_vi *vi, ggi_mode *suggest);
void _ggi_x_free_colormaps(ggi_visual *vis);
void _ggi_x_create_colormaps(ggi_visual *vis, XVisualInfo *vi);
void _ggi_x_build_pixfmt(ggi_visual *vis, ggi_mode *tm, XVisualInfo *vi);
int _ggi_x_dress_parentwin(ggi_visual *vis, ggi_mode *tm);
void _ggi_x_set_xclip(ggi_visual *vis, Display *disp, GC gc,
		      int x, int y, int w, int h);
void _ggi_x_create_dot_cursor(ggi_visual *vis);
void _ggi_x_create_invisible_cursor(ggi_visual *vis);
void _ggi_x_readback_fontdata(ggi_visual *vis);

int _ggi_x_is_better_gt(ggi_graphtype than, ggi_graphtype this);
int _ggi_x_is_better_fmt(XVisualInfo *than, XVisualInfo *cthis);
int _ggi_x_is_better_screen(Screen *than, Screen *cthis);


/* buffer.c prototypes */
ggifunc_resacquire GGI_X_db_acquire;
ggifunc_resrelease GGI_X_db_release;
int GGI_X_setdisplayframe_child(ggi_visual *vis, int num);
int GGI_X_setorigin_child(ggi_visual *vis, int x, int y);
int GGI_X_setreadframe_slave(ggi_visual *vis, int num);
int GGI_X_setwriteframe_slave(ggi_visual *vis, int num);
XImage *_ggi_x_create_ximage(ggi_visual *vis, char *data, int w, int h);
int _ggi_x_createfb(ggi_visual *vis);
void _ggi_x_freefb(ggi_visual *vis);
int GGI_X_create_window_drawable (ggi_visual *vis);
gii_inputxwin_exposefunc GGI_X_expose;
ggifunc_flush GGI_X_flush_ximage_child;

#define GGI_X_DIRTY(vis, _x, _y, _w, _h) do {               		\
if (priv->dirtytl.x > priv->dirtybr.x) {				\
  priv->dirtybr.x = _x + _w -1; priv->dirtybr.y = _y + _h-1;		\
  priv->dirtytl.x = _x; priv->dirtytl.y = _y; break; }			\
if (priv->dirtytl.x > _x) priv->dirtytl.x = _x;				\
if (priv->dirtytl.y > _y) priv->dirtytl.y = _y;				\
if (priv->dirtybr.x < _x + _w-1) priv->dirtybr.x = _x + _w-1;		\
if (priv->dirtybr.y < _y + _h-1) priv->dirtybr.y = _y + _h-1;		\
} while (0)

#define GGI_X_CLEAN(vis, _x, _y, _w, _h) do { \
if (priv->dirtytl.x >= _x && priv->dirtybr.x <= _x + _w-1) {		\
  if (priv->dirtytl.y >= _y && priv->dirtybr.y <= _y + _h-1) {		\
    priv->dirtytl.x = 1; priv->dirtybr.x = 0; break; }			\
  if ((priv->dirtybr.y < _y) || (priv->dirtytl.y > _y + _h-1)) break;	\
  if ((priv->dirtybr.y > _y + _h-1) && (priv->dirtytl.y < _y)) break;	\
  if (priv->dirtytl.y < _y) priv->dirtybr.y = _y-1;			\
  if (priv->dirtybr.y > _y + _h-1) priv->dirtytl.y = _y + _h;		\
} else if (priv->dirtytl.y >= _y && priv->dirtybr.y <= _y + _h-1) {	\
  if ((priv->dirtybr.x < _x) || (priv->dirtytl.x > _x + _w-1)) break;	\
  if ((priv->dirtybr.x > _x + _w-1) && (priv->dirtytl.x < _x)) break;	\
  if (priv->dirtytl.x < _x) priv->dirtybr.x = _x-1;		        \
  if (priv->dirtybr.x > _x + _w-1) priv->dirtytl.x = _x + _w;		\
}} while (0)
#define GGI_X_SYNC(_vis) XFlush(GGIX_PRIV(_vis)->disp);
#define GGI_X_MAYBE_SYNC(_vis) \
if (!(LIBGGI_FLAGS(_vis) & GGIFLAG_ASYNC)) XFlush(GGIX_PRIV(_vis)->disp);

#define GGI_X_READ_Y  (y + LIBGGI_VIRTY(vis) * vis->r_frame_num)
#define GGI_X_WRITE_Y (y + LIBGGI_VIRTY(vis) * vis->w_frame_num)
#define GGI_X_DISPLAY_Y (y + LIBGGI_VIRTY(vis) * vis->d_frame_num)

ggifunc_gcchanged	GGI_X_gcchanged;

ggifunc_getmode		GGI_X_getmode;
ggifunc_checkmode	GGI_X_checkmode;
ggifunc_setmode		GGI_X_setmode;

ggifunc_drawpixel	GGI_X_drawpixel_slave;
ggifunc_drawpixel	GGI_X_drawpixel_slave_draw;
ggifunc_drawpixel	GGI_X_drawpixel_draw;

ggifunc_drawpixel	GGI_X_drawpixel_nc_slave;
ggifunc_drawpixel	GGI_X_drawpixel_nc_slave_draw;

ggifunc_putpixel	GGI_X_putpixel_slave;
ggifunc_putpixel	GGI_X_putpixel_draw;

ggifunc_putpixel	GGI_X_putpixel_nc_slave;

ggifunc_getpixel	GGI_X_getpixel_slave;
ggifunc_getpixel	GGI_X_getpixel_draw;

ggifunc_drawhline	GGI_X_drawhline_slave;
ggifunc_drawhline	GGI_X_drawhline_slave_draw;
ggifunc_drawhline	GGI_X_drawhline_draw;

ggifunc_drawhline	GGI_X_drawhline_nc_slave;
ggifunc_drawhline	GGI_X_drawhline_nc_slave_draw;

ggifunc_puthline	GGI_X_puthline_slave;
ggifunc_puthline	GGI_X_puthline_draw;

ggifunc_gethline	GGI_X_gethline_slave;
ggifunc_gethline	GGI_X_gethline_draw;

ggifunc_drawvline	GGI_X_drawvline_slave;
ggifunc_drawvline	GGI_X_drawvline_slave_draw;
ggifunc_drawvline	GGI_X_drawvline_draw;

ggifunc_drawvline	GGI_X_drawvline_nc_slave;
ggifunc_drawvline	GGI_X_drawvline_nc_slave_draw;

ggifunc_putvline	GGI_X_putvline_slave;
ggifunc_putvline	GGI_X_putvline_draw;

ggifunc_getvline	GGI_X_getvline_slave;
ggifunc_getvline	GGI_X_getvline_draw;

ggifunc_drawline	GGI_X_drawline_slave;
ggifunc_drawline	GGI_X_drawline_slave_draw;
ggifunc_drawline	GGI_X_drawline_draw;

ggifunc_drawbox		GGI_X_drawbox_slave;
ggifunc_drawbox		GGI_X_drawbox_slave_draw;
ggifunc_drawbox		GGI_X_drawbox_draw;

ggifunc_putbox		GGI_X_putbox_slave;
ggifunc_putbox		GGI_X_putbox_draw;

ggifunc_getbox		GGI_X_getbox_slave;
ggifunc_getbox		GGI_X_getbox_draw;

ggifunc_copybox		GGI_X_copybox_slave;
ggifunc_copybox		GGI_X_copybox_slave_draw;
ggifunc_copybox		GGI_X_copybox_draw;

ggifunc_fillscreen	GGI_X_fillscreen_slave;
ggifunc_fillscreen	GGI_X_fillscreen_slave_draw;
ggifunc_fillscreen	GGI_X_fillscreen_draw;

ggifunc_putc		GGI_X_putc_slave_draw;
ggifunc_putc		GGI_X_putc_draw;
ggifunc_getcharsize	GGI_X_getcharsize_font;


/* color.c protos */
int _ggi_x_flush_cmap (ggi_visual *vis);
ggifunc_setPalette	GGI_X_setPalette;
ggifunc_setgammamap	GGI_X_setgammamap;
ggifunc_getgammamap	GGI_X_getgammamap;

#endif /* _GGI_DISPLAY_X_H */
