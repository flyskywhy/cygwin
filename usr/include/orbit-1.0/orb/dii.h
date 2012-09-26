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

#ifndef _ORBIT_DII_H_
#define _ORBIT_DII_H_

#include "orb/orbit_types.h"
#include "orb/interface_repository.h"

extern CORBA_Status CORBA_Object_create_request(
	CORBA_Object obj,
	CORBA_Context ctx,
	CORBA_Identifier operation,
	CORBA_NVList *arg_list,
	CORBA_NamedValue *result,
	CORBA_Request *request,
	CORBA_Flags req_flags,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Request_add_arg(
	CORBA_Request req,
	CORBA_Identifier name,
	CORBA_TypeCode arg_type,
	void *value,
	CORBA_long len,
	CORBA_Flags arg_flags,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Request_invoke(
	CORBA_Request req,
	CORBA_Flags invoke_flags,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Request_delete(
	CORBA_Request req,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_Request_send(
	CORBA_Request req,
	CORBA_Flags invoke_flags,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_send_multiple_requests(
	CORBA_Request reqs[],
	CORBA_Environment *env,
	CORBA_long count,
	CORBA_Flags invoke_flags);

extern CORBA_Status CORBA_Request_get_response(
	CORBA_Request req,
	CORBA_Flags response_flags,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_get_next_response(
	CORBA_Environment *env,
	CORBA_Flags response_flags,
	CORBA_Request *req);

extern CORBA_Status CORBA_NVList_add_item(
	CORBA_NVList *list,
	CORBA_Identifier item_name,
	CORBA_TypeCode item_type,
	void *value,
	CORBA_long value_len,
	CORBA_Flags item_flags,
	CORBA_Environment *ev);

extern void ORBit_NamedValue_free(
	CORBA_NamedValue *nv);


extern CORBA_Status CORBA_ORB_create_list(
	CORBA_ORB orb,
	CORBA_long count,
	CORBA_NVList **new_list,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_ORB_create_operation_list(
	CORBA_ORB orb,
	CORBA_OperationDef oper,
	CORBA_NVList **new_list,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_NVList_free(CORBA_NVList *list,
				      CORBA_Environment *ev);

extern CORBA_Status CORBA_NVList_free_memory(
	CORBA_NVList *list,
	CORBA_Environment *ev);

extern CORBA_Status CORBA_NVList_get_count(
	CORBA_NVList *list,
	CORBA_long *count,
	CORBA_Environment *ev);

extern const int sizeofs[], container_sizeofs[];

#endif /* _ORBIT_DII_H_ */
