/* $Id: ggi-defs.h,v 1.2 2005/07/31 15:30:38 soyt Exp $
******************************************************************************

   LibGGI API header file

   Copyright (C) 2004      Peter Ekberg		[peda@lysator.liu.se]

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

#ifndef _GGI_GGI_DEFS_H
#define _GGI_GGI_DEFS_H

#include <ggi/system.h>


#ifdef BUILDING_LIBGGI
# define GGIAPIFUNC EXPORTFUNC
# define GGIAPIVAR  EXPORTVAR
#else
# define GGIAPIFUNC IMPORTFUNC
# define GGIAPIVAR  IMPORTVAR
#endif

#endif /* _GGI_GGI_DEFS_H */
