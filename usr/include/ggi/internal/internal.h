/* $Id: internal.h,v 1.30 2005/09/19 18:46:44 cegger Exp $
******************************************************************************

   LibGGI internal functions and macros

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

#ifndef _GGI_INTERNAL_H
#define _GGI_INTERNAL_H

#define _INTERNAL_LIBGGI


#include <ggi/types.h>
#include <ggi/gg.h>
#include <ggi/ggi-defs.h>
#include <ggi/internal/gii.h>
#include <ggi/internal/plat.h>
#include <ggi/internal/structs.h>


/*
******************************************************************************
 Library internal functions and variables
******************************************************************************
*/

__BEGIN_DECLS
/* Exported variables */
GGIAPIVAR void *_ggi_global_lock;

/* db.c */
GGIAPIFUNC ggi_directbuffer *_ggi_db_get_new(void);
GGIAPIFUNC void _ggi_db_free(ggi_directbuffer * db);
GGIAPIFUNC int _ggi_db_add_buffer(ggi_db_list * dbl, ggi_directbuffer * buf);
GGIAPIFUNC int _ggi_db_del_buffer(ggi_db_list * dbl, int idx);
GGIAPIFUNC int _ggi_db_move_buffer(ggi_db_list * dst, ggi_db_list * src,
				   int idx);
GGIAPIFUNC ggi_directbuffer *_ggi_db_find_frame(ggi_visual * vis,
						int frameno);

/* dl.c */
GGIAPIFUNC ggi_dlhandle *_ggiAddExtDL(ggi_visual *vis,
				      const void *conffilehandle,
				      const char *api,
				      const char *args, void *argptr,
				      const char *symprefix);
GGIAPIFUNC int _ggiOpenDL(ggi_visual * vis, const void *conffilehandle,
			const char *api, const char *args, void *argptr);
GGIAPIFUNC void _ggiExitDL(ggi_visual * vis, ggi_dlhandle_l * lib);
GGIAPIFUNC void _ggiZapDL(ggi_visual * vis, ggi_dlhandle_l ** lib);
GGIAPIFUNC int _ggiAddDL(ggi_visual * vis, const void *conffilehandle,
			const char *api, const char *args, void *argptr,
			int type);
GGIAPIFUNC int _ggiProbeDL(ggi_visual * vis, const void *conffilehandle,
		const char * api, const char * args, void * argptr,
		int type, ggi_dlhandle ** dlh, uint32_t * dlret);

/* init.c */
GGIAPIFUNC const void *_ggiGetConfigHandle(void);

/* internal.c */
GGIAPIFUNC int _ggi_countbits(uint32_t val);
GGIAPIFUNC int _ggi_mask2shift(uint32_t mask);

#define GGI_PIXFMT_GRAPHTYPE	0
#define GGI_PIXFMT_CHANNEL	1
#define GGI_PIXFMT_ALPHA_USED	2
GGIAPIFUNC void _ggi_build_pixfmt(ggi_pixelformat * pixfmt);
GGIAPIFUNC int _ggi_parse_pixfmtstr(const char *pixfmtstr,
		char separator, const char **endptr,
		size_t pixfmtstr_len,
		ggi_pixel *r_mask, ggi_pixel *g_mask,
		ggi_pixel *b_mask, ggi_pixel *a_mask);
GGIAPIFUNC int _ggi_build_pixfmtstr(ggi_visual * vis, char *pixfmtstr,
			size_t pixfmtstr_len, int flags);

GGIAPIFUNC int _ggi_match_palette(ggi_color * pal, int pal_len,
				  const ggi_color * col);
GGIAPIFUNC ggifunc_setreadframe _ggi_default_setreadframe;
GGIAPIFUNC ggifunc_setwriteframe _ggi_default_setwriteframe;
GGIAPIFUNC void _ggi_build_palette(ggi_color * pal, int num);
GGIAPIFUNC void _ggi_smart_match_palettes(ggi_color * pal, int size,
			       ggi_color * ref_pal, int ref_size);

/* mode.c */
GGIAPIFUNC void _ggiSetDefaultMode(const char *str);

