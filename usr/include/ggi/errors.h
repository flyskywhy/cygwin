/* $Id: errors.h,v 1.6 2005/05/01 00:46:26 aldot Exp $
******************************************************************************

   GGI error definitions

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

   GGI returncode policy is usually (unless otherwise noted):

   ==0 on normal completion
    >0 when giving additional hints or returning positive integer data
    <0 for errors

   GGI error codes are of the form GGI_*, and are guaranteed to be
   negative (except GGI_OK ofcourse, which is guaranteed to be zero).

******************************************************************************
*/

#ifndef _GGI_ERRORS_H
#define _GGI_ERRORS_H

#define GGI_OK		  0	/* All is well */

#define GGI_ENOMEM	-20	/* Out of memory */
#define GGI_ENOFILE	-21	/* File does not exist */
#define GGI_ENODEVICE	-22	/* Input/Output device can not be opened */
#define GGI_EARGREQ	-23	/* Required argument missing */
#define GGI_EARGINVAL	-24	/* Invalid argument(s) */
#define GGI_ENOTALLOC	-25	/* Trying to use or deallocate a resource that
				   was not previously allocated */
#define GGI_EFATAL	-26	/* Fatal error - the state of the target of
				   the operation is undefined */
#define GGI_EBADFILE	-27	/* Error reading (config) file */
#define GGI_ENOSPACE	-28	/* Out of space / range */
#define GGI_ENOFUNC	-29	/* Function not implemented */
#define GGI_EBUSY	-30	/* Object is busy */
#define GGI_ENOTFOUND	-31	/* The requested object was not found */
#define GGI_EEXCLUSIVE	-32	/* Tried to get non-exclusive access to object
				   which only supports exclusive access */
#define GGI_ENOMATCH	-33	/* No matching entry found */

#define GGI_EEVUNKNOWN	-40	/* Unknown event sent to or received from
				   input source */
#define GGI_EEVNOTARGET	-41	/* No apropriate target for sent event */
#define GGI_EEVOVERFLOW	-42	/* Overflow when queuing event */

#define GGI_EUNKNOWN	-99	/* Unknown error */

#endif /* _GGI_ERRORS_H */
