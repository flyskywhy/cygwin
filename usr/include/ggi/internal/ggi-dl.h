/* $Id: ggi-dl.h,v 1.3 2004/09/13 09:35:20 cegger Exp $
******************************************************************************

   LibGGI - clipping macros and inclusion of stuff needed by sublibs

   Copyright (C) 1999	Marcus Sundberg		[marcus@ggi-project.org]

   Note: this file should really be renamed.

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

#ifndef _GGI_INTERNAL_GGI_DL_H
#define _GGI_INTERNAL_GGI_DL_H

#include <ggi/types.h>
#include <ggi/internal/gii-dl.h>
#include <ggi/internal/internal.h>
#include <ggi/internal/dltypes.h>

#define PREPARE_FB(vis) if (vis->accelactive) { LIBGGIIdleAccel(vis); }

/* A shift operator with direction determined by sign of the shift count. */
#define SSHIFT(val, shift)  \
        (((shift) >= 0) ? (val) << (shift) : (val) >> -(shift))

/* Macros for applying clip regions */
#define CHECKXY(vis,cx,cy) \
do { \
	if ((cx) <  LIBGGI_GC((vis))->cliptl.x || \
	    (cy) <  LIBGGI_GC((vis))->cliptl.y || \
	    (cx) >= LIBGGI_GC((vis))->clipbr.x || \
	    (cy) >= LIBGGI_GC((vis))->clipbr.y) { \
		    return 0; \
	    } \
} while (0);


#define LIBGGICLIP_XYW(vis,cx,cy,w) \
do { \
	if ((cy) < LIBGGI_GC(vis)->cliptl.y || \
	    (cy) >= LIBGGI_GC(vis)->clipbr.y) { \
		return 0; \
	} \
	if ((cx) < LIBGGI_GC(vis)->cliptl.x) { \
		int diff = LIBGGI_GC(vis)->cliptl.x - (cx); \
		(cx) += diff; \
		(w) -= diff; \
	} \
	if ((cx)+(w) > LIBGGI_GC(vis)->clipbr.x) { \
		(w) = LIBGGI_GC(vis)->clipbr.x - (cx); \
	} \
	if ((w) <= 0) return 0; \
} while (0);


#define LIBGGICLIP_XYW_BUFMOD(vis,cx,cy,w,buf,bufmod) \
do { \
	if ((cy) < LIBGGI_GC(vis)->cliptl.y || \
	    (cy) >= LIBGGI_GC(vis)->clipbr.y) { \
		return 0; \
	} \
	if ((cx) < LIBGGI_GC(vis)->cliptl.x) { \
		int diff = LIBGGI_GC(vis)->cliptl.x - (cx); \
		(cx)  += diff; \
		(buf) += (diff bufmod); \
		(w) -= diff; \
	} \
	if ((cx)+(w) > LIBGGI_GC(vis)->clipbr.x) { \
		(w) = LIBGGI_GC(vis)->clipbr.x - (cx); \
	} \
	if ((w) <= 0) return 0; \
} while (0);


#define LIBGGICLIP_XYH(vis,cx,cy,h) \
do { \
	if ((cx) < LIBGGI_GC(vis)->cliptl.x || \
	    (cx) >= LIBGGI_GC(vis)->clipbr.x) { \
		return 0; \
	} \
	if ((cy) < LIBGGI_GC(vis)->cliptl.y) { \
		int diff = LIBGGI_GC(vis)->cliptl.y - (cy); \
		(cy) += diff; \
		(h) -= diff; \
	} \
	if ((cy)+(h) > LIBGGI_GC(vis)->clipbr.y) { \
		(h) = LIBGGI_GC(vis)->clipbr.y - (cy); \
	} \
	if ((h) <= 0) return 0; \
} while (0);


