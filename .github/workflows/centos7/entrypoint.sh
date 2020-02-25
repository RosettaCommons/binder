#!/bin/sh -l
uname -a 
cat /etc/issue
yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
yum -y install  clang clang-devel clang-libs  llvm-devel llvm-static
yum -y install  libcxx-devel cmake3 make gcc gcc-c++
cmake3 CMakeLists.txt
make

out=$?
echo ::set-output name=out::$out
