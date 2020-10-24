#!/bin/sh -l
set -x
brew install wget coreutils
wget --no-verbose https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
tar -Jxo clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
export PATH=$PATH:clang+llvm-11.0.0-x86_64-apple-darwin/bin

cmake CMakeLists.txt
make
otool -L source/binder
ctest . --output-on-failure 
