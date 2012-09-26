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

#ifndef _ORBIT_POA_H_
#define _ORBIT_POA_H_

#include "orbit_types.h"

extern PortableServer_ThreadPolicyValue PortableServer_ThreadPolicy__get_value(
	PortableServer_ThreadPolicy obj,
	CORBA_Environment *ev);

extern PortableServer_LifespanPolicyValue PortableServer_LifespanPolicy__get_value(
	PortableServer_LifespanPolicy obj,
	CORBA_Environment *ev);

extern PortableServer_IdUniquenessPolicyValue PortableServer_IdUniquenessPolicy__get_value(
	PortableServer_IdUniquenessPolicy obj,
	CORBA_Environment *ev);

extern PortableServer_IdAssignmentPolicyValue PortableServer_IdAssignmentPolicy__get_value(
	PortableServer_IdAssignmentPolicy obj,
	CORBA_Environment *ev);

extern PortableServer_ImplicitActivationPolicyValue PortableServer_ImplicitActivationPolicy__get_value(
	PortableServer_ImplicitActivationPolicy obj,
	CORBA_Environment *ev);

extern PortableServer_ServantRetentionPolicyValue PortableServer_ServantRetentionPolicy__get_value(
	PortableServer_ServantRetentionPolicy obj,
	CORBA_Environment *ev);

extern PortableServer_RequestProcessingPolicyValue PortableServer_RequestProcessingPolicy__get_value(
	PortableServer_RequestProcessingPolicy obj,
	CORBA_Environment *ev);

PortableServer_POAManager_State
PortableServer_POAManager_get_state(PortableServer_POAManager obj,
				    CORBA_Environment *ev);

extern void PortableServer_POAManager_activate(
	PortableServer_POAManager obj,
	CORBA_Environment *ev);

extern void PortableServer_POAManager_hold_requests(
	PortableServer_POAManager obj,
	CORBA_boolean wait_for_completion,
	CORBA_Environment *ev);

extern void PortableServer_POAManager_discard_requests(
	PortableServer_POAManager obj,
	CORBA_boolean wait_for_completion,
	CORBA_Environment *ev);

extern void PortableServer_POAManager_deactivate(
	PortableServer_POAManager obj,
	CORBA_boolean etherealize_objects,
	CORBA_boolean wait_for_completion,
	CORBA_Environment *ev);

extern CORBA_boolean PortableServer_AdapterActivator_unknown_adapter(
	PortableServer_AdapterActivator obj,
	PortableServer_POA parent,
	CORBA_char *name,
	CORBA_Environment *ev);

extern PortableServer_Servant PortableServer_ServantActivator_incarnate(
	PortableServer_ServantActivator obj,
	PortableServer_ObjectId *oid,
	PortableServer_POA adapter,
	CORBA_Environment *ev);

extern void PortableServer_ServantActivator_etherealize(
	PortableServer_ServantActivator obj,
	PortableServer_ObjectId *oid,
	PortableServer_POA adapter,
	PortableServer_Servant serv,
	CORBA_boolean cleanup_in_progress,
	CORBA_boolean remaining_activations,
	CORBA_Environment *ev);

extern PortableServer_POA PortableServer_POA_create_POA(
	PortableServer_POA obj,
	CORBA_char *adapter_name,
	PortableServer_POAManager a_POAManager,
	CORBA_PolicyList *policies,
	CORBA_Environment *ev);

extern PortableServer_POA PortableServer_POA_find_POA(
	PortableServer_POA obj,
	CORBA_char *adapter_name,
	CORBA_boolean activate_it,
	CORBA_Environment *ev);

extern void PortableServer_POA_destroy(
	PortableServer_POA obj,
	CORBA_boolean etherealize_objects,
	CORBA_boolean wait_for_completion,
	CORBA_Environment *ev);

extern PortableServer_ThreadPolicy PortableServer_POA_create_thread_policy(
	PortableServer_POA obj,
	PortableServer_ThreadPolicyValue value,
	CORBA_Environment *ev);

extern PortableServer_LifespanPolicy PortableServer_POA_create_lifespan_policy(
	PortableServer_POA obj,
	PortableServer_LifespanPolicyValue value,
	CORBA_Environment *ev);

extern PortableServer_IdUniquenessPolicy PortableServer_POA_create_id_uniqueness_policy(
	PortableServer_POA obj,
	PortableServer_IdUniquenessPolicyValue value,
	CORBA_Environment *ev);

extern PortableServer_IdAssignmentPolicy PortableServer_POA_create_id_assignment_policy(
	PortableServer_POA obj,
	PortableServer_IdAssignmentPolicyValue value,
	CORBA_Environment *ev);

extern PortableServer_ImplicitActivationPolicy PortableServer_POA_create_implicit_activation_policy(
	PortableServer_POA obj,
	PortableServer_ImplicitActivationPolicyValue value,
	CORBA_Environment *ev);

extern PortableServer_ServantRetentionPolicy PortableServer_POA_create_servant_retention_policy(
	PortableServer_POA obj,
	PortableServer_ServantRetentionPolicyValue value,
	CORBA_Environment *ev);

extern PortableServer_RequestProcessingPolicy PortableServer_POA_create_request_processing_policy(
	PortableServer_POA obj,
	PortableServer_RequestProcessingPolicyValue value,
	CORBA_Environment *ev);

extern CORBA_char *PortableServer_POA__get_the_name(
	PortableServer_POA obj,
	CORBA_Environment *ev);

extern PortableServer_POA PortableServer_POA__get_the_parent(
	PortableServer_POA obj,
	CORBA_Environment *ev);

extern PortableServer_POAManager PortableServer_POA__get_the_POAManager(
	PortableServer_POA obj,
	CORBA_Environment *ev);

