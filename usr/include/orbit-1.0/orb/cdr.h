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

#ifndef _ORBIT_CDR_H_
#define _ORBIT_CDR_H_

#include "orbit_types.h"

typedef enum {
	BigEndian=0,
	LittleEndian=1
} CDR_Endianness;

typedef struct {
	CDR_Endianness host_endian;
	CDR_Endianness data_endian;
	CORBA_octet *buffer;
	unsigned int buf_len;
	unsigned int wptr, rptr;
	CORBA_boolean readonly;
	CORBA_boolean release_buffer;
} CDR_Codec;

#define HEXDIGIT(c) (isdigit((guchar)(c))?(c)-'0':tolower((guchar)(c))-'a'+10)
#define HEXOCTET(a,b) ((HEXDIGIT((a)) << 4) | HEXDIGIT((b)))

extern CDR_Codec *CDR_codec_init(void);
extern CDR_Codec *CDR_codec_init_static(CDR_Codec *codec);
extern void CDR_codec_free(CDR_Codec *);

extern void CDR_put_short(CDR_Codec *codec, CORBA_short s);
extern void CDR_put_ushort(CDR_Codec *codec, CORBA_unsigned_short us);
extern void CDR_put_long(CDR_Codec *codec, CORBA_long l);
extern void CDR_put_ulong(CDR_Codec *codec, CORBA_unsigned_long ul);
#ifdef HAVE_CORBA_LONG_LONG
extern void CDR_put_long_long(CDR_Codec *codec, CORBA_long_long ll);
extern void CDR_put_ulong_long(CDR_Codec *codec, CORBA_unsigned_long_long ull);
extern CORBA_boolean CDR_get_ulong_long(CDR_Codec *codec, CORBA_unsigned_long_long *ul);
extern CORBA_boolean CDR_get_long_long(CDR_Codec *codec, CORBA_long_long *ul);
#endif
extern void CDR_put_float(CDR_Codec *codec, CORBA_float f);
extern void CDR_put_double(CDR_Codec *codec, CORBA_double d);
extern void CDR_put_long_double(CDR_Codec *codec, CORBA_long_double ld);
extern void CDR_put_octet(CDR_Codec *codec, CORBA_octet datum);
extern void CDR_put_octets(CDR_Codec *codec, void *data, unsigned long len);
extern void CDR_put_char(CDR_Codec *codec, CORBA_char c);
extern void CDR_put_boolean(CDR_Codec *codec, CORBA_boolean datum);
extern void CDR_put_string(CDR_Codec *codec, const char *str);
extern CORBA_boolean CDR_buffer_gets(CDR_Codec *codec, void *dest, const unsigned int len);
extern CORBA_boolean CDR_get_short(CDR_Codec *codec, CORBA_short *us);
extern CORBA_boolean CDR_get_ushort(CDR_Codec *codec, CORBA_unsigned_short *us);
extern CORBA_boolean CDR_get_long(CDR_Codec *codec, CORBA_long *l);
extern CORBA_boolean CDR_get_ulong(CDR_Codec *codec, CORBA_unsigned_long *ul);
extern CORBA_boolean CDR_get_octet(CDR_Codec *codec, CORBA_octet *datum);
extern CORBA_boolean CDR_get_boolean(CDR_Codec *codec, CORBA_boolean *b);
extern CORBA_boolean CDR_get_char(CDR_Codec *codec, CORBA_char *c);
extern CORBA_boolean CDR_get_string(CDR_Codec *codec, CORBA_char **str);
extern CORBA_boolean CDR_get_string_static(CDR_Codec *codec, CORBA_char **str);
extern CORBA_boolean CDR_get_seq_begin(CDR_Codec *codec, CORBA_unsigned_long *ul);

#endif /* !_ORBIT_CDR_H_ */
