#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H 1

#include <glib.h>

typedef gint16 CORBA_short;
typedef gint32 CORBA_long;
typedef guint16 CORBA_unsigned_short;
typedef guint32 CORBA_unsigned_long;
typedef gfloat CORBA_float;
typedef gdouble CORBA_double;
typedef char CORBA_char;
typedef guchar CORBA_boolean;
typedef guchar CORBA_octet;
typedef gdouble CORBA_long_double;
typedef guint16 CORBA_wchar; /* I'm not sure what size a wchar is supposed to be */

/* Just a peeve */
typedef CORBA_char GIOP_char;
typedef CORBA_wchar GIOP_wchar;
typedef CORBA_short GIOP_short;
typedef CORBA_long GIOP_long;
typedef CORBA_unsigned_short GIOP_unsigned_short;
typedef CORBA_unsigned_long GIOP_unsigned_long;
typedef CORBA_octet GIOP_octet;
typedef CORBA_long GIOP_enum;
typedef CORBA_boolean GIOP_boolean;
typedef CORBA_float GIOP_float;
typedef CORBA_double GIOP_double;
typedef CORBA_long_double GIOP_long_double;

#ifdef G_HAVE_GINT64
#define HAVE_CORBA_LONG_LONG
/* According to the spec, these two are optional. We support them if we can. */
typedef gint64 CORBA_long_long;
typedef guint64 CORBA_unsigned_long_long;
typedef CORBA_long_long GIOP_long_long;
typedef CORBA_unsigned_long_long GIOP_unsigned_long_long;
#else
#warning ""
#warning "You don't G_HAVE_GINT64 defined in glib."
#warning "Please make sure you don't have an old glibconfig.h lying around."
#warning ""
#endif

#endif
