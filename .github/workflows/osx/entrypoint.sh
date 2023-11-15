#!/bin/sh -l
set -x
brew install wget coreutils xz pybind11
wget --no-verbose https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
ls
tar -xJf clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
export PATH=$PATH:clang+llvm-11.0.0-x86_64-apple-darwin/bin

cmake CMakeLists.txt
make
otool -L source/binder
ctest . --output-on-failure
out=$?
cat Testing/Temporary/LastTest.log
if [ $out -ne 0 ]; then
    exit $out
fi