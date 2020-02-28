#!/bin/sh -l
uname -a 
cat /etc/issue
yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
yum -y install  clang clang-devel clang-libs  llvm-devel llvm-static
yum -y install  cmake make gcc gcc-c++
rpm -Uvh https://download.copr.fedorainfracloud.org/results/averbyts/fastjet/epel-8-x86_64/01259648-pybind11/pybind11-devel-2.4.3-2.el8.x86_64.rpm
yum -y install  python3 python3-devel python2 python2-devel
cmake CMakeLists.txt -DLLVMCONFIG=/usr/bin/llvm-config -DBINDER_MOCK_TEST=OFF
make
ctest .

out=$?
echo ::set-output name=out::$out
