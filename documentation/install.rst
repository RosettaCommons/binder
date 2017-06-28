Installation
============
**Binder** is written in C++11 and need to be built before use. This page describe steps for build process.



Requirements
************
The following tools need to be present in order to build and use **Binder**

- CMake, https://cmake.org
- Pybind11, RosettaCommons fork: https://github.com/RosettaCommons/pybind11
- [optional] Ninja (or you can use `make` by ommiting `-G Ninja` command below) 



Building
********
The steps below is encoded in binder/build.py file so for default install you can just run this script directly


#. To build Binder exectute the following command sequence in shell (replace ``$HOME/prefix`` and ``$HOME/binder`` with your paths):

.. code-block:: bash


  # Create build dir
  mkdir $HOME/prefix && cd $HOME/prefix

  # Clone  LLVM
  git clone http://llvm.org/git/llvm.git llvm && cd llvm
  git reset --hard origin/release_38

  # Clone Clang
  cd $HOME/prefix/llvm/tools
  git clone http://llvm.org/git/clang.git clang
  cd clang && git reset --hard origin/release_38


  # Clone Clang extra tools
  cd $HOME/prefix/llvm/tools/clang/tools
  git clone http://llvm.org/git/clang-tools-extra.git extra

  # Create symlink pointing to binder/src dir
  ln -s $HOME/binder/binder $HOME/prefix/llvm/tools/clang/tools/extra/binder


  # Create ``llvm/tools/clang/tools/extra/CMakeLists.txt`` file with content: ``add_subdirectory(binder)``
  echo 'add_subdirectory(binder)' > $HOME/prefix/llvm/tools/clang/tools/extra/CMakeLists.txt

  # Build Binder
  mkdir $HOME/prefix/build && cd $HOME/prefix/build
  cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_EH=1 -DLLVM_ENABLE_RTTI=ON .. && ninja

  # At this point, if all above steps is succeseful, binder should be at
  # $HOME/prefix/build/bin/binder
