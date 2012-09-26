/* $Id: ggi.h,v 1.17 2005/07/31 15:30:38 soyt Exp $
******************************************************************************

   LibGGI API header file

   Copyright (C) 1997 Jason McMullan		[jmcc@ggi-project.org]
   Copyright (C) 1997 Steffen Seeger		[seeger@ggi-project.org]
   Copyright (C) 1998 Andrew Apted		[andrew@ggi-project.org]
   Copyright (C) 1998 Andreas Beck		[becka@ggi-project.org]
   Copyright (C) 1998-2000 Marcus Sundberg	[marcus@ggi-project.org]
   Copyright (C) 2001 Brian S. Julin		[bri@tull.umassp.edu]

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

#ifndef _GGI_GGI_H
#define _GGI_GGI_H

#include <ggi/types.h>
#include <ggi/gii.h>
#include <ggi/ggi-defs.h>

#include <stdio.h>     /* need FILE for ggiFPrintMode */

/* Do we need double here? */
typedef double ggi_float;

#ifndef _INTERNAL_LIBGGI
/* Opaque pointer types.
   This little magic gains us some type checking.
   ANSI warning: If you have a really really weird machine (one that has
   different pointer sizes or types for different pointed-to objects),
   you might need to typedef void *ggi_*_t; instead.
 */
struct ggi_h_dummy1 { char dummy1; };
struct ggi_h_dummy2 { char dummy2; };
typedef struct ggi_h_dummy1 *ggi_visual_t;
typedef struct ggi_h_dummy2 *ggi_resource_t;
#endif

/*
 * Convenience typedefs for compatibility with pre-GII applications.
 */

typedef gii_event_type		ggi_event_type;
typedef gii_event_mask		ggi_event_mask;
typedef gii_any_event		ggi_any_event;
typedef gii_cmd_nodata_event	ggi_cmd_nodata_event;
typedef gii_cmd_event		ggi_cmd_event;
typedef gii_expose_event	ggi_expose_event;
typedef gii_key_event		ggi_key_event;
typedef gii_pmove_event		ggi_pmove_event;
typedef gii_pbutton_event	ggi_pbutton_event;
typedef gii_val_event		ggi_val_event;
typedef gii_event		ggi_event;


/*
 * Flags & Frames
 */

typedef unsigned int ggi_flags;

/* SYNC/ASYNC mode. Draw instantly or when thw HW likes to. Default is sync */
#define GGIFLAG_ASYNC	0x0001U
/* TIDYBUF mode (default off) is for applications which use directbuffer and
 * manage there own dirty regions.  See ggiSetFlags manpage.
 */
#define GGIFLAG_TIDYBUF	0x0002U


/*
******************************************************************************
 Misc macros
******************************************************************************
*/

/* Swap the bytes in a 16 respective 32 bit unsigned number */
#define GGI_BYTEREV16(x) ((x)<<8 | (x)>>8)
#define GGI_BYTEREV32(x)  \
	((x)<<24 | ((x)&0xff00)<<8 | ((x)&0xff0000)>>8 | (x)>>24)

/* Swap the bitgroups in an 8 bit unsigned number */
#define GGI_BITREV4(x) (((x)>>4) | ((x)<<4))
#define GGI_BITREV2(x)  \
	((x)>>6 | ((x)&0x30)>>2 | ((x)&0x0c)<<2 | (x)<<6)
#define GGI_BITREV1(x)  \
	((x)>>7 | ((x)&0x40)>>5 | ((x)&0x20)>>3 | ((x)&0x10)>>1 |  \
	 ((x)&0x08)<<1 | ((x)&0x04)<<3 | ((x)&0x02)<<5 | (x)<<7)


/*
******************************************************************************
 Information that can be returned to user apps
******************************************************************************
*/

/* Bitmeaning defines */

#define GGI_BM_TYPE_NONE	0x000000	/* This bit is not in use */

/*
  Bit influences color of displayed pixel
*/
#define GGI_BM_TYPE_COLOR	0x010000

#define		GGI_BM_SUB_RED		0x0100
#define		GGI_BM_SUB_GREEN	0x0200
#define		GGI_BM_SUB_BLUE		0x0300

