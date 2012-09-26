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
 *   ORBit specific POA funcitons.
 *
 */

#ifndef _ORBIT_ORBIT_POA_H_
#define _ORBIT_ORBIT_POA_H_

#include "orbit_types.h"
#include "orbit_poa_type.h"


/*
 * Creates a new POAManager
 */


extern PortableServer_POAManager ORBit_POAManager_new();

extern void ORBit_POAManager_free(PortableServer_POAManager poa_mgr, 
				  CORBA_Environment *ev);

extern PortableServer_POA ORBit_POA_new(CORBA_ORB orb,
					CORBA_char *adapter_name,
					PortableServer_POAManager the_POAManager,
					CORBA_PolicyList *policies,
					CORBA_Environment *ev);

extern void ORBit_POA_free(PortableServer_POA poa, CORBA_Environment *ev);

extern void ORBit_POA_add_child(PortableServer_POA poa,
				PortableServer_POA child_poa,
				CORBA_Environment *ev);
void ORBit_POA_remove_child(PortableServer_POA poa,
			    PortableServer_POA child_poa,
			    CORBA_Environment *ev);

gboolean ORBit_POA_handle_request(GIOPRecvBuffer *recv_buffer,
				  PortableServer_POA poa);
PortableServer_POA
ORBit_POA_find_POA_for_object_key(PortableServer_POA root_poa,
				  CORBA_sequence_octet *key);
void
ORBit_POA_find_object_key_for_oid(PortableServer_POA poa,
				  ORBit_POAObject *obj,
				  PortableServer_ObjectId *oid,
				  CORBA_sequence_octet *retval);
ORBit_POAObject *
ORBit_POA_find_oid_for_object_key(PortableServer_POA poa,
				  CORBA_sequence_octet *object_key,
				  PortableServer_ObjectId **oid);

PortableServer_ObjectId *ORBit_POA_allocate_oid(PortableServer_POA poa,
						const char *basis);

void ORBit_POA_etherealize_objects(PortableServer_POA poa, CORBA_Environment *ev);

#ifdef NOT_BACKWARDS_COMPAT_0_4
/* Bad hack for shared libraries */
void ORBit_servant_set_deathwatch(PortableServer_ServantBase *servant,
				  int *use_count,
				  GFunc death_func,
				  gpointer user_data);
#endif

#endif /* !_ORBIT_ORBIT_POA_H_ */
