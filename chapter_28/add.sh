#!/bin/sh
#add.sh

i=1
while [ $i -le 5 ]
do
    sum=`expr $sum + $i`
    echo $sum
    i=`expr $i + 1`
    done
echo "done the sum : $sum"
exit 0
