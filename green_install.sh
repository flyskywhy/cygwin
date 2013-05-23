#! /bin/sh
#
# Li Zheng <flyskywhy@gmail.com>
# 2013.5.20

set_attrib_on_exe()
{
    all=`find $1 -name "*.exe" | xargs file | grep 012 | sed "s/:.*//g"`
    for i in $all; do
        attrib +s $i
    done
}

set_attrib_on_a()
{
    all=`find $1 -name "*.a" | xargs file | grep 012 | sed "s/:.*//g"`
    for i in $all; do
        attrib +s $i
    done
}

set_attrib_on_la()
{
    all=`find $1 -name "*.la" | xargs file | grep 012 | sed "s/:.*//g"`
    for i in $all; do
        attrib +s $i
    done
}

set_attrib_on_exe ./bin
set_attrib_on_exe ./usr
set_attrib_on_a ./usr
set_attrib_on_a ./lib
set_attrib_on_la ./lib
