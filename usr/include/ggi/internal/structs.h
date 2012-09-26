/* $Id: structs.h,v 1.18 2005/09/06 15:22:58 pekberg Exp $
******************************************************************************

   LibGGI internal functions and macros

   ??? Add yourself in ???
   Copyright (C) 1998	   Andrew Apted		[andrew@ggi-project.org]
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

#ifndef _GGI_INTERNAL_STRUCTS_H
#define _GGI_INTERNAL_STRUCTS_H

struct ggi_visual;
struct ggi_resource;
typedef struct ggi_visual *ggi_visual_t;
typedef struct ggi_dlhandle *ggi_lib_id;
typedef struct ggi_resource *ggi_resource_t;

#include <ggi/types.h>
#include <ggi/ggi_ext.h>

#include <ggi/internal/dltypes.h>

#include <ggi/gg-queue.h>

#define GGI_VERSION_DLL	1

/* Create a OP version number from the library and structure revisions
 * for (ABI compatability)
 */
#define	GGI_VERSION_MK(st_rev)		((GGI_VERSION_DLL<<16)|st_rev)
#define GGI_LIBRARY_REVISION(vers)	(((uint32_t)vers)>>16)
#define GGI_STRUCTURE_REVISION(vers)	((vers) & 0xFFFF)

/*
******************************************************************************
 Misc internal structures
******************************************************************************
*/

/* Direct Buffer container */
typedef struct {
	int			num;
	ggi_directbuffer	**bufs;
	int			first_targetbuf, last_targetbuf;
} ggi_db_list;

/* GC structure */
#define GGI_GCCHANGED_FG	(1<<0)
#define GGI_GCCHANGED_BG	(1<<1)
#define GGI_GCCHANGED_CLIP	(1<<2)

typedef struct ggi_gc
{
	unsigned int	version;

	ggi_pixel	fg_color;	/* foreground pixel value	*/
	ggi_pixel	bg_color;	/* background pixel value	*/

	ggi_coord	cliptl, clipbr;	/* clipping rectangle		*/
	ggi_pixel	plane_mask;	/* plane mask bits		*/

} ggi_gc;

/* Colormap */
enum ggi_colormap_region {
	GGI_COLORMAP_RW_REGION		= 0,
	GGI_COLORMAP_RO_REGION		= 1,
	GGI_COLORMAP_RW_RO_REGION	= 2
};

typedef struct ggi_colormap {
		ggi_clut clut;		/* color lookup table */

		size_t rw_start;	/* start index of r/w indeces */
		size_t rw_stop;		/* end index of r/w indices */
		size_t ro_start;	/* start index of r/o indices */
		size_t ro_stop;		/* end index of r/o indices */

		void *priv;		/* hook for target specific data */

		/* Function hooks for target specific operations */

		/* Returns the size of the void *priv */
		size_t (*getPrivSize)(ggi_visual_t vis);

		int (*setRW)(ggi_visual_t vis, size_t start, size_t end);
		int (*setRO)(ggi_visual_t vis, size_t start, size_t end);
		int (*getRW)(ggi_visual_t vis, size_t *start, size_t *end);
		int (*getRO)(ggi_visual_t vis, size_t *start, size_t *end);

		/* sets the palette and automatically determine the rw/ro start/end indeces */
		ggifunc_setPalette* setPalette;

		ssize_t (*findByColor)(ggi_visual_t vis, const ggi_color *color,
				       enum ggi_colormap_region region);
		ssize_t (*findByIdx)(ggi_visual_t vis, size_t idx,
				     enum ggi_colormap_region region);
		int (*matchByColor)(ggi_visual_t vis,
				    const ggi_color *color1,
				    const ggi_color *color2,
				    enum ggi_colormap_region region);
		int (*matchByIdx)(ggi_visual_t vis, size_t idx1, size_t idx2,
				  enum ggi_colormap_region region);
} ggi_colormap;

/* Gamma state structure. */
typedef struct ggi_gammastate
{
	ggi_float	gamma_r, gamma_g, gamma_b; /* gamma factors */
	ggi_color	*map;		 /* Explicitly provided map */
	/* Number of writeable/readable entries in map. */
	/* maxwrite_* == -1 means only factors usable.  */
	int		maxwrite_r, maxwrite_g, maxwrite_b;
	int		maxread_r, maxread_g, maxread_b;

	int start;	/* first index in .map */
	int len;	/* number of map fields */
} ggi_gammastate;

