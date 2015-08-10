#!/bin/sh
#res4.sh
echo "Testing No.9"

if [ "false" ]
    then
    echo "false is true."
    else
    echo "false is false."
    fi
echo
echo "Testing No.10"
if [ $false ]
    then
    echo "\$false is true."
    else
    echo "\$false is false."
    fi
exit 0