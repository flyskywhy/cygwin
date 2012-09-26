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

#ifndef _ORBIT_CORBA_SEQUENCES_H_
#define _ORBIT_CORBA_SEQUENCES_H_


/* moved from sequences.h */
#include "corba_basic_sequences_type.h"

typedef CORBA_sequence_octet CORBA_ReferenceData;

#define _CORBA_sequence_ServiceOption_defined
typedef struct CORBA_sequence_ServiceOption CORBA_sequence_ServiceOption;

#define _CORBA_sequence_ServiceDetail_defined
typedef struct CORBA_sequence_ServiceDetail CORBA_sequence_ServiceDetail;

#define _CORBA_sequence_ORB_ObjectId_defined
typedef struct CORBA_sequence_ORB_ObjectId CORBA_ORB_ObjectIdList;

#define _CORBA_sequence_NameValuePair_defined
typedef struct CORBA_sequence_NameValuePair CORBA_NameValuePairSeq;

#define _CORBA_sequence_CORBA_any_defined
typedef struct CORBA_sequence_CORBA_any_struct CORBA_AnySeq;
typedef struct CORBA_sequence_CORBA_any_struct CORBA_sequence_CORBA_any;

#define _CORBA_sequence_Policy_defined
typedef struct CORBA_sequence_Policy CORBA_PolicyList;

#define _CORBA_sequence_DomainManager_defined
typedef struct CORBA_sequence_DomainManager CORBA_DomainManagerList;

#define _PortableServer_sequence_octet_defined
typedef struct PortableServer_sequence_octet PortableServer_ObjectId;


/* Moved from orbit_types.h */
#ifndef HAVE_CORBA_PRINCIPAL
#define HAVE_CORBA_PRINCIPAL 1
typedef CORBA_sequence_octet CORBA_Principal;
#endif
typedef CORBA_sequence_octet CORBA_DynAny_OctetSeq;
typedef CORBA_sequence_octet CORBA_DynFixed_OctetSeq;
typedef CORBA_sequence_octet CORBA_DynEnum_OctetSeq;
typedef CORBA_sequence_octet CORBA_DynStruct_OctetSeq;
typedef CORBA_sequence_octet CORBA_DynUnion_OctetSeq;
typedef CORBA_sequence_octet CORBA_DynSequence_OctetSeq;
typedef CORBA_sequence_octet CORBA_DynArray_OctetSeq;

#endif /* !_ORBIT_CORBA_SEQUENCES_H_ */
