/* $Id: mansync.h,v 1.6 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Helper library for the implementation of SYNC mode on targets which are
   inherently ASYNC (e.g. X) and require manual flushes of the framebuffer.

   Copyright (C) 1998 Steve Cheng      [steve@ggi-project.org]
   Copyright (C) 1998 Marcus Sundberg  [marcus@ggi-project.org]

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

   -----------------------------------------------------------------------

   There is currently one method of doing the above:

   MANSYNC_TASK: A task which periodically flushes the framebuffer

   A target wishing to use mansync should open mansync with _ggiAddDL()
   in it's own GGIopen().
   It must pass a pointer to a _ggi_opmansync structure as the argument
   to _ggiAddDL(), and must define the following macros:

   MANSYNC_init(vis)
   MANSYNC_deinit(vis)
   MANSYNC_start(vis)
   MANSYNC_stop(vis)
   MANSYNC_ignore(vis)
   MANSYNC_cont(vis)

   which is supposed to call the functions in _ggi_opmansync respectively.

   Mansync provides the following functions:

	int _GGI_mansync_init(vis);
	int _GGI_mansync_deinit(vis);
		Initialize/deinitialize mansync for given visual.

	int _GGI_mansync_start(vis);
	int _GGI_mansync_stop(vis);
		Start/stop mansync handling. (process,thread,etc.)
		You don't need to explicitly call these;
		MANSYNC_SETFLAGS does it for you.

	int _GGI_mansync_ignore(vis);
	int _GGI_mansync_cont(vis);
		Temporarily start/stop mansync, e.g. during mode set.
		It is o.k. to use them even if mansync has not been started.

	MANSYNC_SETFLAGS(vis,flags)
		mansync management in ggiSetFlags().

   (The above functions return 0 if successful, -1 if not.)

   Please see display/X, display/aa or display/tile to see how mansync is
   used.  The functions should be transparent enough.

   ---------------------------------------------------------------------------
   IMPORTANT

   All targets that uses mansync.inc and can only have one
   visual per application open at a time should have a
   global variable:

   static int __GGI_<TARGETNAME>_inuse=0;

   And at the top of GGIopen:

   if (__GGI_<TARGETNAME>_inuse)
	return GGI_EBUSY;
   __GGI_<TARGETNAME>_inuse++;

   And at the end of GGIclose:

   __GGI_<TARGETNAME>_inuse--;

   You're responsible for locking your own visual, not mansync!

******************************************************************************
*/

#ifndef _GGI_DISPLAY_MANSYNC_H
#define _GGI_DISPLAY_MANSYNC_H

#include <ggi/internal/ggi-dl.h>

#define MANSYNC_FPS	20	/* Number of frames per second */


/* We rely on the first member of mansync_hook to be int isasync.
   mansync_hook is defined in individual *.c file. */

#define MANSYNC_ISASYNC(vis)	(*(int *)(vis->helperpriv))


/* Exported functions */

typedef struct {
	int (*init)(ggi_visual *vis);
	int (*deinit)(ggi_visual *vis);

	int (*start)(ggi_visual *vis);
	int (*stop)(ggi_visual *vis);

	int (*ignore)(ggi_visual *vis);
	int (*cont)(ggi_visual *vis);
} _ggi_opmansync;

int _GGI_mansync_init(ggi_visual *vis);
int _GGI_mansync_deinit(ggi_visual *vis);

int _GGI_mansync_start(ggi_visual *vis);
int _GGI_mansync_stop(ggi_visual *vis);

int _GGI_mansync_ignore(ggi_visual *vis);
int _GGI_mansync_cont(ggi_visual *vis);


/* Convenience macro */

#define MANSYNC_SETFLAGS(vis,flags)					\
do {									\
	/* Change from async to sync. */				\
	if(MANSYNC_ISASYNC(vis) && !(flags & GGIFLAG_ASYNC) &&		\
	   /* Don't start mansync if no DB */				\
	   (LIBGGI_APPLIST(vis)->num || LIBGGI_PRIVLIST(vis)->num))	\
		MANSYNC_start(vis);					\
									\
	/* From sync to async */					\
	else if(!MANSYNC_ISASYNC(vis) && (flags & GGIFLAG_ASYNC))	\
		MANSYNC_stop(vis);					\
} while(0)


/* helpers */
#define MANSYNC_DATA		_ggi_opmansync *opmansync

#define MANSYNC_DECL_INIT(priv, vis)	(priv)->opmansync->init((vis))
#define MANSYNC_DECL_DEINIT(priv, vis)	(priv)->opmansync->deinit((vis))
#define MANSYNC_DECL_START(priv, vis)	(priv)->opmansync->start((vis))
#define MANSYNC_DECL_STOP(priv, vis)	(priv)->opmansync->stop((vis))
#define MANSYNC_DECL_IGNORE(priv, vis)	(priv)->opmansync->ignore((vis))
#define MANSYNC_DECL_CONT(priv, vis)	(priv)->opmansync->cont((vis))


#endif /* _GGI_DISPLAY_MANSYNC_H */
