#!/bin/bash

# CONTINUOUSLY reading words from the keyboard
while [[ 1 ]]
do
	echo -n "> Type a word: "
	read text

	# remove the word $text from every file given in the command line
	# for every file given as an argument in the console
	for file_name
	do
		# We create a temporary file
		aux_file=`mktemp`

		# We grab the content of the file_name
		# Remove the ‘text’ inserted by the user
		# Append the resulted content to the temporary file 
		echo `cat $file_name | sed "s/\$text//g" > $aux_file`
		
		# Move the content from the temporary file to the initial file
		mv $aux_file $file_name  
	done

done
