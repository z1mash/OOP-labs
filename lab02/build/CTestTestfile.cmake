# CMake generated Testfile for 
# Source directory: /workspaces/oop/lab02
# Build directory: /workspaces/oop/lab02/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/oop/lab02/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/oop/lab02/CMakeLists.txt;33;add_test;/workspaces/oop/lab02/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
