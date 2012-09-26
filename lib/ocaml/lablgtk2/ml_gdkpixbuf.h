/* $Id: ml_gdkpixbuf.h,v 1.7 2005/10/28 02:01:28 garrigue Exp $ */

#define GdkPixbuf_val(val)       (check_cast(GDK_PIXBUF, val))
CAMLexport value Val_GdkPixbuf_ (GdkPixbuf *, gboolean);
#define Val_GdkPixbuf(p)         Val_GdkPixbuf_(p, TRUE)
#define Val_GdkPixbuf_new(p)     Val_GdkPixbuf_(p, FALSE)
