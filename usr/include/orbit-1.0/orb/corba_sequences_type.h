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

#ifndef _ORBIT_CORBA_SEQUENCES_TYPE_H_
#define _ORBIT_CORBA_SEQUENCES_TYPE_H_

#include "corba_sequences.h"

struct CORBA_sequence_ServiceOption {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CORBA_ServiceOption *_buffer;
	CORBA_boolean _release;
};

struct CORBA_sequence_ServiceDetail {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CORBA_ServiceDetail *_buffer;
	CORBA_boolean _release;
};

struct CORBA_sequence_ORB_ObjectId {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CORBA_ORB_ObjectId *_buffer;  
	CORBA_boolean _release;
};

struct CORBA_sequence_NameValuePair {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	struct CORBA_NameValuePair *_buffer;
	CORBA_boolean _release;
};

struct CORBA_sequence_CORBA_any_struct {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CORBA_any *_buffer;
	CORBA_boolean _release;
};

struct CORBA_sequence_Policy {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CORBA_Policy *_buffer;
	CORBA_boolean _release;
};

struct CORBA_sequence_DomainManager {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CORBA_DomainManager *_buffer;
	CORBA_boolean _release;
};

struct PortableServer_sequence_octet {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CORBA_octet *_buffer;
	CORBA_boolean _release;
};

/* Generic sequence */
struct CORBA_Sequence_type {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	void *_buffer;
	CORBA_boolean _release;
};

#define CORBA_SEQFLAGS_RELEASE 1


#endif /* !_ORBIT_CORBA_SEQUENCES_TYPE_H_ */
