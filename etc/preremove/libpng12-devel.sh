#!/bin/sh
prefix=/usr
sbindir=${prefix}/sbin
bindir=${prefix}/bin
libdir=${prefix}/lib
incdir=${prefix}/include
LIBNAME=libpng12

${sbindir}/update-alternatives --remove libpng ${incdir}/${LIBNAME}

