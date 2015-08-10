#!/bin/sh
#res3.sh
echo "Testing No.6"
if [ $xyz ]
    then
    echo "Uninitialized var is true."
    else
    echo "Uninitialized var is false."
    fi
echo
echo "Testing No.7"
if [ -n "$xyz" ]
    then
    echo "Uninitialized var is true."
    else
    echo "Uninitialized var is false."
    fi
echo
xyz=
echo "Testing No.8"
if [ -n "$xyz" ]
    then
    echo "NULL var is true."
    else
    echo "NULL var is false."
fi
exit 0