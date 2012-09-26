/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
 *  ORBit: A CORBA v2.2 ORB
 *
 *  Copyright (C) 1998 Richard H. Porter, Red Hat Software
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Author: Dick Porter <dick@cymru.net>
 *          Elliot Lee <sopwith@redhat.com>
 *
 */

#ifndef _ORBIT_DYNANY_H_
#define _ORBIT_DYNANY_H_

#include "orbit_types.h"
#include "orbit_object.h"
#include "corba_any.h"

#define ex_DynamicAny_DynAny_Invalid      "IDL:CORBA/DynAny/Invalid:1.0"
#define ex_DynamicAny_DynAny_InvalidValue "IDL:CORBA/DynAny/InvalidValue:1.0"
#define ex_DynamicAny_DynAny_TypeMismatch "IDL:CORBA/DynAny/TypeMismatch:1.0"
#define ex_DynamicAny_DynAny_InvalidSeq   "IDL:CORBA/DynAny/InvalidSeq:1.0"

typedef struct DynamicAny_DynAny_type *DynamicAny_DynAny;
typedef struct DynamicAny_DynAny_type *DynamicAny_DynEnum;
typedef struct DynamicAny_DynAny_type *DynamicAny_DynStruct;
typedef struct DynamicAny_DynAny_type *DynamicAny_DynUnion;
typedef struct DynamicAny_DynAny_type *DynamicAny_DynSequence;
typedef struct DynamicAny_DynAny_type *DynamicAny_DynArray;

struct DynamicAny_DynAny_type {
	struct ORBit_PseudoObject_struct parent;
	gpointer data;
};

DynamicAny_DynAny CORBA_ORB_create_dyn_any       (CORBA_ORB obj,
						  CORBA_any *value,
						  CORBA_Environment *ev);

DynamicAny_DynAny CORBA_ORB_create_basic_dyn_any (CORBA_ORB obj,
						  const CORBA_TypeCode type,
						  CORBA_Environment *ev);

DynamicAny_DynStruct CORBA_ORB_create_dyn_struct (CORBA_ORB obj,
						  const CORBA_TypeCode type,
						  CORBA_Environment *ev);

DynamicAny_DynSequence CORBA_ORB_create_dyn_sequence(CORBA_ORB obj,
						     const CORBA_TypeCode type,
						     CORBA_Environment *ev);

DynamicAny_DynArray CORBA_ORB_create_dyn_array(CORBA_ORB obj,
					       const CORBA_TypeCode type,
					       CORBA_Environment *ev);

DynamicAny_DynUnion CORBA_ORB_create_dyn_union (CORBA_ORB obj,
						const CORBA_TypeCode type,
						CORBA_Environment *ev);

DynamicAny_DynEnum CORBA_ORB_create_dyn_enum (CORBA_ORB obj,
					      const CORBA_TypeCode type,
					      CORBA_Environment *ev);

CORBA_TypeCode DynamicAny_DynAny_type (DynamicAny_DynAny obj,
				       CORBA_Environment *ev);

void       DynamicAny_DynAny_assign   (DynamicAny_DynAny obj,
				       DynamicAny_DynAny dyn_any,
				       CORBA_Environment *ev);

void       DynamicAny_DynAny_from_any (DynamicAny_DynAny obj,
				       CORBA_any *value,
				       CORBA_Environment *ev);

CORBA_any *DynamicAny_DynAny_to_any   (DynamicAny_DynAny obj,
				       CORBA_Environment *ev);

void       DynamicAny_DynAny_destroy  (DynamicAny_DynAny obj,
				       CORBA_Environment *ev);

CORBA_boolean DynamicAny_DynAny_equal (DynamicAny_DynAny obj_a,
				       DynamicAny_DynAny obj_b,
				       CORBA_Environment *ev);

DynamicAny_DynAny DynamicAny_DynAny_copy   (DynamicAny_DynAny obj,
					    CORBA_Environment *ev);

