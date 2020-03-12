#!/bin/sh -l
set -x
uname -a 
cat /etc/issue
yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
yum -y install  clang clang-devel clang-libs  llvm-devel llvm-static
yum -y install  cmake make gcc gcc-c++ diffutils
yum -y install yum-plugin-copr
yum -y copr enable averbyts/pybind11
yum -y install pybind11-devel
yum -y install  python3 python3-devel python2 python2-devel
cmake CMakeLists.txt
make
ctest . --output-on-failure 

out=$?
echo ::set-output name=out::$out