#define GGI_PHYSZ_OVERRIDE	1
#define GGI_PHYSZ_DPI		2
#define GGI_PHYSZ_MM		4
GGIAPIFUNC int _ggi_physz_parse_option(const char *optstr, int *physzflag,
				       ggi_coord * physz);
GGIAPIFUNC int _ggi_physz_figure_visible(ggi_mode *mode, int def_x, int def_y,
					int physzflag, const ggi_coord *screen_size,
					const ggi_coord *screen_res);
GGIAPIFUNC int _ggi_physz_figure_size(ggi_mode * mode, int physzflag,
				      const ggi_coord * op_sz,
				      int dpix, int dpiy,
				      int dsx, int dsy);

/* probe.c */
GGIAPIFUNC ggi_visual_t _ggiProbeTarget(void);

/* stubs.c */
GGIAPIFUNC int _ggiInternFlush(ggi_visual * vis, int x, int y, int w, int h,
			       int tryflag);
GGIAPIFUNC int _ggiPutPixelNC(ggi_visual * vis, int x, int y, ggi_pixel p);
GGIAPIFUNC int _ggiDrawPixelNC(ggi_visual * vis, int x, int y);
GGIAPIFUNC int _ggiDrawHLineNC(ggi_visual * vis, int x, int y, int w);
GGIAPIFUNC int _ggiDrawVLineNC(ggi_visual * vis, int x, int y, int h);
GGIAPIFUNC int _ggiIdleAccel(ggi_visual * vis);
GGIAPIFUNC int _ggiSendKGICommand(ggi_visual * vis, int cmd, void *arg);

/* unit.h */
#include <ggi/internal/unit.h>

/* visual.c */
GGIAPIFUNC void *_ggi_malloc(size_t siz);
GGIAPIFUNC void *_ggi_calloc(size_t siz);
GGIAPIFUNC void *_ggi_realloc(void *ptr, size_t siz);
GGIAPIFUNC void _ggi_mem_error(void);
GGIAPIFUNC int _ggi_alloc_drvpriv(void);
GGIAPIFUNC void _ggi_free_drvpriv(int id);
GGIAPIFUNC void _ggiZapMode(ggi_visual * vis, int zapall);

GGIAPIFUNC ggi_visual *_ggiNewVisual(void);
GGIAPIFUNC void _ggiDestroyVisual(ggi_visual * vis);

GGIAPIFUNC gg_swartype _ggiGetSwarType(void);

/* colormap.c */
GGIAPIFUNC size_t _ggiColormapGetPrivsize(ggi_visual_t vis);
GGIAPIFUNC int _ggiColormapSetRW(ggi_visual_t vis, size_t start, size_t end);
GGIAPIFUNC int _ggiColormapGetRW(ggi_visual_t vis,
				 size_t * start, size_t * end);
GGIAPIFUNC int _ggiColormapSetRO(ggi_visual_t vis, size_t start, size_t end);
GGIAPIFUNC int _ggiColormapGetRO(ggi_visual_t vis,
				 size_t * start, size_t * end);

GGIAPIFUNC int _ggiColormapSetPalette(ggi_visual_t vis, size_t start,
				      size_t size, const ggi_color * cmap);
GGIAPIFUNC ssize_t _ggiColormapFindByColor(ggi_visual_t vis,
					   const ggi_color * color,
					   enum ggi_colormap_region region);
GGIAPIFUNC ssize_t _ggiColormapFindByIdx(ggi_visual_t vis, size_t idx,
					 enum ggi_colormap_region region);
GGIAPIFUNC int _ggiColormapMatchByColor(ggi_visual_t vis,
					const ggi_color * color1,
					const ggi_color * color2,
					enum ggi_colormap_region region);
GGIAPIFUNC int _ggiColormapMatchByIdx(ggi_visual_t vis,
				      size_t idx1, size_t idx2,
				      enum ggi_colormap_region region);

__END_DECLS


/*
******************************************************************************
 Macros for quickly accessing performance critical LibGGI functions.
******************************************************************************
*/

