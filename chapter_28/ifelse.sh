#!/bin/sh
#ifelse.sh
a=4
b=3
if [ $a -gt $b ]
    then
    t=$b
    b=$a
    a=$t
    fi
echo "a = $a"
echo "b = $b"
exit 0