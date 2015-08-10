#!/bin/sh
#list.sh
for file in `ls`
do
    if [ -f $file ]
        then
        echo "$file is a regular file"
        elif [ -d $file ]
        then
        echo "$file is a directory"
        else
        echo "unknown file type"
        fi
    done
exit 0