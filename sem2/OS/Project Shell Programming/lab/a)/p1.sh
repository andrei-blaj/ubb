#!/bin/bash

# Reading the directory name from the console
echo -n "Enter directory name: "
read dir

# Checking to see if the inserted name is in fact a directory
# If it isn’t then we terminate the program
if [ ! -d $dir ];
then
        echo "Inexitent directory"
        exit 0
fi

# using the ’s’ variable tot store the sum of the number of lines of all the files
# ‘index’ represents the number of files  
s=0
index=0

# Going through all the files in the directories and subdirectories
for it in `find $dir -name "*.*"`
do
	# Checking to see if the current name ‘it’ is a file 
	if [ ! -d $it ];
	then
		# ‘x’ holds the number of lines in the current file
        	x=`cat $it | wc -l`
		
		# We add ‘x’ to ’s’ and increment ‘index’
		s=`expr $s + $x`
		index=`expr $index + 1`	
	fi
done

# Print the average
echo `expr $s / $index`

