/* $Id: gii.h,v 1.18 2005/09/03 18:16:24 soyt Exp $
******************************************************************************

   LibGII internals

   Copyright (C) 1998 Andreas Beck	[becka@ggi-project.org]
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

#ifndef _GGI_INTERNAL_GII_H
#define _GGI_INTERNAL_GII_H

#define _INTERNAL_LIBGII

#include <ggi/system.h>
#include <ggi/events.h>
#include <ggi/errors.h>

typedef struct gii_input  *gii_input_t;

#include <ggi/gii.h>
#include <ggi/gg-queue.h>

/* Default symbol form libgii modules */
#define GII_DLINIT_SYM		"GIIdlinit"

#define GII_MAXSUBLIBS	256
#define GII_SUBLIBMASK	0x000000ff
#define GII_MAINMASK	0xffffff00

__BEGIN_DECLS

/* Exported variables */
GIIAPIVAR int                _gii_threadsafe;
GIIAPIVAR void              *_gii_global_lock;

/* Global variables */
extern void                 *_giiconfhandle;
extern void                 *_gii_safe_lock;
extern void                 *_gii_event_lock;

__END_DECLS

/* Function types */
typedef int		(giifunc_handler)(struct gii_input *inp,
					  gii_event *event);

typedef gii_event_mask	(giifunc_eventpoll)(struct gii_input *inp, void *arg);
typedef int		(giifunc_sendevent)(struct gii_input *inp,
					    gii_event *event);
typedef int		(giifunc_seteventmask)(struct gii_input *inp,
					       gii_event_mask evm);
typedef gii_event_mask	(giifunc_geteventmask)(struct gii_input *inp);
typedef int		(giifunc_getselectfdset)(struct gii_input *inp,
						 fd_set *readfds);
typedef int		(giifunc_inputclose)(struct gii_input *inp);
typedef int		(giifunc_inputinit)(struct gii_input *inp,
					    const char *args, void *argptr,
					    const char *target);

/* Deviceinfo */
typedef struct gii_deviceinfo {
	GG_SLIST_ENTRY(gii_deviceinfo) devlist; /* For multi-device libs */
	uint32_t                 origin;	/* Multi-device libs */
	gii_cmddata_getdevinfo  *dev;	/* Info about device */
	gii_cmddata_getvalinfo  *val;	/* Array of valuator info */
} gii_deviceinfo;

/* Cache data for an entire chain of inputsources */
typedef struct {
	int		count;		/* Usage count */
	int 		maxfd;
	fd_set		fdset;
	gii_event_mask	eventmask, inputcan;
	uint32_t       	flags;
	int		havesafe;
	int		haveasync;
	int		asyncpipes[2];	/* Write one byte to interrupt
					   giiEventPoll() */
} gii_inputchain_cache;

typedef struct gii_input {
	unsigned int		version;
	void			*mutex;		/* Lock when changing FIXME! */
	struct gii_input        *next,*prev;	/* Ring structure */

	struct gii_dlhandle	*dlhand;	/* for closing */

	uint32_t       		origin;
	int 			maxfd;
	fd_set			fdset;
	gii_event_mask		curreventmask, targetcan;
	uint32_t       		flags;

	struct gii_ev_queue_set	*queue;
	struct gii_ev_queue	*safequeue;

	giifunc_eventpoll	*GIIeventpoll;
	giifunc_sendevent	*GIIsendevent;
	giifunc_seteventmask	*GIIseteventmask;
	giifunc_geteventmask	*GIIgeteventmask;
	giifunc_getselectfdset	*GIIgetselectfdset;
	giifunc_handler		*GIIhandler;
	giifunc_inputclose	*GIIclose;

	void 			*priv;

	gii_inputchain_cache	*cache;
	GG_SLIST_HEAD(devinfo, gii_deviceinfo) devinfo;
} gii_input;

#define GII_FLAGS_HASPOLLED	0x00000001

#define GII_QUEUE_SIZE      8192
#define GII_Q_THRESHOLD     (GII_QUEUE_SIZE - (int)sizeof(gii_event) - 1)

/* The threshold the point where events wrap back to the start of the
 * buffer.  Events are stored in the buffer in whole; they do not get
 * split in half at the end of the buffer.  Instead, the event that
 * crosses the threshold will physically be the last, and the next event
 * has offset 0 in the buffer.
 *
 * Corollary: head is always <= Q_THRESHOLD.
 */

typedef struct gii_ev_queue {
	int     count;	/* number of events in the buffer */
	int     head;	/* offset into buf[] where next event is put */
	int     tail;	/* offset into buf[] of last event */
	uint8_t buf[GII_QUEUE_SIZE];
} gii_ev_queue;

typedef struct gii_ev_queue_set {
	gii_event_mask	 seen;
	gii_ev_queue	*queues[evLast];
	void		*mutex;
} gii_ev_queue_set;

typedef struct gii_dlhandle {
	void		*handle;
	void		*identifier;	/* For access to all other funcs. */
	void		*init;		/* Init functions */
} gii_dlhandle;


/* Internal API calls
 */
__BEGIN_DECLS

gii_dlhandle *_giiLoadDL(const char *name);
int _giiCloseDL(gii_dlhandle *hand);

GIIAPIFUNC void _giiEventBlank(gii_event *ev, size_t size);
GIIAPIFUNC int  _giiEvQueueAdd(gii_input *inp, gii_event *ev);

int _giiStdSendDevInfo(gii_input *inp, gii_cmddata_getdevinfo *data);
int _giiStdSendValEvent(gii_input *inp, gii_cmddata_getvalinfo *vi,
			int val, int maxval);

gii_event_mask _giiPollall(gii_input *inp, gii_event_mask mask, void *arg);

gii_inputchain_cache *_giiCacheAlloc(void);
void _giiCacheFree(gii_inputchain_cache *cache);
GIIAPIFUNC void _giiUpdateCache(gii_input *inp);

GIIAPIFUNC int _giiSafeAdd(struct gii_input *inp, gii_event *ev);
int _giiSafeMove(struct gii_input *toinp, struct gii_input *frominp);

void _giiAsyncNotify(gii_input *inp);

GIIAPIFUNC uint32_t _giiRegisterDevice(gii_input *inp,
				       gii_cmddata_getdevinfo  *dev,
				       gii_cmddata_getvalinfo  *val);

int                 _giiUnregisterDevice(gii_input *inp,
					 uint32_t origin);

__END_DECLS

#endif /* _GGI_INTERNAL_GII_H */
