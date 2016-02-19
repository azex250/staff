#!/bin/bash
DB='books.db'
while [ "$a" != "4" ]
do
	echo '0 - is book in db?'
	echo '1 - delete'
	echo '2 - add'
	echo '3 - show all'
	echo '4 - exit'

	read a

	case "$a" in
		0)
			echo 'print book name to match'
			read b
			grep -x "$b" $DB > /dev/null

			if [ "$?" == "0" ]
			then
				echo "Stored in data base"
			else 
				echo "Not stored in data base"
			fi;;	
		1)
			echo 'print book to delete'
			read b
			sed -i /^${b}$/d $DB;;
	 	2)
			echo 'print book to add'
			read b
			echo $b >> $DB;;
		3)
			cat $DB;;
		4)
			echo 'Goodbye';;
		*)
			echo 'Unknown command';;
	esac
done		
