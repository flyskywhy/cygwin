#! /bin/sh
#
# There're many symlink in cygwin, but if not attrib +s, the symlink can't work
# even Cygwin.bat can still work. setup.exe from www.cygwin.com will automatically
# attrib +s them, so we need run this shell script with this green cygwin manually.
# Li Zheng <flyskywhy@gmail.com>
# 2013.6.6

set_attrib()
{
    all=`find $1 -name "*" -print0 | xargs -0 grep "^\!<symlink>" -l`
    for i in $all; do
        attrib +s $i
    done
}

set_attrib ./bin
set_attrib ./etc
set_attrib ./lib
set_attrib ./opt
set_attrib ./srv
set_attrib ./usr
set_attrib ./var
