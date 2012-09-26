/* $Id: types.h,v 1.12 2005/08/12 18:48:23 cegger Exp $
******************************************************************************

   LibGGI general definitions, data structures, etc.

   Copyright (C) 1995-1996	Andreas Beck	[becka@ggi-project.org]
   Copyright (C) 1995-1996	Steffen Seeger	[seeger@ggi-project.org]
   Copyright (C) 1998		Marcus Sundberg	[marcus@ggi-project.org]
   Copyright (C) 2001		Brian S. Julin  [bri@tull.umassp.edu]

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

#ifndef	_GGI_TYPES_H
#define	_GGI_TYPES_H

#include <ggi/system.h>

/*
******************************************************************************
 LibGGI datatypes and structures
******************************************************************************
*/

#define        GGI_AUTO     (0)

typedef struct { int16_t x, y; }				ggi_coord;
typedef struct { long	 x, y; }				ggi_subcoord;
typedef	uint32_t						ggi_pixel;

typedef	uint32_t						ggi_attr;
#define	ATTR_FGCOLOR	0x0000FF00	/* fgcolor clut index	*/
#define	ATTR_BGCOLOR	0x000000FF	/* bgcolor clut index	*/
#define	ATTR_NORMAL	0x00000000	/* normal style		*/
#define	ATTR_HALF	0x00010000	/* half intensity	*/
#define	ATTR_BRIGHT	0x00020000	/* high intensity	*/
#define	ATTR_INTENSITY	0x00030000	/* mask to get intensity*/
#define	ATTR_UNDERLINE	0x00040000	/* underline attribute	*/
#define	ATTR_BOLD	0x00080000	/* bold style		*/
#define	ATTR_ITALIC	0x00100000	/* italic style		*/
#define	ATTR_REVERSE	0x00200000	/* reverse fg/bg	*/
#define	ATTR_BLINK	0x00800000	/* enable blinking	*/
#define	ATTR_FONT	0xFF000000	/* font table		*/
#define	ATTR_COLOR(fg, bg)	((bg & 0xFF) | ((fg & 0xFF) << 8))

typedef struct { uint16_t r,g,b,a; }				ggi_color;
typedef struct { uint16_t size; ggi_color *data; }		ggi_clut;

#define	GGI_COLOR_PRECISION 16	/* 16 bit per R,G, B value	*/

/*
 * Graphtypes
 */
typedef uint32_t ggi_graphtype;

#define GT_DEPTH_SHIFT		(0)
#define GT_SIZE_SHIFT		(8)
#define GT_SUBSCHEME_SHIFT	(16)
#define GT_SCHEME_SHIFT		(24)

#define GT_DEPTH_MASK		(0xffU << GT_DEPTH_SHIFT)
#define GT_SIZE_MASK		(0xffU << GT_SIZE_SHIFT)
#define GT_SUBSCHEME_MASK	(0xffU << GT_SUBSCHEME_SHIFT)
#define GT_SCHEME_MASK		(0xffU << GT_SCHEME_SHIFT)

/* Macros to extract info from a ggi_graphtype. */
#define GT_DEPTH(x)		(((x) & GT_DEPTH_MASK) >> GT_DEPTH_SHIFT)
#define GT_SIZE(x)		(((x) & GT_SIZE_MASK) >> GT_SIZE_SHIFT)
#define GT_ByPP(x)		((GT_SIZE(x) + 7) / 8)
#define GT_ByPPP(w,x)		(((w) * (GT_SIZE(x)) + 7) / 8)
#define GT_SUBSCHEME(x)		((x) & GT_SUBSCHEME_MASK)
#define GT_SCHEME(x)		((x) & GT_SCHEME_MASK)

/* Macros to set info in a ggi_graphtype. */
#define GT_SETDEPTH(gt,x) \
    do { (gt) = ((gt) & ~GT_DEPTH_MASK) | ((x)<<GT_DEPTH_SHIFT); } while (0)
