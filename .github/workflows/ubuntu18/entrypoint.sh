#!/bin/sh -l
uname -a 
cat /etc/issue
apt-get update
apt-get -y install  clang llvm  clang-dev*
apt-get -y install  cmake make gcc
apt-get install pybind11-dev pybind11-doc python-dev python3-dev
cmake CMakeLists.txt 
make
ctest . --output-on-failure 
out=$?
echo ::set-output name=out::$out
