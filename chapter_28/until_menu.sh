#!/bin/sh
#until_menu.sh

echo "1 save"
echo "2 load"
echo "3 exit"
echo
echo "please choose"
read choice
until [ $choice = "3" -o $choice = "E" -o $choice = "e" ]
do
    case $choice in
        1 | S | s)
            echo "save";;
        2 | L | l)
            echo "load";;
        *)
            echo "invalid choice";;
        esac
    echo "please choose"
    read choice
    done
echo "done"
exit 0