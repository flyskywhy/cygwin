/* $Id: ll.h,v 1.10 2005/07/31 15:30:38 soyt Exp $
******************************************************************************

   Private structures common to lowlevel libraries.

   Copyright (C) 2002		Brian S. Julin
   Copyright (C) 2002		Christoph Egger

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


#ifndef _GGI_LL_H
#define _GGI_LL_H


/* IMPORTANT: This file is not for use in/with LibGGI itself.
 * ll.h contains structures common to lowlevel libraries, to prevent
 * lowlevel libraries from depending on each other.  This file
 * should not be considered part of the LibGGI API even though it
 * is installed with LibGGI.  Nothing in the LibGGI source code
 * should ever include this file.  Don't include this file
 * directly in an application; It will be automatically included
 * with the headers of the libraries that need it.
 */


/**************************************************************************
 * Low level Objects -- sharable by many GGI Project lowlevel libraries
 */

#ifdef HAVE_STDINT_H	/* This header provides uint32_t */
#include <stdint.h>
#endif

/* Position/size of a lowlevel object on the screen.
 */
struct ggi_ll_pos {
	long x, y;		/* longs used for sub-pixel accuracy */
	unsigned long w, h;
};
typedef struct ggi_ll_pos * ggi_ll_pos_t;

/* Magnification, internal content panning/flipping, tesselation.
 */
struct ggi_ll_lense {
	long x, y;
	long w, h;
};
typedef struct ggi_ll_lense * ggi_ll_lense_t;

/* Units/offset used when ggi_ll_pos is not using simple pixel model
 */
enum ggi_ll_coordbase {

	LL_COORDBASE_MASK	= 0x000e,

	/* Coordinates/lengths are given in pixels */
	LL_COORDBASE_PIXEL      = 0x0000,
	LL_COORDBASE_PIXELS     = 0x0000,

	/* Coordinates/lengths are given in dots */
	LL_COORDBASE_DOT        = 0x0002,
	LL_COORDBASE_DOTS       = 0x0002,

	/* Coordinates/lengths are given in millimeters */
	LL_COORDBASE_MILLIMETER = 0x0004,

	/* Coordinates/lengths are given in micrometers */
	LL_COORDBASE_MICROMETER = 0x0006,

	/* Coordinates/lengths are given in 1/64th inches */
	LL_COORDBASE_1_64_INCH  = 0x0008,

	/* Flag -- when set, coordinates/lengths are given in
	 * above units / LibGAlloc props.sub.motor.div_max
	 */
	LL_COORDBASE_UNIT       = 0x0000,
	LL_COORDBASE_UNITS      = 0x0000,
	LL_COORDBASE_SUBUNIT    = 0x0001,
	LL_COORDBASE_SUBUNITS   = 0x0001,

	/* Flag -- used when setting the coordbase.  Interperate
	 * new coordbase coordinates as being in default units,
	 * rather than translated by the previous coordbase units.
	 */
	LL_COORDBASE_RESET	= 0x8000,

	/* Flag -- used when a ggi_ll_cb structure is being shared
	 * by higher level library objects.
	 *
	 * If set in the structure and not set in the request,
	 * copy the structure on write.  If set in the both
	 * do not copy the structure on write, and remove the flag
	 * from the structure.  If set in the request but not in the
	 * structure, do not copy on write, but set the flag in the
	 * structure.  Thus to set values in a shared cb but keep
	 * it shared, call the access function twice with the flag
	 * asserted, the second time using 0 values for the coords.
	 *
	 * Threaded environments will have to lock this process themselves..
	 */
	LL_COORDBASE_COW	= 0x4000


};	/* ggi_ll_coordbase */

struct ggi_ll_cb {
	long xoff, yoff;	  /* offset from actual point of origin */
	long xsoff, ysoff;	  /* offset from actual size */
	enum ggi_ll_coordbase cb; /* Users perception of coordinate units */
	ggi_coord mul, div;	  /* ratio of users units to actual units */
};
typedef struct ggi_ll_cb * ggi_ll_cb_t;


/* direct access address, stride, pixfmt, current read/write/display frame
 */
struct ggi_ll_ststate {
	int bitdepth, stride, w, h;
	union { void *addr; int frame; } read;
	union { void *addr; int frame; } write;
	union { void *addr; int frame; } display;
};
typedef struct ggi_ll_ststate * ggi_ll_ststate_t;


/* Generic storage sublib access method prototypes and hook structure
 */
typedef ggi_pixel ggi_storageval;

