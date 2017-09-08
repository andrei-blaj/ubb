#!/bin/bash

if [[ $# < 1 ]];
then
    echo "Not enough arguments."
    exit 0
fi

if [[ $# > 1 ]];
then
    echo "Top many arguments."
    exit 0
fi

if [ ! -d $1 ];
then
        echo "Inexitent directory"
        exit 0
fi

dir=$1 #luam argumentul ca numele directorului 

for it in `find $dir -name "*.sh"`
do
        x=`cat $it | wc -w`
        if [[ `expr $x % 2` -eq 1 ]];
        then
                echo "$it $x cuvinte"
        fi
done

for it in `find $dir -name "*.awk"`
do
        x=`cat $it | wc -l`
        if [[ `expr $x % 2` -eq 0 ]];
        then
                echo "$it $x linii"
        fi
done

#for it in `ls -R $dir`
#do
#
#               
#
#       if [[ $it == *.sh ]];
#       then
#               # it is a bash file
#               x=`cat $it | wc -w`
#               
#               if [[ $x%2 -eq 1 ]];
#               then
#                       echo "$it, $x cuvinte"
#               fi
#       fi

#       if [[ $it == *.awk ]];
#       then
                # it's an awk file
#               x=`cat $it | wc -l`

#               if [[ $x%2 -eq 0 ]];
#               then 
#                        echo "$it, $x linii"
#               fi
#       fi

#done
