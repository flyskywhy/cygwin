#!/bin/sh
# cygwin-doc.sh

# determine if there is a Start Menu "Cygwin.lnk" directory, remove links if so
CYGWIN_ASM="$(cygpath -AP)/Cygwin"
if [ -d "$CYGWIN_ASM" ]; then
	if [ -f "$CYGWIN_ASM/Cygwin FAQ.lnk" ]; then
		/bin/rm -f "$CYGWIN_ASM/Cygwin FAQ.lnk"
	fi
	if [ -f "$CYGWIN_ASM/User's Guide (One file).lnk" ]; then
		/bin/rm -f "$CYGWIN_ASM/User's Guide (One file).lnk"
	fi
	if [ -f "$CYGWIN_ASM/User's Guide (PDF).lnk" ]; then
		/bin/rm -f "$CYGWIN_ASM/User's Guide (PDF).lnk"
	fi
	if [ -f "$CYGWIN_ASM/User's Guide.lnk" ]; then
		/bin/rm -f "$CYGWIN_ASM/User's Guide.lnk"
	fi
	if [ -f "$CYGWIN_ASM/Cygwin User's Guide.lnk" ]; then
		/bin/rm -f "$CYGWIN_ASM/Cygwin User's Guide.lnk"
	fi
	if [ -f "$CYGWIN_ASM/Cygwin API Reference.lnk" ]; then
		/bin/rm -f "$CYGWIN_ASM/Cygwin API Reference.lnk"
	fi
fi	


CYGWIN_SM="$(cygpath -P)/Cygwin"
if [ -d "$CYGWIN_SM" ]; then
	if [ -f "$CYGWIN_SM/Cygwin FAQ.lnk" ]; then
		/bin/rm -f "$CYGWIN_SM/Cygwin FAQ.lnk"
	fi
	if [ -f "$CYGWIN_SM/Cygwin User's Guide.lnk" ]; then
		/bin/rm -f "$CYGWIN_SM/Cygwin User's Guide.lnk"
	fi
	if [ -f "$CYGWIN_SM/Cygwin API Reference.lnk" ]; then
		/bin/rm -f "$CYGWIN_SM/Cygwin API Reference.lnk"
	fi
fi	

# Install info updates
PREFIX=/usr/share
INFODIR=${PREFIX}/info
cd ${INFODIR}
for i in libc.info libm.info; do
  install-info --delete --dir-file=${INFODIR}/dir --info-file=${i}
done
