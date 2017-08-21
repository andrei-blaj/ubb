#!/bin/bash

for F in *.sh /etc/*; do
    echo $F
done

if [ `expr $# % 4` -eq 0 ]; then
    echo yeay
fi

if test `expr $# % 4` -eq 0; then
    echo yeay
fi
