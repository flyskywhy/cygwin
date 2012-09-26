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

#ifndef _ORBIT_IR_H_
#define _ORBIT_IR_H_

#include "orbit_types.h"

extern CORBA_boolean CORBA_TypeCode_equal(
	CORBA_TypeCode obj,
	CORBA_TypeCode tc,
	CORBA_Environment *ev);

extern CORBA_TCKind CORBA_TypeCode_kind(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_RepositoryId CORBA_TypeCode_id(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_Identifier CORBA_TypeCode_name(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_unsigned_long CORBA_TypeCode_member_count(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_Identifier CORBA_TypeCode_member_name(
	CORBA_TypeCode obj,
	CORBA_unsigned_long index,
	CORBA_Environment *ev);

extern CORBA_TypeCode CORBA_TypeCode_member_type(
	CORBA_TypeCode obj,
	CORBA_unsigned_long index,
	CORBA_Environment *ev);

extern CORBA_any *CORBA_TypeCode_member_label(
	CORBA_TypeCode obj,
	CORBA_unsigned_long index,
	CORBA_Environment *ev);

extern CORBA_TypeCode CORBA_TypeCode_discriminator_type(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_long CORBA_TypeCode_default_index(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_unsigned_long CORBA_TypeCode_length(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_TypeCode CORBA_TypeCode_content_type(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_unsigned_short CORBA_TypeCode_fixed_digits(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_short CORBA_TypeCode_fixed_scale(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_long CORBA_TypeCode_param_count(
	CORBA_TypeCode obj,
	CORBA_Environment *ev);

extern CORBA_any *CORBA_TypeCode_parameter(
	CORBA_TypeCode obj,
	CORBA_long index,
	CORBA_Environment *ev);

#endif /* !_ORBIT_IR_H_ */
