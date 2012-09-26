# -*- Makefile -*-, you silly Emacs!
# vim: set ft=make:

DPATCH_PACKAGE	?= ${DEB_SOURCE_PACKAGE}
DPATCH_PACKAGE	?= ${PACKAGE}
DPATCH_STAMPDIR	?= debian/patched
DPATCH_STAMPFN	?= patch-stamp

ifdef PATCHLIST
UNPATCHLIST	:= ${PATCHLIST}
DPATCH_ALL	:=
else
DPATCH_ALL	:= -all
endif

ifneq (${DPATCH_STAMPDIR},debian/patched)
_STAMPDIR	:= --stampdir=${DPATCH_STAMPDIR}
endif

ifdef DPATCH_WORKDIR
_WORKDIR	:= --workdir ${DPATCH_WORKDIR}
endif

patch: ${DPATCH_STAMPFN}
${DPATCH_STAMPFN}:
	test -d ${DPATCH_STAMPDIR} || install -d ${DPATCH_STAMPDIR}
	@echo "Patches applied in the Debian version of ${DPATCH_PACKAGE}:" > $@T
	@echo >> $@T
	dpatch ${_WORKDIR} apply${DPATCH_ALL} ${_STAMPDIR} ${PATCHLIST}
	dpatch ${_WORKDIR} cat${DPATCH_ALL} ${PATCHLIST} >>$@T
	mv -f $@T $@

unpatch:
	dpatch ${_WORKDIR} deapply${DPATCH_ALL} ${_STAMPDIR} ${UNPATCHLIST}
	rm -rf ${DPATCH_STAMPFN} ${DPATCH_STAMPFN}T ${DPATCH_STAMPDIR}

