/* $Id: misc.h,v 1.5 2005/07/30 12:48:49 cegger Exp $
******************************************************************************

   LibGGIMisc extension internals.

   Copyright (c) Fri Mar  2 2001 by: 
	Brian S. Julin		bri@calyx.com

  
   
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   The above copyright notice applies to all files in this package, unless 
   explicitly stated otherwise in the file itself or in a file named COPYING 
   in the same directory as the file.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   THE AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



******************************************************************************
*/

#ifndef _GGI_INTERNAL_MISC_H
#define _GGI_INTERNAL_MISC_H

#include <ggi/internal/internal.h>
#include <ggi/misc.h>

__BEGIN_DECLS

/* Exported variables */
GGIMISCAPIVAR ggi_extid _ggiMiscID;

__END_DECLS

/*-* Data types for the API functions */
typedef int (ggiMiscfunc_WaitRayPos)(ggi_visual *vis, int32_t *x, int32_t *y);
typedef int (ggiMiscfunc_GetRayPos)(ggi_visual *vis, int32_t *x, int32_t *y);
typedef int (ggiMiscfunc_SetSplitline)(ggi_visual *vis, int y);


typedef struct ggiMiscpriv {

  /*-* API function pointers */
	ggiMiscfunc_WaitRayPos *waitraypos;
	ggiMiscfunc_GetRayPos *getraypos;
	ggiMiscfunc_SetSplitline *setsplitline;

  /*-* Other structure members */
	void *priv;

} ggiMiscpriv;

/* Used to access the ggimiscpriv structure for a particular visual. */
#define LIBGGI_GGIMISCEXT(vis) ((ggiMiscpriv *)LIBGGI_EXT((vis),_ggiMiscID))

#endif /* _GGI_INTERNAL_MISC_H */
