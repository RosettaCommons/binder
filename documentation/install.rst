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

  # At this point, if all above steps is succeseful, binder should be at
  # $HOME/prefix/build/bin/binder


Installation with pre-installed LLVM 
============
Requirements
************
The basic dependencies for this type of installanion are very similar to these described above and include:

- CMake, version 3.4.3 or higher from https://cmake.org 
- C++ compiler with c++11 support, e.g. gcc frm  https://gcc.gnu.org/  
- make or Ninja 
- llvm with development packages (headers)
- clang  with development packages (headers)

The installation process of the required packages varies from system to system.
On the RHEL7/RHEL8/Fedora22+/Ubuntu18+  systems binder can be compilled with the llvm, clang and dependent packages available 
for these systems from their default repositories
 
 
For RHEL7/RHEL8/Fedora22+:

- To install the needed packages   run as root 
 
  ``yum install clang clang-devel llvm-devel llvm-static clang-libs``
  
- If a newer or specific version of the llvm/clang is needed, it can be installed  as root
   
  ``yum install clang8.0 clang8.0-devel llvm8.0-devel llvm8.0-static clang8.0-libs``
   
  to obtain a specific version (8.0 in this case).
    
- If the option above is not sufficient, or the available packages are outdated, for the 
  CentOS/RHEL/Fedora and compatible systems the llvm-toolset-7.0 toolset (or later) from
  https://www.softwarecollections.org/en/scls/rhscl/llvm-toolset-7.0/ provides . Run as root
  
  ``yum install llvm-toolset-7.0* ``
 

 Then the compilation can be performed using the following shell
 
 ``scl enable llvm-toolset-7 bash``
 
- Please note that binder requires cmake of version 3, therefore for some older systems
package cmake3 should be installed and used instead of cmake.
 
 ``yum install cmake3``

For Ubuntu18+ run:
 
 ``sudo apt-get update``
 
 ``sudo apt-get -y install  clang llvm  clang-dev*``
 
 ``sudo apt-get -y install  cmake make gcc g++``


Building
********
To build ``binder`` run

``cmake CMakeLists.txt -DCMAKE_INSTALL_PREFIX:PATH=/home/user/whereiwanttohaveit/``

``make``

``make install``

To perform the build with a specific version of LLVM, the location of LLVM and CLANG directories 
should be set simultaneously via the location of their cmake configurations, i.e.

``cmake CMakeLists.txt   -DLLVM_DIR=/usr/lib64/llvm8.0/lib/cmake/llvm -DClang_DIR=/usr/lib64/llvm8.0/lib/cmake/clang

Alternatively,the location of the llvm-config script could be set.

``cmake CMakeLists.txt   -DLLVMCONFIG=/usr/lib64/llvm7.0/bin/llvm-config``

By default cmake will build some tests and use python for some simple tests.
To disable tests use  ``-DBINDER_ENABLE_TEST=OFF``. To suggest python versions to perform tests with use options like
``-BINDER_TEST_PYTHON_VERSIONS=2,3.5``.  Note that version 0 can be used to check the generated sources agains the reference sources.


