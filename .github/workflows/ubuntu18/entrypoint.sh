#!/bin/sh -l
uname -a 
cat /etc/issue
sudo apt-get install  clang llvm libclang clang-dev*
sudo apt-get install  cmake make gcc gcc-c++
#sudo apt-get install  pybind11-devel python3 python3-devel python2 python2-devel 
cmake CMakeLists.txt -DBINDER_ENABLE_TEST=OFF
make
ctest . --output-on-failure 
out=$?
echo ::set-output name=out::$out