#define GT_SETSIZE(gt,x) \
    do { (gt) = ((gt) & ~GT_SIZE_MASK) | ((x)<<GT_SIZE_SHIFT); } while (0)
#define GT_SETSUBSCHEME(gt,x) \
    do { (gt) = ((gt) & ~GT_SUBSCHEME_MASK) | (x); } while (0)
#define GT_SETSCHEME(gt,x) \
    do { (gt) = ((gt) & ~GT_SCHEME_MASK) | (x); } while (0)

/* Enumerated schemes */
#define GT_TEXT			((0x01) << GT_SCHEME_SHIFT)
#define GT_TRUECOLOR		((0x02) << GT_SCHEME_SHIFT)
#define GT_GREYSCALE		((0x03) << GT_SCHEME_SHIFT)
#define GT_PALETTE		((0x04) << GT_SCHEME_SHIFT)
#define GT_STATIC_PALETTE	((0x05) << GT_SCHEME_SHIFT)
#define GT_SUBSAMPLE_YUV	((0x06) << GT_SCHEME_SHIFT)
#define GT_SUBSAMPLE_U_YCRBR	((0x07) << GT_SCHEME_SHIFT)
#define GT_SUBSAMPLE_S_YCRBR	((0x08) << GT_SCHEME_SHIFT)
#define GT_NIL			((0xff) << GT_SCHEME_SHIFT)

/* Subschemes */
#define GT_SUB_REVERSE_ENDIAN   ((0x01) << GT_SUBSCHEME_SHIFT)
#define GT_SUB_HIGHBIT_RIGHT    ((0x02) << GT_SUBSCHEME_SHIFT)
#define GT_SUB_PACKED_GETPUT    ((0x04) << GT_SUBSCHEME_SHIFT)

/* Macro that constructs a graphtype */
#define GT_CONSTRUCT(depth,scheme,size) \
	((depth) | (scheme) | ((size) << GT_SIZE_SHIFT))

/* Common graphtypes */
#define GT_TEXT16	GT_CONSTRUCT(4, GT_TEXT, 16)
#define GT_TEXT32	GT_CONSTRUCT(8, GT_TEXT, 32)
#define GT_1BIT		GT_CONSTRUCT(1, GT_PALETTE, 1)
#define GT_2BIT		GT_CONSTRUCT(2, GT_PALETTE, 2)
#define GT_4BIT		GT_CONSTRUCT(4, GT_PALETTE, 4)
#define GT_8BIT		GT_CONSTRUCT(8, GT_PALETTE, 8)
#define GT_15BIT	GT_CONSTRUCT(15, GT_TRUECOLOR, 16)
#define GT_16BIT	GT_CONSTRUCT(16, GT_TRUECOLOR, 16)
#define GT_24BIT	GT_CONSTRUCT(24, GT_TRUECOLOR, 24)
#define GT_32BIT	GT_CONSTRUCT(24, GT_TRUECOLOR, 32)
#define GT_AUTO		(0)
#define GT_INVALID	(0xffffffff)

/*
 * ggi_mode structure
 */
typedef struct		/* requested by user and changed by driver    */
{
	int32_t		frames;		/* frames needed		    */
	ggi_coord	visible;	/* vis. pixels, may change slightly */
	ggi_coord	virt;		/* virtual pixels, may change	    */
	ggi_coord	size;		/* size of visible in mm	    */
	ggi_graphtype	graphtype;	/* which mode ?			    */
	ggi_coord	dpp;		/* dots per pixel		    */
} ggi_mode;


/*
******************************************************************************
 LibGGI batchop interface
******************************************************************************
*/

/* OPcodes */
#define GGI_OP_GET		0x10000000 /* Flag, gets data from target */
#define GGI_OP_OWNER_MASK       0x0fff0000 /* What extension owns this */
#define GGI_OP_OWNER_GGI        0x00000000 /* GGI primitives */
#define GGI_OP_OWNER_USER       0x0fff0000 /* Will never be allocated */

