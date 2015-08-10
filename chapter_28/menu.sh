#!/bin/sh
#menu.sh
echo "1 save"
echo "2 load"
echo "3 exit"
echo
echo "please choose"
read chioce

case $chioce in
    1)
        echo "save";;
    2)
        echo "load";;
    3)
        echo "exit";;
    *)
        echo "invalid choice"
        exit 1;;
esac
exit 0