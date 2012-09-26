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

#ifndef _ORBIT_CORBA_BASIC_SEQUENCES_TYPE_H_
#define _ORBIT_CORBA_BASIC_SEQUENCES_TYPE_H_

#include <ORBitutil/basic_types.h>

#ifndef _CORBA_sequence_octet_defined
#define _CORBA_sequence_octet_defined 1

typedef struct CORBA_sequence_octet_struct {
	CORBA_unsigned_long _maximum;
	CORBA_unsigned_long _length;
	CORBA_octet *_buffer;
	CORBA_boolean _release;
} CORBA_sequence_octet;
#endif /* !_CORBA_sequence_octet_defined */

#include <orb/corba_sequences.h>
#endif /* !_ORBIT_CORBA_BASIC_SEQUENCES_TYPE_H_ */
