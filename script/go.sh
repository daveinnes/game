#!/bin/bash
while getopts ":brdc" opt; do
  case ${opt} in
    b ) 
        bash $G_DIR/script/build.sh
          ;;
    r )
        bash $G_DIR/script/run.sh
        ;;
    d )
        bash $G_DIR/script/debug.sh
        ;;
    c )
        bash $G_DIR/script/clean.sh
        ;;
  esac
done