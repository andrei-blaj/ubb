#!/bin/bash

A=5
echo $A

echo $1 $2 $3 $4 $5 $6 $7 $8 $9
shift
echo $1 $2 $3 $4 $5 $6 $7 $8 $9
shift 3
echo $1 $2 $3 $4 $5 $6 $7 $8 $9

echo $* $#






