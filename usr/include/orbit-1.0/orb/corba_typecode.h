/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
 *  ORBit: A CORBA v2.2 ORB
 *
 *  Copyright (C) 1998 Richard H. Porter
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
 *
 */

#ifndef _ORBIT_CORBA_TYPECODE_H_
#define _ORBIT_CORBA_TYPECODE_H_

/* moved from orbit_types.h */
typedef struct CORBA_TypeCode_struct *CORBA_TypeCode;

typedef enum {
	CORBA_tk_null=0,
	CORBA_tk_void=1,
	CORBA_tk_short=2,
	CORBA_tk_long=3,
	CORBA_tk_ushort=4,
	CORBA_tk_ulong=5,
	CORBA_tk_float=6,
	CORBA_tk_double=7,
	CORBA_tk_boolean=8,
	CORBA_tk_char=9,
	CORBA_tk_octet=10,
	CORBA_tk_any=11,
	CORBA_tk_TypeCode=12,
	CORBA_tk_Principal=13,
	CORBA_tk_objref=14,
 	CORBA_tk_struct=15,
	CORBA_tk_union=16,
	CORBA_tk_enum=17,
	CORBA_tk_string=18,
	CORBA_tk_sequence=19,
	CORBA_tk_array=20,
	CORBA_tk_alias=21,
	CORBA_tk_except=22,
	CORBA_tk_longlong=23,
	CORBA_tk_ulonglong=24,
	CORBA_tk_longdouble=25,
	CORBA_tk_wchar=26,
	CORBA_tk_wstring=27,
	CORBA_tk_fixed=28,
	CORBA_tk_recursive=0xffffffff,
	CORBA_tk_last=29	/* hack for GIOP */
} CORBA_TCKind;

#define TC_CORBA_short TC_short
#define TC_CORBA_long TC_long
#define TC_CORBA_longlong TC_longlong
#define TC_CORBA_long_long TC_longlong
#define TC_CORBA_ushort TC_ushort
#define TC_CORBA_unsigned_short TC_ushort
#define TC_CORBA_ulong TC_ulong
#define TC_CORBA_unsigned_long TC_ulong
#define TC_CORBA_ulonglong TC_ulonglong
#define TC_CORBA_unsigned_long_long TC_ulonglong
#define TC_CORBA_float TC_float
#define TC_CORBA_double TC_double
#define TC_CORBA_longdouble TC_longdouble
#define TC_CORBA_long_double TC_longdouble
#define TC_CORBA_boolean TC_boolean
#define TC_CORBA_char TC_char
#define TC_CORBA_wchar TC_wchar
#define TC_CORBA_octet TC_octet
#define TC_CORBA_any TC_any
#define TC_CORBA_TypeCode TC_TypeCode
#define TC_CORBA_Principal TC_Principal
#define TC_CORBA_Object TC_Object
#define TC_CORBA_string TC_string
#define TC_CORBA_wstring TC_wstring

#define TC_null ((CORBA_TypeCode)&TC_null_struct)
#define TC_void ((CORBA_TypeCode)&TC_void_struct)
#define TC_short ((CORBA_TypeCode)&TC_short_struct)
#define TC_long ((CORBA_TypeCode)&TC_long_struct)
#define TC_longlong ((CORBA_TypeCode)&TC_longlong_struct)
#define TC_ushort ((CORBA_TypeCode)&TC_ushort_struct)
#define TC_ulong ((CORBA_TypeCode)&TC_ulong_struct)
#define TC_ulonglong ((CORBA_TypeCode)&TC_ulonglong_struct)
#define TC_float ((CORBA_TypeCode)&TC_float_struct)
#define TC_double ((CORBA_TypeCode)&TC_double_struct)
#define TC_longdouble ((CORBA_TypeCode)&TC_longdouble_struct)
#define TC_boolean ((CORBA_TypeCode)&TC_boolean_struct)
#define TC_char ((CORBA_TypeCode)&TC_char_struct)
#define TC_wchar ((CORBA_TypeCode)&TC_wchar_struct)
#define TC_octet ((CORBA_TypeCode)&TC_octet_struct)
#define TC_any ((CORBA_TypeCode)&TC_any_struct)
#define TC_TypeCode ((CORBA_TypeCode)&TC_TypeCode_struct)
#define TC_Principal ((CORBA_TypeCode)&TC_Principal_struct)
#define TC_Object ((CORBA_TypeCode)&TC_Object_struct)
#define TC_string ((CORBA_TypeCode)&TC_string_struct)
#define TC_wstring ((CORBA_TypeCode)&TC_wstring_struct)
#define TC_CORBA_NamedValue ((CORBA_TypeCode)&TC_CORBA_NamedValue_struct)