/* Resource structure */
struct ggi_resource;
typedef struct ggi_resource {
	ggifunc_resacquire *acquire;
	ggifunc_resrelease *release;
	void    *self;		/* The structure being locked */
	void    *priv;		/* Private data needed for acquire/release: */
	int      count;		/* Usage counter */
	uint32_t curactype;	/* Current access type */
} ggi_resource;


/* Variables needed to support physical units like
 * dpi and mm in a target (optional, stored in target-private area)
 */
#define PHYSZ_DATA		\
	int physzflags;		\
	ggi_coord physz;	\


/*
******************************************************************************
 Structures to manage dynamicly loaded modules
******************************************************************************
*/

typedef struct ggi_dlhandle {
	gg_module *handle;
	char   *name;
	int	usecnt;
	int 	type;
	struct ggi_visual *visual;
	ggifunc_dlentry	*entry;
	ggifunc_open	*open;
	ggifunc_exit	*exit;
	ggifunc_close	*close;
} ggi_dlhandle;

typedef struct ggi_dlhandle_l {
	struct ggi_dlhandle *handle;

	GG_SLIST_ENTRY(ggi_dlhandle_l) dllist;
} ggi_dlhandle_l;

typedef struct ggi_extension {
	char name[32];
	int id;
	int initcount;
	size_t size;
	int (*paramchange)(ggi_visual_t,int whatchanged);
	GG_TAILQ_ENTRY(ggi_extension) extlist;
} ggi_extension;

typedef struct {
	int   attachcount;
	void *priv;
} ggi_extlist;

/*
******************************************************************************
 ggi_visual structure and operations
******************************************************************************
*/

#define _GGI_NROF_HELPERS	20

/*
 * Increment the version number every time you add
 * new features.
 */

#define GGI_VERSION_VISUAL	GGI_VERSION_MK(1)
typedef struct ggi_visual {
	unsigned int       version;
	void		  *mutex;	/* Lock when changing.. */
	GG_SLIST_ENTRY(ggi_visual) vislist;	/* Single visual list */

	ggi_flags	flags;		/* Flags */

        /* used to be gamma. pad for binary compat until next major release. */
        ggi_float	dummy1, dummy2, dummy3;

	/*
	  Integer values [9/15]
	*/
	int		fd;		/* File descriptor for use by target */
	int 		d_frame_num;	/* Current display frame */
	int		r_frame_num;	/* Current read frame */
	int		w_frame_num;	/* Current write frame */
	int		origin_x;	/* Current origin */
	int		origin_y;
	int		numknownext;	/* Number of registered extensions */
	int		needidleaccel;	/* Accelerator must be idled before
					   accessing framebuffer */
	int		accelactive;	/* Accelerator is active */
	int		dummyint[6];	/* For future expansion */

	/*
	  Operation struct pointers [4/10]
	*/
	struct ggi_visual_opdisplay *opdisplay;	/* Display open/mode setting */
	struct ggi_visual_opgc      *opgc;	/* GC operations */
	struct ggi_visual_opcolor   *opcolor;	/* Color & Palette Ops */
	struct ggi_visual_opdraw    *opdraw;	/* Drawing operations */
	void	*opdummy[5];			/* For future expansion */
	GG_SLIST_HEAD(generic_ext,ggi_dlhandle_l) generic_ext; /* extensions for generic libs */

	/*
	  Other pointers [36/36] (Adding stuff to the end of the visual is no
	  			  problem as all dynamic libraries only handles
				  pointers to visuals)
	*/
	ggi_directbuffer *r_frame;	/* Quick access pointers for the */
	ggi_directbuffer *w_frame;	/* linear-* libraries */

	ggi_gc		 *gc;		/* Graphics context */
	ggi_colormap *palette;		/* Current palette */

	ggi_mode	 *mode;		/* Current mode */
	ggi_pixelformat	 *pixfmt;	/* Format of the pixels */
	struct gii_input *input;	/* Input handle for visual */
	void	         *targetpriv;	/* Target private data */

	ggi_db_list 	 *app_dbs;	/* List of public DBs */
	ggi_db_list	 *priv_dbs;	/* List of private DBs */

	GG_SLIST_HEAD(dlhandle,ggi_dlhandle_l) dlhandle; /* Handles to dynamic libs */

	/* Extension stuff */
	GG_SLIST_HEAD(extlib,ggi_dlhandle_l) extlib;   /* Dynamic libs from extensions */
	ggi_extlist	 *extlist;	/* Pointer to array of private data */

	void	*drvpriv[_GGI_NROF_HELPERS];	/* Driver private data */

	void		*helperpriv;    /* Helper library private data */
	ggi_gammastate	*gamma;		/* was genericpriv (obselete) */
	void		*colorpriv;	/* Color library private data */
} ggi_visual;

