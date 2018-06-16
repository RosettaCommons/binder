#!/bin/bash
# make binding gereration via bash

# Generate all_includes file
grep -rh "#include" include/* | sort -u > all_bash_includes.hpp
# Makde bindings dir from scratch \
rm -rf ./bash_bindings/ && mkdir bash_bindings/
 # Make bindings code 
$PWD/../../build/llvm-4.0.0/build_4.0.0*/bin/binder \
  --root-module test_struct \
  --prefix $PWD/bash_bindings/ \
  --bind testers -trace \
  all_bash_includes.hpp \
  -- -std=c++11 -I$PWD/include \
  -DMY_PROJECT_DEFINE -DNDEBUG

# compile first generated bindings
# NOTE 'pybase' may need to change on your system
cd bash_bindings
pybase=`which python3`
g++ \
  -O3 \
  -I${pybase::-12}/include/python3.6m -I$PWD/../../../build/pybind11/include -I$PWD/../include \
  -I$PWD/../../../source -shared  \
  -std=c++11  -c test_struct.cpp  \
  -o test_struct.o -fPIC



# compile second generated bindings
# NOTE 'pybase' may need to change on your system
cd test_struct/
g++ \
  -O3 \
  -I"${pybase::-12}"/include/python3.6m -I$PWD/../../../../build/pybind11/include -I$PWD/..//../include \
  -I$PWD/../../../../source -shared  \
  -std=c++11  -c test_struct.cpp  \
  -o test_struct.o -fPIC && \

cd ../

# Link together compiled bindings
g++ -o test_struct.so -shared test_struct/test_struct.o test_struct.o

# Try running via python
python3 -c "import sys; sys.path.append('.'); import test_struct; f = test_struct.testers.test_my_struct(); print(f.an_int)"

cd ../