#define GGI_ACCESSFUNC_UNNEEDED 0x01 /* Return value: trivial direct access  */
#define GGI_ACCESSFUNC_NOFLUSH  0x02 /* Return value: no visual flush needed */

struct ggi_ll_stops;
typedef struct ggi_ll_stops * ggi_ll_stops_t;

typedef int (storage2mem_func)(ggi_ll_ststate_t src, size_t xoffset,
			       size_t yoffset, size_t stride,
			       void *membuf, size_t deststride,
			       size_t linewidth, size_t numlines);

typedef int (mem2storage_func)(ggi_ll_ststate_t dest, size_t xoffset,
                               size_t yoffset, size_t stride,
                               void *membuf, size_t srcstride,
                               size_t linewidth, size_t numlines);

typedef int (storage2storage_func)(ggi_ll_ststate_t dest, size_t xoffset,
                                   size_t yoffset, size_t stride,
                                   ggi_ll_ststate_t src,
                                   ggi_ll_stops_t srcops,
                                   size_t srcxoffset,
                                   size_t srcyoffset, size_t srcstride,
                                   size_t linewidth, size_t numlines);

typedef int (const2storage_func)(ggi_ll_ststate_t dest, size_t xoffset,
                                 size_t yoffset, size_t stride,
                                 ggi_storageval val, size_t linewidth,
                                 size_t numlines);

struct ggi_ll_stops {
	int                     usage;

	storage2mem_func        *storage2mem;
	mem2storage_func        *mem2storage;
	storage2storage_func    *storage2storage;
	const2storage_func      *const2storage;
};

/* Constant-fill values for absent channels
*/
struct ggi_ll_fgbg_gc {
	ggi_storageval fgsrc, bgsrc;	/* default values for source      */
	ggi_storageval fgdest, bgdest;	/* default values for destination */
};
typedef struct ggi_ll_fgbg_gc * ggi_ll_fgbg_gc_t;

/* Raster Operations (and pixel-wise operations, too)
 */
enum ggi_ll_rop {

  /* Bitwise boolean operations on two primary operands. */
  /* TODO: Convenience macros to convert between truth table & flag needed. */
  LL_ROP_TRUTHTABLE_0000 = 0x00000001,
  LL_ROP_ZERO            = 0x00000001,
  LL_ROP_FALSE           = 0x00000001,
  LL_ROP_TRUTHTABLE_0001 = 0x00000002,
  LL_ROP_NOR             = 0x00000002,
  LL_ROP_TRUTHTABLE_0010 = 0x00000004,
  LL_ROP_TRUTHTABLE_0011 = 0x00000008,
  LL_ROP_NOT_SOURCE      = 0x00000008,
  LL_ROP_NOT_OPERAND1    = 0x00000008,
  LL_ROP_TRUTHTABLE_0100 = 0x00000010,
  LL_ROP_TRUTHTABLE_0101 = 0x00000020,
  LL_ROP_NOT_DEST        = 0x00000020,
  LL_ROP_NOT_OPERAND2    = 0x00000020,
  LL_ROP_TRUTHTABLE_0110 = 0x00000040,
  LL_ROP_XOR             = 0x00000040,
  LL_ROP_TRUTHTABLE_0111 = 0x00000080,
  LL_ROP_NAND            = 0x00000080,
  LL_ROP_TRUTHTABLE_1000 = 0x00000100,
  LL_ROP_AND             = 0x00000100,
  LL_ROP_TRUTHTABLE_1001 = 0x00000200,
  LL_ROP_XNOR            = 0x00000200,
  LL_ROP_TRUTHTABLE_1010 = 0x00000400,
  LL_ROP_DEST            = 0x00000400,
  LL_ROP_OPERAND2        = 0x00000400,
  LL_ROP_TRUTHTABLE_1011 = 0x00000800,
  LL_ROP_TRUTHTABLE_1100 = 0x00001000,
  LL_ROP_SOURCE          = 0x00001000,
  LL_ROP_OPERAND1        = 0x00001000,
  LL_ROP_TRUTHTABLE_1101 = 0x00002000,
  LL_ROP_TRUTHTABLE_1110 = 0x00004000,
  LL_ROP_OR              = 0x00004000,
  LL_ROP_TRUTHTABLE_1111 = 0x00008000,
  LL_ROP_ONE             = 0x00008000,
  LL_ROP_TRUE            = 0x00008000,

