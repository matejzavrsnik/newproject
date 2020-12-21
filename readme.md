# Building from scratch

## Windows

1) install git, python, conan, Visual Studio, ...
2) git clone --recursive https://github.com/matejzavrsnik/overeye.git
3) cmake for VS ...
4) open in VS

## Ubuntu / Debian

1) sudo apt install cmake git build-essential python3-pip libgl-dev libglu1-mesa-dev
2) sudo pip install conan
3) git clone --recursive https://github.com/matejzavrsnik/overeye.git
4) ./build.sh all

## openSUSE

1) install git, python, conan, ... GL, GLEW, SDL2
2) set BUILDING_ON_OPENSUSE in cmake to link against system installed GL, GLEW, and SDL2
3) git clone --recursive https://github.com/matejzavrsnik/overeye.git
4) ./build.sh all
