#!/bin/sh

filesdir=$1
searchstr=$2

if [ -z "$filesdir" ] || [ -z "$searchstr" ];
then
	echo "empty input!"
	return 1
fi

if [ ! -d "$filesdir" ];
then
	echo "directory invalid"
	return 1
fi

num_files=$(ls -1 "$filesdir" | wc -l)
num_lines=$(grep -R "$searchstr" "$filesdir" | wc -l)

echo "The number of files are ${num_files} and the number of matching lines are ${num_lines}"
