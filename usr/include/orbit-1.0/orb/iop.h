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

#ifndef _ORBIT_IOP_H_
#define _ORBIT_IOP_H_

#include <ORBitutil/basic_types.h>

#include <orb/corba_basic_sequences_type.h>

#ifndef HAVE_CORBA_PRINCIPAL
#define HAVE_CORBA_PRINCIPAL 1
typedef CORBA_sequence_octet CORBA_Principal;
#endif

typedef CORBA_unsigned_long IOP_ProfileId;

#define IOP_TAG_INTERNET_IOP 0
#define IOP_TAG_MULTIPLE_COMPONENTS 1
#define IOP_TAG_GENERIC_IOP    0x4f425400
#define IOP_TAG_ORBIT_SPECIFIC 0xbadfaecal

typedef struct IOP_TaggedProfile {
	IOP_ProfileId tag;
	CORBA_sequence_octet profile_data;
} IOP_TaggedProfile;

typedef struct CORBA_sequence_TaggedProfile {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	IOP_TaggedProfile *_buffer;
} CORBA_sequence_TaggedProfile;

typedef struct IOP_IOR {
	CORBA_char *type_id;
	CORBA_sequence_TaggedProfile profiles;
} IOP_IOR;

typedef CORBA_unsigned_long IOP_ComponentId;

typedef struct IOP_TaggedComponent {
	IOP_ComponentId tag;
	CORBA_sequence_octet component_data;
} IOP_TaggedComponent;

typedef struct CORBA_sequence_TaggedComponent {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	IOP_TaggedComponent *_buffer;
} CORBA_sequence_TaggedComponent;

typedef struct CORBA_sequence_TaggedComponent IOP_MultipleComponentProfile;

#define IOP_TAG_ORB_TYPE 0
#define IOP_TAG_CODE_SETS 1
#define IOP_TAG_SEC_NAME 14
#define IOP_TAG_ASSOCIATION_OPTIONS 13
#define IOP_TAG_GENERIC_SEC_MECH 12

typedef CORBA_unsigned_long IOP_ServiceId;

typedef struct IOP_ServiceContext {
	IOP_ServiceId context_id;
	CORBA_sequence_octet context_data;
} IOP_ServiceContext;

typedef struct CORBA_sequence_ServiceContext {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	IOP_ServiceContext *_buffer;
} CORBA_sequence_ServiceContext;

typedef struct CORBA_sequence_ServiceContext IOP_ServiceContextList;

#define IOP_TransactionService 0
#define IOP_CodeSets 1

typedef CORBA_unsigned_long CONV_FRAME_CodeSetId;

typedef struct CORBA_sequence_CodeSetId {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CONV_FRAME_CodeSetId *_buffer;
} CORBA_sequence_CodeSetId;

typedef struct CONV_FRAME_CodeSetComponent {
	CONV_FRAME_CodeSetId native_code_set;
	CORBA_sequence_CodeSetId conversion_code_sets;
} CONV_FRAME_CodeSetComponent;

typedef struct CONV_FRAME_CodeSetComponentInfo {
	CONV_FRAME_CodeSetComponent ForCharData;
	CONV_FRAME_CodeSetComponent ForWcharData;
} CONV_FRAME_CodeSetComponentInfo;

typedef struct CONV_FRAME_CodeSetContext {
	CONV_FRAME_CodeSetId char_data;
	CONV_FRAME_CodeSetId wchar_data;
} CONV_FRAME_CodeSetContext;

typedef struct GIOP_Version {
	CORBA_octet major;
	CORBA_octet minor;
} GIOP_Version;

typedef enum {
	GIOP_Request=0,
	GIOP_Reply,
	GIOP_CancelRequest,
	GIOP_LocateRequest,
	GIOP_LocateReply,
	GIOP_CloseConnection,
	GIOP_MessageError
} GIOP_MsgType_1_0;

typedef struct GIOP_MessageHeader_1_0 {
	CORBA_char magic[4];
	GIOP_Version GIOP_version;
	CORBA_boolean byte_order;
	CORBA_octet message_type;
	CORBA_unsigned_long message_size;
} GIOP_MessageHeader_1_0;

typedef struct GIOP_MessageHeader_1_1 {
	CORBA_char magic[4];
	GIOP_Version GIOP_version;
	CORBA_octet flags;
	CORBA_octet message_type;
	CORBA_unsigned_long message_size;
} GIOP_MessageHeader_1_1;

typedef struct GIOP_RequestHeader_1_0 {
	IOP_ServiceContextList service_context;
	CORBA_unsigned_long request_id;
	CORBA_boolean response_expected;
	CORBA_sequence_octet object_key;
	CORBA_char *operation;
	CORBA_Principal requesting_principal;
} GIOP_RequestHeader_1_0;

typedef struct GIOP_RequestHeader_1_1 {
	IOP_ServiceContextList service_context;
	CORBA_unsigned_long request_id;
	CORBA_boolean response_expected;
	CORBA_octet reserved[3];
	CORBA_sequence_octet object_key;
	CORBA_char *operation;
	CORBA_Principal requesting_principal;
} GIOP_RequestHeader_1_1;

typedef struct GIOP_SystemExceptionReplyBody {
	CORBA_char *exception_id;
	CORBA_unsigned_long minor_code_value;
	CORBA_unsigned_long completion_status;
} GIOP_SystemExceptionReplyBody;

typedef struct GIOP_CancelRequestHeader {
	CORBA_unsigned_long request_id;
} GIOP_CancelRequestHeader;

typedef struct GIOP_LocateRequestHeader {
	CORBA_unsigned_long request_id;
	CORBA_sequence_octet object_key;
} GIOP_LocateRequestHeader;

typedef struct IIOP_Version {
	CORBA_octet major;
	CORBA_octet minor;
} IIOP_Version;

typedef struct IIOP_ProfileBody_1_0 {
	IIOP_Version iiop_version;
	CORBA_char *host;
	CORBA_unsigned_short port;
	CORBA_sequence_octet object_key;
} IIOP_ProfileBody_1_0;

typedef struct IIOP_ProfileBody_1_1 {
	IIOP_Version iiop_version;
	CORBA_char *host;
	CORBA_unsigned_short port;
	CORBA_sequence_octet object_key;
	CORBA_sequence_TaggedComponent components;
} IIOP_ProfileBody_1_1;

#endif /* !_ORBIT_IOP_H_ */
