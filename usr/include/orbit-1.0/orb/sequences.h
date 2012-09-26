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

#ifndef _ORBIT_SEQUENCES_H_
#define _ORBIT_SEQUENCES_H_

/* #include "corba_sequences_type.h" */
#include "orbit_types.h"

CORBA_octet *CORBA_octet_allocbuf(CORBA_unsigned_long len);
CORBA_sequence_octet *CORBA_sequence_octet__alloc(void);


extern CORBA_sequence_CORBA_any *CORBA_sequence_CORBA_any__alloc(void);
extern gpointer CORBA_sequence_CORBA_any__free(gpointer mem, gpointer dat,
						  CORBA_boolean free_strings);	/* ORBit internal use */
CORBA_any *CORBA_sequence_CORBA_any_allocbuf(CORBA_unsigned_long len);


#endif /* !_ORBIT_SEQUENCES_H_ */
