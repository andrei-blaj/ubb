#!/bin/bash

D=$1
PREV=""

while true; do
    if [ -z "$PREV" ]; then
        PREV=`ls -lR $D`
    fi
    sleep 1
    NOW=`ls -lR $D`
    if [ ! "$PREV" = "$NOW" ]; then
        echo something changed
    fi
    PREV=$NOW
done

