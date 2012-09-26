#!/bin/sh
prefix=/usr
bindir=${prefix}/bin
sbindir=${prefix}/sbin

${sbindir}/update-alternatives --remove automake ${bindir}/automake-1.4

