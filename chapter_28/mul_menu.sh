#!/bin/sh
#mul_menu.sh
echo "1 save"
echo "2 load"
echo "3 exit"
echo
echo "please choose"
read chioce

while [ $chioce != "3" -a $chioce != "E" -a $chioce != "e" ]
do
    case $chioce in
        1 | S | s)
        echo "save";;
        2 | L | l)
            echo "load";;
        *)
            echo "invalid choice";;
        esac
    echo "please choose"
    read chioce
    done
echo "done"
exit 0