/* $Id: linvtsw.h,v 1.2 2004/10/31 15:16:43 cegger Exp $
******************************************************************************

   VT switch handling for Linux console

   Copyright (C) 1999 Marcus Sundber	[marcus@ggi-project.org]

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

#ifndef _GGI_DISPLAY_LINVTSW_H
#define _GGI_DISPLAY_LINVTSW_H

#include <ggi/internal/ggi-dl.h>

typedef void (ggi_linvtsw_func)(void *vis);

typedef struct {
	/* Function to call when switch away is requested */
	ggi_linvtsw_func *switchreq;
	/* Function to call when switch away is actually done */
	ggi_linvtsw_func *switching;
	/* Function to call when switched back to */
	ggi_linvtsw_func *switchback;
	/* Argument to pass to the functions */
	void *funcarg;
	/* Flag telling if we should halt the app on switch away */
	int  *dohalt;
	/* Flag telling if we should switch immediately or when the app calls
	   doswitch (see bellow) */
	int  *autoswitch;
	/* Flag telling if we are displaying on the console hardware.
	   If this is set the console will be put in KD_GRAPHIC mode,
	   and an expose event will be generated on switchback. */
	int   onconsole;
	/* The helper returns the current VT number here */
	int   vtnum;
	/* Set by linvtsw uppon return. If autoswitch is not set the target
	   should call this when switch away should occur. */
	ggi_linvtsw_func *doswitch;
	/* If this is non-zero a new VT will always be allocated.
	   If this can't be done we will fail. */
	int   forcenew;
	/* Completely detach from the VT system. */
	int   novt;
	/* The helper returns the usage count here. If it is > 1 it is not
	   advisable to open things like input-linux-kbd, because it's most
	   likely already open. */
	int refcount;
} ggi_linvtsw_arg;

#endif /* _GGI_DISPLAY_LINVTSW_H */
