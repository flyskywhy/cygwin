#!/bin/sh
[ -f /etc/preremove/gcc-mingw-gpc-manifest.lst ] || exit 0
echo "*** Removing gcc-mingw-gpc files.  Please wait. ***"
cd /usr
/bin/rm -rvf `cat /etc/preremove/gcc-mingw-gpc-manifest.lst` /etc/preremove/gcc-mingw-gpc-manifest.lst
