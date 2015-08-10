#!/bin/sh
# int_str.sh
a=1024
((a = $a + 1))
echo " the value of a is : $a"
b=102a
echo " the value of b is : $b"
declare -i b
echo " the value of b is : $b"
((b=$b + 1))
echo " the value of b is : $b"
c=""
echo " the value of c is : $c"
((c=$c + 1))
echo " the value of c is : $c"
((d=$d + 1))
echo " the value of d is : $d"
exit 0