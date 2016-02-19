#!/bin/bash
if [ -z $1 ]
then
	echo "miss attribute"
	exit 1
else
	echo $1
fi

mod=`stat -c %a $1`
echo $mod
mod=$((mod|100))
echo $mod
chmod $mod $1