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

#ifndef _ORBIT_CORBA_ENV_H_
#define _ORBIT_CORBA_ENV_H_

typedef struct CORBA_Environment_type CORBA_Environment;

/* 3.15 */
typedef enum {
	CORBA_COMPLETED_YES=0,
	CORBA_COMPLETED_NO,
	CORBA_COMPLETED_MAYBE
} CORBA_completion_status;

typedef enum {
	CORBA_NO_EXCEPTION=0,
	CORBA_USER_EXCEPTION,
	CORBA_SYSTEM_EXCEPTION
} CORBA_exception_type;


#define ex_CORBA_UNKNOWN 1
#define ex_CORBA_BAD_PARAM 2
#define ex_CORBA_NO_MEMORY 3
#define ex_CORBA_IMP_LIMIT 4
#define ex_CORBA_COMM_FAILURE 5
#define ex_CORBA_INV_OBJREF 6
#define ex_CORBA_NO_PERMISSION 7
#define ex_CORBA_INTERNAL 8
#define ex_CORBA_MARSHAL 9
#define ex_CORBA_INITIALIZE 10
#define ex_CORBA_NO_IMPLEMENT 11
#define ex_CORBA_BAD_TYPECODE 12
#define ex_CORBA_BAD_OPERATION 13
#define ex_CORBA_NO_RESOURCES 14
#define ex_CORBA_NO_RESPONSE 15
#define ex_CORBA_PERSIST_STORE 16
#define ex_CORBA_BAD_INV_ORDER 17
#define ex_CORBA_TRANSIENT 18
#define ex_CORBA_FREE_MEM 19
#define ex_CORBA_INV_IDENT 20
#define ex_CORBA_INV_FLAG 21
#define ex_CORBA_INTF_REPOS 22
#define ex_CORBA_BAD_CONTEXT 23
#define ex_CORBA_OBJ_ADAPTER 24
#define ex_CORBA_DATA_CONVERSION 25
#define ex_CORBA_OBJECT_NOT_EXIST 26
#define ex_CORBA_TRANSACTION_REQUIRED 27
#define ex_CORBA_TRANSACTION_ROLLEDBACK 28
#define ex_CORBA_INVALID_TRANSACTION 29


#endif /* !_ORBIT_CORBA_ENV_H_ */



