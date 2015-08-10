#!/bin/sh
#func_menu.sh
input()
{
    case $1 in
        1 | S | s)
            echo "save";;
        2 | L | l)
            echo "load";;
        3 | E | e)
            echo "exit"
            break;;
        *)
            echo "invalid choice";;
        esac
    
}

echo "1 save"
echo "2 load"
echo "3 exit"
echo
while true
do
    echo "please choose"
    read res
    input $res
    done
echo "done"
exit 0