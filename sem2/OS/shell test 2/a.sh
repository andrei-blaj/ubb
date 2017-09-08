#!/bin/bash

# $0 = ./a.sh

if [[ $# < 2 ]];
then
        echo "Not enough arguments."
        exit 0
fi

#shift
#while test $# -gt 0
#do
#   ls $1 | wc -l
#   shift
#done


cuv=$1
shift 1

sol=0

for directory
do
        if [ ! -d $directory ];
        then
                # no directory
                continue
        fi

                cd $directory

                cnt=0

                for it in `ls`
                do
                        if [ -d $it ];
                        then
                                # not a file
                                continue
                        fi

                                x=`cat $it | grep "\<$cuv\>" | wc -l`

                                if [ $x -gt 2 ];
                                then
                                        cnt=`expr $cnt + 1`
                                fi
                done

                if [ $cnt -gt 1 ];
                then
                        sol=`expr $sol + 1`
                fi

                cd ..
done

echo $sol
