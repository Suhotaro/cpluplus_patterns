#! /bin/bash

DIRS="./*"

for i in ${DIRS} ; do
	if [ -d ${i} ]; then
        echo "entering: ${i}"
		cd ${i} && make $1
        cd ..
	fi
done