/* The rest of the extensions will define their owner codes and opcodes
 * in their own headers.  A registry is kept here, but in comment form
 * so as to reduce revision requirements between LibGGI and extensions.
 =======================================================================
 OPCODE REGISTRY:

 GGI_OP_OWNER_BUF       0x00010000      Owned/defined by LibBuf
 GGI_OP_OWNER_MISC      0x00020000      Owned/defined by LibGGIMisc
 GGI_OP_OWNER_OVL       0x00030000      Owned/defined by LibOvl
 GGI_OP_OWNER_BLT       0x00040000      Owned/defined by LibBlt
 =======================================================================
*/

/* Opcodes for GGI's operations */

#define GGI_OP_DRAWPIXEL	0x00000001	/* drawops.drawpixel */
#define GGI_OP_PUTPIXEL		0x00000002	/* drawops.putpixel  */
#define GGI_OP_DRAWHLINE	0x00000003	/* drawops.drawhline */
#define GGI_OP_PUTHLINE		0x00000004	/* drawops.puthline  */
#define GGI_OP_DRAWVLINE	0x00000005	/* drawops.drawvline */
#define GGI_OP_PUTVLINE		0x00000006	/* drawops.putvline  */
#define GGI_OP_DRAWBOX		0x00000007	/* drawops.drawbox   */
#define GGI_OP_PUTBOX		0x00000008	/* drawops.putbox    */
#define GGI_OP_DRAWLINE		0x00000009	/* drawops.drawline  */
#define GGI_OP_COPYBOX		0x0000000a	/* drawops.copybox   */
#define GGI_OP_CROSSBLIT	0x0000000b	/* drawops.copybox   */

/* Since GGI's API is entirely stable, we guarantee we will never use these
 * bits, which makes it easier for extensions providing altered analogs to
 * GGI drawing primitives to map between their altered primitives and ours.
 */
#define GGI_OP_NEVERUSED        0x0000f000

/* PT == parmtype.  Operations need parameters.  Here we define parmtypes,
 * such that mmutils can match up source and destination batchops.
 */

/* What IS the batchparm representing? */
#define GGI_PT_IS_MASK		0xffff0000
#define GGI_PT_IS_CHANMASK	0x003f0000
#define GGI_PT_IS_TYPEMASK	0x0f000000
#define GGI_PT_IS_MISCMASK	0xe0000000
#define GGI_PT_IS_COORD		0x00000000 /* A coordinate		     */
#define GGI_PT_IS_COLOR1	0x00010000 /* A color channel (R, Y, C)	     */
#define GGI_PT_IS_COLOR2	0x00020000 /* A color channel (B, U, Cr, M)  */
#define GGI_PT_IS_COLOR3	0x00040000 /* A color channel (G, V, Cg, Y)  */
#define GGI_PT_IS_COLOR4	0x00080000 /* A color channel (K)	     */
#define GGI_PT_IS_ALPHA		0x00100000 /* A translucency  (A)	     */
#define GGI_PT_IS_DEPTH		0x00200000 /* A depth	      (Z, Bump)	     */
#define GGI_PT_IS_PAT		0x01000000 /* A pattern for tesselation fills*/
#define GGI_PT_IS_CLIP		0x02000000 /* A clipping region		     */
#define GGI_PT_IS_ERR		0x03000000 /* An error term		     */
#define GGI_PT_IS_FGCOL		0x04000000 /* A foreground color	     */
#define GGI_PT_IS_BGCOL		0x05000000
#define GGI_PT_IS_BOP		0x06000000 /* A boolean ROP		     */
#define GGI_PT_IS_KEYCOL	0x07000000 /* A color key		     */
#define GGI_PT_IS_KEYMASK	0x08000000 /* A color key mask		     */
#define GGI_PT_IS_PLANEMASK	0x09000000 /* A plane mask		     */
#define GGI_PT_IS_OPCODE	0x0a000000 /* An opcode or command	     */
#define GGI_PT_IS_SRC		0x10000000 /* Pertains to source, not dest   */
#define GGI_PT_IS_INDEXED	0x20000000 /* Uses a LUT		     */
#define GGI_PT_IS_MODE		0x60000000 /* An operational mode (pixel size,
					    * pixel format, blend, etc.)     */