#define GGI_DL_ERROR		0x80000000
#define GGI_DL_OPDISPLAY	0x00000001
#define GGI_DL_OPCOLOR		0x00000002
#define GGI_DL_OPDRAW		0x00000004
#define GGI_DL_EXTENSION	0x00000008
#define GGI_DL_OPGC		0x00000010
#define GGI_DLTYPE_INTERNAL 	0x01
#define GGI_DLTYPE_EXTENSION	0x02
#define GGI_DLTYPE_GLOBAL	0x04	/* Resolve library's exported symbols */

struct ggi_op_head {
	unsigned int	version;
	GG_SLIST_HEAD(_dlhandle,ggi_dlhandle_l) dlhandle;

	void		*dummy;	/* For future expansion */
};

/* Display and mode setting management
 * Increment the version number every time you change/add a function.
 */
#define GGI_VERSION_VISUAL_OPDISPLAY GGI_VERSION_MK(1)
#define GGI_OPDISPLAY_NUMFUNCS 20
struct ggi_visual_opdisplay {
	struct ggi_op_head head;

/*------- Section: Misc management (5/10 slots) -------------*/
	/* Flush all pending operations */
	ggifunc_flush *flush;
	/* Send a KGI command if possible */
	ggifunc_kgicommand *kgicommand;
	/* Get current list of active APIs */
	ggifunc_getapi *getapi;
	/* Set various flags for visual, e.g. ASYNC mode */
	ggifunc_setflags *setflags;
	/* Idle the accelerator */
	ggifunc_idleaccel *idleaccel;

	void	*dummy_miscman[5];	/* Place holder */

/*------- Section: Mode management (3/5 slots) -------------*/
	/* Get the display mode */
	ggifunc_getmode *getmode;
	/* Check the display mode */
	ggifunc_checkmode *checkmode;
	/* Set the display mode */
	ggifunc_setmode *setmode;

	void	*dummy_mode[2];	/* Place holder */

/*------- Section: Event management (0/5 slots) ------------*/

	ggifunc_sendevent *sendevent;

	void	*dummy_event[4];/* Place holder */

};

/* Color and palette management
 * Increment the version number every time you change/add a function.
 */
#define GGI_VERSION_VISUAL_OPCOLOR GGI_VERSION_MK(1)
#define GGI_OPCOLOR_NUMFUNCS 20
struct ggi_visual_opcolor {
	struct ggi_op_head head;

/*------- Section: Color (6/10 slots) -------------*/
	/* Map a color into a ggi_pixel - used for the drawinfo structure */
	ggifunc_mapcolor *mapcolor;

	/* Map a ggi_pixel into a color */
	ggifunc_unmappixel *unmappixel;

	/* Pack a len size array of ggi_color into buffer - use getbpp! */
	ggifunc_packcolors *packcolors;

	/* Unpack an array of pixels into an array of colors */
	ggifunc_unpackpixels *unpackpixels;

	/* Set palette */
	ggifunc_setpalvec *setpalvec;

	/* Get palette */
	ggifunc_getpalvec *getpalvec;

	void	*dummy_color[4];	/* Place holder */

/*------- Section: Gamma (4/10 slots) -------------*/
	/* Get the gamma value */
	ggifunc_getgamma *getgamma;
	/* Set the gamma value */
	ggifunc_setgamma *setgamma;
	/* Get the gamma map explicitly */
	ggifunc_getgammamap *getgammamap;

	/* Set the gamma map explicitly */
	ggifunc_setgammamap *setgammamap;

	void	*dummy_gamma[6];	/* Place holder */
};


/* Drawing functions
 * Increment the version number every time you change/add a function.
 */
#define GGI_VERSION_VISUAL_OPDRAW	GGI_VERSION_MK(1)
#define GGI_OPDRAW_NUMFUNCS 55
struct ggi_visual_opdraw {
	struct ggi_op_head head;

/*------- Section: Framebuffer (4/10 slots) -------------*/
	ggifunc_setorigin *setorigin;

	ggifunc_setdisplayframe *setdisplayframe;
	ggifunc_setreadframe *setreadframe;
	ggifunc_setwriteframe *setwriteframe;

	void	*dummy_fb[6];		/* Place holders */

/*------- Section: Misc graphics (4/10 slots) -------------*/
	ggifunc_fillscreen *fillscreen;

	ggifunc_putc *putc;
	ggifunc_puts *puts;
	ggifunc_getcharsize *getcharsize;

