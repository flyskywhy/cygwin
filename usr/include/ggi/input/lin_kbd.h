/* $Id: lin_kbd.h,v 1.1.1.1 2001/05/12 23:00:14 cegger Exp $
******************************************************************************

   Linux-kbd inputlib - use the Linux console in mediumraw mode for key input

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

#ifndef _GGI_INPUT_LIN_KBD_H
#define _GGI_INPUT_LIN_KBD_H

typedef void (gii_linkbd_swfunc)(void *vis);

typedef struct {
	/* Function to call when switched away */
	gii_linkbd_swfunc *switchaway;
	/* Function to call when switched back to */
	gii_linkbd_swfunc *switchback;
	/* Argument to pass to the functions */
	void *funcarg;
	/* Flag telling if we should halt the app on switch away */
	int   dohalt;
	/* Flag telling if we are displaying on the console hardware.
	   If this is set the console will be put in KD_GRAPHIC mode,
	   and an expose event will be generated on switchback. */
	int   onconsole;
	/* The size we should specify in expose events if onconsole is set. */
	int x, y;
} gii_inputlinkbd_arg;

/* Send this event to change the once specified size for expose events. */
#define GII_CMDCODE_LINKBDSETSIZE (0x01 | GII_CMDFLAG_PRIVATE)
typedef struct {
	int x, y;
} gii_linkbd_cmddata_setsize;

#endif /* _GGI_INPUT_LIN_KBD_H */