  /* Pixel-wise ROP capabilities */
  /* Keying and math -- per-operand */
  LL_ROP_KEYVAL_OPERAND1  = 0x00010000, /* key on the first operand          */
  LL_ROP_KEYVAL_SOURCE    = 0x00010000,
  LL_ROP_KEYMASK_OPERAND1 = 0x00020000, /* mask key on the 1st operand       */
  LL_ROP_KEYMASK_SOURCE   = 0x00020000,

  LL_ROP_COEFF_OPERAND1   = 0x00040000, /* apply a cooefficient to 1st       */
  LL_ROP_COEFF_SOURCE     = 0x00040000, /* operand.  Implies Alpha channel   */
  LL_ROP_ALPHA_OPERAND1   = 0x00040000, /* used if approved for use with an  */
  LL_ROP_ALPHA_SOURCE     = 0x00040000, /* alpha-carrying tank.              */

  LL_ROP_THRESH_OPERAND1  = 0x00080000, /* apply threshold to the 1st        */
  LL_ROP_THRESH_SOURCE    = 0x00080000, /* operand.  Implies Z channel used  */
  LL_ROP_DEPTH_OPERAND1   = 0x00080000, /* if approved for use with an       */
  LL_ROP_DEPTH_SOURCE     = 0x00080000, /* Z-carrying tank.                  */

  LL_ROP_KEYVAL_OPERAND2  = 0x00100000, /* key on the 2nd operand            */
  LL_ROP_KEYVAL_DEST      = 0x00100000,
  LL_ROP_KEYMASK_OPERAND2 = 0x00200000, /* mask key on the 2nd operand       */
  LL_ROP_KEYMASK_DEST     = 0x00200000,

  LL_ROP_COEFF_OPERAND2   = 0x00400000, /* apply a cooefficient to 2nd       */
  LL_ROP_COEFF_DEST       = 0x00400000, /* operand.  Implies Alpha channel   */
  LL_ROP_ALPHA_OPERAND2   = 0x00400000, /* used if approved for use with an  */
  LL_ROP_ALPHA_DEST       = 0x00400000, /* alpha-carrying tank or frame.     */

  LL_ROP_THRESH_OPERAND2  = 0x00080000, /* apply threshold to the 2nd        */
  LL_ROP_THRESH_DEST      = 0x00080000, /* operand.  Implies Z channel used  */
  LL_ROP_DEPTH_OPERAND2   = 0x00080000, /* if approved for use with an       */
  LL_ROP_DEPTH_DEST       = 0x00080000, /* Z-carrying tank.                  */

  /* Keying and math -- both operands */
  LL_ROP_ADD              = 0x01000000, /* add operands to form result       */
  LL_ROP_KEY_CMP          = 0x02000000, /* key on compare                    */

  /* Stuff for pattern fills/filters.  Operand 1 only. */
  LL_ROP_TESSELATE        = 0x10000000, /* tesselate (pat fill/filter)       */
  LL_ROP_XWRAP            = 0x20000000, /* rotate/wrap/pin horizontally      */
  LL_ROP_YWRAP            = 0x40000000, /* rotate/wrap/pin vertically        */

  /* Companion flags designate the ROP is part of a pipeline. */
  LL_ROP_OPERAND1_AUX     = 0x04000000, /* Preprocesses another ROP's op1    */
  LL_ROP_SOURCE_AUX       = 0x04000000,
  LL_ROP_OPERAND2_AUX     = 0x08000000, /* Preprocesses another ROP's op2    */
  LL_ROP_DEST_AUX         = 0x08000000,
  LL_ROP_AUX              = 0x0c000000, /* Run side by side another ROP      */

  /* Common combos (Principle of least surprise) */
  LL_ROP_ALPHA_CHANNEL    = 0x01440000, /* 2-operand ALPHA blend (assuming   */
  LL_ROP_ALPHA	          = 0x01440000, /* tanks/frame are alpha-carrying.)  */
  LL_ROP_ALPHA_AUX        = 0x0d440000, /* Alpha with separate buffer.       */

  LL_ROP_Z_CHANNEL        = 0x02880000, /* 2-operand Z, in-channel           */
  LL_ROP_Z_AUX            = 0x0e880000, /* 2-operand Z, separate buffer      */
  LL_ROP_Z                = 0x0e880000,

  /* This flag must not be set for the above to be valid. */
  /* ISO C limits enum to int */
#define  LL_ROP_ALT        0x80000000   /* Reserved for future use.          */

  LL_ROP_NOP              = 0x00000000, /* This rop does nothing.            */

};	/* ggi_ll_rop */

