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

#ifndef _ORBIT_ORB_H_
#define _ORBIT_ORB_H_

#include "orb/orbit_types.h"
#include "orb/interface_repository.h"

extern CORBA_ORB CORBA_ORB_init(
	int *argc,
	char **argv,
	CORBA_ORBid orb_identifier,
	CORBA_Environment *ev);

extern CORBA_char *CORBA_ORB_object_to_string(
	CORBA_ORB orb,
	CORBA_Object obj,
	CORBA_Environment *ev);

extern CORBA_Object CORBA_ORB_string_to_object(
	CORBA_ORB orb,
	CORBA_char *str,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_ORB_get_default_context(
	CORBA_ORB orb,
	CORBA_Context *ctx,
	CORBA_Environment *ev);

extern CORBA_boolean CORBA_ORB_get_service_information(
	CORBA_ORB orb,
	CORBA_ServiceType service_type,
	CORBA_ServiceInformation *service_information,
	CORBA_Environment *ev);

extern CORBA_Current *CORBA_ORB_get_current(
	CORBA_ORB orb,
	CORBA_Environment *ev);

extern CORBA_ORB_ObjectIdList* CORBA_ORB_list_initial_services(
	CORBA_ORB orb,
	CORBA_Environment *ev);

extern CORBA_Object CORBA_ORB_resolve_initial_references(
	CORBA_ORB orb,
	CORBA_ORB_ObjectId identifier,
	CORBA_Environment *ev);

extern void CORBA_ORB_set_initial_reference(
	CORBA_ORB orb,
	CORBA_ORB_ObjectId identifier,
	CORBA_Object obj,
	CORBA_Environment *ev);

extern CORBA_boolean CORBA_ORB_work_pending(
	CORBA_ORB orb,
	CORBA_Environment *ev);

extern void CORBA_ORB_perform_work(
	CORBA_ORB orb,
	CORBA_Environment *ev);

extern void CORBA_ORB_shutdown(
	CORBA_ORB orb,
	CORBA_boolean wait_for_completion,
	CORBA_Environment *ev);

extern void CORBA_ORB_run(
	CORBA_ORB orb,
	CORBA_Environment *ev);

extern CORBA_PolicyType CORBA_Policy__get_policy_type(
	CORBA_Policy obj,
	CORBA_Environment *ev);

extern CORBA_Policy CORBA_Policy_copy(
	CORBA_Policy obj,
	CORBA_Environment *ev);

extern void CORBA_Policy_destroy(
	CORBA_Policy obj,
	CORBA_Environment *ev);

extern CORBA_InterfaceDef CORBA_Object_get_interface(
	CORBA_Object obj,
	CORBA_Environment *ev);

extern CORBA_boolean CORBA_Object_is_nil(
	CORBA_Object obj,
	CORBA_Environment *ev);

extern CORBA_Object CORBA_Object_duplicate(
	CORBA_Object obj,
	CORBA_Environment *ev);

extern void CORBA_Object_release(
	CORBA_Object obj,
	CORBA_Environment *ev);

extern CORBA_boolean CORBA_Object_non_existent(
	CORBA_Object obj,
	CORBA_Environment *ev);

extern CORBA_boolean CORBA_Object_is_equivalent(
	CORBA_Object obj,
	CORBA_Object other_object,
	CORBA_Environment *ev);

extern CORBA_unsigned_long CORBA_Object_hash(
	CORBA_Object obj,
	CORBA_unsigned_long maximum,
	CORBA_Environment *ev);

extern CORBA_Policy CORBA_Object_get_policy(
	CORBA_Object obj,
	CORBA_PolicyType policy_type,
	CORBA_Environment *ev);

extern CORBA_DomainManagerList *CORBA_Object_get_domain_managers(
	CORBA_Object obj,
	CORBA_Environment *ev);

extern CORBA_Policy CORBA_DomainManager_get_domain_policy(
	CORBA_DomainManager obj,
	CORBA_PolicyType policy_type,
	CORBA_Environment *ev);

extern void CORBA_ConstructionPolicy_make_domain_manager(
	CORBA_ConstructionPolicy obj,
	CORBA_Object /*CORBA_InterfaceDef*/ object_type,
	CORBA_boolean constr_policy,
	CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_struct_tc(CORBA_ORB obj,
					  CORBA_RepositoryId id,
					  CORBA_Identifier name,
					  CORBA_StructMemberSeq members,
					  CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_union_tc(CORBA_ORB obj,
					 CORBA_RepositoryId id,
					 CORBA_Identifier name,
					 CORBA_TypeCode discriminator_type,
					 CORBA_UnionMemberSeq members,
					 CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_enum_tc(CORBA_ORB obj,
					CORBA_RepositoryId id,
					CORBA_Identifier name,
					CORBA_EnumMemberSeq members,
					CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_alias_tc(CORBA_ORB obj,
					 CORBA_RepositoryId id,
					 CORBA_Identifier name,
					 CORBA_TypeCode original_type,
					 CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_exception_tc(CORBA_ORB obj,
					     CORBA_RepositoryId id,
					     CORBA_Identifier name,
					     CORBA_StructMemberSeq members,
					     CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_interface_tc(CORBA_ORB obj,
					     CORBA_RepositoryId id,
					     CORBA_Identifier name,
					     CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_string_tc(CORBA_ORB obj,
					  CORBA_unsigned_long bound,
					  CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_wstring_tc(CORBA_ORB obj,
					   CORBA_unsigned_long bound,
					   CORBA_Environment *ev);

CORBA_TypeCode CORBA_ORB_create_fixed_tc(CORBA_ORB obj,
					 CORBA_unsigned_short digits,
					 CORBA_short scale,
					 CORBA_Environment *ev);

extern CORBA_TypeCode CORBA_ORB_create_sequence_tc(
	CORBA_ORB obj,
	CORBA_unsigned_long bound,
	CORBA_TypeCode element_type,
	CORBA_Environment *ev);

extern CORBA_TypeCode CORBA_ORB_create_recursive_sequence_tc(
	CORBA_ORB obj,
	CORBA_unsigned_long bound,
	CORBA_unsigned_long offset,
	CORBA_Environment *ev);

extern CORBA_TypeCode CORBA_ORB_create_array_tc(
	CORBA_ORB obj,
	CORBA_unsigned_long length,
	CORBA_TypeCode element_type,
	CORBA_Environment *ev);

#endif /* !_ORBIT_ORB_H_ */
