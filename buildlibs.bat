cmake -DCMAKE_BUILD_TYPE=Release -DJSONCPP_WITH_CMAKE_PACKAGE=ON -DCMAKE_INSTALL_PREFIX=./build/install -S ./external/jsoncpp -B ./build/jsoncpp -G "MinGW Makefiles"
cmake --build ./build/jsoncpp --target install
mingw32-make ./external/PDCurses/wincon
cp ./external/PDCurses/wincon/pdcurses.a ./build/install/lib/pdcurses.a