/* Alpha Blends and Z/Alpha behaviors
 */
enum ggi_ll_math {

	LL_MATH_ALPHA_OVER		= 0x00000001,
	LL_MATH_ALPHA_SRC_OVER		= 0x00000001,
	LL_MATH_ALPHA_UNDER		= 0x00000010,
	LL_MATH_ALPHA_DST_OVER		= 0x00000010,
	LL_MATH_ALPHA_SRC_IN		= 0x00000002,
	LL_MATH_ALPHA_DST_IN		= 0x00000020,
	LL_MATH_ALPHA_SRC_OUT		= 0x00000004,
	LL_MATH_ALPHA_DST_OUT		= 0x00000040,
	LL_MATH_ALPHA_TOP		= 0x00000008,
	LL_MATH_ALPHA_SRC_TOP		= 0x00000008,
	LL_MATH_ALPHA_DST_TOP		= 0x00000080,
	LL_MATH_ALPHA_BOTTOM		= 0x00000080,
	LL_MATH_ALPHA_XOR		= 0x00000100,
	LL_MATH_ALPHA_PLUS		= 0x00000200,
	LL_MATH_ALPHA_POSTDIV		= 0x00000400,
	LL_MATH_ALPHA_DISPOSE		= 0x00000800,
	LL_MATH_Z_DISPOSE		= 0x00001000,

#define LL_MATH_ALTSHIFT		16

	LL_MATH_CMP_GT			= 0x00002000,
	LL_MATH_CMP_LT			= 0x00004000,
	LL_MATH_CMP_GTE			= 0x0000a000,
	LL_MATH_CMP_LTE			= 0x0000c000,
	LL_MATH_CMP_UNSIGNED		= 0x00000000,
	LL_MATH_CMP_SIGNED		= 0x20000000,
	LL_MATH_ALPHA_SRC_PREMULT	= 0x40000000
	/* ISO C limits enum to int */
#define	LL_MATH_ALPHA_DST_PREMULT	 0x80000000

};	/* ggi_ll_math */


/* Coarse level format conversion specifiers.
 */
enum ggi_ll_adjuster {

  LL_ADJ_BACKASS_WORDS      = 0x0001, /* undo "Windows fmt" LSBF words       */
  LL_ADJ_DEPTH_UPSIZE       = 0x0002, /* adjust depth upwards	             */
  LL_ADJ_DEPTH_DOWNSIZE     = 0x0004, /* adjust depth downwards              */
  LL_ADJ_USE_OWN_CLUT       = 0x0008, /* use an internal CLUT of its own     */
  LL_ADJ_COLORSPACE         = 0x0010, /* adjust colorspace                   */
  LL_ADJ_PIXFMT_OMNIPRESENT = 0x0020, /* translate very common pixelformats  */
  LL_ADJ_PIXFMT_COMMON      = 0x0040, /* translate common pixelformats.      */
  LL_ADJ_PIXFMT_WELLKNOWN   = 0x0080, /* translate non-rare pixelformats.    */
  LL_ADJ_PIXFMT_WELLDEFINED = 0x0100, /* translate non-quirky pixelformats.  */
  LL_ADJ_PIXFMT_ALL         = 0x0200, /* translate just about anything.      */
  LL_ADJ_ENDIAN4            = 0x1000, /* reverse endianness                  */
  LL_ADJ_ENDIAN8            = 0x2000,
  LL_ADJ_ENDIAN16           = 0x4000,
  LL_ADJ_ENDIAN32           = 0x8000,

};	/* ggi_ll_adjuster */

/* Blend and keying rules */
struct ggi_ll_math_gc {
	enum ggi_ll_rop rop;
	enum ggi_ll_math math;
	enum ggi_ll_adjuster adj;
};
typedef struct ggi_ll_math_gc * ggi_ll_math_gc_t;


/* Now for the macro magic -- ll objects balance compactness with flexibility,
 * allowing objects to share any of the above structures for a small
 * memory/runtime overhead.
 */
#define GGI_LL_OBJ(NUM_ATTRIBS) \
        uint32_t map;                                              \
        void *ptrs[NUM_ATTRIBS + 3];
        /* ptrs always contains { NULL, NULL, NULL, ...data... } */

/* This struct should never be alloced or sizeof() taken.   It is
 * defined for the sake of bounds checkers.  Well, OK, to deceive bounds
 * checkers really.  :-)
 */
