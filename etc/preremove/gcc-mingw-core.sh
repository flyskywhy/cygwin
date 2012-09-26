#!/bin/sh
[ -f /etc/preremove/gcc-mingw-core-manifest.lst ] || exit 0
echo "*** Removing gcc-mingw-core files.  Please wait. ***"
cd /usr
/bin/rm -rvf `cat /etc/preremove/gcc-mingw-core-manifest.lst` /etc/preremove/gcc-mingw-core-manifest.lst
