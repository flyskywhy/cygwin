/* $Id: auto.h,v 1.1 2004/01/29 13:49:34 cegger Exp $
******************************************************************************

   Header for auto target.

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

#ifndef _GGI_DISPLAY_AUTO_H
#define _GGI_DISPLAY_AUTO_H

#include <ggi/internal/ggi-dl.h>


/* Target specific data */
struct ggi_auto_TargetOption {
	int (*checkDisplay)(void);

	int num_options;
	const char **option;	/* array of options */
};


/* OS specific data */
struct ggi_auto_Target {
	const char *display;	/* display target */
	const char *os_options;	/* OS option string */

	/* target specific options */
	struct ggi_auto_TargetOption *probe;
};


typedef struct {
	/* The OS contains the list of targets to probe for */
	struct ggi_auto_Target *target;
	int num_targets;
} ggi_auto_priv;


#define NO_OPTION	NULL


/* probe.c */
ggi_visual_t _GGI_auto_findOptimalTarget(ggi_auto_priv *priv);


/* <os>.c */
int OS_createTargetInfo(ggi_auto_priv *priv);
int OS_freeTargetInfo(ggi_auto_priv *priv);


#endif /* _GGI_DISPLAY_AUTO_H */
