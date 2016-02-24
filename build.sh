#!/bin/bash

#compile the objects
echo Building objects...
gcc -c -o fptr.o fptr.c
gcc -c -o test.o test.c
gcc -c -o test2.o test2.c

#link into executables
echo Linking Executables...
gcc -o fptr.exe fptr.o 
gcc -o fptr-test.exe fptr.o test.o
gcc -o fptr-test2.exe fptr.o test2.o

#execute
echo
echo Testing no external link...
echo
./fptr.exe
echo
echo Testing linked to test.o...
echo
./fptr-test.exe
echo
echo Testing linked to test2.o...
echo
./fptr-test2.exe