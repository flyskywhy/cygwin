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

#ifndef _ORBIT_CORBA_TYPECODE_TYPE_H_
#define _ORBIT_CORBA_TYPECODE_TYPE_H_

#include <ORBitutil/basic_types.h>
#include "corba_typecode.h"
#include "corba_any.h"

typedef struct CORBA_TypeCode_Bounds {
	int dummy;
} CORBA_TypeCode_Bounds;

typedef struct CORBA_TypeCode_BadKind {
	int dummy;
} CORBA_TypeCode_BadKind;

struct CORBA_TypeCode_struct {
	struct ORBit_PseudoObject_struct parent;
	CORBA_TCKind kind;
	const char *name;
	const char *repo_id;
	CORBA_unsigned_long length;
	CORBA_unsigned_long sub_parts;
	const char **subnames;		/* for struct, exception, union, enum */
	CORBA_TypeCode *subtypes;	/* for struct, exception, union, alias, array, sequence */
	CORBA_any *sublabels;		/* for union */
	CORBA_TypeCode discriminator;	/* for union */
	CORBA_unsigned_long recurse_depth; /* for recursive sequence */
	CORBA_long default_index;	/* for union */
	CORBA_unsigned_short digits; /* for fixed */
	CORBA_short scale;	     /* for fixed */
};


#endif /* !_ORBIT_CORBA_TYPECODE_TYPE_H_ */

