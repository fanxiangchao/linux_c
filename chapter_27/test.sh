#!/bin/sh
#test.sh
[ -f $1 ]
echo $?
[ -d $2 ]
echo $?
[ -s $3 ]
echo $?
[ -f $0 ]
echo $?
exit 0