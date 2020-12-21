cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(library
   VERSION 0.0.1
   DESCRIPTION "library description"
   LANGUAGES CXX
)

# Add these files to this binary
file(GLOB IncludeHeaderFiles include/*.h)
file(GLOB InternalHeaderFiles src/*.h)
file(GLOB SourceFiles src/*.cpp)

file (GLOB ImguiAuxiliaryFiles
   ../3rdparty/imgui/backends/imgui_impl_opengl3.cpp
   ../3rdparty/imgui/backends/imgui_impl_opengl3.h
   ../3rdparty/imgui/backends/imgui_impl_sdl.cpp
   ../3rdparty/imgui/backends/imgui_impl_sdl.h
   ../3rdparty/imgui/misc/cpp/imgui_stdlib.cpp
   ../3rdparty/imgui/misc/cpp/imgui_stdlib.h)

set(SOURCES ${IncludeHeaderFiles} ${InternalHeaderFiles} ${SourceFiles} ${ImguiAuxiliaryFiles})

# The result
add_library(library ${SOURCES})

# set compiler warnings as defined in cmake/warnings and included in root CMakeLists.txt
set_project_warnings(library)

# make this folder visible to executable
target_include_directories(library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link this library to others

target_link_libraries(library 
   CONAN_PKG::imgui # defined in root CMakeLists.txt
)

# I had trouble importing conan packages for SDL2, QT, and SFML because they
# required libgl1-mesa-dev package to be installed, which isn't a package on
# my openSUSE 15.1 so I was unable to install it. Instead I installed these
# as system packages rather than conan packages and linked to library this way.
if(BUILDING_ON_OPENSUSE)
   target_link_libraries(library
      GL # installed on the system
      GLEW # installed on the system
      SDL2 # installed on the system
   )
else()
   target_link_libraries(library 
      CONAN_PKG::glew # defined in root CMakeLists.txt
      CONAN_PKG::sdl2 # defined in root CMakeLists.txt
   )
endif()
