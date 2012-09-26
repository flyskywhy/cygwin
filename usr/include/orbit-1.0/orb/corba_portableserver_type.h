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

#ifndef _ORBIT_CORBA_PORTABLESERVER_TYPE_H_
#define _ORBIT_CORBA_PORTABLESERVER_TYPE_H_

/* 19.26 */

typedef void *PortableServer_ServantLocator_Cookie;
typedef void *PortableServer_Servant;

#ifndef _PortableServer_ForwardRequest_defined
#define _PortableServer_ForwardRequest_defined

typedef struct PortableServer_ForwardRequest {
   CORBA_Object forward_reference;
} PortableServer_ForwardRequest;

#define ex_PortableServer_ForwardRequest "IDL:PortableServer/ForwardRequest:1.0"
#endif /* !_PortableServer_ForwardRequest_defined */

#define PortableServer_THREAD_POLICY_ID 16
struct PortableServer_ThreadPolicy_type {
	struct CORBA_Policy_type corba_policy;
	PortableServer_ThreadPolicyValue value;
};

#define PortableServer_LIFESPAN_POLICY_ID 17
extern const CORBA_PolicyType PortableServer_LifespanPolicy_PolicyType;
struct PortableServer_LifespanPolicy_type {
	struct CORBA_Policy_type corba_policy;
	PortableServer_LifespanPolicyValue value;
};

#define PortableServer_ID_UNIQUENESS_POLICY_ID 18
struct PortableServer_IdUniquenessPolicy_type {
	struct CORBA_Policy_type corba_policy;
	PortableServer_IdUniquenessPolicyValue value;
};

#define PortableServer_ID_ASSIGNMENT_POLICY_ID 19
struct PortableServer_IdAssignmentPolicy_type {
	struct CORBA_Policy_type corba_policy;
	PortableServer_IdAssignmentPolicyValue value;
};

#define PortableServer_IMPLICIT_ACTIVATION_POLICY_ID 20
struct PortableServer_ImplicitActivationPolicy_type {
	struct CORBA_Policy_type corba_policy;
	PortableServer_ImplicitActivationPolicyValue value;
};

#define PortableServer_SERVANT_RETENTION_POLICY_ID 21
struct PortableServer_ServantRetentionPolicy_type {
	struct CORBA_Policy_type corba_policy;
	PortableServer_ServantRetentionPolicyValue value;
};

#define PortableServer_REQUEST_PROCESSING_POLICY_ID 22
struct PortableServer_RequestProcessingPolicy_type {
	struct CORBA_Policy_type corba_policy;
	PortableServer_RequestProcessingPolicyValue value;
};

#ifndef _PortableServer_POAManager_AdapterInactive_defined
#define _PortableServer_POAManager_AdapterInactive_defined

typedef struct PortableServer_POAManager_AdapterInactive {
	int fill_me_in;
} PortableServer_POAManager_AdapterInactive;

#define ex_PortableServer_POAManager_AdapterInactive "IDL:PortableServer/POAManager/AdapterInactive:1.0"
#endif /* !_PortableServer_POAManager_AdapterInactive_defined */

typedef enum { PortableServer_POAManager_HOLDING,
	       PortableServer_POAManager_ACTIVE,
	       PortableServer_POAManager_DISCARDING,
	       PortableServer_POAManager_INACTIVE
} PortableServer_POAManager_State;

struct PortableServer_POAManager_type {
	struct ORBit_PseudoObject_struct parent;
	GSList* poa_collection;
	CORBA_ORB orb;
	PortableServer_POAManager_State state;
};

struct PortableServer_AdapterActivator_type {
	int fill_me_in;
};

struct PortableServer_ServantManager_type {
	int fill_me_in;
};

#ifndef _PortableServer_POA_AdapterAlreadyExists_defined
#define _PortableServer_POA_AdapterAlreadyExists_defined

typedef struct PortableServer_POA_AdapterAlreadyExists {
	int fill_me_in;
} PortableServer_POA_AdapterAlreadyExists;

#define ex_PortableServer_POA_AdapterAlreadyExists "IDL:PortableServer/POA/AdapterAlreadyExists:1.0"
#endif /* !_PortableServer_POA_AdapterAlreadyExists_defined */

#ifndef _PortableServer_POAManager_AdapterInactive_defined
#define _PortableServer_POAManager_AdapterInactive_defined

typedef struct PortableServer_POAManager_AdapterInactive {
	int fill_me_in;
} PortableServer_POAManager_AdapterInactive;

#define ex_PortableServer_POAManager_AdapterInactive "IDL:PortableServer/POAManager/AdapterInactive:1.0"
#endif /* !_PortableServer_POAManager_AdapterInactive_defined */

