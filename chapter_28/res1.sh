#!/bin/sh
#res1.sh

echo "Testing No.1"
if [ 0 ]
    then
    echo "0 is true."
    else
    echo "0 is false."
    fi
echo
echo "Testing No.2"
if [ 1 ]
    then
    echo "1 is true."
    else
    echo "1 is false."
    fi
echo
echo "Testing No.3"
if [ -1 ]
    then
    echo "-1 is true."
    else
    echo "-1 is false."
    fi

exit 0