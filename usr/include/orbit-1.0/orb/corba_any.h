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

#ifndef _ORBIT_CORBA_ANY_H_
#define _ORBIT_CORBA_ANY_H_

#include "orbit_types.h"
#include "corba_typecode.h"

#include <unistd.h>

typedef struct CORBA_any_type CORBA_any;

size_t ORBit_gather_alloc_info(CORBA_TypeCode tc);
gint ORBit_find_alignment(CORBA_TypeCode tc);
CORBA_TypeCode ORBit_get_union_tag(CORBA_TypeCode union_tc,
				   gpointer *val, gboolean update);
gpointer ORBit_copy_value(gpointer value, CORBA_TypeCode tc);
void _ORBit_copy_value(gpointer *val, gpointer *newval, CORBA_TypeCode tc);

void CORBA_any__copy(CORBA_any *out, CORBA_any *in);

#endif /* !_ORBIT_CORBA_ANY_H_ */