void DynamicAny_DynAny_insert_boolean (DynamicAny_DynAny obj,
				       CORBA_boolean value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_octet   (DynamicAny_DynAny obj,
				       CORBA_octet value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_char    (DynamicAny_DynAny obj,
				       CORBA_char value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_short   (DynamicAny_DynAny obj,
				       CORBA_short value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_ushort  (DynamicAny_DynAny obj,
				       CORBA_unsigned_short value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_long    (DynamicAny_DynAny obj,
				       CORBA_long value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_ulong   (DynamicAny_DynAny obj,
				       CORBA_unsigned_long value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_float   (DynamicAny_DynAny obj,
				       CORBA_float value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_double  (DynamicAny_DynAny obj,
				       CORBA_double value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_string  (DynamicAny_DynAny obj,
				       const CORBA_char *value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_reference (DynamicAny_DynAny obj,
					 CORBA_Object value,
					 CORBA_Environment *ev);

void DynamicAny_DynAny_insert_typecode  (DynamicAny_DynAny obj,
					 CORBA_TypeCode value,
					 CORBA_Environment *ev);

#ifdef HAVE_CORBA_LONG_LONG
void DynamicAny_DynAny_insert_longlong  (DynamicAny_DynAny obj,
					 CORBA_long_long value,
					 CORBA_Environment *ev);

void DynamicAny_DynAny_insert_ulonglong (DynamicAny_DynAny obj,
					 CORBA_unsigned_long_long value,
					 CORBA_Environment *ev);
#endif

void DynamicAny_DynAny_insert_longdouble (DynamicAny_DynAny obj,
					  CORBA_long_double value,
					  CORBA_Environment *ev);

void DynamicAny_DynAny_insert_wchar (DynamicAny_DynAny obj,
				     CORBA_wchar value,
				     CORBA_Environment *ev);

void DynamicAny_DynAny_insert_wstring (DynamicAny_DynAny obj,
				       CORBA_wchar *value,
				       CORBA_Environment *ev);

void DynamicAny_DynAny_insert_any (DynamicAny_DynAny obj,
				   CORBA_any *value,
				   CORBA_Environment *ev);

CORBA_boolean DynamicAny_DynAny_get_boolean (DynamicAny_DynAny obj,
					     CORBA_Environment *ev);

CORBA_octet DynamicAny_DynAny_get_octet (DynamicAny_DynAny obj,
					 CORBA_Environment *ev);

CORBA_char DynamicAny_DynAny_get_char (DynamicAny_DynAny obj,
				       CORBA_Environment *ev);

CORBA_short DynamicAny_DynAny_get_short (DynamicAny_DynAny obj,
					 CORBA_Environment *ev);

CORBA_unsigned_short DynamicAny_DynAny_get_ushort (DynamicAny_DynAny obj,
						   CORBA_Environment *ev);

CORBA_long DynamicAny_DynAny_get_long (DynamicAny_DynAny obj,
				       CORBA_Environment *ev);

CORBA_unsigned_long DynamicAny_DynAny_get_ulong (DynamicAny_DynAny obj,
						 CORBA_Environment *ev);

CORBA_float DynamicAny_DynAny_get_float (DynamicAny_DynAny obj,
					 CORBA_Environment *ev);

CORBA_double DynamicAny_DynAny_get_double (DynamicAny_DynAny obj,
					   CORBA_Environment *ev);

CORBA_char *DynamicAny_DynAny_get_string (DynamicAny_DynAny obj,
					  CORBA_Environment *ev);

CORBA_Object DynamicAny_DynAny_get_reference (DynamicAny_DynAny obj,
					      CORBA_Environment *ev);

CORBA_TypeCode DynamicAny_DynAny_get_typecode (DynamicAny_DynAny obj,
					       CORBA_Environment *ev);

#ifdef HAVE_CORBA_LONG_LONG
CORBA_long_long DynamicAny_DynAny_get_longlong (DynamicAny_DynAny obj,
						CORBA_Environment *ev);

CORBA_unsigned_long_long DynamicAny_DynAny_get_ulonglong (DynamicAny_DynAny obj,
							  CORBA_Environment *ev);
#endif

CORBA_long_double DynamicAny_DynAny_get_longdouble (DynamicAny_DynAny obj,
						    CORBA_Environment *ev);

CORBA_wchar DynamicAny_DynAny_get_wchar (DynamicAny_DynAny obj,
					 CORBA_Environment *ev);

CORBA_wchar *DynamicAny_DynAny_get_wstring (DynamicAny_DynAny obj,
					    CORBA_Environment *ev);

CORBA_any *DynamicAny_DynAny_get_any (DynamicAny_DynAny obj,
				      CORBA_Environment *ev);

CORBA_unsigned_long DynamicAny_DynAny_component_count (DynamicAny_DynAny obj,
						       CORBA_Environment *ev);

DynamicAny_DynAny DynamicAny_DynAny_current_component (DynamicAny_DynAny obj,
						       CORBA_Environment *ev);

CORBA_boolean DynamicAny_DynAny_next (DynamicAny_DynAny obj,
				      CORBA_Environment *ev);

CORBA_boolean DynamicAny_DynAny_seek (DynamicAny_DynAny obj,
				      CORBA_long index,
				      CORBA_Environment *ev);

void DynamicAny_DynAny_rewind (DynamicAny_DynAny obj,
			       CORBA_Environment *ev);

/* DynEnum */
CORBA_char *DynamicAny_DynEnum_get_as_string (DynamicAny_DynEnum obj,
					      CORBA_Environment *ev);

void DynamicAny_DynEnum_set_as_string(DynamicAny_DynEnum obj,
				      const CORBA_char *value_as_string,
				      CORBA_Environment *ev);

CORBA_unsigned_long DynamicAny_DynEnum_get_as_ulong (DynamicAny_DynEnum obj,
						     CORBA_Environment *ev);

void DynamicAny_DynEnum_set_as_ulong (DynamicAny_DynEnum obj,
				      CORBA_unsigned_long value_as_ulong,
				      CORBA_Environment *ev);

/* DynStruct */
CORBA_FieldName         DynamicAny_DynStruct_current_member_name (DynamicAny_DynStruct obj,
								  CORBA_Environment *ev);

CORBA_TCKind            DynamicAny_DynStruct_current_member_kind (DynamicAny_DynStruct obj,
								  CORBA_Environment *ev);

CORBA_NameValuePairSeq *DynamicAny_DynStruct_get_members  (DynamicAny_DynStruct obj,
							   CORBA_Environment *ev);

void                    DynamicAny_DynStruct_set_members  (DynamicAny_DynStruct obj,
							   CORBA_NameValuePairSeq *value,
							   CORBA_Environment *ev);

/* DynUnion */
DynamicAny_DynAny  DynamicAny_DynUnion_get_discriminator  (DynamicAny_DynUnion obj,
							   CORBA_Environment *ev);

void          DynamicAny_DynUnion_set_discriminator       (DynamicAny_DynUnion obj,
							   DynamicAny_DynAny   d,
							   CORBA_Environment *ev);

void          DynamicAny_DynUnion_set_to_default_member   (DynamicAny_DynUnion obj,
							   CORBA_Environment *ev);

void          DynamicAny_DynUnion_set_to_no_active_member (DynamicAny_DynUnion obj,
							   CORBA_Environment *ev);

CORBA_boolean DynamicAny_DynUnion_has_no_active_member    (DynamicAny_DynUnion obj,
							   CORBA_Environment *ev);

CORBA_TCKind  DynamicAny_DynUnion_discriminator_kind      (DynamicAny_DynUnion obj,
							   CORBA_Environment *ev);

DynamicAny_DynAny  DynamicAny_DynUnion_member             (DynamicAny_DynUnion obj,
							   CORBA_Environment *ev);

CORBA_FieldName DynamicAny_DynUnion_member_name           (DynamicAny_DynUnion obj,
							   CORBA_Environment *ev);

CORBA_TCKind  DynamicAny_DynUnion_member_kind             (DynamicAny_DynUnion obj,
							   CORBA_Environment *ev);

typedef struct {
	CORBA_unsigned_long _maximum,
		_length;
	CORBA_any **_buffer;
	CORBA_boolean _release;
} CORBA_sequence_DynamicAny_DynAny_AnySeq;

typedef CORBA_sequence_DynamicAny_DynAny_AnySeq DynamicAny_DynAny_AnySeq;

extern struct CORBA_TypeCode_struct
	TC_CORBA_sequence_DynamicAny_DynAny_AnySeq_struct;
#define TC_CORBA_sequence_DynamicAny_DynAny_AnySeq \
	((CORBA_TypeCode)&TC_CORBA_sequence_DynamicAny_DynAny_AnySeq_struct)

CORBA_sequence_DynamicAny_DynAny_AnySeq *CORBA_sequence_DynamicAny_DynAny_AnySeq__alloc (void);
CORBA_any **CORBA_sequence_DynamicAny_DynAny_AnySeq_allocbuf (CORBA_unsigned_long len);

typedef struct {
	CORBA_unsigned_long _maximum,
		_length;
	DynamicAny_DynAny *_buffer;
	CORBA_boolean _release;
} CORBA_sequence_DynamicAny_DynAny_DynAnySeq;

typedef CORBA_sequence_DynamicAny_DynAny_DynAnySeq DynamicAny_DynAny_DynAnySeq;

extern struct CORBA_TypeCode_struct
	TC_CORBA_sequence_DynamicAny_DynAny_DynAnySeq_struct;
#define TC_CORBA_sequence_DynamicAny_DynAny_DynAnySeq \
	((CORBA_TypeCode)&TC_CORBA_sequence_DynamicAny_DynAny_DynAnySeq_struct)

CORBA_sequence_DynamicAny_DynAny_DynAnySeq *CORBA_sequence_DynamicAny_DynAny_DynAnySeq__alloc (void);
DynamicAny_DynAny *CORBA_sequence_DynamicAny_DynAny_DynAnySeq_allocbuf (CORBA_unsigned_long len);

/* DynSequence */
DynamicAny_DynAny_AnySeq *DynamicAny_DynSequence_get_elements(DynamicAny_DynSequence obj,
							      CORBA_Environment *ev);

void DynamicAny_DynSequence_set_elements(DynamicAny_DynSequence obj,
					 DynamicAny_DynAny_AnySeq *value,
					 CORBA_Environment *ev);

CORBA_unsigned_long DynamicAny_DynSequence_get_length (DynamicAny_DynSequence obj,
						       CORBA_Environment *ev);

void DynamicAny_DynSequence_set_length (DynamicAny_DynSequence obj,
					CORBA_unsigned_long length,
					CORBA_Environment *ev);

/* DynArray */
DynamicAny_DynAny_AnySeq *DynamicAny_DynArray_get_elements(DynamicAny_DynArray obj,
							   CORBA_Environment *ev);

void DynamicAny_DynArray_set_elements(DynamicAny_DynArray obj,
				      DynamicAny_DynAny_AnySeq *value,
				      CORBA_Environment *ev);

/*
 * These defines create the API for the inherited methods.
 */
#define DynamicAny_DynFixed_type			DynamicAny_DynAny_type
#define DynamicAny_DynFixed_assign			DynamicAny_DynAny_assign
#define DynamicAny_DynFixed_from_any			DynamicAny_DynAny_from_any
#define DynamicAny_DynFixed_to_any			DynamicAny_DynAny_to_any
#define DynamicAny_DynFixed_destroy			DynamicAny_DynAny_destroy
#define DynamicAny_DynFixed_equal			DynamicAny_DynAny_equal 
#define DynamicAny_DynFixed_copy			DynamicAny_DynAny_copy
#define DynamicAny_DynFixed_insert_boolean		DynamicAny_DynAny_insert_boolean
#define DynamicAny_DynFixed_insert_octet		DynamicAny_DynAny_insert_octet
#define DynamicAny_DynFixed_insert_char			DynamicAny_DynAny_insert_char
#define DynamicAny_DynFixed_insert_short		DynamicAny_DynAny_insert_short
#define DynamicAny_DynFixed_insert_ushort		DynamicAny_DynAny_insert_ushort
#define DynamicAny_DynFixed_insert_long			DynamicAny_DynAny_insert_long
#define DynamicAny_DynFixed_insert_ulong		DynamicAny_DynAny_insert_ulong
#define DynamicAny_DynFixed_insert_float		DynamicAny_DynAny_insert_float
#define DynamicAny_DynFixed_insert_double		DynamicAny_DynAny_insert_double
#define DynamicAny_DynFixed_insert_string		DynamicAny_DynAny_insert_string
#define DynamicAny_DynFixed_insert_reference		DynamicAny_DynAny_insert_reference
#define DynamicAny_DynFixed_insert_typecode		DynamicAny_DynAny_insert_typecode
#define DynamicAny_DynFixed_insert_longlong		DynamicAny_DynAny_insert_longlong
#define DynamicAny_DynFixed_insert_ulonglong		DynamicAny_DynAny_insert_ulonglong
#define DynamicAny_DynFixed_insert_longdouble		DynamicAny_DynAny_insert_longdouble
#define DynamicAny_DynFixed_insert_wchar		DynamicAny_DynAny_insert_wchar
#define DynamicAny_DynFixed_insert_wstring		DynamicAny_DynAny_insert_wstring
#define DynamicAny_DynFixed_insert_any			DynamicAny_DynAny_insert_any
#define DynamicAny_DynFixed_get_boolean			DynamicAny_DynAny_get_boolean
#define DynamicAny_DynFixed_get_octet			DynamicAny_DynAny_get_octet
#define DynamicAny_DynFixed_get_char			DynamicAny_DynAny_get_char
#define DynamicAny_DynFixed_get_short			DynamicAny_DynAny_get_short
#define DynamicAny_DynFixed_get_ushort			DynamicAny_DynAny_get_ushort
#define DynamicAny_DynFixed_get_long			DynamicAny_DynAny_get_long
#define DynamicAny_DynFixed_get_ulong			DynamicAny_DynAny_get_ulong
#define DynamicAny_DynFixed_get_float			DynamicAny_DynAny_get_float
#define DynamicAny_DynFixed_get_double			DynamicAny_DynAny_get_double
#define DynamicAny_DynFixed_get_string			DynamicAny_DynAny_get_string
#define DynamicAny_DynFixed_get_reference		DynamicAny_DynAny_get_reference
#define DynamicAny_DynFixed_get_typecode		DynamicAny_DynAny_get_typecode
#define DynamicAny_DynFixed_get_longlong		DynamicAny_DynAny_get_longlong
#define DynamicAny_DynFixed_get_ulonglong		DynamicAny_DynAny_get_ulonglong
#define DynamicAny_DynFixed_get_longdouble		DynamicAny_DynAny_get_longdouble
#define DynamicAny_DynFixed_get_wchar			DynamicAny_DynAny_get_wchar
#define DynamicAny_DynFixed_get_wstring			DynamicAny_DynAny_get_wstring
#define DynamicAny_DynFixed_get_any			DynamicAny_DynAny_get_any
#define DynamicAny_DynFixed_component_count		DynamicAny_DynAny_component_count 
#define DynamicAny_DynFixed_current_component		DynamicAny_DynAny_current_component
#define DynamicAny_DynFixed_next			DynamicAny_DynAny_next
#define DynamicAny_DynFixed_seek			DynamicAny_DynAny_seek
#define DynamicAny_DynFixed_rewind			DynamicAny_DynAny_rewind


#define DynamicAny_DynEnum_type				DynamicAny_DynAny_type
#define DynamicAny_DynEnum_assign			DynamicAny_DynAny_assign
#define DynamicAny_DynEnum_from_any			DynamicAny_DynAny_from_any
#define DynamicAny_DynEnum_to_any			DynamicAny_DynAny_to_any
#define DynamicAny_DynEnum_destroy			DynamicAny_DynAny_destroy
#define DynamicAny_DynEnum_equal			DynamicAny_DynAny_equal 
#define DynamicAny_DynEnum_copy				DynamicAny_DynAny_copy
#define DynamicAny_DynEnum_insert_boolean		DynamicAny_DynAny_insert_boolean
#define DynamicAny_DynEnum_insert_octet			DynamicAny_DynAny_insert_octet
#define DynamicAny_DynEnum_insert_char			DynamicAny_DynAny_insert_char
#define DynamicAny_DynEnum_insert_short			DynamicAny_DynAny_insert_short
#define DynamicAny_DynEnum_insert_ushort		DynamicAny_DynAny_insert_ushort
#define DynamicAny_DynEnum_insert_long			DynamicAny_DynAny_insert_long
#define DynamicAny_DynEnum_insert_ulong			DynamicAny_DynAny_insert_ulong
#define DynamicAny_DynEnum_insert_float			DynamicAny_DynAny_insert_float
#define DynamicAny_DynEnum_insert_double		DynamicAny_DynAny_insert_double
#define DynamicAny_DynEnum_insert_string		DynamicAny_DynAny_insert_string
#define DynamicAny_DynEnum_insert_reference		DynamicAny_DynAny_insert_reference
#define DynamicAny_DynEnum_insert_typecode		DynamicAny_DynAny_insert_typecode
#define DynamicAny_DynEnum_insert_longlong		DynamicAny_DynAny_insert_longlong
#define DynamicAny_DynEnum_insert_ulonglong		DynamicAny_DynAny_insert_ulonglong
#define DynamicAny_DynEnum_insert_longdouble		DynamicAny_DynAny_insert_longdouble
#define DynamicAny_DynEnum_insert_wchar			DynamicAny_DynAny_insert_wchar
#define DynamicAny_DynEnum_insert_wstring		DynamicAny_DynAny_insert_wstring
#define DynamicAny_DynEnum_insert_any			DynamicAny_DynAny_insert_any
#define DynamicAny_DynEnum_get_boolean			DynamicAny_DynAny_get_boolean
#define DynamicAny_DynEnum_get_octet			DynamicAny_DynAny_get_octet
#define DynamicAny_DynEnum_get_char			DynamicAny_DynAny_get_char
#define DynamicAny_DynEnum_get_short			DynamicAny_DynAny_get_short
#define DynamicAny_DynEnum_get_ushort			DynamicAny_DynAny_get_ushort
#define DynamicAny_DynEnum_get_long			DynamicAny_DynAny_get_long
#define DynamicAny_DynEnum_get_ulong			DynamicAny_DynAny_get_ulong
#define DynamicAny_DynEnum_get_float			DynamicAny_DynAny_get_float
#define DynamicAny_DynEnum_get_double			DynamicAny_DynAny_get_double
#define DynamicAny_DynEnum_get_string			DynamicAny_DynAny_get_string
#define DynamicAny_DynEnum_get_reference		DynamicAny_DynAny_get_reference
#define DynamicAny_DynEnum_get_typecode			DynamicAny_DynAny_get_typecode
#define DynamicAny_DynEnum_get_longlong			DynamicAny_DynAny_get_longlong
#define DynamicAny_DynEnum_get_ulonglong		DynamicAny_DynAny_get_ulonglong
#define DynamicAny_DynEnum_get_longdouble		DynamicAny_DynAny_get_longdouble
#define DynamicAny_DynEnum_get_wchar			DynamicAny_DynAny_get_wchar
#define DynamicAny_DynEnum_get_wstring			DynamicAny_DynAny_get_wstring
#define DynamicAny_DynEnum_get_any			DynamicAny_DynAny_get_any
#define DynamicAny_DynEnum_component_count		DynamicAny_DynAny_component_count 
#define DynamicAny_DynEnum_current_component		DynamicAny_DynAny_current_component
#define DynamicAny_DynEnum_next				DynamicAny_DynAny_next
#define DynamicAny_DynEnum_seek				DynamicAny_DynAny_seek
#define DynamicAny_DynEnum_rewind			DynamicAny_DynAny_rewind

#define DynamicAny_DynStruct_type			DynamicAny_DynAny_type
#define DynamicAny_DynStruct_assign			DynamicAny_DynAny_assign
#define DynamicAny_DynStruct_from_any			DynamicAny_DynAny_from_any
#define DynamicAny_DynStruct_to_any			DynamicAny_DynAny_to_any
#define DynamicAny_DynStruct_destroy			DynamicAny_DynAny_destroy
#define DynamicAny_DynStruct_equal			DynamicAny_DynAny_equal 
#define DynamicAny_DynStruct_copy			DynamicAny_DynAny_copy
#define DynamicAny_DynStruct_insert_boolean		DynamicAny_DynAny_insert_boolean
#define DynamicAny_DynStruct_insert_octet		DynamicAny_DynAny_insert_octet
#define DynamicAny_DynStruct_insert_char		DynamicAny_DynAny_insert_char
#define DynamicAny_DynStruct_insert_short		DynamicAny_DynAny_insert_short
#define DynamicAny_DynStruct_insert_ushort		DynamicAny_DynAny_insert_ushort
#define DynamicAny_DynStruct_insert_long		DynamicAny_DynAny_insert_long
#define DynamicAny_DynStruct_insert_ulong		DynamicAny_DynAny_insert_ulong
#define DynamicAny_DynStruct_insert_float		DynamicAny_DynAny_insert_float
#define DynamicAny_DynStruct_insert_double		DynamicAny_DynAny_insert_double
#define DynamicAny_DynStruct_insert_string		DynamicAny_DynAny_insert_string
#define DynamicAny_DynStruct_insert_reference		DynamicAny_DynAny_insert_reference
#define DynamicAny_DynStruct_insert_typecode		DynamicAny_DynAny_insert_typecode
#define DynamicAny_DynStruct_insert_longlong		DynamicAny_DynAny_insert_longlong
#define DynamicAny_DynStruct_insert_ulonglong		DynamicAny_DynAny_insert_ulonglong
#define DynamicAny_DynStruct_insert_longdouble		DynamicAny_DynAny_insert_longdouble
#define DynamicAny_DynStruct_insert_wchar		DynamicAny_DynAny_insert_wchar
#define DynamicAny_DynStruct_insert_wstring		DynamicAny_DynAny_insert_wstring
#define DynamicAny_DynStruct_insert_any			DynamicAny_DynAny_insert_any
#define DynamicAny_DynStruct_get_boolean		DynamicAny_DynAny_get_boolean
#define DynamicAny_DynStruct_get_octet			DynamicAny_DynAny_get_octet
#define DynamicAny_DynStruct_get_char			DynamicAny_DynAny_get_char
#define DynamicAny_DynStruct_get_short			DynamicAny_DynAny_get_short
#define DynamicAny_DynStruct_get_ushort			DynamicAny_DynAny_get_ushort
#define DynamicAny_DynStruct_get_long			DynamicAny_DynAny_get_long
#define DynamicAny_DynStruct_get_ulong			DynamicAny_DynAny_get_ulong
#define DynamicAny_DynStruct_get_float			DynamicAny_DynAny_get_float
#define DynamicAny_DynStruct_get_double			DynamicAny_DynAny_get_double
#define DynamicAny_DynStruct_get_string			DynamicAny_DynAny_get_string
#define DynamicAny_DynStruct_get_reference		DynamicAny_DynAny_get_reference
#define DynamicAny_DynStruct_get_typecode		DynamicAny_DynAny_get_typecode
#define DynamicAny_DynStruct_get_longlong		DynamicAny_DynAny_get_longlong
#define DynamicAny_DynStruct_get_ulonglong		DynamicAny_DynAny_get_ulonglong
#define DynamicAny_DynStruct_get_longdouble		DynamicAny_DynAny_get_longdouble
#define DynamicAny_DynStruct_get_wchar			DynamicAny_DynAny_get_wchar
#define DynamicAny_DynStruct_get_wstring		DynamicAny_DynAny_get_wstring
#define DynamicAny_DynStruct_get_any			DynamicAny_DynAny_get_any
#define DynamicAny_DynStruct_component_count		DynamicAny_DynAny_component_count 
#define DynamicAny_DynStruct_current_component		DynamicAny_DynAny_current_component
#define DynamicAny_DynStruct_next			DynamicAny_DynAny_next
#define DynamicAny_DynStruct_seek			DynamicAny_DynAny_seek
#define DynamicAny_DynStruct_rewind			DynamicAny_DynAny_rewind

#define DynamicAny_DynUnion_type			DynamicAny_DynAny_type
#define DynamicAny_DynUnion_assign			DynamicAny_DynAny_assign
#define DynamicAny_DynUnion_from_any			DynamicAny_DynAny_from_any
#define DynamicAny_DynUnion_to_any			DynamicAny_DynAny_to_any
#define DynamicAny_DynUnion_destroy			DynamicAny_DynAny_destroy
#define DynamicAny_DynUnion_equal			DynamicAny_DynAny_equal 
#define DynamicAny_DynUnion_copy			DynamicAny_DynAny_copy
#define DynamicAny_DynUnion_insert_boolean		DynamicAny_DynAny_insert_boolean
#define DynamicAny_DynUnion_insert_octet		DynamicAny_DynAny_insert_octet
#define DynamicAny_DynUnion_insert_char			DynamicAny_DynAny_insert_char
#define DynamicAny_DynUnion_insert_short		DynamicAny_DynAny_insert_short
#define DynamicAny_DynUnion_insert_ushort		DynamicAny_DynAny_insert_ushort
#define DynamicAny_DynUnion_insert_long			DynamicAny_DynAny_insert_long
#define DynamicAny_DynUnion_insert_ulong		DynamicAny_DynAny_insert_ulong
#define DynamicAny_DynUnion_insert_float		DynamicAny_DynAny_insert_float
#define DynamicAny_DynUnion_insert_double		DynamicAny_DynAny_insert_double
#define DynamicAny_DynUnion_insert_string		DynamicAny_DynAny_insert_string
#define DynamicAny_DynUnion_insert_reference		DynamicAny_DynAny_insert_reference
#define DynamicAny_DynUnion_insert_typecode		DynamicAny_DynAny_insert_typecode
#define DynamicAny_DynUnion_insert_longlong		DynamicAny_DynAny_insert_longlong
#define DynamicAny_DynUnion_insert_ulonglong		DynamicAny_DynAny_insert_ulonglong
#define DynamicAny_DynUnion_insert_longdouble		DynamicAny_DynAny_insert_longdouble
#define DynamicAny_DynUnion_insert_wchar		DynamicAny_DynAny_insert_wchar
#define DynamicAny_DynUnion_insert_wstring		DynamicAny_DynAny_insert_wstring
#define DynamicAny_DynUnion_insert_any			DynamicAny_DynAny_insert_any
#define DynamicAny_DynUnion_get_boolean			DynamicAny_DynAny_get_boolean
#define DynamicAny_DynUnion_get_octet			DynamicAny_DynAny_get_octet
#define DynamicAny_DynUnion_get_char			DynamicAny_DynAny_get_char
#define DynamicAny_DynUnion_get_short			DynamicAny_DynAny_get_short
#define DynamicAny_DynUnion_get_ushort			DynamicAny_DynAny_get_ushort
#define DynamicAny_DynUnion_get_long			DynamicAny_DynAny_get_long
#define DynamicAny_DynUnion_get_ulong			DynamicAny_DynAny_get_ulong
#define DynamicAny_DynUnion_get_float			DynamicAny_DynAny_get_float
#define DynamicAny_DynUnion_get_double			DynamicAny_DynAny_get_double
#define DynamicAny_DynUnion_get_string			DynamicAny_DynAny_get_string
#define DynamicAny_DynUnion_get_reference		DynamicAny_DynAny_get_reference
#define DynamicAny_DynUnion_get_typecode		DynamicAny_DynAny_get_typecode
#define DynamicAny_DynUnion_get_longlong		DynamicAny_DynAny_get_longlong
#define DynamicAny_DynUnion_get_ulonglong		DynamicAny_DynAny_get_ulonglong
#define DynamicAny_DynUnion_get_longdouble		DynamicAny_DynAny_get_longdouble
#define DynamicAny_DynUnion_get_wchar			DynamicAny_DynAny_get_wchar
#define DynamicAny_DynUnion_get_wstring			DynamicAny_DynAny_get_wstring
#define DynamicAny_DynUnion_get_any			DynamicAny_DynAny_get_any
#define DynamicAny_DynUnion_component_count		DynamicAny_DynAny_component_count 
#define DynamicAny_DynUnion_current_component		DynamicAny_DynAny_current_component
#define DynamicAny_DynUnion_next			DynamicAny_DynAny_next
#define DynamicAny_DynUnion_seek			DynamicAny_DynAny_seek
#define DynamicAny_DynUnion_rewind			DynamicAny_DynAny_rewind

#define DynamicAny_DynSequence_type			DynamicAny_DynAny_type
#define DynamicAny_DynSequence_assign			DynamicAny_DynAny_assign
#define DynamicAny_DynSequence_from_any			DynamicAny_DynAny_from_any
#define DynamicAny_DynSequence_to_any			DynamicAny_DynAny_to_any
#define DynamicAny_DynSequence_destroy			DynamicAny_DynAny_destroy
#define DynamicAny_DynSequence_equal			DynamicAny_DynAny_equal 
#define DynamicAny_DynSequence_copy			DynamicAny_DynAny_copy
#define DynamicAny_DynSequence_insert_boolean		DynamicAny_DynAny_insert_boolean
#define DynamicAny_DynSequence_insert_octet		DynamicAny_DynAny_insert_octet
#define DynamicAny_DynSequence_insert_char		DynamicAny_DynAny_insert_char
#define DynamicAny_DynSequence_insert_short		DynamicAny_DynAny_insert_short
#define DynamicAny_DynSequence_insert_ushort		DynamicAny_DynAny_insert_ushort
#define DynamicAny_DynSequence_insert_long		DynamicAny_DynAny_insert_long
#define DynamicAny_DynSequence_insert_ulong		DynamicAny_DynAny_insert_ulong
#define DynamicAny_DynSequence_insert_float		DynamicAny_DynAny_insert_float
#define DynamicAny_DynSequence_insert_double		DynamicAny_DynAny_insert_double
#define DynamicAny_DynSequence_insert_string		DynamicAny_DynAny_insert_string
#define DynamicAny_DynSequence_insert_reference		DynamicAny_DynAny_insert_reference
#define DynamicAny_DynSequence_insert_typecode		DynamicAny_DynAny_insert_typecode
#define DynamicAny_DynSequence_insert_longlong		DynamicAny_DynAny_insert_longlong
#define DynamicAny_DynSequence_insert_ulonglong		DynamicAny_DynAny_insert_ulonglong
#define DynamicAny_DynSequence_insert_longdouble	DynamicAny_DynAny_insert_longdouble
#define DynamicAny_DynSequence_insert_wchar		DynamicAny_DynAny_insert_wchar
#define DynamicAny_DynSequence_insert_wstring		DynamicAny_DynAny_insert_wstring
#define DynamicAny_DynSequence_insert_any		DynamicAny_DynAny_insert_any
#define DynamicAny_DynSequence_get_boolean		DynamicAny_DynAny_get_boolean
#define DynamicAny_DynSequence_get_octet		DynamicAny_DynAny_get_octet
#define DynamicAny_DynSequence_get_char			DynamicAny_DynAny_get_char
#define DynamicAny_DynSequence_get_short		DynamicAny_DynAny_get_short
#define DynamicAny_DynSequence_get_ushort		DynamicAny_DynAny_get_ushort
#define DynamicAny_DynSequence_get_long			DynamicAny_DynAny_get_long
#define DynamicAny_DynSequence_get_ulong		DynamicAny_DynAny_get_ulong
#define DynamicAny_DynSequence_get_float		DynamicAny_DynAny_get_float
#define DynamicAny_DynSequence_get_double		DynamicAny_DynAny_get_double
#define DynamicAny_DynSequence_get_string		DynamicAny_DynAny_get_string
#define DynamicAny_DynSequence_get_reference		DynamicAny_DynAny_get_reference
#define DynamicAny_DynSequence_get_typecode		DynamicAny_DynAny_get_typecode
#define DynamicAny_DynSequence_get_longlong		DynamicAny_DynAny_get_longlong
#define DynamicAny_DynSequence_get_ulonglong		DynamicAny_DynAny_get_ulonglong
#define DynamicAny_DynSequence_get_longdouble		DynamicAny_DynAny_get_longdouble
#define DynamicAny_DynSequence_get_wchar		DynamicAny_DynAny_get_wchar
#define DynamicAny_DynSequence_get_wstring		DynamicAny_DynAny_get_wstring
#define DynamicAny_DynSequence_get_any			DynamicAny_DynAny_get_any
#define DynamicAny_DynSequence_component_count		DynamicAny_DynAny_component_count 
#define DynamicAny_DynSequence_current_component	DynamicAny_DynAny_current_component
#define DynamicAny_DynSequence_next			DynamicAny_DynAny_next
#define DynamicAny_DynSequence_seek			DynamicAny_DynAny_seek
#define DynamicAny_DynSequence_rewind			DynamicAny_DynAny_rewind

#define DynamicAny_DynArray_type			DynamicAny_DynAny_type
#define DynamicAny_DynArray_assign			DynamicAny_DynAny_assign
#define DynamicAny_DynArray_from_any			DynamicAny_DynAny_from_any
#define DynamicAny_DynArray_to_any			DynamicAny_DynAny_to_any
#define DynamicAny_DynArray_destroy			DynamicAny_DynAny_destroy
#define DynamicAny_DynArray_equal			DynamicAny_DynAny_equal 
#define DynamicAny_DynArray_copy			DynamicAny_DynAny_copy
#define DynamicAny_DynArray_insert_boolean		DynamicAny_DynAny_insert_boolean
#define DynamicAny_DynArray_insert_octet		DynamicAny_DynAny_insert_octet
#define DynamicAny_DynArray_insert_char			DynamicAny_DynAny_insert_char
#define DynamicAny_DynArray_insert_short		DynamicAny_DynAny_insert_short
#define DynamicAny_DynArray_insert_ushort		DynamicAny_DynAny_insert_ushort
#define DynamicAny_DynArray_insert_long			DynamicAny_DynAny_insert_long
#define DynamicAny_DynArray_insert_ulong		DynamicAny_DynAny_insert_ulong
#define DynamicAny_DynArray_insert_float		DynamicAny_DynAny_insert_float
#define DynamicAny_DynArray_insert_double		DynamicAny_DynAny_insert_double
#define DynamicAny_DynArray_insert_string		DynamicAny_DynAny_insert_string
#define DynamicAny_DynArray_insert_reference		DynamicAny_DynAny_insert_reference
#define DynamicAny_DynArray_insert_typecode		DynamicAny_DynAny_insert_typecode
#define DynamicAny_DynArray_insert_longlong		DynamicAny_DynAny_insert_longlong
#define DynamicAny_DynArray_insert_ulonglong		DynamicAny_DynAny_insert_ulonglong
#define DynamicAny_DynArray_insert_longdouble		DynamicAny_DynAny_insert_longdouble
#define DynamicAny_DynArray_insert_wchar		DynamicAny_DynAny_insert_wchar
#define DynamicAny_DynArray_insert_wstring		DynamicAny_DynAny_insert_wstring
#define DynamicAny_DynArray_insert_any			DynamicAny_DynAny_insert_any
#define DynamicAny_DynArray_get_boolean			DynamicAny_DynAny_get_boolean
#define DynamicAny_DynArray_get_octet			DynamicAny_DynAny_get_octet
#define DynamicAny_DynArray_get_char			DynamicAny_DynAny_get_char
#define DynamicAny_DynArray_get_short			DynamicAny_DynAny_get_short
#define DynamicAny_DynArray_get_ushort			DynamicAny_DynAny_get_ushort
#define DynamicAny_DynArray_get_long			DynamicAny_DynAny_get_long
#define DynamicAny_DynArray_get_ulong			DynamicAny_DynAny_get_ulong
#define DynamicAny_DynArray_get_float			DynamicAny_DynAny_get_float
#define DynamicAny_DynArray_get_double			DynamicAny_DynAny_get_double
#define DynamicAny_DynArray_get_string			DynamicAny_DynAny_get_string
#define DynamicAny_DynArray_get_reference		DynamicAny_DynAny_get_reference
#define DynamicAny_DynArray_get_typecode		DynamicAny_DynAny_get_typecode
#define DynamicAny_DynArray_get_longlong		DynamicAny_DynAny_get_longlong
#define DynamicAny_DynArray_get_ulonglong		DynamicAny_DynAny_get_ulonglong
#define DynamicAny_DynArray_get_longdouble		DynamicAny_DynAny_get_longdouble
#define DynamicAny_DynArray_get_wchar			DynamicAny_DynAny_get_wchar
#define DynamicAny_DynArray_get_wstring			DynamicAny_DynAny_get_wstring
#define DynamicAny_DynArray_get_any			DynamicAny_DynAny_get_any
#define DynamicAny_DynArray_component_count		DynamicAny_DynAny_component_count 
#define DynamicAny_DynArray_current_component		DynamicAny_DynAny_current_component
#define DynamicAny_DynArray_next			DynamicAny_DynAny_next
#define DynamicAny_DynArray_seek			DynamicAny_DynAny_seek
#define DynamicAny_DynArray_rewind			DynamicAny_DynAny_rewind

#endif /* !_ORBIT_DYNANY_H_ */
