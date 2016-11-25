#! /bin/bash

# Using:
# ./build.sh - to buuild projects
# ./build.sh clean - to clean projects

printf "start building ------->>\n"

DIRS="./*"
cmd=$1
echo "command to invoke: ${cmd}"

for i in ${DIRS} ; do
	if [ -d ${i} ]; then
        echo "DIR: ${i}"
		cd ${i} && ./build.sh ${cmd}
        cd ..
	fi
done

printf "<<------- stop building\n"
