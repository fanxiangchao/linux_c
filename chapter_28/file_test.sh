#!/bin/sh
#file_test.sh

if [ -L $1 ]
    then
    echo "symlink file"
    elif [ -d $1 ]
    then
    echo "dir file"
    elif [ -f $1 ]
    then
    echo "regular file"
    fi
exit 0