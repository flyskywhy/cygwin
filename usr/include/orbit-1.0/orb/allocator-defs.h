/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/* By Elliot Lee. Copyright (c) 1998 Red Hat Software */


/********************************************************
 * Never include this header file directly. Only allocators.[ch]
 * should do this
 ********************************************************/

/* Macro crap */

#ifdef ALLOCATOR_DEFINITION

#define ORBIT_DEFINE_CHUNK(x, xsize) \
DEFINE_LOCK(x##_allocator); \
GMemChunk *x##_allocator = NULL

#elif defined(ALLOCATOR_INITIALIZATION)

#define ORBIT_DEFINE_CHUNK(x, xsize) INIT_LOCK(x##_allocator); \
x##_allocator = g_mem_chunk_new(#x, (xsize), \
(xsize) * ORBIT_CHUNKS_PREALLOC, G_ALLOC_AND_FREE)

#else

#define ORBIT_DEFINE_CHUNK(x, xsize) \
EXTERN_LOCK(x##_allocator); \
extern GMemChunk *x##_allocator

#endif

/*****************************************************
 * Here's where we define the actual chunks that are used
 *****************************************************/
ORBIT_DEFINE_CHUNK(CORBA_TypeCode, sizeof(struct CORBA_TypeCode_struct));
ORBIT_DEFINE_CHUNK(CORBA_Object, sizeof(struct CORBA_Object_struct));
ORBIT_DEFINE_CHUNK(CORBA_NVList, sizeof(struct CORBA_NVList_type));

#undef ORBIT_DEFINE_CHUNK
