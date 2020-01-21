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
        else
            HEADERS_CHANGED=`bash $G_DIR/script/headerschanged.sh $CODE_FILE $OBJ_FILE`
            if [ "$HEADERS_CHANGED" = true ]; then
                BUILD=true
            fi
        fi
    fi

    if [ "$BUILD" = true ]; then
        echo Building $1.cpp...
        g++ -g -c -Wno-multichar $CODE_FILE
    fi
}

pushd $G_DIR/bin/obj > /dev/null
buildObject main
buildObject game
buildObject input
buildObject render
buildObject world
buildObject scene
buildObject object
buildObject util
buildObject objectfactory
buildObject gatherer
buildObject gui
buildObject player
buildObject tuning
buildObject time
buildObject textmatrix
buildObject buildable
buildObject resource
buildObject mine
buildObject lab
buildObject production
buildObject unit
buildObject nexus
buildObject base
buildObject building
buildObject pylon
buildObject multibuilding
buildObject unitbehavior
buildObject playerbehavior
buildObject wall
buildObject waypoint
buildObject pathfinding

popd > /dev/null

echo Linking...
g++ -g \
    -Wall \
    -o $G_DIR/bin/game \
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
    $G_DIR/bin/obj/gatherer.o \
    $G_DIR/bin/obj/gui.o \
    $G_DIR/bin/obj/player.o \
    $G_DIR/bin/obj/tuning.o \
    $G_DIR/bin/obj/time.o \
    $G_DIR/bin/obj/textmatrix.o \
    $G_DIR/bin/obj/buildable.o \
    $G_DIR/bin/obj/resource.o \
    $G_DIR/bin/obj/mine.o \
    $G_DIR/bin/obj/lab.o \
    $G_DIR/bin/obj/production.o \
    $G_DIR/bin/obj/unit.o \
    $G_DIR/bin/obj/nexus.o \
    $G_DIR/bin/obj/scene.o \
    $G_DIR/bin/obj/base.o \
    $G_DIR/bin/obj/building.o \
    $G_DIR/bin/obj/pylon.o \
    $G_DIR/bin/obj/multibuilding.o \
    $G_DIR/bin/obj/unitbehavior.o \
    $G_DIR/bin/obj/playerbehavior.o \
    $G_DIR/bin/obj/wall.o \
    $G_DIR/bin/obj/waypoint.o \
    $G_DIR/bin/obj/pathfinding.o \

echo Done!
