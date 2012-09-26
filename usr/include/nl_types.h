/* Copyright (C) 1996, 1997, 1999, 2003, 2004 Free Software Foundation, Inc.
   This file is part of the Catgets package, which is a copy of a
   component of the GNU C Library.

   Catgets is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   Catgets is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with Catgets; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.
*/

#ifndef _NL_TYPES_H
#define _NL_TYPES_H 1

#include <features.h>

/* Convenience macros to test the version of glibc.
   Use like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note - this won't work for gcc1, since the _MINOR macro wasn't
   defined then.

   Glibc's features.h defines __GNUC_PREREQ
  */
#ifndef __GNUC_PREREQ
 #if defined __GNUC__ && defined __GNUC_MINOR__
 # define __GNUC_PREREQ(maj, min) \
  ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
 #else
 # define __GNUC_PREREQ(maj, min) 0
 #endif
#endif

/* The nonnull function attribute allows to mark pointer parameters which
   must not be NULL.  

   Newer glibc's features.h defines __nonnull
*/
#ifndef __nonnull
 #if __GNUC_PREREQ (3,3)
 # define __nonnull(params) __attribute__ ((__nonnull__ params))
 #else
 # define __nonnull(params)
 #endif
#endif


/* GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this works only with
   gcc 2.8.x and egcs.  For gcc 3.2 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well.  

   Glibc's features.h define __THROW and __NTH
*/
#if !defined(__THROW)
# if !defined __cplusplus && __GNUC_PREREQ (3, 3)
#  define __THROW	__attribute__ ((__nothrow__))
#  define __NTH(fct)	__attribute__ ((__nothrow__)) fct
# else
#  if defined __cplusplus && __GNUC_PREREQ (2,8)
#   define __THROW	throw ()
#   define __NTH(fct)	fct throw ()
#  else
#   define __THROW
#   define __NTH(fct)	fct
#  endif
# endif
#endif


/* The default message set used by the gencat program.  */
#define NL_SETD 1

/* Value for FLAG parameter of `catgets' to say we want XPG4 compliance.  */
#define NL_CAT_LOCALE 1


__BEGIN_DECLS

/* Message catalog descriptor type.  */
typedef void *nl_catd;

/* Type used by `nl_langinfo'.  */
/* Cygwin langinfo.h declares this
typedef int nl_item;
*/

/* Open message catalog for later use, returning descriptor.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern nl_catd catopen (__const char *__cat_name, int __flag) __nonnull ((1));

/* Return translation with NUMBER in SET of CATALOG; if not found
   return STRING.  */
extern char *catgets (nl_catd __catalog, int __set, int __number,
		      __const char *__string) __THROW __nonnull ((1));

/* Close message CATALOG.  */
extern int catclose (nl_catd __catalog) __THROW __nonnull ((1));

__END_DECLS

#endif /* nl_types.h  */
