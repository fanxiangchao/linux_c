#!/bin/sh
#str.sh
str1="hello"
str2="hello"
str3=""

test "$str1"="$str2"
echo $?
test -z "$str3"
echo $?
test -n "$str2"
echo $?
test "$str1"="$str2"
echo $?

echo "using [ ]"
[ "$str1"="$stt2" ]
echo $?
[ -z "$str3" ]
echo $?
[ -n "str2" ]
echo $?
[ "$str1" != "$str2" ]
echo $?
exit 0