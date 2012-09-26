#!/bin/sh
prefix=/usr
bindir=${prefix}/bin
sbindir=${prefix}/sbin
wrapper=${prefix}/share/autotools/am-wrapper.sh

${sbindir}/update-alternatives --remove automake ${wrapper}
