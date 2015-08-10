#!/bin/sh
#base.sh
file=`basename $0`
echo "file name : $file"
path=`pwd`
((path=$path+$file))
echo "full path : $path"
exit 0