#ifndef _PortableServer_POA_AdapterNonExistent_defined
#define _PortableServer_POA_AdapterNonExistent_defined

typedef struct PortableServer_POA_AdapterNonExistent {
	int fill_me_in;
} PortableServer_POA_AdapterNonExistent;

#define ex_PortableServer_POA_AdapterNonExistent "IDL:PortableServer/POA/AdapterNonExistent:1.0"
#endif /* !_PortableServer_POA_AdapterNonExistent_defined */

#ifndef _PortableServer_POA_InvalidPolicy_defined
#define _PortableServer_POA_InvalidPolicy_defined

typedef struct PortableServer_POA_InvalidPolicy {
   CORBA_unsigned_short index;
} PortableServer_POA_InvalidPolicy;

#define ex_PortableServer_POA_InvalidPolicy "IDL:PortableServer/POA/InvalidPolicy:1.0"
#endif /* !_PortableServer_POA_InvalidPolicy_defined */

#ifndef _PortableServer_POA_NoServant_defined
#define _PortableServer_POA_NoServant_defined

typedef struct PortableServer_POA_NoServant {
	int fill_me_in;
} PortableServer_POA_NoServant;

#define ex_PortableServer_POA_NoServant "IDL:PortableServer/POA/NoServant:1.0"
#endif /* !_PortableServer_POA_NoServant_defined */

#ifndef _PortableServer_POA_ObjectAlreadyActive_defined
#define _PortableServer_POA_ObjectAlreadyActive_defined

typedef struct PortableServer_POA_ObjectAlreadyActive {
	int fill_me_in;
} PortableServer_POA_ObjectAlreadyActive;

#define ex_PortableServer_POA_ObjectAlreadyActive "IDL:PortableServer/POA/ObjectAlreadyActive:1.0"
#endif /* !_PortableServer_POA_ObjectAlreadyActive_defined */

#ifndef _PortableServer_POA_ObjectNotActive_defined
#define _PortableServer_POA_ObjectNotActive_defined

typedef struct PortableServer_POA_ObjectNotActive {
	int fill_me_in;
} PortableServer_POA_ObjectNotActive;

#define ex_PortableServer_POA_ObjectNotActive "IDL:PortableServer/POA/ObjectNotActive:1.0"
#endif /* !_PortableServer_POA_ObjectNotActive_defined */

#ifndef _PortableServer_POA_ServantAlreadyActive_defined
#define _PortableServer_POA_ServantAlreadyActive_defined

typedef struct PortableServer_POA_ServantAlreadyActive {
	int fill_me_in;
} PortableServer_POA_ServantAlreadyActive;

#define ex_PortableServer_POA_ServantAlreadyActive "IDL:PortableServer/POA/ServantAlreadyActive:1.0"
#endif /* !_PortableServer_POA_ServantAlreadyActive_defined */

#ifndef _PortableServer_POA_ServantNotActive_defined
#define _PortableServer_POA_ServantNotActive_defined

typedef struct PortableServer_POA_ServantNotActive {
	int fill_me_in;
} PortableServer_POA_ServantNotActive;

#define ex_PortableServer_POA_ServantNotActive "IDL:PortableServer/POA/ServantNotActive:1.0"
#endif /* !_PortableServer_POA_ServantNotActive_defined */

#ifndef _PortableServer_POA_WrongAdapter_defined
#define _PortableServer_POA_WrongAdapter_defined

typedef struct PortableServer_POA_WrongAdapter {
	int fill_me_in;
} PortableServer_POA_WrongAdapter;

#define ex_PortableServer_POA_WrongAdapter "IDL:PortableServer/POA/WrongAdapter:1.0"
#endif /* !_PortableServer_POA_WrongAdapter_defined */

#ifndef _PortableServer_POA_WrongPolicy_defined
#define _PortableServer_POA_WrongPolicy_defined

typedef struct PortableServer_POA_WrongPolicy {
	int fill_me_in;
} PortableServer_POA_WrongPolicy;

#define ex_PortableServer_POA_WrongPolicy "IDL:PortableServer/POA/WrongPolicy:1.0"
#endif /* !_PortableServer_POA_WrongPolicy_defined */

#ifndef _PortableServer_Current_NoContext_defined
#define _PortableServer_Current_NoContext_defined

typedef struct PortableServer_Current_NoContext {
	int fill_me_in;
} PortableServer_Current_NoContext;

#define ex_PortableServer_Current_NoContext "IDL:PortableServer/Current/NoContext:1.0"
#endif /* !_PortableServer_Current_NoContext_defined */

struct PortableServer_Current_type {
	int fill_me_in;
};