#define LIBGGICLIP_XYH_BUFMOD(vis,cx,cy,h,buf,bufmod) \
do { \
	if ((cx) < LIBGGI_GC(vis)->cliptl.x || \
	    (cx) >= LIBGGI_GC(vis)->clipbr.x) { \
		return 0; \
	} \
	if ((cy) < LIBGGI_GC(vis)->cliptl.y) { \
		int diff = LIBGGI_GC(vis)->cliptl.y - (cy); \
		(cy)  += diff; \
		(buf) += (diff bufmod); \
		(h) -= diff; \
	} \
	if ((cy)+(h) > LIBGGI_GC(vis)->clipbr.y) { \
		(h) = LIBGGI_GC(vis)->clipbr.y - (cy); \
	} \
	if ((h) <= 0) return 0; \
} while (0);


#define LIBGGICLIP_XYWH(vis,cx,cy,w,h) \
do {  \
	if ((cx) < LIBGGI_GC((vis))->cliptl.x) { \
		int diff = LIBGGI_GC((vis))->cliptl.x - (cx); \
		(cx) += diff; \
		(w)  -= diff; \
	} \
	if ((cx)+(w) >= LIBGGI_GC((vis))->clipbr.x) { \
		(w) = LIBGGI_GC((vis))->clipbr.x - (cx); \
	} \
	if ((w) <= 0) return 0; \
	if ((cy) < LIBGGI_GC((vis))->cliptl.y) { \
		int diff = LIBGGI_GC((vis))->cliptl.y - (cy); \
		(cy) += diff; \
		(h)  -= diff; \
	} \
	if ((cy)+(h) > LIBGGI_GC((vis))->clipbr.y) { \
		(h) = LIBGGI_GC((vis))->clipbr.y - (cy); \
	} \
	if ((h) <= 0) return 0; \
} while (0);


#define LIBGGICLIP_PUTBOX(vis,cx,cy,w,h,src,srcwidth,srcmod) \
do { \
	int diff; \
	/* Vertical clipping */ \
	diff = LIBGGI_GC(vis)->cliptl.y - (cy); \
	if (diff > 0) { \
		(cy) += diff; \
		(h) -= diff; \
		(src) += diff*(srcwidth); \
	} \
	diff = LIBGGI_GC(vis)->clipbr.y - (cy); \
	if ((h) > diff) (h) = diff; \
	if ((h) <= 0) return 0; \
	/* Horizontal clipping */ \
	diff = LIBGGI_GC(vis)->cliptl.x - (cx); \
	if (diff > 0) { \
		(cx) += diff; \
		(w) -= diff; \
		(src) += (diff srcmod); \
	} \
	diff = LIBGGI_GC(vis)->clipbr.x - (cx); \
	if ((w) > diff) (w) = diff; \
	if ((w) <= 0) return 0; \
} while (0);


#define LIBGGICLIP_COPYBOX(vis,xsrc,ysrc,w,h,xdest,ydest) \
do {  \
	if ((xdest) < LIBGGI_GC((vis))->cliptl.x) { \
		int diff = LIBGGI_GC((vis))->cliptl.x - (xdest); \
		(xdest) += diff; \
		(xsrc)  += diff; \
		(w)  -= diff; \
	} \
	if ((xdest)+(w) >= LIBGGI_GC((vis))->clipbr.x) { \
		(w) = LIBGGI_GC((vis))->clipbr.x - (xdest); \
	} \
	if ((w) <= 0) return 0; \
	if ((ydest) < LIBGGI_GC((vis))->cliptl.y) { \
		int diff = LIBGGI_GC((vis))->cliptl.y - (ydest); \
		(ydest) += diff; \
		(ysrc)  += diff; \
		(h)  -= diff; \
	} \
	if ((ydest)+(h) > LIBGGI_GC((vis))->clipbr.y) { \
		(h) = LIBGGI_GC((vis))->clipbr.y - (ydest); \
	} \
	if ((h) <= 0) return 0; \
} while (0);


#define LIBGGICLIP_FULLSCREEN(vis) \
((LIBGGI_GC(vis)->cliptl.x | LIBGGI_GC(vis)->cliptl.y) == 0 && \
 LIBGGI_GC(vis)->clipbr.x == LIBGGI_VIRTX(vis) && \
 LIBGGI_GC(vis)->clipbr.y == LIBGGI_VIRTY(vis))

#endif /* _GGI_INTERNAL_GGI_DL_H */
