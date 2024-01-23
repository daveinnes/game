cmake -DCMAKE_PREFIX_PATH=./build/install -G "MinGW Makefiles" -S . -B ./build/game
mingw32-make -C ./build/game 