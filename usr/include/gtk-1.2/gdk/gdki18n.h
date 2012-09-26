/* GDK - The GIMP Drawing Kit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GTK+ Team and others 1997-1999.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/. 
 */

#ifndef __GDK_I18N_H__
#define __GDK_I18N_H__

/* GDK uses "glib". (And so does GTK).
 */
#include <glib.h>

/* international string support */

#include <stdlib.h>

#if !defined(G_HAVE_BROKEN_WCTYPE) && (defined(G_HAVE_WCTYPE_H) || defined(G_HAVE_WCHAR_H)) && !defined(X_LOCALE)
#  ifdef G_HAVE_WCTYPE_H
#    include <wctype.h>
#  else
#    ifdef G_HAVE_WCHAR_H
#      include <wchar.h>
#    endif
#  endif
#  define gdk_iswalnum(c) iswalnum(c)
#  define gdk_iswspace(c) iswspace(c)
#else
#  include <ctype.h>
#  define gdk_iswalnum(c) ((wchar_t)(c) <= 0xFF && isalnum(c))
#  define gdk_iswspace(c) ((wchar_t)(c) <= 0xFF && isspace(c))
#endif

/* The following 9 macros are added in gtk+ 1.2.X. Don't use them without
 * checking GTK_CHECK_VERSION. For example,
 *	#if GTK_CHECK_VERSION (1,2,X)
 *	    ... code which uses gdk_iswalpha(), gdk_iswcntrl(), etc. ...
 *      #endif
 */
#if !defined(G_HAVE_BROKEN_WCTYPE) && (defined(G_HAVE_WCTYPE_H) || defined(G_HAVE_WCHAR_H)) && !defined(X_LOCALE)
#  define gdk_iswalpha(c)  iswalpha(c)
#  define gdk_iswcntrl(c)  iswcntrl(c)
#  define gdk_iswdigit(c)  iswdigit(c)
#  define gdk_iswlower(c)  iswlower(c)
#  define gdk_iswgraph(c)  iswgraph(c)
#  define gdk_iswprint(c)  iswprint(c)
#  define gdk_iswpunct(c)  iswpunct(c)
#  define gdk_iswupper(c)  iswupper(c)
#  define gdk_iswxdigit(c) iswxdigit(c)
#else
#  define gdk_iswalpha(c)  ((wchar_t)(c) <= 0xFF && isalpha(c))
#  define gdk_iswcntrl(c)  ((wchar_t)(c) <= 0xFF && iscntrl(c))
#  define gdk_iswdigit(c)  ((wchar_t)(c) <= 0xFF && isdigit(c))
#  define gdk_iswlower(c)  ((wchar_t)(c) <= 0xFF && islower(c))
#  define gdk_iswgraph(c)  ((wchar_t)(c) >  0xFF || isgraph(c))
#  define gdk_iswprint(c)  ((wchar_t)(c) >  0xFF || isprint(c))
#  define gdk_iswpunct(c)  ((wchar_t)(c) <= 0xFF && ispunct(c))
#  define gdk_iswupper(c)  ((wchar_t)(c) <= 0xFF && isupper(c))
#  define gdk_iswxdigit(c) ((wchar_t)(c) <= 0xFF && isxdigit(c))
#endif

#endif /* __GDK_I18N_H__ */
