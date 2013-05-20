#! /bin/sh
#
# Li Zheng <flyskywhy@gmail.com>
# 2013.5.20

set_attrib()
{
    all=`find $1 -name "*.exe" | xargs file | grep 012 | sed "s/:.*//g"`
    for i in $all; do
        attrib +s $i
    done
}

set_attrib ./bin
set_attrib ./usr