#!/bin/sh -l
uname -a 
cat /etc/issue
yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
yum -y install  clang clang-devel clang-libs  llvm-devel llvm-static
yum -y install  cmake make gcc gcc-c++
cmake CMakeLists.txt -DLLVMCONFIG=/usr/bin/llvm-config
make

out=$?
echo ::set-output name=out::$out