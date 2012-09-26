#!/bin/sh
prefix=/usr
infodir=${prefix}/share/info

/usr/bin/install-info --delete \
	--dir-file=${infodir}/dir --info-file=${infodir}/gdbm.info.gz

