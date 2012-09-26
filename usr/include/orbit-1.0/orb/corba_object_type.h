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

#ifndef _ORBIT_CORBA_OBJECT_TYPE_H_
#define _ORBIT_CORBA_OBJECT_TYPE_H_

#include <sys/uio.h> /* for struct iovec */

#include <IIOP/IIOP.h>	  /* for giop_connection */

#include "corba_object.h"
#include "corba_basic_sequences_type.h"

#include "orbit_object_type.h"

struct CORBA_Object_struct {
	struct ORBit_RootObject_struct parent;
	CORBA_ORB orb;
	GIOPConnection *connection;
	CORBA_char *object_id;
	GSList *profile_list;
	GSList *forward_locations;
	ORBit_Object_info *active_profile;	/* points at a member of profile_list or forward_locations */

	/* Used for direct calls */
	gpointer *vepv;
	/* PortableServer_Servant - looping includes :( */ gpointer servant;
	guint vepv_size;
};


#endif /* !_ORBIT_CORBA_OBJECT_TYPE_H_ */
