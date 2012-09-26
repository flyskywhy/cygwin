/*
******************************************************************************

   Headers for KII target.

   Copyright (C) 2004 Nicholas Souchu

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

#ifndef _GGI_INPUT_KII_H
#define _GGI_INPUT_KII_H

#include <stdlib.h>

#ifndef __FreeBSD__
#  include <kgi/config.h>
#  include <kgi/system.h>
#endif

#define KII_NEED_MODIFIER_KEYSYMS
#include <kii/kii.h>

#include <ggi/internal/gii-dl.h>
#include <ggi/internal/gii_debug.h>

/*
 * KII display options
 */
enum {
	KII_OPT_DEVICE = 0,
	KII_NUM_OPTS
};

struct kii_context_s
{
	struct {
		int	fd;
	} mapper;

	struct {

		kii_u_t  size, curr;
		kii_u8_t buffer[1024];

	} evbuf;
	kiic_mapper_get_keymap_info_result_t keymap_info;
};

typedef struct kii_context_s kii_context_t;

GIIAPIFUNC kii_error_t kiiInit(kii_context_t *ctx, const gg_option *options);
GIIAPIFUNC kii_error_t kiiMapDevice(kii_context_t *ctx);
GIIAPIFUNC int kiiEventDeviceFD(kii_context_t *ctx);

#define	KII_DEVICE_KEYBOARD	1
#define	KII_DEVICE_POINTER	2
GIIAPIFUNC kii_u_t kiiLegalModifier(kii_context_t *ctx, kii_u_t device, kii_u32_t key);

GIIAPIFUNC void kiiGetu(kii_context_t *ctx, kii_enum_t var, kii_u_t *val);
GIIAPIFUNC kii_error_t kiiGetKeymap(kii_context_t *ctx, kii_unicode_t *map,
	kii_u_t keymap, kii_u_t keymin, kii_u_t keymax);

GIIAPIFUNC kii_u_t kiiEventAvailable(kii_context_t *ctx);
GIIAPIFUNC const kii_event_t *kiiNextEvent(kii_context_t *ctx);

GIIAPIFUNC void kiiPrintEvent(kii_context_t *ctx, FILE *f, const kii_event_t *ev);

#endif /* _GGI_INPUT_KII_H */
