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

#ifndef _ORBIT_ORBIT_POA_TYPE_H_
#define _ORBIT_ORBIT_POA_TYPE_H_

typedef void (*ORBitSkeleton)(PortableServer_ServantBase *_ORBIT_servant,
			      gpointer _ORBIT_recv_buffer,
			      CORBA_Environment *ev,
			      gpointer implementation);
typedef ORBitSkeleton (*ORBit_impl_finder)(PortableServer_ServantBase *servant,
				    gpointer _ORBIT_recv_buffer,
				    gpointer *implementation);
typedef void (*ORBit_local_objref_init)(CORBA_Object obj,
					PortableServer_ServantBase *servant);
typedef struct {
	ORBit_impl_finder relay_call;
	const gchar *class_name;
	ORBit_local_objref_init init_local_objref;
} PortableServer_ClassInfo;

#define ORBIT_RAND_KEY_LEN 8

typedef struct {
	PortableServer_ObjectId *object_id;
	PortableServer_Servant servant;
	PortableServer_POA poa;
	CORBA_ORB orb;
	CORBA_unsigned_long objnum;

	/* Stuff for doing shared libraries nicely */
	guchar rand_data[ORBIT_RAND_KEY_LEN];

#ifdef NOT_BACKWARDS_COMPAT_0_4
	int *use_count;
	GFunc death_callback;
	gpointer user_data;
#endif
} ORBit_POAObject;

typedef struct {
	PortableServer_ClassInfo *class_info;
	ORBit_POAObject *object;
} ORBit_ObjectKey;

#define ORBIT_OBJECT_KEY(x) ((ORBit_ObjectKey *)(x))

struct PortableServer_POA_type {
	struct ORBit_PseudoObject_struct parent;

	PortableServer_POA parent_poa;
	CORBA_ORB orb;
	CORBA_unsigned_long poaID;

	GHashTable *active_object_map;
	GPtrArray *objnum_to_obj; /* maps objnums to ORBit_POAObject's */
	CORBA_long first_free_id;

	/* Requests received while in a HOLDING state */
	GSList *held_requests;

	/* this'll be a hash table when I can be arsed to look up 
	   how to implement efficient hash tables  - Phil.*/
	GSList *child_POAs;     
	
	CORBA_char *the_name;
	PortableServer_POAManager the_POAManager;

	PortableServer_AdapterActivator the_activator;

	PortableServer_ServantManager servant_manager;
	PortableServer_Servant default_servant;

	PortableServer_ThreadPolicyValue thread;
	PortableServer_LifespanPolicyValue lifespan;
	PortableServer_IdUniquenessPolicyValue id_uniqueness;
	PortableServer_IdAssignmentPolicyValue id_assignment;
	PortableServer_ImplicitActivationPolicyValue implicit_activation;
	PortableServer_ServantRetentionPolicyValue servant_retention;
	PortableServer_RequestProcessingPolicyValue request_processing;

	guchar rand_data[ORBIT_RAND_KEY_LEN];
};

#endif /* !_ORBIT_ORBIT_POA_TYPE_H_ */
