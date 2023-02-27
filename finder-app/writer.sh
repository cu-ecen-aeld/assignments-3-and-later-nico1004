#!/bin/sh

writefile=$1
writestr=$2

if [ -z "$writestr" ] || [ -z "$writefile" ];
then
	echo "arguments not specified"
	return 1
fi

mkdir -p "$(dirname "$writefile")"
echo "$writestr" > "$writefile"

