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

#ifndef _ORBIT_CORBA_ORB_H_
#define _ORBIT_CORBA_ORB_H_

typedef char *CORBA_ORB_ObjectId;

#ifndef CORBA_POLICY_TYPE
#define CORBA_POLICY_TYPE 1
/* We need to define this in corba_orb_type.h as well, sometimes... */
typedef struct CORBA_Policy_type *CORBA_Policy;
#endif

typedef CORBA_unsigned_long CORBA_PolicyType;

typedef struct CORBA_ORB_type *CORBA_ORB;

typedef struct CORBA_DomainManager_type *CORBA_DomainManager;

typedef struct CORBA_ConstructionPolicy_type *CORBA_ConstructionPolicy;

#define ex_CORBA_ORB_InvalidName "IDL:CORBA/ORB/InvalidName:1.0"

#endif /* !_ORBIT_CORBA_ORB_H_ */