typedef struct PortableServer_ServantBase__epv {
	void *_private;
	void (*finalize)(PortableServer_Servant, CORBA_Environment *);
	PortableServer_POA (*default_POA)(PortableServer_Servant, CORBA_Environment *);
} PortableServer_ServantBase__epv;

typedef PortableServer_ServantBase__epv *PortableServer_ServantBase__vepv;

typedef struct PortableServer_ServantBase {
	void *_private;
	PortableServer_ServantBase__vepv *vepv;
} PortableServer_ServantBase;

/* 19.27 */

typedef void (*PortableServer_DynamicImplRoutine) (PortableServer_Servant servant, CORBA_ServerRequest request);

typedef struct PortableServer_DynamicImpl__epv {
	void *_private;
	PortableServer_DynamicImplRoutine invoke;
	CORBA_RepositoryId (*primary_interface) (PortableServer_Servant svt, PortableServer_ObjectId id, PortableServer_POA poa, CORBA_Environment *env);
} PortableServer_DynamicImpl__epv;

typedef struct PortableServer_DynamicImpl__vepv {
	PortableServer_ServantBase__epv *_base_epv;
	PortableServer_DynamicImpl__epv *PortableServer_DynamicImpl_epv;
} PortableServer_DynamicImpl__vepv;

typedef struct PortableServer_DynamicImpl {
	void *_private;
	PortableServer_DynamicImpl__vepv *vepv;
} PortableServer_DynamicImpl;

typedef struct {
   void *_private;
} POA_PortableServer_ServantManager__epv;

typedef struct {
	void *_private;

	PortableServer_Servant (*incarnate) (PortableServer_Servant servant,
					     PortableServer_ObjectId * oid,
					     PortableServer_POA adapter,
					     CORBA_Environment * ev);

	void (*etherealize) (PortableServer_Servant servant,
			     PortableServer_ObjectId* oid,
			     PortableServer_POA adapter,
			     PortableServer_Servant serv,
			     CORBA_boolean cleanup_in_progress,
			     CORBA_boolean remaining_activations,
			     CORBA_Environment * ev);

} POA_PortableServer_ServantActivator__epv;

typedef struct {
   PortableServer_ServantBase__epv *_base_epv;
   POA_PortableServer_ServantManager__epv *PortableServer_ServantManager_epv;
   POA_PortableServer_ServantActivator__epv *PortableServer_ServantActivator_epv;
} POA_PortableServer_ServantActivator__vepv;

typedef struct {
   void *_private;
   POA_PortableServer_ServantActivator__vepv *vepv;
} POA_PortableServer_ServantActivator;

extern void
POA_PortableServer_ServantActivator__init(PortableServer_Servant servant,
					  CORBA_Environment * ev);
extern void
POA_PortableServer_ServantActivator__fini(PortableServer_Servant servant,
					  CORBA_Environment * ev);

typedef struct {
	void *_private;

	PortableServer_Servant (*preinvoke) (PortableServer_Servant servant,
					     PortableServer_ObjectId * oid,
					     PortableServer_POA adapter,
					     CORBA_Identifier operation,
					     PortableServer_ServantLocator_Cookie *the_cookie,
					     CORBA_Environment * ev);

	void (*postinvoke) (PortableServer_Servant servant,
			    PortableServer_ObjectId * oid,
			    PortableServer_POA adapter,
			    CORBA_Identifier operation,
			    PortableServer_ServantLocator_Cookie the_cookie,
			    PortableServer_Servant the_servant,
			    CORBA_Environment * ev);
} POA_PortableServer_ServantLocator__epv;

typedef struct {
   PortableServer_ServantBase__epv *_base_epv;
   POA_PortableServer_ServantManager__epv *PortableServer_ServantManager_epv;
   POA_PortableServer_ServantLocator__epv *PortableServer_ServantLocator_epv;
} POA_PortableServer_ServantLocator__vepv;

typedef struct {
   void *_private;
   POA_PortableServer_ServantLocator__vepv *vepv;
} POA_PortableServer_ServantLocator;

extern void
POA_PortableServer_ServantLocator__init(PortableServer_Servant servant,
					CORBA_Environment * ev);
extern void
POA_PortableServer_ServantLocator__fini(PortableServer_Servant servant,
					CORBA_Environment * ev);

struct CORBA_ServerRequest_type {
	struct ORBit_PseudoObject_struct parent;
	GIOPRecvBuffer *rbuf;
	GIOPSendBuffer *sbuf;
	CORBA_NVList *params;
	CORBA_ORB orb;
	guchar did_ctx, did_exc;
};

#endif /* !_ORBIT_CORBA_PORTABLESERVER_TYPE_H_ */