#define		GGI_BM_SUB_CYAN		0x1000
#define		GGI_BM_SUB_MAGENTA	0x1100
#define		GGI_BM_SUB_YELLOW	0x1200
#define		GGI_BM_SUB_K		0x1300

#define		GGI_BM_SUB_Y		0x2000
#define		GGI_BM_SUB_U		0x2100
#define		GGI_BM_SUB_V		0x2200
#define		GGI_BM_SUB_Y0		0x2000
#define		GGI_BM_SUB_Y1		0x2300
#define		GGI_BM_SUB_Y2		0x2400
#define		GGI_BM_SUB_Y3		0x2500
#define		GGI_BM_SUB_Y4		0x2600
#define		GGI_BM_SUB_Y5		0x2700
#define		GGI_BM_SUB_Y6		0x2800
#define		GGI_BM_SUB_Y7		0x2900
#define		GGI_BM_SUB_U0		0x2100
#define		GGI_BM_SUB_U1		0x2a00
#define		GGI_BM_SUB_U2		0x2b00
#define		GGI_BM_SUB_U3		0x2c00
#define		GGI_BM_SUB_V0		0x2200
#define		GGI_BM_SUB_V1		0x2d00
#define		GGI_BM_SUB_V2		0x2e00
#define		GGI_BM_SUB_V3		0x2f00

#define		GGI_BM_SUB_CLUT		0xf000	/* This bit Color or attrib ? */

/*
  Bit changes appearance of pixel/glyph
*/
#define GGI_BM_TYPE_ATTRIB	0x020000

#define		GGI_BM_SUB_ALPHA		0x0100

#define		GGI_BM_SUB_BLINK		0x1000
#define		GGI_BM_SUB_INTENSITY		0x1100
#define		GGI_BM_SUB_UNDERLINE		0x1200
#define		GGI_BM_SUB_BOLD			0x1300
#define		GGI_BM_SUB_ITALIC		0x1400

#define		GGI_BM_SUB_FGCOL		0x2000
#define		GGI_BM_SUB_BGCOL		0x2100

#define		GGI_BM_SUB_TEXNUM		0x3000
#define		GGI_BM_SUB_FONTSEL		0x3100  /* select font banks*/
#define		GGI_BM_SUB_PALSEL		0x3200	/* select palettes */
#define		GGI_BM_SUB_MODESEL		0x3300	/* select palettes */

/*
  Bit that influence drawing logic
*/
#define GGI_BM_TYPE_LOGIC	0x030000

#define		GGI_BM_SUB_ZBUFFER		0x0100
#define		GGI_BM_SUB_WRITEPROT		0x1000
#define		GGI_BM_SUB_WINDOWID		0x2000
#define		GGI_BM_SUB_DELTA		0x3000 /* stencil for video */

/* Pixelformat for ggiGet/Put* buffers and pixellinearbuffers */
typedef struct {
	int		depth;		/* Number of significant bits */
	int		size;		/* Physical size in bits */

	/*
	 * Simple and common things first :
	 *
	 * Usage of the mask/shift pairs:
	 * If new_value is the _sizeof(ggi_pixel)*8bit_ value of the thing
	 * you want to set, you do
	 *
	 * *pointer &= ~???_mask;		// Mask out old bits
	 * *pointer |= (new_value>>shift) & ???_mask;
	 *
	 * The reason to use 32 bit and "downshifting" is alignment
	 * and extensibility. You can easily adjust to other datasizes
	 * with a simple addition ...
	 */

	/* Simple colors:
	 */
	ggi_pixel	red_mask;	/* Bitmask of red bits */
	int		red_shift;	/* Shift  for red bits */

	ggi_pixel	green_mask;	/* Bitmask of green bits */
	int		green_shift;	/* Shift  for green bits */

	ggi_pixel	blue_mask;	/* Bitmask of blue bits */
	int		blue_shift;	/* Shift  for blue bits */

	/* A few common attributes :
	 */
	ggi_pixel	alpha_mask;	/* Bitmask of alphachannel bits */
	int		alpha_shift;	/* Shift  for alpha bits */

	ggi_pixel	clut_mask;	/* Bitmask of bits for the clut */
	int		clut_shift;	/* Shift  for bits for the clut*/

	ggi_pixel	fg_mask;	/* Bitmask of foreground color */
	int		fg_shift;	/* Shift  for foreground color */

	ggi_pixel	bg_mask;	/* Bitmask of background color */
	int		bg_shift;	/* Shift  for background color */

	ggi_pixel	texture_mask;	/* Bitmask of the texture (for
					   textmodes - the actual character) */
	int		texture_shift;	/* Shift  for texture */

	/*
	 * Now if this doesn't suffice you might want to parse the following
	 * to find out what each bit does:
	 */

	uint32_t	bitmeaning[sizeof(ggi_pixel)*8];

	uint32_t	flags;		/* Pixelformat flags */

	uint32_t	stdformat;	/* Standard format identifier */
	/* This one has only one use for the usermode application:
	 * To quickly check, if two buffers are identical. If both
	 * stdformats are the same and _NOT_ 0 (which means "WEIRD"),
	 * you may use things like memcpy between them which will have
	 * the desired effect ...
	 */

} ggi_pixelformat;

