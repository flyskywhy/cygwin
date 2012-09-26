#!/bin/sh
# Cygwin setup.exe runs this file just before package is being removed.
# The shell must be 'sh'.
#
# This file can be tested while doing porting by sending
# install directory in command line:
#
#    cd foo-N.N/
#    sh -x CYGWIN-PATCHES/preremove.sh .inst

PATH=/bin:/usr/bin:/sbin:$PATH

set -e

Environment()
{
    #  Define variables to the rest of the script

    [ "$1" ] && dest="$1"        # install destination

    if [ "$dest" ]; then
        #  Delete trailing slash
        dest=$(echo $dest | sed -e 's,/$,,' )
    fi

    package="quilt"        #!! CHANGE THIS

    #   This file will be installed as
    #   /etc/preremove/<package>.sh so derive <package>
    #   But if this file is run from CYGIN-PATCHES/preremove.sh
    #   then we do not know the package name

    name=$(echo $0 | sed -e 's,.*/,,' -e 's,\.sh,,' )

    if [ "$name" != "preremove" ]; then
        package="$name"
    fi

    bindir="$dest/usr/bin"
    libdir="$dest/usr/lib"
    libdirx11="$dest/usr/lib/X11"
    includedir="$dest/usr/include"

    sharedir="$dest/usr/share"
    infodir="$sharedir/info"
    docdir="$sharedir/doc"
    etcdir="$dest/etc"

    infobin="/usr/bin/install-info"

    #   1) list of files to be copied to /etc
    #   2) Source locations

    conffiles_to="$etcdir/preremove/$package-manifest.lst"
    conffiles_from="$etcdir/preremove/$package-manifest-from.lst"
}

Warn ()
{
    echo "$@" >&2
}

Run ()
{
    ${test+echo} "$@"
}

RemoveConffiles ()
{
    [ ! -f $conffiles_to ] && return

    #  If user hasn't changed the system wide configuration file,
    #  then remove it (postinstall will install new one). Find reports:
    #
    #  /usr/share/doc/package-0.17.3/
    #  /usr/share/doc/package-0.92.4/
    #  /usr/share/doc/package-0.96.1/
    #  ...
    #
    #  So take the last one and delete trailing slash.

    latest=$(LC_ALL=C find $dest/usr/share/doc/$package*/ \
               -maxdepth 0 -type d \
             | sort | tail -1 | sed 's,/$,,')

    if [ ! "$latest" ]; then
        Warn "$0: [FATAL]] Cannot find $package install doc dir"
        exit 1
    fi

    [ ! -f $conffiles_from ] && return
    [ ! -f $conffiles_to   ] && return

    tmpprefix=${TEMPDIR:-/tmp}/tmp$$
    from=$tmpprefix.from
    to=$tmpprefix.to

    #  Filter out all comments. Grep only lines with filenames

    grep '^[^#]*/' $conffiles_from > $from
    grep '^[^#]*/' $conffiles_to   > $to

    paste $from $to  |
    {
        while read from to
        do

          echo $from
          echo $to

            from=$(echo $from | sed "s,\$PKGDOCDIR,$pkgdocdir$latest," )
            to=$(echo $dest$to | sed "s,\$PKG,$pkgdocdir," )

            if [ -f $to ] && [ -f $from ] ; then
                diff $from $to > /dev/null

                if [ "$?" = "0" ]; then
                    Run rm -f "$to"
                else
                    Warn "$0: [$package:WARN] $to has changed." \
                         "Not installing new $from"
                fi
            fi
        done
    }

    rm -f $tmpprefix.*
}

Main ()
{
    Environment "$@"    &&
    RemoveConffiles
}

Main "$@"

# End of file
