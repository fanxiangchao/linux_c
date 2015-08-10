#!/bin/sh
#number.sh
test "1" -eq "2"
echo $?
test "1" -ne "2"
echo $?
test "1" -gt "2"
echo $?
test "1" -lt "2"
echo $?
test "2" -ge "2"
echo $?
test "2" -le "2"
echo $?

echo "using [ ]"

[ "1" -eq "2" ]
echo $?
[ "1" -ne "2" ]
echo $?
[ "1" -gt "2" ]
echo $?
[ "1" -lt "2" ]
echo $?
[ "2" -ge "2" ]
echo $?
[ "2" -le "2" ]
echo $?

exit 0