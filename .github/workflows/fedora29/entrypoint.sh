#!/bin/sh -l
set -x
uname -a 
cat /etc/issue
yum -y install  git  zlib zlib-devel ncurses-devel  clang clang-devel clang-libs  llvm llvm-devel llvm-static
yum -y install  libcxx-devel cmake make gcc gcc-c++
yum -y install  pybind11-devel python3 python3-devel python2 python2-devel 

cmake CMakeLists.txt
make
ldd source/binder
ldd -u -r source/binder
ctest . --output-on-failure 
out=$?
echo ::set-output name=out::$out
