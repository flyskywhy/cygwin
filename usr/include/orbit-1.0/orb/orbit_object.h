/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
 *  ORBit: A CORBA v2.2 ORB
 *
 *  Copyright (C) 1998 Richard H. Porter and Red Hat Software
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
 *  Author: Phil Dawes <philipd@parallax.co.uk>
 *
 */

/*
 *   ORBit specific CORBA_Object funcitons.
 *
 */
#ifndef _ORBIT_ORBIT_OBJECT_H_
#define _ORBIT_ORBIT_OBJECT_H_

#include <IIOP/IIOP.h>
#include "corba_object.h"

extern CORBA_Object ORBit_CORBA_Object_new(CORBA_Environment *ev);
extern void ORBit_CORBA_Object_free(CORBA_Object obj, CORBA_Environment *ev);


typedef enum {
	ORBIT_PSEUDO_ORB,
	ORBIT_PSEUDO_POA,
	ORBIT_PSEUDO_POAMANAGER,
	ORBIT_PSEUDO_POLICY,
	ORBIT_PSEUDO_TYPECODE,
	ORBIT_PSEUDO_REQUEST,
	ORBIT_PSEUDO_SERVERREQUEST,
	ORBIT_PSEUDO_CONTEXT
} ORBit_PseudoObject_type;
typedef struct ORBit_PseudoObject_struct *ORBit_PseudoObject;

void ORBit_pseudo_object_init(ORBit_PseudoObject obj,
			      ORBit_PseudoObject_type obj_type,
			      CORBA_Environment *ev);
void ORBit_policy_object_init(CORBA_Policy obj,
			      CORBA_PolicyType obj_type,
			      CORBA_Environment *ev);

/* Use ORBit_CORBA_Object_new() */
void ORBit_object_reference_init(CORBA_Object obj, CORBA_Environment *ev);

typedef struct {
	CORBA_char *host;
	CORBA_unsigned_short port;
} TAG_INTERNET_IOP_info;

typedef struct {
	CORBA_char *unix_sock_path;
	CORBA_unsigned_short ipv6_port;
} TAG_ORBIT_SPECIFIC_info;

typedef struct {
	int fill_me_in;
} TAG_MULTIPLE_COMPONENTS_info;

typedef struct {
	CORBA_octet iiop_major, iiop_minor;
	IOP_ProfileId profile_type;
	union {
		TAG_INTERNET_IOP_info iopinfo;
		TAG_ORBIT_SPECIFIC_info orbitinfo;
		TAG_MULTIPLE_COMPONENTS_info mcinfo;
	} tag;

	/* If the object key is invariant wrt to the various profiles, then
	   this should probably go in CORBA_Object_struct
	 */
	CORBA_sequence_octet object_key;
	struct { CORBA_unsigned_long _length; char _buffer[1]; } *object_key_data;
	struct iovec object_key_vec;
} ORBit_Object_info;

void ORBit_set_object_key(ORBit_Object_info *info);

CORBA_Object ORBit_create_object_with_info(GSList *profiles,
					   const CORBA_char *type_id,
					   CORBA_ORB orb,
					   CORBA_Environment *ev);

#define ORBit_object_get_connection(obj) \
     ((obj)->connection && (obj)->connection->is_valid)?((obj)->connection):_ORBit_object_get_connection(obj)
GIOPConnection *_ORBit_object_get_connection(CORBA_Object obj);
GIOPConnection *ORBit_object_get_forwarded_connection(CORBA_Object obj);
void ORBit_object_locate(CORBA_Object obj, CORBA_Environment *ev);

void ORBit_marshal_object(GIOPSendBuffer *send_buffer, CORBA_Object obj);
CORBA_Object ORBit_demarshal_object(GIOPRecvBuffer *recv_buffer,
				    CORBA_ORB orb);
GSList *ORBit_demarshal_IOR(GIOPRecvBuffer *recv_buffer);

extern void ORBit_delete_profiles(GSList *profile_list);
GIOPConnection *ORBit_handle_location_forward(GIOPRecvBuffer *rb, CORBA_Object obj);

#endif /* _ORBIT_ORBIT_OBJECT_H_ */
