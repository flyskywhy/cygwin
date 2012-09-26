#!/bin/sh
# Preremove script for wget.

/bin/cmp -s /etc/wgetrc /usr/share/doc/wget-1.10.2/sample.wgetrc &&
  { echo "$0: /etc/wgetrc is unmodified; removing for an update" ;
    /bin/rm -f /etc/wgetrc; }
