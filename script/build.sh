#!/bin/bash

function buildObject {
    CODE_FILE=$G_DIR/code/$1.cpp
    OBJ_FILE=$G_DIR/bin/obj/$1.o
    
    BUILD=false
    if [ ! -f "$OBJ_FILE" ]; then
        BUILD=true
    else
        CODE_TIME=`stat -c %Y $CODE_FILE`
        OBJ_TIME=`stat -c %Y $OBJ_FILE`
        if [ "$CODE_TIME" -gt "$OBJ_TIME" ]; then
            BUILD=true
        fi
    fi

    if [ "$BUILD" = true ]; then
        echo Building $1.cpp...
        g++ -g -c $CODE_FILE
    fi
}

pushd $G_DIR/bin/obj > /dev/null
buildObject main
buildObject game
buildObject input
buildObject render
buildObject world
buildObject object
buildObject util
buildObject objectfactory
buildObject mine
buildObject gui
buildObject player
buildObject tuning
buildObject time
popd > /dev/null

echo Linking...
g++ -g -o $G_DIR/bin/game \
    -lncurses \
    -ljsoncpp \
    $G_DIR/bin/obj/main.o \
    $G_DIR/bin/obj/game.o \
    $G_DIR/bin/obj/input.o \
    $G_DIR/bin/obj/render.o \
    $G_DIR/bin/obj/world.o \
    $G_DIR/bin/obj/object.o \
    $G_DIR/bin/obj/util.o \
    $G_DIR/bin/obj/objectfactory.o \
    $G_DIR/bin/obj/mine.o \
    $G_DIR/bin/obj/gui.o \
    $G_DIR/bin/obj/player.o \
    $G_DIR/bin/obj/tuning.o \
    $G_DIR/bin/obj/time.o \

echo Done!
