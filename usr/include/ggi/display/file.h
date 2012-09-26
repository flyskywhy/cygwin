/* $Id: file.h,v 1.6 2005/07/31 15:30:38 soyt Exp $
******************************************************************************

   Display-file: definitions

   Copyright (C) 1998 Andrew Apted		[andrew@ggi-project.org]
   Copyright (C) 1998-2000 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GGI_DISPLAY_FILE_H
#define _GGI_DISPLAY_FILE_H

#include <ggi/internal/ggi-dl.h>


typedef int  (file_detect_func)(char *filename);
typedef void (file_writer_func)(ggi_visual *vis);

#define FILE_BUFFER_SIZE  1024


typedef struct {
	int flags;

	char *filename;

	file_writer_func *writer;

	int      fb_size;
	int      fb_stride;
	uint8_t *fb_ptr;

	int num_cols;

	/* raw mode */
	int offset_pal;
	int offset_image;

	int      file_size;
	uint8_t *file_mmap;

	/* output buffering */
	int buf_len;
	uint8_t buffer[FILE_BUFFER_SIZE];

	char *flushcmd;
	int   flushtotal;
	int   flushevery;
	int   flushcnt;
	struct timeval	flushlast;
	struct timeval	flushstep;

} ggi_file_priv;

#define FILEFLAG_RAW	0x0001

#define FILE_PRIV(vis)	((ggi_file_priv *) LIBGGI_PRIVATE(vis))


#define ROUND_UP_SIZE  (4*1024)   /* FIXME: depends on page size */


/* File Primitives
 */

extern int  _ggi_file_create_file(ggi_visual *vis, const char *filename);
extern void _ggi_file_close_file(ggi_visual *vis);
extern void _ggi_file_rewind(ggi_visual *vis);
extern void _ggi_file_flush(ggi_visual *vis);

extern void _ggi_file_write_byte(ggi_visual *vis, unsigned int val);
extern void _ggi_file_write_word(ggi_visual *vis, unsigned int val);
extern void _ggi_file_write_string(ggi_visual *vis, const unsigned char *str);
extern void _ggi_file_write_zeros(ggi_visual *vis, int count);


/* Image Writers
 */

extern file_detect_func _ggi_file_ppm_detect;
extern file_writer_func _ggi_file_ppm_write;

/* Misc
 */

extern int GGI_file_resetmode(ggi_visual *vis);


/* LibGGI Interface
 */

ggifunc_getmode			GGI_file_getmode;
ggifunc_setmode			GGI_file_setmode;
ggifunc_checkmode		GGI_file_checkmode;
ggifunc_getapi			GGI_file_getapi;
ggifunc_setflags		GGI_file_setflags;
ggifunc_setPalette	GGI_file_setPalette;

/**************************************************************************

RAW FILE FORMAT
===============

   FILE = header [ palette ] padding image.

   header = magic width height graphtype stride padsize.

   magic = 0x10 "GGIFILE".

   width, height, padsize, stride = <high byte> <low byte>.

   graphtype = <scheme byte> <subscheme byte> <size byte> <depth byte>.

   palette = color...        // number of colors is (1<<depth)

   color = <red byte> <green byte> <blue byte>.

   padding = <zero byte>...  // number of zeros given by padsize
                             // (Note: the header + palette is padded
                             // to a multible of the image stride)
   image = <image byte>...

**************************************************************************/

#endif /* _GGI_DISPLAY_FILE_H */
