/* $Id: quartz.h,v 1.2 2005/01/28 10:03:58 cegger Exp $
******************************************************************************

   Quartz Input Header

   Copyright (C) 2004 Christoph Egger

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

#ifndef _GGI_INPUT_QUARTZ_H
#define _GGI_INPUT_QUARTZ_H

#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>

typedef struct {
	WindowRef theWindow;
	void *gglock;		/* locking mutex */
} gii_inputquartz_arg;

/* Send this event to change parameters on the fly */
#define GII_CMDCODE_QZSETPARAM	(0x01 | GII_CMDFLAG_PRIVATE)
typedef struct {
	WindowRef theWindow;
	int (*resizefunc)(WindowRef theWindow, Rect orig, Rect prev, Rect cur);

	unsigned int flags;
} gii_quartz_cmddata_setparam;

#define GII_QZFLAG_UPDATE_WINDOW	1
#define GII_QZFLAG_UPDATE_RESIZEFUNC	2

#endif /* _GGI_INPUT_QUARTZ_H */

