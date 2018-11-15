#!/bin/bash
CODE_FILE=$1
OBJ_FILE=$2
OBJ_TIME=`stat -c %Y $OBJ_FILE`
grep "#include" $CODE_FILE | while read -r line ; do
    echo "Processing $line"
    HEADER_FILE_NAME=${line/\"/\"};
    echo $HEADER_FILE_NAME
    #CODE_TIME=`stat -c %Y $CODE_FILE`
    #if [ "$CODE_TIME" -gt "$OBJ_TIME" ]; then
    #fi
done