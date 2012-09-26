#!/bin/sh
[ -f /etc/preremove/gcc-mingw-objc-manifest.lst ] || exit 0
echo "*** Removing gcc-mingw-objc files.  Please wait. ***"
cd /usr
/bin/rm -rvf `cat /etc/preremove/gcc-mingw-objc-manifest.lst` /etc/preremove/gcc-mingw-objc-manifest.lst
