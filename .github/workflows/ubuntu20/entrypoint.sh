#!/bin/sh -l
uname -a 
cat /etc/issue
apt-get update
apt-get -y install  clang llvm  clang-dev*
apt-get -y install  cmake make gcc g++
apt-get install  python-pybind11 python3-pybind11    pybind11-dev pybind11-doc python-dev python3-dev
cmake CMakeLists.txt 
make
ctest . --output-on-failure 
out=$?
echo ::set-output name=out::$out
