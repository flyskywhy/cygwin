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

#ifndef _ORBIT_OPTIONS_H_
#define _ORBIT_OPTIONS_H_

typedef enum {
	no_arg=0,
	string_arg,
	int_arg
} ORBit_opt_type;

typedef struct {
	char *name;
	ORBit_opt_type type;
	void *arg;
} ORBit_orb_options;

extern void ORBit_option_set(ORBit_orb_options *found, const char *val);
extern void ORBit_option_parse(int *argc, char **argv, ORBit_orb_options *options);

#endif /* !_ORBIT_OPTIONS_H_ */
