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
 *	  Philip Dawes
 *	  Elliot Lee <sopwith@redhat.com>
 *
 */

#ifndef _ORBIT_ORBIT_OBJECT_TYPE_H_
#define _ORBIT_ORBIT_OBJECT_TYPE_H_

#include "orbit_object.h"


/****** Root object **********/
/*****************************/

typedef struct ORBit_RootObject_Interface_struct ORBit_RootObject_Interface;
struct ORBit_RootObject_Interface_struct
{
	void (*release)(gpointer obj, CORBA_Environment *ev);
};



#define ORBIT_ROOT_OBJECT(x) ((ORBit_RootObject)(x))


typedef struct ORBit_RootObject_struct *ORBit_RootObject;
struct ORBit_RootObject_struct {
	ORBit_RootObject_Interface* interface; /* the interface */

	guchar is_pseudo_object;
	gint refs;
};


/* Reference counting interface */

#define ORBIT_ROOT_OBJECT_REF(obj) (ORBIT_ROOT_OBJECT(obj)->refs++)
#define ORBIT_ROOT_OBJECT_UNREF(obj) (ORBIT_ROOT_OBJECT(obj)->refs--)


     /* Virtual function interface*/

#define ORBIT_ROOT_OBJECT_release(obj,ev) \
(ORBIT_ROOT_OBJECT(obj)->interface->release(obj,ev))



extern void ORBit_RootObject_set_interface(ORBit_RootObject obj,
					   ORBit_RootObject_Interface* epv,
					   CORBA_Environment *ev);



/****** Pseudo object --> RootObject ********/
/*********************************************/

#define ORBIT_PSEUDO_OBJECT(x) ((ORBit_PseudoObject)(x))

struct ORBit_PseudoObject_struct {
	struct ORBit_RootObject_struct parent;
	ORBit_PseudoObject_type pseudo_object_type;
};


#endif /* !_ORBIT_CORBA_OBJECT_TYPE_H_ */
