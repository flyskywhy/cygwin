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

#ifndef _ORBIT_CORBA_PORTABLESERVER_H_
#define _ORBIT_CORBA_PORTABLESERVER_H_

typedef struct PortableServer_ThreadPolicy_type *PortableServer_ThreadPolicy;
typedef struct PortableServer_LifespanPolicy_type *PortableServer_LifespanPolicy;
typedef struct PortableServer_IdUniquenessPolicy_type *PortableServer_IdUniquenessPolicy;
typedef struct PortableServer_IdAssignmentPolicy_type *PortableServer_IdAssignmentPolicy;
typedef struct PortableServer_ImplicitActivationPolicy_type *PortableServer_ImplicitActivationPolicy;
typedef struct PortableServer_ServantRetentionPolicy_type *PortableServer_ServantRetentionPolicy;
typedef struct PortableServer_RequestProcessingPolicy_type *PortableServer_RequestProcessingPolicy;
typedef struct PortableServer_POAManager_type* PortableServer_POAManager;
typedef struct PortableServer_AdapterActivator_type *PortableServer_AdapterActivator;
typedef struct PortableServer_ServantManager_type *PortableServer_ServantManager;
typedef struct PortableServer_ServantActivator_type *PortableServer_ServantActivator;
typedef struct PortableServer_ServantLocator_type *PortableServer_ServantLocator;
typedef struct PortableServer_POA_type *PortableServer_POA;
typedef struct PortableServer_Current_type *PortableServer_Current;

typedef enum {
	PortableServer_ORB_CTRL_MODEL=0,
	PortableServer_SINGLE_THREAD_MODEL
} PortableServer_ThreadPolicyValue;

typedef enum {
	PortableServer_TRANSIENT=0,
	PortableServer_PERSISTENT
} PortableServer_LifespanPolicyValue;

typedef enum {
	PortableServer_UNIQUE_ID=0,
	PortableServer_MULTIPLE_ID
} PortableServer_IdUniquenessPolicyValue;

typedef enum {
	PortableServer_USER_ID=0,
	PortableServer_SYSTEM_ID
} PortableServer_IdAssignmentPolicyValue;

typedef enum {
	PortableServer_IMPLICIT_ACTIVATION=0,
	PortableServer_NO_IMPLICIT_ACTIVATION
} PortableServer_ImplicitActivationPolicyValue;

typedef enum {
	PortableServer_RETAIN=0,
	PortableServer_NON_RETAIN
} PortableServer_ServantRetentionPolicyValue;

typedef enum {
	PortableServer_USE_ACTIVE_OBJECT_MAP_ONLY=0,
	PortableServer_USE_DEFAULT_SERVANT,
	PortableServer_USE_SERVANT_MANAGER
} PortableServer_RequestProcessingPolicyValue;

#endif /* !_ORBIT_CORBA_PORTABLESERVER_H_ */
