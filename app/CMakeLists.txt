cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(app_name
   VERSION 0.0.1
   DESCRIPTION "the app itself"
   LANGUAGES CXX
)

set(SOURCES
    main.cpp
    another.cpp
    another.h
)

# The result
add_executable(app ${SOURCES})

# set compiler warnings as defined in cmake/warnings and included in root CMakeLists.txt
set_project_warnings(app)

# Link with libraries
target_link_libraries(app lib)
