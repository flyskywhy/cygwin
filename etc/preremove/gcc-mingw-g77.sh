#!/bin/sh
[ -f /etc/preremove/gcc-mingw-g77-manifest.lst ] || exit 0
echo "*** Removing gcc-mingw-g77 files.  Please wait. ***"
cd /usr
/bin/rm -rvf `cat /etc/preremove/gcc-mingw-g77-manifest.lst` /etc/preremove/gcc-mingw-g77-manifest.lst
