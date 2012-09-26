/* $Id: ggi_ext.h,v 1.8 2005/09/19 07:45:15 cegger Exp $
******************************************************************************

   Copyright (C) 1998      Andreas Beck		[becka@ggi-project.org]
   Copyright (C) 2000      Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_GGI_EXT_H
#define _GGI_GGI_EXT_H

#include <ggi/ggi.h>


#ifndef _INTERNAL_LIBGGI
/* Opaque pointer type.
   This little magic gains us some type checking. */
struct ggi_ext_h_dummy1 { char dummy1; };
typedef struct ggi_ext_h_dummy1 *ggi_lib_id;
#endif

typedef int ggi_extid;	/* Don't rely on that ! */

__BEGIN_DECLS

GGIAPIFUNC ggi_extid    ggiExtensionRegister(const char *name, size_t size,
			  int (*paramchange)(ggi_visual_t,int whatchanged));
GGIAPIFUNC int          ggiExtensionUnregister(ggi_extid id);
GGIAPIFUNC int          ggiExtensionAttach(ggi_visual_t vis,ggi_extid id);
GGIAPIFUNC int          ggiExtensionDetach(ggi_visual_t vis,ggi_extid id);
GGIAPIFUNC ggi_lib_id   ggiExtensionLoadDL(ggi_visual_t vis,
					   const void *conffilehandle,
					   const char *api,
					   const char *args, void *argptr,
					   const char *symprefix);

__END_DECLS

#endif /* _GGI_GGI_EXT_H */
