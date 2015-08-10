#!/bin/sh
#until_add.sh

i=1
until [ $i -gt 5 ]
do
    sum=`expr $sum + $i`
    echo $sum
    i=`expr $i + 1`
    done
echo "done the sum : $sum"
exit 0