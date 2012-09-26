/* $Id: ggi-unix.h,v 1.3 2005/07/31 15:30:38 soyt Exp $
******************************************************************************

   LibGGI UNIX-specific API header file

   Copyright (C) 1999 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_GGI_UNIX_H
#define _GGI_GGI_UNIX_H

#include <ggi/ggi.h>


__BEGIN_DECLS

/* Wait for filedescriptors and LibGGI events the the same time */
GGIAPIFUNC int ggiEventSelect(ggi_visual_t vis, ggi_event_mask *mask, int n,
			      fd_set *readfds, fd_set *writefds,
			      fd_set *exceptfds, struct timeval *timeout);

__END_DECLS

#endif /* GGI_GGI_UNIX_H */
