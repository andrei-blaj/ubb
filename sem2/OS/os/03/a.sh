#!/bin/bash

if test -f $1; then
    echo it is a file
else
    echo it is not a file
fi

if test -e $1 && ! test -f $1; then
    echo it is not a file
elif ! test -f $1; then
    echo it does not exist
else
    echo it is a file
fi

if [ -e $1 ] && [ ! -f $1 ]; then
    echo it is not a file
elif [ ! -f $1 ]; then
    echo it does not exist
else
    echo it is a file
fi

if [ 1 -eq 2 ]; then
    echo all wrong
elif [ "a" = "b" ]; then
    echo not better at all
elif test 1 -eq 2; then
    echo just as wrong
else
    echo life is as expected
fi

