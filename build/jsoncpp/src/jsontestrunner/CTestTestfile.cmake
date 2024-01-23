# CMake generated Testfile for 
# Source directory: C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner
# Build directory: C:/Users/david/Documents/code/game/build/jsoncpp/src/jsontestrunner
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(jsoncpp_readerwriter "C:/Users/david/AppData/Local/Programs/Python/Python310/python.exe" "-B" "C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/../../test/runjsontests.py" "C:/Users/david/Documents/code/game/build/jsoncpp/bin/jsontestrunner_exe.exe" "C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/../../test/data")
set_tests_properties(jsoncpp_readerwriter PROPERTIES  WORKING_DIRECTORY "C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/../../test/data" _BACKTRACE_TRIPLES "C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/CMakeLists.txt;43;add_test;C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/CMakeLists.txt;0;")
add_test(jsoncpp_readerwriter_json_checker "C:/Users/david/AppData/Local/Programs/Python/Python310/python.exe" "-B" "C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/../../test/runjsontests.py" "--with-json-checker" "C:/Users/david/Documents/code/game/build/jsoncpp/bin/jsontestrunner_exe.exe" "C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/../../test/data")
set_tests_properties(jsoncpp_readerwriter_json_checker PROPERTIES  WORKING_DIRECTORY "C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/../../test/data" _BACKTRACE_TRIPLES "C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/CMakeLists.txt;47;add_test;C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/CMakeLists.txt;0;")
