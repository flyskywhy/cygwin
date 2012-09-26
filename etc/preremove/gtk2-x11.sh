#!/bin/sh

if [ -f /etc/gtk-2.0/gdk-pixbuf.loaders ] ; then \
  rm -f /etc/gtk-2.0/gdk-pixbuf.loaders ; \
fi
if [ -f /etc/gtk-2.0/gtk.immodules ] ; then \
  rm -f /etc/gtk-2.0/gtk.immodules ; \
fi
