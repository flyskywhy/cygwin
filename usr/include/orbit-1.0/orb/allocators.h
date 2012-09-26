/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/* By Elliot Lee. Copyright (c) 1998 Red Hat Software */

#ifndef ALLOCATORS_H
#define ALLOCATORS_H 1

#include <orb/orbit.h>

#include <orb/allocator-defs.h>

#define ORBIT_CHUNK_ALLOC(typename) \
ORBit_chunk_alloc(typename##_allocator, LOCK_NAME(typename##_allocator))

#define ORBIT_CHUNK_FREE(typename, mem) \
ORBit_chunk_free(typename##_allocator, LOCK_NAME(typename##_allocator), (mem))

void ORBit_chunks_init(void);

gpointer ORBit_chunk_alloc(GMemChunk *chunk,
			   PARAM_LOCK(chunk_lock));

void ORBit_chunk_free(GMemChunk *chunk,
		      PARAM_LOCK(chunk_lock),
		      gpointer mem);

/* General memory allocation routines */

#define PTR_TO_MEMINFO(x) (((ORBit_mem_info *)(x)) - 1)
#define MEMINFO_TO_PTR(x) ((gpointer)((x) + 1))

typedef gpointer (*ORBit_free_childvals)(gpointer mem,
					 gpointer func_data,
					 CORBA_boolean ignore);

typedef struct {
	gulong magic;

	/* If this routine returns FALSE, it indicates that it already free'd
	   the memory block itself */
	ORBit_free_childvals free; /* function pointer to free function */
	gpointer func_data;

	/* The following double serves two purposes. Firstly it
	 * ensures, that ORBit_mem_info's size is a multiple of 8
	 * (which is a must). Secondly it leaves room for a special
	 * marker used to distinguish between memory, which has to be
	 * freed (in that case the marker is FREE_MARKER_IS_ALLOCATED
	 * [0xfefefefe]) or memory, which must not be freed as it is a
	 * string residing in the receive buffer of a request (in that
	 * case the marker per GIOP is the length of the following
	 * string, thus some number guaranteed to be smaller than
	 * 0xfefefefe, I don't think, we ever support transferring
	 * strings with a length of 4GB ;-)
	 *
	 * The marker is not 0xffffffff, because that is also -1.
	 * Remember that the length in the receive buffer can have
	 * swapped endianess, so using 0xffff0000 is a plan to
	 * disaster.  
	 */
	gdouble align_me_properly_and_provide_space_for_marker;
} ORBit_mem_info;

gpointer ORBit_alloc(size_t block_size,
		     ORBit_free_childvals freefunc,
		     gpointer func_data);
gpointer ORBit_alloc_2(size_t block_size,
		       ORBit_free_childvals freefunc,
		       gpointer func_data,
		       size_t before_size);

void ORBit_free(gpointer mem, CORBA_boolean ignore);

/* internal stuff */
gpointer ORBit_free_via_TypeCode(gpointer mem,
				 gpointer tcp,
				 gboolean ignore);

#endif /* ALLOCATORS_H */