/* Pixelformat flags */
#define GGI_PF_REVERSE_ENDIAN	0x01
#define GGI_PF_HIGHBIT_RIGHT	0x02
#define GGI_PF_HAM		0x04
#define GGI_PF_EXTENDED		0x08

/*
******************************************************************************
 DirectBuffer
******************************************************************************
*/

typedef enum {
	blPixelLinearBuffer,
	blPixelPlanarBuffer,
	blExtended,
	blSampleLinearBuffer,
	blSamplePlanarBuffer,

	blLastBufferLayout
} ggi_bufferlayout;

typedef struct {
	int		stride;		/* bytes per row		*/
	ggi_pixelformat *pixelformat;	/* format of the pixels		*/
} ggi_pixellinearbuffer;

typedef struct {
	int		next_line;	/* bytes until next line	*/
	int		next_plane;	/* bytes until next plane	*/
	ggi_pixelformat *pixelformat;	/* format of the pixels		*/
} ggi_pixelplanarbuffer;

typedef struct {
	int		num_pixels;	/* how many pixelformats	*/
	int		stride;		/* bytes per row		*/
	ggi_pixelformat *pixelformat[4];/* format of the pixels		*/
} ggi_samplelinearbuffer;

typedef struct {
	int		next_line[3];	/* bytes until next line	*/
	int		next_plane[3];	/* bytes until next plane	*/
	ggi_pixelformat *pixelformat[4];/* format of the pixels		*/
} ggi_sampleplanarbuffer;

/* Buffer types */
#define GGI_DB_NORMAL		0x0001  /* "frame" is valid when set */
#define GGI_DB_EXTENDED		0x0002
#define GGI_DB_MULTI_LEFT	0x0004
#define GGI_DB_MULTI_RIGHT	0x0008

/* Flags that may be or'ed with the buffer type */
#define GGI_DB_SIMPLE_PLB	0x01000000
/* GGI_DB_SIMPLE_PLB means that the buffer has the following properties:
      type == GGI_DB_NORMAL
      read == write
      noaccess == 0
      align == 0
      layout == blPixelLinearBuffer
*/

typedef struct {
	uint32_t	type;		/* buffer type */
	int		frame;		/* framenumber (GGI_DB_NORMAL) */

	/*	access info	*/
	ggi_resource_t	resource;	/* If non-NULL you must acquire the
					   buffer before using it */
	void		*read;		/* buffer address for reads	*/
	void		*write;		/* buffer address for writes	*/
	unsigned int	page_size;	/* zero for true linear buffers	*/

	uint32_t	noaccess;
	/* bitfield. bit x set means you may _not_ access this DB at the
	   width of 2^x bytes. Usually 0, but _check_ it. */

	uint32_t	align;
	/* bitfield. bit x set means you may only access this DB at the
	   width of 2^x bytes, when the access is aligned to a multiple
	   of 2^x. Note that bit 0 is a bit bogus here, but it should
	   be always 0, as then ((noaccess|align)==0) is a quick check
	   for "no restrictions". */

	ggi_bufferlayout	layout;

	/* The actual buffer info. Depends on layout. */
	union {
		ggi_pixellinearbuffer plb;
		ggi_pixelplanarbuffer plan;
		ggi_samplelinearbuffer slb;
		ggi_sampleplanarbuffer splan;
		void *extended;
	} buffer;
} ggi_directbuffer;


