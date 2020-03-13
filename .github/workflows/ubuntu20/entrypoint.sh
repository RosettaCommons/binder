#!/bin/sh -l
set -x
uname -a 
cat /etc/issue
apt-get update
apt-get -y install  clang llvm  clang-dev*
apt-get -y install  cmake make gcc g++
apt-get -y install   python3-pybind11    pybind11-dev pybind11-doc python2-dev python3-dev  python2 python3
cmake CMakeLists.txt
make
ctest . --output-on-failure 
out=$?
echo ::set-output name=out::$out
