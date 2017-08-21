#!/bin/bash

SUM=0
COUNT=0
for W in `cat $1`; do
    L=`echo $W | wc -m`
    L=`expr $L - 1`
    SUM=`expr $SUM + $L`
    COUNT=`expr $COUNT + 1`
done

echo "Sum=$SUM Count=$COUNT Average=`expr $SUM / $COUNT`"
