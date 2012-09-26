/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
 *  ORBit: A CORBA v2.2 ORB
 *
 *  Copyright (C) 1998, 1999 Richard H. Porter, Red Hat Software
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

#ifndef _ORBIT_ENV_H_
#define _ORBIT_ENV_H_

#include "orbit_types.h"

extern void CORBA_exception_set(CORBA_Environment *ev,
	CORBA_exception_type major, 
	const CORBA_char *except_repos_id,
	void *param);

extern void CORBA_exception_set_system(CORBA_Environment *ev,
	CORBA_unsigned_long ex_value,
	CORBA_completion_status completed);

extern void CORBA_exception_init(CORBA_Environment *ev);

extern CORBA_char *CORBA_exception_id(CORBA_Environment *e);

extern void *CORBA_exception_value(CORBA_Environment *ev);

extern void CORBA_exception_free(CORBA_Environment *ev);

extern CORBA_any *CORBA_exception_as_any(CORBA_Environment *ev);

typedef struct {
	const CORBA_TypeCode tc;
	void (*demarshal)(GIOPRecvBuffer *_ORBIT_recv_buffer, CORBA_Environment *ev);
} ORBit_exception_demarshal_info;

typedef struct {
	const CORBA_TypeCode tc;
	void (*marshal)(GIOPSendBuffer *_ORBIT_send_buffer, CORBA_Environment *ev);
} ORBit_exception_marshal_info;

/* ORBit-specific */
void ORBit_handle_exception(GIOPRecvBuffer *rb, CORBA_Environment *ev,
			    const ORBit_exception_demarshal_info *user_exceptions,
			    CORBA_ORB orb);
void ORBit_send_system_exception(GIOPSendBuffer *send_buffer,
				 CORBA_Environment *ev);
void ORBit_send_user_exception(GIOPSendBuffer *send_buffer,
			       CORBA_Environment *ev,
			       const ORBit_exception_marshal_info *user_exceptions);

/* Used by stubs */
void ORBit_handle_system_exception(CORBA_Environment *ev,
				   CORBA_unsigned_long system_exception_minor,
				   CORBA_unsigned_long completion_status,
				   GIOPRecvBuffer *recv_buffer,
				   GIOPSendBuffer *send_buffer);

#endif /* !_ORBIT_ENV_H_ */
