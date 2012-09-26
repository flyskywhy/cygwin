/* $Id: xwin.h,v 1.3 2005/03/28 20:33:33 pekberg Exp $
******************************************************************************

   Xwin inputlib - use an existing X window as a LibGII input source

   Copyright (C) 1998 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_INPUT_XWIN_H
#define _GGI_INPUT_XWIN_H

#include <X11/Xlib.h>

/* Returns non-zero if we should queue the expose event */
typedef int (gii_inputxwin_exposefunc)(void *arg, int x, int y, int w, int h);
typedef int (gii_inputxwin_resizefunc)(void *arg, int w, int h, gii_event *ev);
typedef int (gii_inputxwin_lockfunc)(void *arg);
typedef int (gii_inputxwin_unlockfunc)(void *arg);

typedef struct {
	Display *disp;		/* Display to use */
	Window   win;		/* Window to use */
	int	 ptralwaysrel;	/* Pointer events are always relative */
	int	 wait;		/* Wait for SETPARAM event before being
				   usable */
	gii_inputxwin_exposefunc *exposefunc; /* If this is non-null we call
				   the specified function to see if we should
				   send the expose event or not */
	void	*exposearg;	/* This is the argument we pass to exposefunc*/
	gii_inputxwin_resizefunc *resizefunc; /* If this is non-null we call
				   the specified function to fill in a suitable
				   event to send due to the resize if it returns
				   0. If it returns non-0, we don't queue any
				   event. */
	void	*resizearg;	/* This is the argument we pass to resizefunc*/
	gii_inputxwin_lockfunc *lockfunc; /* If this is non-null we call
				   the specified function to lock the polling
				   function */
	void	*lockarg;	/* This is the argument we pass to lockfunc */
	gii_inputxwin_unlockfunc *unlockfunc; /* If this is non-null we call
				   the specified function to unlock the polling
				   function */
	void	*unlockarg;	/* This is the argument we pass to unlockfunc*/
} gii_inputxwin_arg;

/* Send this event to change parameters on the fly */
#define GII_CMDCODE_XWINSETPARAM (0x01 | GII_CMDFLAG_PRIVATE)
typedef struct {
	Window	 win;
	int	 ptralwaysrel;
	Window	 parentwin;
} gii_xwin_cmddata_setparam;

#endif /* _GGI_INPUT_XWIN_H */
