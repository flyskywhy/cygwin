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
 *  Author: Dick Porter <dick@acm.org>
 *	    Elliot Lee <sopwith@redhat.com>
 *
 */

/* these two blocks are outside of the main header for good reason...
   People may include headers from many different stubs, and we want to
   have the version checked on all of them.
 */
#ifndef ORBIT_SERIAL
#define ORBIT_SERIAL 9
#endif

#ifdef ORBIT_IDL_SERIAL
#if ORBIT_IDL_SERIAL < 9
#error "You need to rerun 'orbit-idl' on the .idl file whose stubs you are using. These stubs were generated with an older version of ORBit, and need to be regenerated."
#endif
#endif

#ifndef _ORBIT_H_
#define _ORBIT_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <glib.h>

#define BACKWARDS_COMPAT_0_4
#undef NOT_BACKWARDS_COMPAT_0_4

#include <sys/types.h>
#include <sys/uio.h>
#include <IIOP/IIOP.h>
#include <ORBitutil/util.h>
#include <orb/orbit_config.h>
#include <orb/orbit_types.h>
#include <orb/allocators.h>
#include <orb/cdr.h>
#include <orb/dii.h>
#include <orb/dynany.h>
#include <orb/env.h>
#include <orb/iop.h>
#include <orb/ir.h>
#include <orb/options.h>
#include <orb/orb.h>
#include <orb/poa.h>
#include <orb/sequences.h>
#include <orb/orbit_typecode.h>
#include <orb/typecode.h>

#ifndef ORBIT_MAJOR_VERSION
#define ORBIT_MAJOR_VERSION (0)
#define ORBIT_MINOR_VERSION (5)
#define ORBIT_MICRO_VERSION (17)
#endif

extern const guint orbit_major_version,
	orbit_minor_version,
	orbit_micro_version;
extern const char orbit_version[];

extern const CORBA_unsigned_long ORBit_zero_int;

extern void CORBA_any_set_release(
	CORBA_any *,
	CORBA_boolean);

extern CORBA_boolean CORBA_any_get_release(
	CORBA_any *);

extern void CORBA_sequence_set_release(
	void *,
	CORBA_boolean);

extern CORBA_boolean CORBA_sequence_get_release(
	void *);

#define CORBA_any__alloc CORBA_any_alloc
extern CORBA_any *CORBA_any_alloc(
	void);

extern gpointer CORBA_any__free(gpointer mem, gpointer func_data,
				CORBA_boolean ignore);
extern gpointer CORBA_TypeCode__free(gpointer mem, gpointer func_data,
				     CORBA_boolean ignore);

extern CORBA_boolean ORBit_any_equivalent (CORBA_any *obj,
					   CORBA_any *any,
					   CORBA_Environment *ev);

extern CORBA_char *CORBA_string_dup(const CORBA_char *string);
extern CORBA_char *CORBA_string_alloc(CORBA_unsigned_long len);
extern gpointer CORBA_string__free(gpointer str, gpointer dat, CORBA_boolean ignore);

gpointer CORBA_Object__free(gpointer str, gpointer dat, CORBA_boolean ignore);

extern CORBA_wchar *CORBA_wstring_alloc(CORBA_unsigned_long len);
#define CORBA_wstring_free CORBA_string_free

/* 19.14 */
extern CORBA_long CORBA_fixed_integer_part(
	const void *fp);

extern CORBA_long CORBA_fixed_fraction_part(
	const void *fp);

extern void CORBA_fixed_set(
	void *rp,
	CORBA_long i,
	CORBA_long f);

extern void CORBA_fixed_add(
	void *rp,
	const void *f1p,
	const void *f2p);

extern void CORBA_fixed_sub(
	void *rp,
	const void *f1p,
	const void *f2p);

extern void CORBA_fixed_mul(
	void *rp,
	const void *f1p,
	const void *f2p);

extern void CORBA_fixed_div(
	void *rp,
	const void *f1p,
	const void *f2p);

extern CORBA_fixed_d_s *CORBA_fixed_alloc(
	CORBA_unsigned_short d);

extern void CORBA_free(
	void *storage);

extern int ORBit_parse_inet(
	CORBA_Object obj,
	char *hostname,
	unsigned short port,
	gboolean existing_only);

extern int ORBit_parse_unixsock(CORBA_Object obj,
				char *sockpath,
				gboolean existing_only);

/****
     This function lets you use your own event loop, if you so wish.
     Also see IIOP.h's IIOP{Add,Remove}ConnectionHandler function pointers,
     which are app-settable (you should set them before CORBA_ORB_init,
     if you want them to be useful)
 ****/

    /* needs to be called by your event loop when data comes in on one of the
       GIOPConnection fd's */
void ORBit_custom_run_setup(CORBA_ORB orb, CORBA_Environment *ev);
	void ORBit_handle_incoming(GIOPConnection *connection);

/* Returns CORBA_TRUE if the request is OK to proceed. */
typedef enum {
	ORBIT_MESSAGE_BAD,
	ORBIT_MESSAGE_ALLOW,
	ORBIT_MESSAGE_ALLOW_ALL /* Allow all subsequent messages on
				   this connection with no checking */
} ORBit_MessageValidationResult;
typedef ORBit_MessageValidationResult (*ORBit_request_validate)
	     (CORBA_unsigned_long request_id,
	      CORBA_Principal *principal,
	      CORBA_char *operation);
void ORBit_set_request_validation_handler(ORBit_request_validate validator);

extern struct iovec ORBit_default_principal_iovec;
void ORBit_set_default_principal(CORBA_Principal *principal);

extern CORBA_unsigned_long ORBit_class_assignment_counter;

CORBA_unsigned_long ORBit_register_class(const PortableServer_ClassInfo *class_info);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/* !_ORBIT_H_ */
