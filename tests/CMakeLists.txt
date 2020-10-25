cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(tests_name
   VERSION 0.0.1
   DESCRIPTION "the tests for lib"
   LANGUAGES CXX
)

set(SOURCES
   main.cpp
   test.cpp
)

# The result
add_executable(tests ${SOURCES})

# Set compiler warnings as defined in cmake/warnings
set_project_warnings(tests)

# Link with libraries
target_link_libraries(tests lib)
target_link_libraries(tests CONAN_PKG::gtest) # defined in root CMakeLists.txt
