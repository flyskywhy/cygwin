/* $Id: directx.h,v 1.1 2004/08/27 12:01:07 pekberg Exp $
******************************************************************************

   directx inputlib - use an existing directx window as a LibGII input source

   Copyright (C) 2004 Peter Ekberg	[peda@lysator.liu.se]

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

#ifndef _GGI_INPUT_DIRECTX_H
#define _GGI_INPUT_DIRECTX_H

#include <ggi/events.h>

/* Send this event to make input-directx reread system parameters
 * such as the keyboard repeat rate.
 */
#define GII_CMDCODE_DXSETTINGCHANGE \
	(0x01 | GII_CMDFLAG_PRIVATE | GII_CMDFLAG_NODATA)

#endif /* _GGI_INPUT_DIRECTX_H */
