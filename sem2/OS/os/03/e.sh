#!/bin/bash

D=$1
N=$2
find $D -type f | while read F; do
    if file $F | grep -q "ASCII text"; then
        K=`wc -l $F | sed "s/ .*//"`
        if [ $K -gt $N ]; then
            echo $F
        fi 
    fi 
done
