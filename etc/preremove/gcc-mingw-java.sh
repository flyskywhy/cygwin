#!/bin/sh
[ -f /etc/preremove/gcc-mingw-java-manifest.lst ] || exit 0
echo "*** Removing gcc-mingw-java files.  Please wait. ***"
cd /usr
/bin/rm -rvf `cat /etc/preremove/gcc-mingw-java-manifest.lst` /etc/preremove/gcc-mingw-java-manifest.lst
