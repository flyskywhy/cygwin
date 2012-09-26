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

#ifndef _ORBIT_CORBA_ORB_TYPE_H_
#define _ORBIT_CORBA_ORB_TYPE_H_

#include "corba_object.h"

struct CORBA_ORB_type {
	struct ORBit_PseudoObject_struct parent;
	CORBA_ORBid orb_identifier;
	CORBA_RepositoryId repoid;
	CORBA_boolean use_poa;

	CORBA_Object imr, ir, naming, root_poa;
	struct {
		GIOPConnection *ipv4;
		GIOPConnection *ipv6;
		GIOPConnection *usock;
	} cnx;

	GHashTable *objrefs;

	GPtrArray *poas;

	CORBA_Context default_ctx;
};

#define CORBA_ORB_CAST(orb) ((CORBA_ORB)orb)

typedef struct CORBA_ORB_InvalidName {
	int dummy;
} CORBA_ORB_InvalidName;

struct CORBA_Policy_type {
	struct ORBit_PseudoObject_struct parent;
	CORBA_PolicyType policy_type;
};
#ifndef CORBA_POLICY_TYPE
#define CORBA_POLICY_TYPE 1
typedef struct CORBA_Policy_type *CORBA_Policy;
#endif

struct CORBA_DomainManager_type {
	struct ORBit_PseudoObject_struct parent;
};

#define CORBA_SecConstruction (11)

struct CORBA_ConstructionPolicy_type {
	int fill_me_in;
};


#endif /* !_ORBIT_CORBA_ORB_TYPE_H_ */
