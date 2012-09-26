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

#ifndef _ORBIT_CORBA_OBJECT_H_
#define _ORBIT_CORBA_OBJECT_H_

#include <ORBitutil/basic_types.h>

#include "corba_env.h"
#include "corba_orb.h"
#include "corba_sequences.h"

#define CORBA_OBJECT_NIL NULL

typedef struct CORBA_Object_struct *CORBA_Object;

#define CORBA_OBJECT(x) ((CORBA_Object)(x))

/* Used for internal stuff mostly, but also good if you want to store
   a hash of objects */
gboolean g_CORBA_Object_equal(CORBA_Object obj1, CORBA_Object obj2);
guint g_CORBA_Object_hash(CORBA_Object obj);

void ORBit_impl_CORBA_Object_is_a(gpointer servant,
				  GIOPRecvBuffer * _ORBIT_recv_buffer,
				  CORBA_Environment *ev, gpointer dummy);
#define ORBIT_IMPLEMENTS_IS_A

extern CORBA_boolean CORBA_Object_is_a(
	CORBA_Object obj,
	CORBA_char *logical_type_id,
	CORBA_Environment *ev);

#endif /* !_ORBIT_CORBA_OBJECT_H_ */



