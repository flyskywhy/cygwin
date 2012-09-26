## dpatch.lib.shpp			-*- shell-script -*-

set -e

dpatch_lib_patch ()
{
	if test "x${DPATCH_LIB_NO_DEFAULT}" = "x"; then
		patch -p1 $*
		return
	fi
	dpatch_patch $*
}

dpatch_lib_unpatch ()
{
	if test "x${DPATCH_LIB_NO_DEFAULT}" = "x"; then
		patch -p1 -R $*
		return
	fi
	dpatch_unpatch $*
}


case $0 in
	*/dpatch-run)
		patch=$1
		action=$2
		workdir=$3
		;;
	*)
		patch=$0
		action=$1
		workdir=$2
		;;
esac

if test "x$action" = "x"; then
    echo "$(basename ${patch}): script expects -patch|-unpatch as argument" >&2
    exit 1
fi

[ -f debian/patches/00patch-opts ] && . debian/patches/00patch-opts
patch_opts="${patch_opts:--g0 -f --no-backup-if-mismatch} ${workdir:+-d ${workdir}}"

case "${action}" in
	-patch) dpatch_lib_patch ${patch_opts} < ${patch};;
	-unpatch) dpatch_lib_unpatch ${patch_opts} < ${patch};;
	*)
	        echo "$(basename ${patch}): script expects -patch|-unpatch as argument" >&2
		exit 1;;
esac

exit 0

