/* $Id: unit.h,v 1.5 2004/11/27 23:10:39 soyt Exp $
******************************************************************************

   LibGGI core - conversion between units

   Copyright (C) 2004 Christoph Egger	[Christoph_Egger@]

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

#ifndef _GGI_INTERNAL_UNIT_H
#define _GGI_INTERNAL_UNIT_H

#include "config.h"
#include <ggi/internal/internal.h>


static inline void _ggi_unit_dpi2pix(ggi_coord *pix, const ggi_coord *dpi,
			const ggi_coord *dpp)
{
#if 0
	LIB_ASSERT(dpp != NULL, "Invalid argument");
	LIB_ASSERT(dpp != NULL, "Invalid argument");
	LIB_ASSERT(dpi != NULL, "Invalid argument");
	LIB_ASSERT(dpi != NULL, "Invalid argument");
	LIB_ASSERT(pix != NULL, "Invalid argument");
	LIB_ASSERT(pix != NULL, "Invalid argument");

	LIB_ASSERT(dpp->x != 0, "Division by zero");
	LIB_ASSERT(dpp->y != 0, "Division by zero");
#endif
	pix->x = dpi->x / dpp->x;
	pix->y = dpi->y / dpp->y;

	return;
}


static inline void _ggi_unit_pix2dpi(ggi_coord *dpi, const ggi_coord *pix,
			const ggi_coord *dpp)
{
#if 0
	LIB_ASSERT(dpp != NULL, "Invalid argument");
	LIB_ASSERT(dpp != NULL, "Invalid argument");
	LIB_ASSERT(dpi != NULL, "Invalid argument");
	LIB_ASSERT(dpi != NULL, "Invalid argument");
	LIB_ASSERT(pix != NULL, "Invalid argument");
	LIB_ASSERT(pix != NULL, "Invalid argument");

	LIB_ASSERT(dpp->x != 0, "Division by zero");
	LIB_ASSERT(dpp->y != 0, "Division by zero");
#endif
	dpi->x = pix->x / dpp->x;
	dpi->y = pix->y / dpp->y;

	return;
}

#endif /* _GGI_INTERNAL_UNIT_H */
