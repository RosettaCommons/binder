#!/bin/sh -l
set -x
uname -a 
cat /etc/issue
yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
yum -y install  clang clang-devel clang-libs  llvm-devel llvm-static
yum -y install  libcxx-devel cmake3 make cmake gcc gcc-c++ 
yum -y install yum-plugin-copr
yum -y copr enable averbyts/pybind11
yum -y install pybind11-devel
yum -y install  python3 python3-devel python python-devel 
cmake3 CMakeLists.txt
make
ctest . --output-on-failure 

out=$?
echo ::set-output name=out::$out
