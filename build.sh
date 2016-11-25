#! /bin/bash

# Using:
# ./build.sh - to buuild projects
# ./build.sh clean - to clean projects

printf "start building ------->>\n"

cmd=$1
echo "command to invoke: ${cmd}"

cd behavor
./build.sh ${cmd}
cd ..

cd creational
./build.sh ${cmd}
cd ..

cd structural
./build.sh ${cmd}
cd ..

printf "<<------- stop building\n"
