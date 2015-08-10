#!/bin/sh
#final_menu.sh

echo "1 save"
echo "2 load"
echo "3 exit"

echo
echo "please choose"
read choice
while true
do
    case $choice in
        1 | S | s)
            echo "save";;
        2 | L | l)
            echo "load";;
        3 | E | e)
            echo "exit"
            break;;
        *)
            echo "invlaid choice";;
        esac
    echo "please choose"
    read choice
    done
echo "done"
exit 0
