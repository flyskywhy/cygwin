/* $Id: gg_replace.h.in,v 1.9 2005/08/08 08:48:16 pekberg Exp $
******************************************************************************

   LibGG replacements for missing or broken library functions.
 
   Copyright (C) 2004 Peter Ekberg	[peda@lysator.liu.se]

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   THE AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

******************************************************************************
*/

#ifndef _GGI_INTERNAL_GG_REPLACE_H
#define _GGI_INTERNAL_GG_REPLACE_H

#include <ggi/gg-defs.h>


#ifndef intptr_t
#define intptr_t	intptr_t
#endif

#ifndef uintptr_t
#define uintptr_t	uintptr_t
#endif


/* using system strtoul */

#ifdef _GG_REPLACE_STRTOUL
#define strtoul _gg_strtoul
GGAPIFUNC unsigned long
strtoul(const char *nptr, char **endptr, int base);
#endif

/* using system memcmp */

#ifdef _GG_REPLACE_MEMCMP
#define memcmp _gg_memcmp
GGAPIFUNC int
memcmp(const void *s1, const void *s2, size_t n);
#endif

/* using system getopt */

#ifdef _GG_REPLACE_GETOPT
#define getopt   _gg_getopt
#define opterr   _gg_opterr
#define optind   _gg_optind
#define optopt   _gg_optopt
#define optreset _gg_optreset
#define optarg   _gg_optarg
GGAPIFUNC int
getopt(int nargc, char * const nargv[], const char *ostr);
GGAPIVAR int opterr;
GGAPIVAR int optind;
GGAPIVAR int optopt;
GGAPIVAR int optreset;
GGAPIVAR char *optarg;
#endif

/* using system snprintf */

#ifdef _GG_REPLACE_SNPRINTF
#define snprintf _gg_snprintf
GGAPIFUNC int
snprintf(char *str, size_t count, const char *fmt, ...);
#endif

/* using system vsnprintf */

#ifdef _GG_REPLACE_VSNPRINTF
#include <stdarg.h>	/* for va_list */

#define vsnprintf _gg_vsnprintf
GGAPIFUNC int
vsnprintf(char *str, size_t count, const char *fmt, va_list args);
#endif

/* using system strlcpy */
/* using system strlcat */

/* using system strcasecmp */
/* using system strncasecmp */

/* using system popen */
/* using system pclose */

#endif /* _GGI_INTERNAL_GG_REPLACE_H */
