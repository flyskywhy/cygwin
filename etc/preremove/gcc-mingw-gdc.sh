#!/bin/sh
[ -f /etc/preremove/gcc-mingw-gdc-manifest.lst ] || exit 0
echo "*** Removing gcc-mingw-gdc files.  Please wait. ***"
cd /usr
/bin/rm -rvf `cat /etc/preremove/gcc-mingw-gdc-manifest.lst` /etc/preremove/gcc-mingw-gdc-manifest.lst