extern PortableServer_AdapterActivator PortableServer_POA__get_the_activator(
	PortableServer_POA obj,
	CORBA_Environment *ev);

extern void PortableServer_POA__set_the_activator(
	PortableServer_POA obj,
	PortableServer_AdapterActivator the_activator,
	CORBA_Environment *ev);

extern PortableServer_ServantManager PortableServer_POA_get_servant_manager(
	PortableServer_POA obj,
	CORBA_Environment *ev);

extern void PortableServer_POA_set_servant_manager(
	PortableServer_POA obj,
	PortableServer_ServantManager imgr,
	CORBA_Environment *ev);

extern PortableServer_Servant PortableServer_POA_get_servant(
	PortableServer_POA obj,
	CORBA_Environment *ev);

extern void PortableServer_POA_set_servant(
	PortableServer_POA obj,
	PortableServer_Servant p_servant,
	CORBA_Environment *ev);

extern PortableServer_ObjectId *PortableServer_POA_activate_object(
	PortableServer_POA obj,
	PortableServer_Servant p_servant,
	CORBA_Environment *ev);

extern void PortableServer_POA_activate_object_with_id(
	PortableServer_POA obj,
	PortableServer_ObjectId *id,
	PortableServer_Servant p_servant,
	CORBA_Environment *ev);

extern void PortableServer_POA_deactivate_object(
	PortableServer_POA obj,
	PortableServer_ObjectId *oid,
	CORBA_Environment *ev);

extern CORBA_Object PortableServer_POA_create_reference(
	PortableServer_POA obj,
	CORBA_RepositoryId intf,
	CORBA_Environment *ev);

extern CORBA_Object PortableServer_POA_create_reference_with_id(
	PortableServer_POA obj,
	PortableServer_ObjectId *oid,
	CORBA_RepositoryId intf,
	CORBA_Environment *ev);

extern PortableServer_ObjectId *PortableServer_POA_servant_to_id(
	PortableServer_POA obj,
	PortableServer_Servant p_servant,
	CORBA_Environment *ev);

extern CORBA_Object PortableServer_POA_servant_to_reference(
	PortableServer_POA obj,
	PortableServer_Servant p_servant,
	CORBA_Environment *ev);

extern PortableServer_Servant PortableServer_POA_reference_to_servant(
	PortableServer_POA obj,
	CORBA_Object reference,
	CORBA_Environment *ev);

extern PortableServer_ObjectId *PortableServer_POA_reference_to_id(
	PortableServer_POA obj,
	CORBA_Object reference,
	CORBA_Environment *ev);

extern PortableServer_Servant PortableServer_POA_id_to_servant(
	PortableServer_POA obj,
	PortableServer_ObjectId *oid,
	CORBA_Environment *ev);

extern CORBA_Object PortableServer_POA_id_to_reference(
	PortableServer_POA obj,
	PortableServer_ObjectId *oid,
	CORBA_Environment *ev);

extern PortableServer_POA PortableServer_Current_get_POA(
	PortableServer_Current obj,
	CORBA_Environment *ev);

extern PortableServer_ObjectId *PortableServer_Current_get_object_id(
	PortableServer_Current obj,
	CORBA_Environment *ev);

extern CORBA_char *PortableServer_ObjectId_to_string(
	PortableServer_ObjectId *id,
	CORBA_Environment *env);

extern CORBA_wchar *PortableServer_ObjectId_to_wstring(
	PortableServer_ObjectId *id,
	CORBA_Environment *env);

extern PortableServer_ObjectId *PortableServer_string_to_ObjectId(
	CORBA_char *str,
	CORBA_Environment *env);

extern PortableServer_ObjectId *PortableServer_wstring_to_ObjectId(
	CORBA_wchar *str,
	CORBA_Environment *env);

extern PortableServer_POA PortableServer_ServantBase__default_POA(
	PortableServer_Servant,
	CORBA_Environment *);

extern void PortableServer_ServantLocator_preinvoke(
	PortableServer_ObjectId *oid,
	PortableServer_POA adapter,
	CORBA_Identifier op_name,
	PortableServer_ServantLocator_Cookie *cookie);

extern void PortableServer_ServantLocator_postinvoke(
	PortableServer_ObjectId *oid,
	PortableServer_POA adapter,
	CORBA_Identifier op_name,
	PortableServer_ServantLocator_Cookie cookie,
	PortableServer_Servant servant);

extern void PortableServer_ServantBase__init(
	PortableServer_Servant,
	CORBA_Environment *);

extern void PortableServer_ServantBase__fini(
	PortableServer_Servant,
	CORBA_Environment *);

/* 19.27 */
extern CORBA_Identifier CORBA_ServerRequest_operation(
	CORBA_ServerRequest req,
	CORBA_Environment *env);

extern CORBA_Context CORBA_ServerRequest_ctx(
	CORBA_ServerRequest req,
	CORBA_Environment *env);

extern void CORBA_ServerRequest_arguments(
	CORBA_ServerRequest req,
	CORBA_NVList *parameters,
	CORBA_Environment *env);

extern void CORBA_ServerRequest_set_result(
	CORBA_ServerRequest req,
	CORBA_any *value,
	CORBA_Environment *env);

extern void CORBA_ServerRequest_set_exception(
	CORBA_ServerRequest req,
	CORBA_exception_type major,
	CORBA_any *value,
	CORBA_Environment *env);

extern void PortableServer_DynamicImpl__init(PortableServer_Servant,
					     CORBA_Environment *ev);

extern void PortableServer_DynamicImpl__fini(PortableServer_Servant,
					     CORBA_Environment *ev);


#include "orbit_poa_type.h"

#endif /* !_ORBIT_POA_H_ */
