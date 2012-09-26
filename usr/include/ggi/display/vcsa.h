/* $Id: vcsa.h,v 1.5 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Display-VCSA: definitions

   Copyright (C) 1998 Andrew Apted    [andrew@ggi-project.org]

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

#ifndef _GGI_DISPLAY_VCSA_H
#define _GGI_DISPLAY_VCSA_H

#include <ggi/internal/ggi-dl.h>


/* Visual-private data */

typedef struct {
	PHYSZ_DATA

	int width;
	int height;

	int inputs;
	int flags;

} ggi_vcsa_priv;

#define VCSA_PRIV(vis) ((ggi_vcsa_priv *) LIBGGI_PRIVATE(vis))

#define VCSA_INP_KBD     0x0001
#define VCSA_INP_MOUSE   0x0002

#define VCSA_FLAG_ASCII  0x0100
#define VCSA_FLAG_SHADE  0x0200


/**
 ** LibGGI internal stuff
 **/

ggifunc_getmode		GGI_vcsa_getmode;
ggifunc_setmode		GGI_vcsa_setmode;
ggifunc_checkmode	GGI_vcsa_checkmode;
ggifunc_getapi		GGI_vcsa_getapi;
ggifunc_setflags	GGI_vcsa_setflags;

ggifunc_putpixel_nc	GGI_vcsa_putpixel_nc;
ggifunc_getpixel	GGI_vcsa_getpixel;
ggifunc_putc		GGI_vcsa_putc;
ggifunc_puts		GGI_vcsa_puts;
ggifunc_getcharsize	GGI_vcsa_getcharsize;
ggifunc_drawhline_nc	GGI_vcsa_drawhline_nc;
ggifunc_puthline	GGI_vcsa_puthline;
ggifunc_gethline	GGI_vcsa_gethline;

ggifunc_mapcolor	GGI_vcsa_mapcolor;
ggifunc_unmappixel	GGI_vcsa_unmappixel;

extern int GGI_vcsa_resetmode(ggi_visual *vis);


#endif /* _GGI_DISPLAY_VCSA_H */
