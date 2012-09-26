#ifndef UTIL_H
#define UTIL_H 1

#include <glib.h>

#define ORBIT_DEBUG 1

#ifdef ORBIT_DEBUG
#define ORBIT_DEBUG_NOTE(x) (x)
#else
#define ORBIT_DEBUG_NOTE(x)
#endif


#define BitTest(f, bit)  ((f) & (1<<(bit)))
#define BitSet(f, bit) ((f) |= (1<<(bit)))
#define BitClr(f, bit) ((f) &= ~(1<<(bit)))
/* Align an address upward to a boundary, expressed as a number of bytes.
   E.g. align to an 8-byte boundary with argument of 8.  */

/*
 *   (this + boundary - 1)
 *          &
 *    ~(boundary - 1)
 */

#ifndef __CYGWIN__
#define ALIGN_ADDRESS(this, boundary) \
  ((gpointer)((( ((unsigned long)(this)) + (((unsigned long)(boundary)) -1)) & (~(((unsigned long)(boundary))-1)))))

#else
	/* Cygwin doubles and long longs have a strange alignment.
	 * They are a 8-byte intervals, but starting only
	 * at 0x4 and 0xc (ie displaced by 4).
	 * So, if the boundary is 8, we need to do extra work.
	 */
#define ALIGN_ADDRESS_1(this, boundary) \
  ((gpointer)((( ((unsigned long)(this)) + (((unsigned long)(boundary)) -1)) & (~(((unsigned long)(boundary))-1)))))

#define ALIGN_ADDRESS_2(this) \
  ((gpointer) (((unsigned long)(ALIGN_ADDRESS_1(this, 4))) % 8 ? ((unsigned long)(ALIGN_ADDRESS_1(this, 4))) : ((unsigned long)(ALIGN_ADDRESS_1(this, 4))) + 4))
  
#define ALIGN_ADDRESS(this, boundary) \
  (boundary == 8 ? ALIGN_ADDRESS_2(this) : ALIGN_ADDRESS_1(this, boundary))

#endif

#include <ORBitutil/thread-safety.h>
#include <ORBitutil/trace.h>
#include <ORBitutil/compat.h>
#include <ORBitutil/os-specifics.h>

#endif
