#!/bin/sh
#for_add.sh
for i in 1 2 3 4 5
do
    sum=`expr $sum + $i`
    echo "i=$i"
    echo "sum=$sum"
    done
echo "done the sum : $sum"
exit 0