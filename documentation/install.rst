Installation
============
**Binder** is written in C++11 and must be built before use. This page describes the steps for the build process. Please note that installiation require up to ~2.6+ Gb of free disk space.



Requirements
************
The following tools need to be present in order to build and use **Binder**

- CMake, https://cmake.org
- Pybind11, RosettaCommons fork: https://github.com/RosettaCommons/pybind11
- [optional] Ninja (or you can use `make` by ommiting `-G Ninja` command below)



Building
********
The steps below is encoded in `binder/build.py` and `binder/build-and-run-tests.py` files so for default install you can just run `build-and-run-tests.py` script directly


#. To build Binder exectute the following command sequence in shell (replace ``$HOME/prefix`` and ``$HOME/binder`` with your paths):

.. code-block:: bash

  # clone Binder
  cd $HOME
  git clone https://github.com/RosettaCommons/binder.git

  # Create build dir
  mkdir $HOME/prefix && cd $HOME/prefix

  # Clone  LLVM
  git clone http://llvm.org/git/llvm.git llvm && cd llvm
  git checkout release_60

  # Clone Clang
  cd $HOME/prefix/llvm/tools
  git clone http://llvm.org/git/clang.git clang
  cd clang && git checkout release_60


  # Clone Clang extra tools
  cd $HOME/prefix/llvm/tools/clang/tools
  git clone http://llvm.org/git/clang-tools-extra.git extra
  cd extra && git checkout release_60

  # Create symlink pointing to binder/src dir
  ln -s $HOME/binder/source $HOME/prefix/llvm/tools/clang/tools/extra/binder

  # Create ``llvm/tools/clang/tools/extra/CMakeLists.txt`` file with content: ``add_subdirectory(binder)``
  echo 'add_subdirectory(binder)' > $HOME/prefix/llvm/tools/clang/tools/extra/CMakeLists.txt

  # Build Binder
  mkdir $HOME/prefix/build && cd $HOME/prefix/build
  cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_EH=1 -DLLVM_ENABLE_RTTI=ON ../llvm && ninja

  # At this point, if all above steps is succeseful, binder should be at $HOME/prefix/build/bin/binder
