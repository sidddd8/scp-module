#!/bin/bash

# Download all the SCP instances of the OR-library
# See http://people.brunel.ac.uk/~mastjjb/jeb/orlib/scpinfo.html

# FILE  COPIED FROM  https://github.com/charlyisidore/scp
# AND MODOFIED

command -v lynx > /dev/null || { echo "Error: lynx is required to run the script"; exit 1; }
lynx -dump http://people.brunel.ac.uk/~mastjjb/jeb/orlib/files/ | grep -oe 'http://people.brunel.ac.uk/~mastjjb/jeb/orlib/files/\(scp.*\.txt\)' | wget -i - -nv

from_stn_instance()
{
	read line
	data=($(echo "$line" | tr -d "\r\n"))
	n=${data[0]}
	m=${data[1]}
	c=($(for j in $(seq 1 $n)
	     do echo 1
	     done))
	echo "$m $n"
	echo "${c[@]}"
	for i in $(seq 1 $m)
	do
		read line
		echo "3 $line"
	done
}

