#!/bin/sh
[ -f /etc/preremove/gcc-mingw-ada-manifest.lst ] || exit 0
echo "*** Removing gcc-mingw-ada files.  Please wait. ***"
cd /usr
for i in `cat /etc/preremove/gcc-mingw-ada-manifest.lst` ; do /bin/rm -rf $i ; done && rm -vf /etc/preremove/gcc-mingw-ada-manifest.lst
