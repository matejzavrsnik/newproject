cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(lib_name
   VERSION 0.0.1
   DESCRIPTION "library for the app"
   LANGUAGES CXX
)

set(SOURCES
    include/lib.h
    src/lib.cpp
    src/internal.cpp
    src/internal.h
)

# The result
add_library(lib ${SOURCES})

# set compiler warnings as defined in cmake/warnings and included in root CMakeLists.txt
set_project_warnings(lib)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
