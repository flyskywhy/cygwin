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
 *  Author: Dick Porter <dick@acm.org>
 *
 */

#ifndef _ORBIT_TRACE_H_
#define _ORBIT_TRACE_H_

#include <stdarg.h>
#include "util.h"

typedef enum {
	TraceMod_ORB,
	TraceMod_CDR,
	TraceMod_IIOP,
	TraceMod_TC,
	TraceMod_IR,
	TraceMod_User=32
} ORBit_TraceModule;

typedef enum {
	TraceLevel_Alert=0,
	TraceLevel_Critical,
	TraceLevel_Error,
	TraceLevel_Warning,
	TraceLevel_Notice,
	TraceLevel_Info,
	TraceLevel_Debug
} ORBit_TraceLevel;

extern const char *ORBit_Trace_levellist[];

#ifdef ORBIT_DEBUG
extern void ORBit_Trace_setCallback(int (*)(char *, va_list));
extern int (*ORBit_Trace_getCallback(void))(char *, va_list);
extern void ORBit_Trace_setModules(int);
extern void ORBit_Trace_setLevel(ORBit_TraceLevel);
extern int ORBit_Trace(ORBit_TraceModule, ORBit_TraceLevel, char *, ...);
#else
#define ORBit_Trace_setCallback(x)
#define ORBit_Trace_getCallback() NULL
#define ORBit_Trace_setModules(x)
#define ORBit_Trace_setLevel(x)
#define ORBit_Trace(x)
#endif


#endif /* !_ORBIT_TRACE_H_ */
