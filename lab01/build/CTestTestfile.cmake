# CMake generated Testfile for 
# Source directory: /workspaces/oop/lab01
# Build directory: /workspaces/oop/lab01/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/oop/lab01/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/oop/lab01/CMakeLists.txt;33;add_test;/workspaces/oop/lab01/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