	void	*dummy_misc[6];		/* Place holders */

/*------- Section: Pixel graphics (5/10 slots) -------------*/
	ggifunc_drawpixel *drawpixel;
	ggifunc_putpixel *putpixel;
	ggifunc_getpixel *getpixel;

	ggifunc_drawpixel_nc *drawpixel_nc;
	ggifunc_putpixel_nc *putpixel_nc;

	void	*dummy_pixel[5];	/* Place holders */

/*------- Section: Simple Line graphics (9/15 slots) -------------*/
	ggifunc_drawline *drawline;

	ggifunc_drawhline *drawhline;
	ggifunc_puthline *puthline;
	ggifunc_gethline *gethline;

	ggifunc_drawvline *drawvline;
	ggifunc_putvline *putvline;
	ggifunc_getvline *getvline;

  	ggifunc_drawhline_nc *drawhline_nc;
	ggifunc_drawvline_nc *drawvline_nc;

	void	*dummy_line[6];		/* Place holders */

/*------- Section: Box blitting (5/10 slots) -------------*/
	ggifunc_drawbox *drawbox;
	ggifunc_putbox *putbox;
	ggifunc_getbox *getbox;
	ggifunc_copybox *copybox;
	ggifunc_crossblit *crossblit;

	void	*dummy_blit[5];		/* Place holders */
};

/* GC operation
 * Increment the version number every time you change/add a function.
 */
#define GGI_VERSION_VISUAL_OPGC	GGI_VERSION_MK(1)
#define GGI_OPGC_NUMFUNCS 5
struct ggi_visual_opgc {
	struct ggi_op_head head;

/*------- Section: Misc (1/5 slots) -------------*/
	/* Report gc changes */
	ggifunc_gcchanged *gcchanged;

	void  *dummy_gc[4];		/* Place holders */
};

/* Don't know if that is a good place ... but making it a file of its own
 * seems like overkill. Andy.
 */

typedef enum {
	GGI_DB_STD_WEIRD=0,

	GGI_DB_STD_1a8lbl=0x01000000,		/* Mono, low bit left */
	GGI_DB_STD_1a8hbl,			/* Mono, high bit left */

	GGI_DB_STD_2a8lpl=0x02000000,		/* 2 bit, low pair left */
	GGI_DB_STD_2a8hpl,			/* 2 bit, high pair left */

	GGI_DB_STD_4a8lnl=0x04000000,		/* 4 bit, low nibble left */
	GGI_DB_STD_4a8hnl,			/* 4 bit, high nibble left */

	GGI_DB_STD_8a8i8=0x08000000,		/* 8 bit indexed */
	GGI_DB_STD_8a8r3g3b2,			/* 8 bit RGB 3/3/2 */

	GGI_DB_STD_15a16p1r5g5b5=0x10000000,	/* 15 bit RGB 5/5/5 native
						   endian */
	GGI_DB_STD_15a16p1r5g5b5rev,		/* 15 bit RGB 5/5/5 reverse
						   endian */
	GGI_DB_STD_15a16p1b5g5r5,		/* 15 bit BGR 5/5/5 native
						   endian */
	GGI_DB_STD_15a16p1b5g5r5rev,		/* 15 bit BGR 5/5/5 reverse
						   endian */

	GGI_DB_STD_16a16r5g6b5=0x11000000,	/* 16 bit RGB 5/6/5 native
						   endian */
	GGI_DB_STD_16a16r5g6b5rev,		/* 16 bit RGB 5/6/5 reverse
						   endian */
	GGI_DB_STD_16a16b5g6r5,			/* 16 bit BGR 5/6/5 native
						   endian */
	GGI_DB_STD_16a16b5g6r5rev,		/* 16 bit BGR 5/6/5 reverse
						   endian */

	GGI_DB_STD_24a24r8g8b8=0x18000000,	/* 24 bit RGB */
	GGI_DB_STD_24a24b8g8r8,			/* 24 bit BGR */

	GGI_DB_STD_24a32p8r8g8b8=0x20000000,	/* 32 bit <PAD>RGB */
	GGI_DB_STD_24a32b8g8r8p8,		/* 32 bit BGR<PAD> */
	GGI_DB_STD_24a32r8g8b8p8,		/* 32 bit RGB<PAD> */
	GGI_DB_STD_24a32p8b8g8r8,		/* 32 bit <PAD>BGR */

	GGI_DB_STD_last	/* Just to have a special entry to avoid the common
			   ,-at-end warning after changes :-) */
} ggi_db_stdformat;

#endif /* _GGI_INTERNAL_STRUCTS_H */