/*
******************************************************************************
 Resource management
******************************************************************************
*/

/* Access types */
#define GGI_ACTYPE_READ		(1U<<0U)
#define GGI_ACTYPE_WRITE	(1U<<1U)


/*
******************************************************************************
 LibGGI function definitions
******************************************************************************
*/
__BEGIN_DECLS

/* Get the master config dir
 */
GGIAPIFUNC const char *ggiGetConfDir(void);

/* Enter and leave the library
 */
GGIAPIFUNC int  ggiInit(void);
GGIAPIFUNC int  ggiExit(void);
GGIAPIFUNC void ggiPanic(const char *format,...);

/* Open a new visual - use display `NULL' for the default visual
 */
GGIAPIFUNC ggi_visual_t ggiOpen(const char *display,...);
GGIAPIFUNC int          ggiClose(ggi_visual_t vis);

/* Get/Set info
 */
GGIAPIFUNC int        ggiSetFlags(ggi_visual_t vis,ggi_flags flags);
GGIAPIFUNC ggi_flags  ggiGetFlags(ggi_visual_t vis);
#define ggiAddFlags(vis,flags)  \
		ggiSetFlags((vis), ggiGetFlags((vis)) | (flags))
#define ggiRemoveFlags(vis,flags)  \
		ggiSetFlags((vis), ggiGetFlags((vis)) & ~(flags))
GGIAPIFUNC const ggi_pixelformat *ggiGetPixelFormat(ggi_visual_t vis);

/* DB functions
 */
GGIAPIFUNC int  ggiDBGetNumBuffers(ggi_visual_t vis);
GGIAPIFUNC const ggi_directbuffer *ggiDBGetBuffer(ggi_visual_t vis,
						  int bufnum);

/* Resource functions
 */
#define ggiResourceAcquire(res, actype) \
	(((res) == NULL) ? 0 : ggiResourceFastAcquire((res), (actype)))
#define ggiResourceRelease(res) \
	(((res) == NULL) ? 0 : ggiResourceFastRelease((res)))
#define ggiResourceMustAcquire(res)	((res) != NULL)
GGIAPIFUNC int ggiResourceFastAcquire(ggi_resource_t res, uint32_t actype);
GGIAPIFUNC int ggiResourceFastRelease(ggi_resource_t res);

/* Library management
 */
#define GGI_MAX_APILEN	1024
GGIAPIFUNC int ggiGetAPI(ggi_visual_t vis, int num,
			 char *apiname, char *arguments);
#define GGI_CHG_APILIST 0x00000001
#define GGI_CHG_ACCELSYNC 0x00000002
GGIAPIFUNC int ggiIndicateChange(ggi_visual_t vis, int whatchanged);

/* Mode management
 */
GGIAPIFUNC int ggiSetMode(ggi_visual_t visual,ggi_mode *tm);
GGIAPIFUNC int ggiGetMode(ggi_visual_t visual,ggi_mode *tm);
GGIAPIFUNC int ggiCheckMode(ggi_visual_t visual,ggi_mode *tm);

GGIAPIFUNC int ggiSetTextMode(ggi_visual_t visual,int cols,int rows,
			      int vcols,int vrows,int fontx,int fonty,
			      ggi_graphtype type);
GGIAPIFUNC int ggiCheckTextMode(ggi_visual_t visual,int cols,int rows,
			        int vcols,int vrows, int fontx,int fonty,
			        ggi_graphtype type, ggi_mode *suggested_mode);

GGIAPIFUNC int ggiSetGraphMode(ggi_visual_t visual, int x, int y,
			       int xv,int yv,ggi_graphtype type);
GGIAPIFUNC int ggiCheckGraphMode(ggi_visual_t visual, int x, int y,
			         int xv, int yv, ggi_graphtype type,
			         ggi_mode *suggested_mode);