#define GGI_LL_MAX_NUM_PTRS 16
struct ggi_llobj {
	GGI_LL_OBJ(GGI_LL_MAX_NUM_PTRS)
};

/* HOW IT ALL WORKS:
 * The 32-bit integer map is used to point eight types of attributes to
 * any of 16 void* pointers, the first three of which are always NULL (this
 * saves on a special case check to see if the attribute exists -- it exists
 * if the designated pointers are not NULL). This costs only 1 shift, 1 mask,
 * and 1 addition/index.  Thus the container object can range in size
 * from 16 bytes to 80 bytes (or 28 to 188 bytes on 64-bit architectures).
 * Each of the eight types of attributes can consist of 1, 2, or 3 pointers.
 */

#define GGI_LL_ATTRIB_MASK    0x0000000f

/* Positioning
 */
#define GGI_LL_POS_SHIFT 28
#define GGI_LL_POS_NUMPTRS 3

#define GGI_LL_CB_SET(obj) \
(obj)->ptrs[(((obj)->map>>GGI_LL_POS_SHIFT)&GGI_LL_ATTRIB_MASK)]
#define GGI_LL_CB(obj)		(ggi_ll_cb_t)GGI_LL_CB_SET(obj)

#define GGI_LL_LENSE_SET(obj) \
(obj)->ptrs[(((obj)->map>>GGI_LL_POS_SHIFT)&GGI_LL_ATTRIB_MASK)+1]
#define GGI_LL_LENSE(obj)	(ggi_ll_lense_t)GGI_LL_LENSE_SET(obj)

#define GGI_LL_POS_SET(obj) \
(obj)->ptrs[(((obj)->map>>GGI_LL_POS_SHIFT)&GGI_LL_ATTRIB_MASK)+2]
#define GGI_LL_POS(obj)		(ggi_ll_pos_t)GGI_LL_POS_SET(obj)


/* Storage
 */
#define GGI_LL_ST_SHIFT 24
#define GGI_LL_ST_NUMPTRS 2

#define GGI_LL_STOPS_SET(obj) \
(obj)->ptrs[(((obj)->map>>GGI_LL_ST_SHIFT)&GGI_LL_ATTRIB_MASK)]
#define GGI_LL_STOPS(obj)	(ggi_ll_stops_t)GGI_LL_STOPS_SET(obj)

#define GGI_LL_STSTATE_SET(obj) \
(obj)->ptrs[(((obj)->map>>GGI_LL_ST_SHIFT)&GGI_LL_ATTRIB_MASK)+1]
#define GGI_LL_STSTATE(obj)	(ggi_ll_ststate_t)GGI_LL_STSTATE_SET(obj)

/* GC
 */
#define GGI_LL_GC_SHIFT 20
#define GGI_LL_GC_NUMPTRS 3

#define GGI_LL_GC2_SET(obj) \
(obj)->ptrs[(((obj)->map>>GGI_LL_GC_SHIFT)&GGI_LL_ATTRIB_MASK)]
#define GGI_LL_GC2(obj)		(ggi_ll_fgbg_gc_t)GGI_LL_GC2_SET(obj)

#define GGI_LL_GC_SET(obj) \
(obj)->ptrs[(((obj)->map>>GGI_LL_GC_SHIFT)&GGI_LL_ATTRIB_MASK)+1]
#define GGI_LL_GC(obj)		(ggi_ll_fgbg_gc_t)GGI_LL_GC_SET(obj)

#define GGI_LL_MATHGC_SET(obj) \
(obj)->ptrs[(((obj)->map>>GGI_LL_GC_SHIFT)&GGI_LL_ATTRIB_MASK)+2]
#define GGI_LL_MATHGC(obj)	(ggi_ll_math_gc_t)GGI_LL_MATHGC_SET(obj)


/* LibGAlloc resource management
 */
#define GGI_LL_GA_SHIFT 16
#define GGI_LL_GA_NUMPTRS 1

/* reserved for target and extension-specific use
 */
#define GGI_LL_EXTPRIV_SHIFT 8
#define GGI_LL_PRIV_SHIFT 4

/* GGI_LL_FIT will shuffle the object to make more free slots, and
 * ensure there are num slots free for the group with shift shift.
 * It blindly assumes that the llobj is arbitrarily large, so should
 * only be called when you are sure free slots are there to be had.
 */
#define GGI_LL_FIT(obj, shift, num) \
do { \
  fprintf(stderr, "Tell skids to implement GGI_LL_FIT."); \
} while (0);


#endif /* _GGI_LL_H */
