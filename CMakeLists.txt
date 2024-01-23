cmake_minimum_required(VERSION 3.28)
project(game)
add_executable(game 
code/main.cpp 
code/game.cpp
code/input.cpp
code/render.cpp
code/world.cpp
code/scene.cpp
code/object.cpp
code/util.cpp
code/objectfactory.cpp
code/gatherer.cpp
code/gui.cpp
code/player.cpp
code/tuning.cpp
code/time_manager.cpp
code/textmatrix.cpp
code/buildable.cpp
code/resource.cpp
code/mine.cpp
code/lab.cpp
code/production.cpp
code/unit.cpp
code/nexus.cpp
code/base.cpp
code/building.cpp
code/pylon.cpp
code/multibuilding.cpp
code/unitbehavior.cpp
code/playerbehavior.cpp
code/wall.cpp
code/waypoint.cpp
code/pathfinding.cpp)
find_package(jsoncpp REQUIRED)
get_target_property(JSON_INC_PATH jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)
set(CURSES_LIBRARY C:/Users/david/Documents/code/game/build/install/lib/libpdcurses.a)
set(CURSES_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/PDCurses)
include_directories(${JSON_INC_PATH} ${CURSES_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} jsoncpp_lib ${CURSES_LIBRARY})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-multichar")