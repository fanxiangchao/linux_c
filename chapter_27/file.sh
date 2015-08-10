#!/bin/sh
#file.sh
val=file.sh
[ -r $val ]
echo $?
[ -w $val ]
echo $?
[ -x $val ]
echo $?

test -r $val
echo $?
test -w $val
echo $?
test -x $val
echo $?

exit 0