#!/bin/sh
#or.sh
[ -x $1 -o $0 ]
echo $?
[ ! -x $0 ]
echo $?
exit 0