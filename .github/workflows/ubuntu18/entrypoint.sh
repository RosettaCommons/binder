#!/bin/sh -l
set -x
uname -a 
cat /etc/issue
apt-get update
apt-get -y install  clang llvm  clang-dev*
apt-get -y install  cmake make gcc g++
apt-get -y install  python-pybind11 python3-pybind11    pybind11-dev pybind11-doc python-dev python3-dev python python3
cmake CMakeLists.txt  -DBINDER_ENABLE_TEST=OFF
make
#ctest . --output-on-failure 
out=$?
echo ::set-output name=out::$out
