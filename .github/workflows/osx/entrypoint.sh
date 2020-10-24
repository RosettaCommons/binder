#!/bin/sh -l
set -x
brew install wget coreutils xz
wget --no-verbose https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
ls
tar -xJvf clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
#xz -d clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
#ls
#tar -x clang+llvm-11.0.0-x86_64-apple-darwin.tar
export PATH=$PATH:clang+llvm-11.0.0-x86_64-apple-darwin/bin

cmake CMakeLists.txt
make
otool -L source/binder
ctest . --output-on-failure 