#define GGI_PT_IS_SPECIAL	0xe0000000 /* Extension/target/chipset priv  */

/* IN what axis/dimensions/units the value is given/wanted */
#define GGI_PT_IN_MASK		0x0000ff00
#define GGI_PT_IN_AXISMASK	0x00000f00
#define GGI_PT_IN_UNITMASK	0x0000f000
#define GGI_PT_IN_QTY		0x00000000 /* A generic quantity	     */
#define GGI_PT_IN_X		0x00000100 /* X Axis			     */
#define GGI_PT_IN_Y		0x00000200 /* Y Axis			     */
#define GGI_PT_IN_ADDR		0x00000300 /* Linearized fb address	     */
#define GGI_PT_IN_MAJOR		0x00000400 /* Major Axis		     */
#define GGI_PT_IN_MINOR		0x00000500 /* Minor Axis		     */
#define GGI_PT_IN_PIXEL		0x00000000 /* In Pixels			     */
#define GGI_PT_IN_BYTES		0x00001000 /* In Bytes			     */
#define GGI_PT_IN_SLICE		0x0000f000 /* In chipset native size slice   */

/* The ROLE the value plays in the operation */
#define GGP_PT_ROLE_MASK	0x000000c0
#define GGI_PT_ROLE_START	0x00000000 /* A starting value or coordinate */
#define GGI_PT_ROLE_END		0x00000040 /* An ending value or coordinate  */
#define GGI_PT_ROLE_LEN		0x00000080 /* A width or height		     */
#define GGI_PT_ROLE_INCR	0x000000c0 /* An increment, pitch, or slope  */


/*
******************************************************************************
 LibGGI specific events
******************************************************************************
*/

#define GGI_CMDFLAG_LIBGGI (GII_CMDFLAG_EXTERNAL>>1)

/* Tell target that the application should not/should be halted when the
   display is unmapped.	The default is to halt the application.
*/
#define GGICMD_NOHALT_ON_UNMAP (GII_CMDFLAG_EXTERNAL | GGI_CMDFLAG_LIBGGI \
				| GII_CMDFLAG_NODATA | 0x01)
#define GGICMD_HALT_ON_UNMAP (GII_CMDFLAG_EXTERNAL | GGI_CMDFLAG_LIBGGI \
			      | GII_CMDFLAG_NODATA | 0x02)

/* Requests the application to switch target/mode, or to stop drawing on
   the visual.
   The latter is only sent if the application has explicitly requested
   GGICMD_NOHALT_ON_UNMAP. When a GGI_REQSW_UNMAP request is sent the
   application should respond by sending a GGICMD_ACKNOWLEDGE_SWITCH event
   as quickly as possible. After the acknowledge event is sent the
   application must not draw onto the visual until it receives an evExpose
   event, which tells the application that the visual is mapped back again.
*/

#define GGICMD_REQUEST_SWITCH (GII_CMDFLAG_EXTERNAL \
			       | GGI_CMDFLAG_LIBGGI | 0x01)

/* Used for 'request' field in ggi_cmddata_switchrequest */
#define GGI_REQSW_UNMAP		0x01
#define GGI_REQSW_MODE		0x02
#define GGI_REQSW_TARGET	0x04

typedef struct {
	uint32_t	request;
	ggi_mode	mode;
	char		target[64];
} ggi_cmddata_switchrequest;


#define GGICMD_ACKNOWLEDGE_SWITCH (GII_CMDFLAG_EXTERNAL | GGI_CMDFLAG_LIBGGI \
				   | GII_CMDFLAG_NODATA | 0x03)

#endif /* _GGI_TYPES_H */
