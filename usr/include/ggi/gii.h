/* $Id: gii.h,v 1.6 2005/07/29 16:40:54 soyt Exp $
******************************************************************************

   LibGII API header file

   Copyright (C) 1998      Andreas Beck		[becka@ggi-project.org]
   Copyright (C) 1999-2000 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_GII_H
#define _GGI_GII_H

#include <ggi/events.h>
#include <ggi/gii-defs.h>

#ifndef _INTERNAL_LIBGII
/* Opaque pointer types.
   This little magic gains us some type checking. */
struct gii_h_dummy1 { char dummy1; };
typedef struct gii_h_dummy1 *gii_input_t;
#endif


/*
******************************************************************************
 libGII function definitions
******************************************************************************
*/
__BEGIN_DECLS

/* Get the master config dir
 */
GIIAPIFUNC const char *giiGetConfDir(void);

/* Enter and leave the library.
 */
GIIAPIFUNC int  giiInit(void);
GIIAPIFUNC int  giiExit(void);
GIIAPIFUNC void giiPanic(const char *format, ...);

/* Turn on thread safe operation
 */
GIIAPIFUNC int giiMTInit(void);

/* Open a new Input - use input `NULL' for autoselect.
 */
GIIAPIFUNC gii_input_t	giiOpen(const char *input,...);
GIIAPIFUNC int		giiClose(gii_input_t inp);

/* Input management
 */
GIIAPIFUNC gii_input_t giiJoinInputs(gii_input_t inp, gii_input_t inp2);
GIIAPIFUNC int giiSplitInputs(gii_input_t inp, gii_input_t *newhand,
			      uint32_t origin, uint32_t flags);

/* Event Handling
 */
GIIAPIFUNC gii_event_mask	giiEventPoll(gii_input_t inp,
					     gii_event_mask mask,
					     struct timeval *t);
GIIAPIFUNC int			giiEventRead(gii_input_t inp, gii_event *ev,
					     gii_event_mask mask);
GIIAPIFUNC int			giiEventsQueued(gii_input_t inp,
						gii_event_mask mask);
GIIAPIFUNC int			giiEventSend(gii_input_t inp, gii_event *ev);
GIIAPIFUNC int			giiSetEventMask(gii_input_t inp,
						gii_event_mask evm);
GIIAPIFUNC gii_event_mask	giiGetEventMask(gii_input_t inp);

#define giiAddEventMask(inp,mask)  \
		giiSetEventMask((inp), giiGetEventMask((inp)) | (mask))
#define giiRemoveEventMask(inp,mask)  \
		giiSetEventMask((inp), giiGetEventMask((inp)) & ~(mask))

/* Deviceinfo stuff
 */
GIIAPIFUNC int	     giiQueryDeviceInfo        (gii_input_t inp,
						uint32_t origin,
						gii_cmddata_getdevinfo *info);
GIIAPIFUNC int	     giiQueryDeviceInfoByNumber(gii_input_t inp,
						uint32_t number,
						uint32_t *origin,
						gii_cmddata_getdevinfo *info);
GIIAPIFUNC int	     giiQueryValInfo   (gii_input_t inp,
					uint32_t origin,
					uint32_t valnumber,
					gii_cmddata_getvalinfo *info);

__END_DECLS

#endif /* _GGI_GII_H */
