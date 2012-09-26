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

#ifndef _ORBIT_CORBA_ENV_TYPE_H_
#define _ORBIT_CORBA_ENV_TYPE_H_

#include "corba_env.h"
#include "corba_any.h"

typedef struct CORBA_system_exception {
	CORBA_unsigned_long minor;
	CORBA_completion_status completed;
} CORBA_SystemException;

#define SYSEXC(name)	typedef CORBA_SystemException name;

SYSEXC(CORBA_UNKNOWN)
SYSEXC(CORBA_BAD_PARAM)
SYSEXC(CORBA_NO_MEMORY)
SYSEXC(CORBA_IMP_LIMIT)
SYSEXC(CORBA_COMM_FAILURE)
SYSEXC(CORBA_INV_OBJREF)
SYSEXC(CORBA_NO_PERMISSION)
SYSEXC(CORBA_INTERNAL)
SYSEXC(CORBA_MARSHAL)
SYSEXC(CORBA_INITIALIZE)
SYSEXC(CORBA_NO_IMPLEMENT)
SYSEXC(CORBA_BAD_TYPECODE)
SYSEXC(CORBA_BAD_OPERATION)
SYSEXC(CORBA_NO_RESOURCES)
SYSEXC(CORBA_NO_RESPONSE)
SYSEXC(CORBA_PERSIST_STORE)
SYSEXC(CORBA_BAD_INV_ORDER)
SYSEXC(CORBA_TRANSIENT)
SYSEXC(CORBA_FREE_MEM)
SYSEXC(CORBA_INV_IDENT)
SYSEXC(CORBA_INV_FLAG)
SYSEXC(CORBA_INTF_REPOS)
SYSEXC(CORBA_BAD_CONTEXT)
SYSEXC(CORBA_OBJ_ADAPTER)
SYSEXC(CORBA_DATA_CONVERSION)
SYSEXC(CORBA_OBJECT_NOT_EXIST)
SYSEXC(CORBA_TRANSACTION_REQUIRED)
SYSEXC(CORBA_TRANSACTION_ROLLEDBACK)
SYSEXC(CORBA_INVALID_TRANSACTION)


/* 19.22 */
struct CORBA_Environment_type {
	CORBA_exception_type _major;
	CORBA_char *_repo_id;
	void *_params;
	CORBA_any *_any;
};


#endif /* !_ORBIT_CORBA_ENV_TYPE_H_ */
