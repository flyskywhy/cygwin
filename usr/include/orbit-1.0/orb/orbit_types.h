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
 *  Author: Dick Porter <dick@cymru.net>
 *
 */

#ifndef _ORBIT_TYPES_H_
#define _ORBIT_TYPES_H_

#include <stddef.h>	/* for wchar_t */
#include <sys/types.h>  /* for sysdep types */
#include <netinet/in.h>	/* for sockaddr_in */
#include <sys/uio.h> /* for struct iovec */

#include <ORBitutil/basic_types.h>

#define CORBA_TRUE 1
#define CORBA_FALSE 0

typedef CORBA_char *CORBA_ORBid;

typedef CORBA_unsigned_long CORBA_ServiceOption;
typedef CORBA_unsigned_long CORBA_ServiceDetailType;

#include "corba_orb.h"

/*
 * CORBA_RepositoryId and CORBA_Identifier are defined in the Interface
 * Repository, but are needed in other interfaces in the ORB itself.
 */
#if !defined(_CORBA_Identifier_defined)
#define _CORBA_Identifier_defined 1
typedef CORBA_char *CORBA_Identifier;
#define CORBA_Identifier__free CORBA_string__free
#endif

#if !defined(_CORBA_RepositoryId_defined)
#define _CORBA_RepositoryId_defined 1
typedef CORBA_char *CORBA_RepositoryId;
#define CORBA_RepositoryId__free CORBA_string__free
#endif

#include "corba_any.h"

typedef struct CORBA_ServiceDetail_type CORBA_ServiceDetail;
typedef struct CORBA_Request_type *CORBA_Request;
typedef struct CORBA_ServerRequest_type *CORBA_ServerRequest;
typedef struct CORBA_DynFixed_type *CORBA_DynFixed;
typedef struct CORBA_Current_type *CORBA_Current;
typedef void CORBA_Status;
typedef CORBA_unsigned_long CORBA_enum;
typedef CORBA_unsigned_long CORBA_Flags;

typedef struct CORBA_NVList_type {
	CORBA_Flags flags;
	GArray *list;
} CORBA_NVList;

#include "corba_context.h"

#include "corba_portableserver.h"

#include "corba_env.h"

#include "corba_sequences_type.h"

#include "corba_basic_sequences_type.h"

#include "corba_object.h"

#include "orbit_object_type.h"

#include "corba_object_type.h"

#include "corba_orb_type.h"

#include "corba_typecode.h"
#include "corba_typecode_type.h"
#include "corba_any_type.h"
#include "corba_any_proto.h"

#if !defined(TC_IMPL_TC_CORBA_Identifier_0)
#define TC_IMPL_TC_CORBA_Identifier_0 '/'
#define TC_CORBA_Identifier ((CORBA_TypeCode)&TC_CORBA_Identifier_struct)
extern struct CORBA_TypeCode_struct TC_CORBA_Identifier_struct;
#endif

#if !defined(TC_IMPL_TC_CORBA_RepositoryId_0)
#define TC_IMPL_TC_CORBA_RepositoryId_0 '/'
extern struct CORBA_TypeCode_struct TC_CORBA_RepositoryId_struct;
#define TC_CORBA_RepositoryId ((CORBA_TypeCode)&TC_CORBA_RepositoryId_struct)
#endif

/* 19.14 */

/* XXX */
typedef struct CORBA_fixed_d_s {
	CORBA_unsigned_short _digits;
	CORBA_short _scale;
	signed char _sign;
	signed char _value[1];
} CORBA_fixed_d_s;

#include "corba_env_type.h"


typedef struct CORBA_WrongTransaction {
	int dummy;
} CORBA_WrongTransaction;

#define CORBA_ARG_IN (1<<0)
#define CORBA_ARG_OUT (1<<1)
#define CORBA_ARG_INOUT (1<<2)
#define CORBA_CTX_RESTRICT_SCOPE (1<<3)
#define CORBA_CTX_DELETE_DESCENDENTS (1<<4)
#define CORBA_OUT_LIST_MEMORY (1<<5)
#define CORBA_IN_COPY_VALUE (1<<6)
#define CORBA_DEPENDENT_LIST (1<<7)
#define CORBA_INV_NO_RESPONSE (1<<8)
#define CORBA_INV_TERM_ON_ERROR (1<<9)
#define CORBA_RESP_NO_WAIT (1<<10)

typedef struct CORBA_NamedValue {
	CORBA_Identifier name;		/* argument name */
	CORBA_any argument;		/* argument */
	CORBA_long len;			/* length/count of argument value */
	CORBA_Flags arg_modes;		/* argument mode flags */
} CORBA_NamedValue;

typedef CORBA_char *CORBA_FieldName;

typedef struct CORBA_NameValuePair {
	CORBA_FieldName id;
	CORBA_any value;
} CORBA_NameValuePair;

struct CORBA_Current_type {
	int fill_me_in;
};

#include "corba_portableserver_type.h"

typedef CORBA_unsigned_short CORBA_ServiceType;

#define CORBA_Security (1)

struct CORBA_ServiceDetail_type {
	CORBA_ServiceDetailType service_detail_type;
	CORBA_sequence_octet service_detail;
};

typedef struct CORBA_ServiceInformation_struct {
	CORBA_sequence_ServiceOption service_options;
	CORBA_sequence_ServiceDetail service_details;
} CORBA_ServiceInformation;

#endif /* !_ORBIT_TYPES_H_ */
