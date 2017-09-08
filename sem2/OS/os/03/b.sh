#!/bin/bash

for A in 1 2 3 4 f t u w; do
    echo $A
done

for A in $*; do
    echo $A
done

for A; do
    echo $A
done
