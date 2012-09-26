/* $Id: misc.h,v 1.7 2005/07/30 12:48:49 cegger Exp $
******************************************************************************

   LibGGIMisc extension API header file.

   Copyright (c) 2001 Brian S. Julin	bri@calyx.com
   Copyright (c) 1999 Marcus Sundberg   marcus@ggi-project.org
   Copyright (c) 1998 Andreas Beck      becka@ggi-project.org
   
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

#ifndef _GGI_MISC_H
#define _GGI_MISC_H

#include <ggi/ggi.h>
#include <ggi/misc-defs.h>

__BEGIN_DECLS

#define GGI_RP_BORDER	(1 << 27)
#define GGI_RP_BLANK	(1 << 28)
#define GGI_RP_SYNC	(1 << 29)
#define GGI_RP_DONTCARE	(1 << 30)

/* Get the master config dir
 */
GGIMISCAPIFUNC const char *ggiMiscGetConfDir(void);

/* Extension management
 */
GGIMISCAPIFUNC int ggiMiscInit(void);
GGIMISCAPIFUNC int ggiMiscExit(void);

GGIMISCAPIFUNC int ggiMiscAttach(ggi_visual_t vis);
GGIMISCAPIFUNC int ggiMiscDetach(ggi_visual_t vis);


/*-* API functions
 */
GGIMISCAPIFUNC int ggiWaitRayPos(ggi_visual_t vis, int32_t *x, int32_t *y);
GGIMISCAPIFUNC int ggiGetRayPos(ggi_visual_t vis, int32_t *x, int32_t *y);
GGIMISCAPIFUNC int ggiSetSplitline(ggi_visual_t vis, int y);

/*-*/

__END_DECLS

#endif /* _GGI_MISC_H */