#define LIBGGIMapColor(vis,col)		(vis->opcolor->mapcolor(vis,col))
#define LIBGGIUnmapPixel(vis,pixel,col)	\
	(vis->opcolor->unmappixel(vis,pixel,col))

#define LIBGGIDrawPixel(vis,x,y)	(vis->opdraw->drawpixel(vis,x,y))
#define LIBGGIDrawPixelNC(vis,x,y)	(vis->opdraw->drawpixel_nc(vis,x,y))
#define LIBGGIPutPixel(vis,x,y,col)	(vis->opdraw->putpixel(vis,x,y,col))
#define LIBGGIPutPixelNC(vis,x,y,col)	(vis->opdraw->putpixel_nc(vis,x,y,col))
#define LIBGGIGetPixel(vis,x,y,col)	(vis->opdraw->getpixel(vis,x,y,col))

#define LIBGGIIdleAccel(vis)		(vis->opdisplay->idleaccel(vis))


/*
******************************************************************************
 Macros to access members of LibGGI structures.
 Please use these instead of directly referencing the members.
******************************************************************************
*/

#define LIBGGI_EXT(vis,extid)	((vis)->extlist[(extid)].priv)
#define LIBGGI_EXTAC(vis,extid)	((vis)->extlist[(extid)].attachcount)
#define LIBGGI_EXT_CHECK(vis, extid)	(((vis)->numknownext > (extid)) ? \
						LIBGGI_EXT((vis), (extid)) : NULL)
#define LIBGGI_FLAGS(vis)	((vis)->flags)
#define LIBGGI_FD(vis)		((vis)->fd)

#define LIBGGI_MODE(vis)	((vis)->mode)
#define LIBGGI_PIXFMT(vis)	((vis)->pixfmt)
#define LIBGGI_GC(vis)		((vis)->gc)
#define LIBGGI_GC_FGCOLOR(vis)	(LIBGGI_GC(vis)->fg_color)
#define LIBGGI_GC_BGCOLOR(vis)	(LIBGGI_GC(vis)->bg_color)
#define LIBGGI_APPLIST(vis)	((vis)->app_dbs)

#define LIBGGI_PRIVLIST(vis)	((vis)->priv_dbs)
#define LIBGGI_APPBUFS(vis)	(LIBGGI_APPLIST(vis)->bufs)
#define LIBGGI_PRIVBUFS(vis)	(LIBGGI_PRIVLIST(vis)->bufs)
#define LIBGGI_CURREAD(vis)	((vis)->r_frame->read)
#define LIBGGI_CURWRITE(vis)	((vis)->w_frame->write)

#define LIBGGI_DLHANDLE(vis)	((vis)->dlhandle)
#define LIBGGI_PRIVATE(vis)	((vis)->targetpriv)
#define LIBGGI_DRVPRIV(vis,idx)	((vis)->drvpriv[(idx)])

#define LIBGGI_X(vis)		(LIBGGI_MODE(vis)->visible.x)
#define LIBGGI_Y(vis)		(LIBGGI_MODE(vis)->visible.y)
#define LIBGGI_VIRTX(vis)	(LIBGGI_MODE(vis)->virt.x)
#define LIBGGI_VIRTY(vis)	(LIBGGI_MODE(vis)->virt.y)
#define LIBGGI_GT(vis)		(LIBGGI_MODE(vis)->graphtype)

#define LIBGGI_FB_SIZE(mode)	(GT_ByPPP((mode)->virt.x * (mode)->virt.y, (mode)->graphtype))
#define LIBGGI_FB_R_STRIDE(vis)	((vis)->r_frame->buffer.plb.stride)
#define LIBGGI_FB_W_STRIDE(vis)	((vis)->w_frame->buffer.plb.stride)

#define LIBGGI_R_PLAN(vis)	((vis)->r_frame->buffer.plan)
#define LIBGGI_W_PLAN(vis)	((vis)->w_frame->buffer.plan)

#define LIBGGI_PAL(vis)		((vis)->palette)

#endif	/* _GGI_INTERNAL_H */
