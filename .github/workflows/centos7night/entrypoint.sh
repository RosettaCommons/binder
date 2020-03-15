#!/bin/sh -l
set -x
uname -a 
cat /etc/issue
yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
yum -y install clang clang-devel clang-libs  llvm-devel llvm-static
yum -y install libcxx-devel cmake3 make cmake gcc gcc-c++ 
yum -y install yum-plugin-copr
yum -y install python3 python3-devel python python-devel 
yum -y install xz ninja-build git
#The two lines below use copr.
#yum -y copr enable averbyts/pybind11
#yum -y install pybind11-devel


mkdir TEMPHOME
export HOME=$(pwd)/TEMPHOME
#CentOS7 has cmake3 executable for cmake
sed -i 's/cmake /cmake3 /g'  build.py
sed -i 's/ninja /ninja-build /g'  build.py
python build.py

out=$?
echo ::set-output name=out::$out
