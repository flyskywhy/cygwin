#!/bin/sh
[ -f /etc/preremove/gcc-mingw-g++-manifest.lst ] || exit 0
echo "*** Removing gcc-mingw-g++ files.  Please wait. ***"
cd /usr
/bin/rm -rvf `cat /etc/preremove/gcc-mingw-g++-manifest.lst` /etc/preremove/gcc-mingw-g++-manifest.lst
