/* $Id: fbdev.h,v 1.9 2005/07/31 15:30:38 soyt Exp $
******************************************************************************

   Display-FBDEV

   Copyright (C) 1998 Andrew Apted	[andrew@ggi-project.org]
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

#ifndef _GGI_DISPLAY_FBDEV_H
#define _GGI_DISPLAY_FBDEV_H

#include <errno.h>
#include <sys/ioctl.h>
#include <linux/fb.h>

#include <ggi/internal/ggi-dl.h>
#include <ggi/display/linvtsw.h>

ggifunc_getmode		GGI_fbdev_getmode;
ggifunc_setmode		GGI_fbdev_setmode;
ggifunc_checkmode	GGI_fbdev_checkmode;
ggifunc_getapi		GGI_fbdev_getapi;
ggifunc_setflags	GGI_fbdev_setflags;

ggifunc_setorigin	GGI_fbdev_setorigin;
ggifunc_setdisplayframe	GGI_fbdev_setdisplayframe;

ggifunc_kgicommand	GGI_fbdev_kgicommand;


typedef struct ggi_fbdev_timing {
	uint32_t xres;		/* visible resolution		*/
	uint32_t yres;
	uint32_t xres_virtual;	/* virtual resolution		*/
	uint32_t yres_virtual;
	uint32_t bits_per_pixel;/* guess what			*/

	uint32_t pixclock;	/* pixel clock in ps (pico seconds) */
	uint32_t left_margin;	/* time from sync to picture	*/
	uint32_t right_margin;	/* time from picture to sync	*/
	uint32_t upper_margin;	/* time from sync to picture	*/
	uint32_t lower_margin;
	uint32_t hsync_len;	/* length of horizontal sync	*/
	uint32_t vsync_len;	/* length of vertical sync	*/
	uint32_t sync;		/* see FB_SYNC_*		*/
	uint32_t vmode;		/* see FB_VMODE_*		*/

	struct ggi_fbdev_timing *next; /* pointer to next mode	*/
} ggi_fbdev_timing;

/* Visual-specific private data */
typedef struct {
	PHYSZ_DATA

	/* Framebuffer info */
	void *fb_ptr;
	long  fb_size;
	long  mmap_size;
	long  frame_size;
	int   fbnum;
	int   vtnum;
	int   visidx;
	int   need_timings;
	ggi_fbdev_timing *timings;
	int   flags;
#define		GGI_FBDEV_1BPP_REV	1 /* 1bpp uses high-bit right */
#define		GGI_FBDEV_4BPP_REV	1 /* 4bpp uses high-bit right */

	struct fb_var_screeninfo var;
	struct fb_fix_screeninfo fix;


	/* We shadow vis->palette in this format as well, as
	 * it is what fbdev uses.  Note palette and gamma are
	 * mutually exclusive in the fbdev API, so gamma reuses
	 * the palette values.
	 */
	uint16_t *reds;
	uint16_t *greens;
	uint16_t *blues;
	ggi_gammastate gamma;
	ggi_color *orig_cmap;	/* used to restore pre-GGI settings */

	/* Original mode on framebuffer */
	struct fb_var_screeninfo orig_var;
	struct fb_fix_screeninfo orig_fix;

	/* VT switching and inputs */
	int dohalt;
	int autoswitch;
	int switchpending;
	int ismapped;
	ggi_linvtsw_func *doswitch;
	int inputs;
	gii_input *inp;

	/* Acceleration */
	int	iskgi;
	ggi_gc *normalgc;
	char   *accel;
	int	have_accel;
	void   *accelpriv;		/* Accel lib private data */
	volatile uint8_t  *mmioaddr;	/* Faster access for accel lib */
	ggifunc_flush	  *flush;
	ggifunc_idleaccel *idleaccel;

	/* Misc */
	void	*lock;		/* Pointer to the fbdev common lock */
	int	*refcount;	/* Pointer to the refcount */

} ggi_fbdev_priv;

#define FBDEV_PRIV(vis) ((ggi_fbdev_priv *)LIBGGI_PRIVATE(vis))


/* BIG NOTE: ioctl() has different types in the parameters:
 * Solaris: int ioctl(int fildes, int request, ...);
 * Linux: extern int ioctl (int __fd, unsigned long int __request, ...);
 * Since fbdev is Linux specific we use Linux's semantic
 */

/* Multihead safe ioctls */
#ifdef FBDEV_MH
static inline int fbdev_doioctl(ggi_visual *vis, unsigned long req, void *arg)
{
	struct fb_con2fbmap conmap;
	ggi_fbdev_priv *priv = FBDEV_PRIV(vis);
	int ret;
	int err; /* In case ggUnlock modifies errno */

	if (*priv->refcount > 1) {
		ggLock(priv->lock);
		conmap.console = priv->vtnum;
		conmap.framebuffer = priv->fbnum;
		if (ioctl(LIBGGI_FD(vis), FBIOPUT_CON2FBMAP, &conmap) != 0) {
			err = errno;
			DPRINT_MISC("FBIOPUT_CON2FBMAP failed for vis: %p\n", vis);
			ggUnlock(priv->lock);
			errno = err;
			return -1;
		}
		DPRINT_MISC("FBIOPUT_CON2FBMAP vis: %p, vt: %d, fb: %d\n",
			       vis, priv->vtnum, priv->fbnum);
		ret = ioctl(LIBGGI_FD(vis), req, arg);
		err = errno;
		ggUnlock(priv->lock);
		errno = err;

		return ret;
	} else {
		return ioctl(LIBGGI_FD(vis), req, arg);
	}
}
#else
static inline int fbdev_doioctl(ggi_visual *vis, unsigned long req, void *arg)
{
	return ioctl(LIBGGI_FD(vis), req, arg);
}
#endif

#define FBDEV_INP_KBD    0x01
#define FBDEV_INP_MOUSE  0x02

#endif /* _GGI_DISPLAY_FBDEV_H */
