#!/bin/sh -l
uname -a 
cat /etc/issue
yum -y install  clang clang-devel clang-libs  llvm llvm-devel llvm-static
yum -y install  libcxx-devel cmake make gcc gcc-c++
yum -y install  pybind11-devel python3 python3-devel python2 python2-devel
cmake CMakeLists.txt -DLLVMCONFIG=/usr/bin/llvm-config -DBINDER_MOCK_TEST=OFF
make
ctest .
out=$?
echo ::set-output name=out::$out