GGIAPIFUNC int ggiSetSimpleMode(ggi_visual_t visual, int xsize, int ysize,
				int frames, ggi_graphtype type);
GGIAPIFUNC int ggiCheckSimpleMode(ggi_visual_t visual, int xsize, int ysize,
				  int frames, ggi_graphtype type,
				  ggi_mode *md);

/* Print all members of the mode struct
 */
GGIAPIFUNC int ggiSPrintMode(char *s, const ggi_mode *m);
GGIAPIFUNC int ggiFPrintMode(FILE *s, const ggi_mode *m);
#define ggiPrintMode(m) ggiFPrintMode(stdout,(m))

/* Fill a mode struct from the text string s
 */
GGIAPIFUNC int ggiParseMode(const char *s, ggi_mode *m);


/* Flush all pending operations to the display device
 */

/* Normal flush */
GGIAPIFUNC int ggiFlush(ggi_visual_t vis);
/* Flush only the specified region if it would improve performance */
GGIAPIFUNC int ggiFlushRegion(ggi_visual_t vis, int x, int y, int w, int h);

/* Graphics context
 */
GGIAPIFUNC int ggiSetGCForeground(ggi_visual_t vis,ggi_pixel  color);
GGIAPIFUNC int ggiGetGCForeground(ggi_visual_t vis,ggi_pixel *color);
GGIAPIFUNC int ggiSetGCBackground(ggi_visual_t vis,ggi_pixel  color);
GGIAPIFUNC int ggiGetGCBackground(ggi_visual_t vis,ggi_pixel *color);
GGIAPIFUNC int ggiSetGCClipping(ggi_visual_t vis,int  left,int  top,
				int  right,int  bottom);
GGIAPIFUNC int ggiGetGCClipping(ggi_visual_t vis,int *left,int *top,
				int *right,int *bottom);

/* Color palette manipulation
 */
GGIAPIFUNC ggi_pixel ggiMapColor(ggi_visual_t vis,const ggi_color *col);
GGIAPIFUNC int ggiUnmapPixel(ggi_visual_t vis,ggi_pixel pixel,ggi_color *col);

GGIAPIFUNC int ggiPackColors(ggi_visual_t vis,void *buf,const ggi_color *cols,
			     int len);
GGIAPIFUNC int ggiUnpackPixels(ggi_visual_t vis,const void *buf,ggi_color *cols,
			       int len);

GGIAPIFUNC int ggiGetPalette(ggi_visual_t vis,int s,int len,ggi_color *cmap);
GGIAPIFUNC int ggiSetPalette(ggi_visual_t vis,int s,int len,const ggi_color *cmap);
GGIAPIFUNC int ggiSetColorfulPalette(ggi_visual_t vis);

#define GGI_PALETTE_DONTCARE  -1

/* Gamma map manipulation
 */
GGIAPIFUNC int ggiGetGamma(ggi_visual_t vis,
			   ggi_float *r,ggi_float *g,ggi_float *b);
GGIAPIFUNC int ggiSetGamma(ggi_visual_t vis,
			   ggi_float  r,ggi_float  g,ggi_float  b);

GGIAPIFUNC int ggiGetGammaMap(ggi_visual_t vis,int s,int len,
			      ggi_color *gammamap);
GGIAPIFUNC int ggiSetGammaMap(ggi_visual_t vis,int s,int len,
			      const ggi_color *gammamap);

GGIAPIFUNC int ggiGammaMax(ggi_visual_t vis, uint32_t bitmeaning,
			   int *max_r, int *max_w);

/* Origin handling
 */
GGIAPIFUNC int ggiSetOrigin(ggi_visual_t vis,int x,int y);
GGIAPIFUNC int ggiGetOrigin(ggi_visual_t vis,int *x,int *y);

/* Frame handling
 */
GGIAPIFUNC int ggiSetDisplayFrame(ggi_visual_t vis, int frameno);
GGIAPIFUNC int ggiSetReadFrame(ggi_visual_t vis, int frameno);
GGIAPIFUNC int ggiSetWriteFrame(ggi_visual_t vis, int frameno);

