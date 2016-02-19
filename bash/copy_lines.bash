#! /bin/bash

re='^[0-9]+$'
ERR="sintax: 'copy i_file o_file repeat=5' "
COUNTER=5
I_FILE=$1
O_FILE=$2



if [[ $3 =~ $re ]]; then
   COUNTER=$3;
fi

echo repeat $COUNTER times

if [ ! -e $I_FILE ]; then
	echo "no input file"
	echo $ERR
	exit 1;
fi  

if [ -z $2 ]; then
	echo "no output filename"
	echo $ERR
	exit 1;
fi

if [ ! -e $O_FILE ]; then
	touch $O_FILE
fi

echo `cat $I_FILE` > $O_FILE
while [ $COUNTER -ne 1 ]; do
	COUNTER=$((COUNTER-1))
	echo `cat $I_FILE` >> $O_FILE
done

echo input word count `wc -w $I_FILE | cut -d' ' -f1`
echo input char count `wc -c $I_FILE | cut -d' ' -f1`

echo output word count `wc -w $O_FILE | cut -d' ' -f1`
echo output char count `wc -c $O_FILE | cut -d' ' -f1`