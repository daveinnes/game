#!/bin/bash
CODE_FILE=$1
OBJ_FILE=$2
CHANGED=false

function headersChanged {
    OBJ_TIME=`stat -c %Y $OBJ_FILE`
    grep "#include" $CODE_FILE | while read -r line ; do
        HEADER_FILE_NAME=${line//\"/}
        HEADER_FILE_NAME=${HEADER_FILE_NAME/\#include /}
        HEADER_FILE=$G_DIR/code/$HEADER_FILE_NAME
        if [ -f "$HEADER_FILE" ]; then
            HEADER_TIME=`stat -c %Y $HEADER_FILE`
            if [ "$HEADER_TIME" -gt "$OBJ_TIME" ]; then
                echo true
                exit
            fi
        fi
    done
}

if [ -f $OBJ_FILE ]; then
    CHANGED=$(headersChanged)
fi

echo $CHANGED
