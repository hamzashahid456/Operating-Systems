#!/bin/bash
touch new.c
cp file.c new.c

echo " what you wanna do?"
read a

if [ $a -eq '1' ]
then
gcc new.c -o new

elif [ $a -eq '2' ]
then
gcc new.c -o new
./new

elif [ $a -eq '3' ]
then
cat new.c

else
ls
fi

