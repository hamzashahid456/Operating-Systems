#!/bin/bash
touch new.c
cp file.c new.c

echo " what you wanna do?"
read a

execute(){
    case $a in

    1) gcc new.c -o new;;

    2) gcc new.c -o new && ./new;;

    3) cat new.c;;

    *) ls ;;

    esac
}

execute a