GGIAPIFUNC int ggiGetDisplayFrame(ggi_visual_t vis);
GGIAPIFUNC int ggiGetReadFrame(ggi_visual_t vis);
GGIAPIFUNC int ggiGetWriteFrame(ggi_visual_t vis);

/* Generic drawing routines
 */
GGIAPIFUNC int ggiFillscreen(ggi_visual_t vis);

GGIAPIFUNC int ggiDrawPixel(ggi_visual_t vis,int x,int y);
GGIAPIFUNC int ggiPutPixel(ggi_visual_t vis,int x,int y,ggi_pixel pixel);
GGIAPIFUNC int ggiGetPixel(ggi_visual_t vis,int x,int y,ggi_pixel *pixel);

GGIAPIFUNC int ggiDrawLine(ggi_visual_t vis,int x,int y,int xe,int ye);
GGIAPIFUNC int ggiDrawHLine(ggi_visual_t vis,int x,int y,int w);
GGIAPIFUNC int ggiPutHLine(ggi_visual_t vis,int x,int y,int w,const void *buf);
GGIAPIFUNC int ggiGetHLine(ggi_visual_t vis,int x,int y,int w,void *buf);

GGIAPIFUNC int ggiDrawVLine(ggi_visual_t vis,int x,int y,int h);
GGIAPIFUNC int ggiPutVLine(ggi_visual_t vis,int x,int y,int h,const void *buf);
GGIAPIFUNC int ggiGetVLine(ggi_visual_t vis,int x,int y,int h,void *buf);

GGIAPIFUNC int ggiDrawBox(ggi_visual_t vis,int x,int y,int w,int h);
GGIAPIFUNC int ggiPutBox(ggi_visual_t vis,int x,int y,int w,int h,const void *buf);
GGIAPIFUNC int ggiGetBox(ggi_visual_t vis,int x,int y,int w,int h,void *buf);
GGIAPIFUNC int ggiCopyBox(ggi_visual_t vis,int x,int y,int w,int h,
			  int nx,int ny);
GGIAPIFUNC int ggiCrossBlit(ggi_visual_t src,int sx,int sy,int w,int h,
			    ggi_visual_t dst,int dx,int dy);

/* Text drawing routines
*/
GGIAPIFUNC int ggiPutc(ggi_visual_t vis,int x,int y,char c);
GGIAPIFUNC int ggiPuts(ggi_visual_t vis,int x,int y,const char *str);
GGIAPIFUNC int ggiGetCharSize(ggi_visual_t vis,int *width,int *height);

/* Event handling
 */
GGIAPIFUNC gii_event_mask	ggiEventPoll(ggi_visual_t vis,
					     gii_event_mask mask,
					     struct timeval *t);
GGIAPIFUNC int			ggiEventsQueued(ggi_visual_t vis,
						gii_event_mask mask);
GGIAPIFUNC int			ggiEventRead(ggi_visual_t vis, gii_event *ev,
					     gii_event_mask mask);
GGIAPIFUNC int			ggiSetEventMask(ggi_visual_t vis,
						gii_event_mask evm);
GGIAPIFUNC gii_event_mask	ggiGetEventMask(ggi_visual_t vis);
GGIAPIFUNC int			ggiEventSend(ggi_visual_t vis, gii_event *ev);
#define				ggiGetInput(vis)   ggiJoinInputs(vis, NULL)
GGIAPIFUNC gii_input_t		ggiJoinInputs(ggi_visual_t vis,
					      gii_input_t inp);
GGIAPIFUNC gii_input_t		ggiDetachInput(ggi_visual_t vis);

#define ggiAddEventMask(vis,mask)  \
		ggiSetEventMask((vis), ggiGetEventMask((vis)) | (mask))
#define ggiRemoveEventMask(vis,mask)  \
		ggiSetEventMask((vis), ggiGetEventMask((vis)) & ~(mask))

/* Convenience functions */

GGIAPIFUNC int ggiKbhit(ggi_visual_t vis);
GGIAPIFUNC int ggiGetc(ggi_visual_t vis);

__END_DECLS

#endif /* _GGI_GGI_H */
