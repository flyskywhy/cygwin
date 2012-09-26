/* $Id: modelist.h,v 1.8 2005/07/31 15:30:39 soyt Exp $
******************************************************************************

   Functions to handle GGI_AUTO for targets with a list of modes.

   Copyright (C) 1998 Marcus Sundberg	[marcus@ggi-project.org]
   Copyright (C) 2005 Joseph Crayne	[oh.hello.joe@gmail.com]

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

#ifndef _GGI_DISPLAY_MODELIST_H
#define _GGI_DISPLAY_MODELIST_H

#include <ggi/internal/ggi-dl.h>

#if HAVE_STDINT_H
#include <stdint.h>  /* for intptr_t */
#endif
#if HAVE_INTTYPES_H
#include <inttypes.h>	/* for intptr_t */
#endif

#include <ggi/internal/gg_replace.h>


/* obsolete... */
typedef struct {
	short x, y;
	ggi_graphtype gt;
	short bpp;
	char ismodex;
} ggi_modelistmode;

typedef struct {
	ggi_mode mode;
	void *user_data;
} ggi_mode_padded;

typedef void ggi_wildcard_adjuster(ggi_mode_padded * req,
				   ggi_mode_padded * recognizer,
				   void *param);

typedef struct {
	int n;
	int max_n;
	ggi_mode_padded *list;
	/* adjust is called on a list item just before
	 * it is compared against a requested mode. It
	 * can be used to adapt the list item to the
	 * requested mode in order to give flexibility
	 * in matching. */
	ggi_wildcard_adjuster *adjust;
	void *adjust_param;
} ggi_modelist;

/* The ggi_modelist data structure...
 *
 * _GGI_modelist_create( n )
 *    create a ggi_modelist of capacity n with 0 modes in it.
 *    If n is not sufficent, the ggi_modelist will allocate more
 *    space later.
 *
 * _GGI_modelist_destroy( modelist )
 *    deallocates resources pointed to by modlist.
 *
 * _GGI_modelist_append( modelist, mode )
 *    appends the mode pointed to by mode.  A deep copy is performed.
 *
 * _GGI_modelist_checkmode( modelist, mode )
 *    finds the best matching mode and changes the fields of mode
 *    to that of a valid mode.  If a match was found, 0 is returned.
 */

/* prototypes...
ggi_modelist *_GGI_modelist_create( int n );
void _GGI_modelist_destroy( ggi_modelist *ml);
void _GGI_modelist_append( ggi_modelist *ml, ggi_mode_padded *m);
int _GGI_modelist_checkmode(ggi_modelist *ml, ggi_mode_padded *tm);
*/

typedef int (ggi_user_cmp)( ggi_mode *, intptr_t, intptr_t, void *);

typedef struct {
	ggi_mode req; /* the requested mode */
	ggi_mode sug; /* the current best suggested mode */
	intptr_t mode_extra; /* extra target-specific mode data */

	/* The user_cmp hook is called when two mode suggestions
	 * are indistinguishable.  When this happens, it may be
	 * desirable to examin the mode_extra fields.
	 * The four arguments are:
	 * 	req - pointer to requested mode
	 * 	a - mode_extra of one ggi_mode_padded
	 * 	b - mode_extra of the other ggi_mode_padded
	 * 	user_param - this will simply be the value in user_param
	 * A negative value should be returned if a is more desirable
	 * than b.
	 */
	ggi_user_cmp *user_cmp;
	void *user_param;
} ggi_checkmode_t;

/*  The _GGI_generic_checkmode_* functions were designed to allow
 *  you to implement checkmode by iterating over a list of modes
 *  in some target-specific format that you must convert to
 *  ggi_mode_padded before passing into this API.
 *
 * 	create () -- constructor
 * 	destroy () -- destructor
 *
 * 	init ( requested_mode ) -- called once before you begin
 *  		iterating.
 *
 * 	update ( new_mode_suggestion, mode_extra ) -- called to
 * 		test a suggestion against the current best.
 * 	 	mode_extra is a void pointer that will be stored
 * 	 	if this is the new best suggestion.  Its meaning
 * 	 	is up to the caller.
 *
 * 	finish( mode, mode_extra )  -- after this call, mode
 * 		and mode_extra will be the values you passed to
 * 		update() considered best.  If finish() is called
 * 		with a NULL pointer for the second argument,
 * 		then mode_extra will be discarded.
 * 		The return value is 0 if it matches requested_mode
 * 		perfectly, negative otherwise.
 *
 */

/* prototypes ...
ggi_checkmode_t *_GGI_generic_checkmode_create();
void _GGI_generic_checkmode_destroy( ggi_checkmode_t * );
void _GGI_generic_checkmode_init(ggi_checkmode_t *cm, ggi_mode *tm);
void _GGI_generic_checkmode_update(ggi_checkmode_t * cm,
				   ggi_mode * p,
				   intptr_t mode_extra);
int _GGI_generic_checkmode_finish(ggi_checkmode_t * cm,
				  ggi_mode * mode,
				  intptr_t *mode_extra);
*/


#endif				/* _GGI_DISPLAY_MODELIST_H */
