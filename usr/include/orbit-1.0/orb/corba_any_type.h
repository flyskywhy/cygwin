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
 *  Author: Dick Porter <dick@acm.org>
 *
 */

#ifndef _ORBIT_CORBA_ANY_TYPE_H_
#define _ORBIT_CORBA_ANY_TYPE_H_

#include "corba_any.h"
#include "corba_typecode.h"

struct CORBA_any_type {
	CORBA_TypeCode _type;
	gpointer _value;
	CORBA_boolean _release;
};

typedef struct ORBit_marshal_value_info_struct {
	CORBA_TypeCode alias_element_type;
} ORBit_marshal_value_info;

#define CORBA_ANYFLAGS_RELEASE 1


#endif /* !_ORBIT_CORBA_ANY_TYPE_H_ */