#define TC_CORBA_short_struct TC_short_struct
#define TC_CORBA_long_struct TC_long_struct
#define TC_CORBA_longlong_struct TC_longlong_struct
#define TC_CORBA_long_long_struct TC_longlong_struct
#define TC_CORBA_ushort_struct TC_ushort_struct
#define TC_CORBA_unsigned_short_struct TC_ushort_struct
#define TC_CORBA_ulong_struct TC_ulong_struct
#define TC_CORBA_unsigned_long_struct TC_ulong_struct
#define TC_CORBA_ulonglong_struct TC_ulonglong_struct
#define TC_CORBA_unsigned_long_long_struct TC_ulonglong_struct
#define TC_CORBA_float_struct TC_float_struct
#define TC_CORBA_double_struct TC_double_struct
#define TC_CORBA_longdouble_struct TC_longdouble_struct
#define TC_CORBA_long_double_struct TC_longdouble_struct
#define TC_CORBA_boolean_struct TC_boolean_struct
#define TC_CORBA_char_struct TC_char_struct
#define TC_CORBA_wchar_struct TC_wchar_struct
#define TC_CORBA_octet_struct TC_octet_struct
#define TC_CORBA_any_struct TC_any_struct
#define TC_CORBA_TypeCode_struct TC_TypeCode_struct
#define TC_CORBA_Principal_struct TC_Principal_struct
#define TC_CORBA_Object_struct TC_Object_struct
#define TC_CORBA_string_struct TC_string_struct
#define TC_CORBA_wstring_struct TC_wstring_struct

extern struct CORBA_TypeCode_struct TC_null_struct;
extern struct CORBA_TypeCode_struct TC_void_struct;
extern struct CORBA_TypeCode_struct TC_short_struct;
extern struct CORBA_TypeCode_struct TC_long_struct;
extern struct CORBA_TypeCode_struct TC_longlong_struct;
extern struct CORBA_TypeCode_struct TC_ushort_struct;
extern struct CORBA_TypeCode_struct TC_ulong_struct;
extern struct CORBA_TypeCode_struct TC_ulonglong_struct;
extern struct CORBA_TypeCode_struct TC_float_struct;
extern struct CORBA_TypeCode_struct TC_double_struct;
extern struct CORBA_TypeCode_struct TC_longdouble_struct;
extern struct CORBA_TypeCode_struct TC_boolean_struct;
extern struct CORBA_TypeCode_struct TC_char_struct;
extern struct CORBA_TypeCode_struct TC_wchar_struct;
extern struct CORBA_TypeCode_struct TC_octet_struct;
extern struct CORBA_TypeCode_struct TC_any_struct;
extern struct CORBA_TypeCode_struct TC_TypeCode_struct;
extern struct CORBA_TypeCode_struct TC_Principal_struct;
extern struct CORBA_TypeCode_struct TC_Object_struct;
extern struct CORBA_TypeCode_struct TC_string_struct;
extern struct CORBA_TypeCode_struct TC_wstring_struct;
extern struct CORBA_TypeCode_struct TC_CORBA_NamedValue_struct;


#endif /* !_ORBIT_CORBA_TYPECODE_H_ */




