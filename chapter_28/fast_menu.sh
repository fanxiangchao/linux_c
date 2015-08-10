#!/bin/sh
#fast_menu.sh
echo "1 save"
echo "2 load"
echo "3 exit"
echo
echo "please choose"
read chioce

case $chioce in
    1 | S | s)
        echo "save";;
    2 | L | l)
        echo "load";;
    3 | E | e)
        echo "exit";;
    *)
        echo "invalid chioce"
        exit 1;;
    esac
exit 0