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
On the RHEL7/RHEL8/Fedora22+  systems binder can be compilled with the llvm, clang and dependent packages available 
for these systems from their default repositories, i.e.
  
``yum install clang clang-devel llvm-devel llvm-static clang-libs libcxx libcxx-devel``

Please note that binder requires cmake of version 3, therefore for some older systems
package cmake3 should be installed and used instead of cmake.

``yum install cmake3``

If a newer or specific version of the llvm/clang is needed, it can be installed 
as desribed in detail below.

- Some versions of LLVM from the standard repositories of CentOS7/RHEL7/Fedora. Run as root 
 
  ``yum install clang clang-devel llvm-devel llvm-static clang-libs libcxx libcxx-devel``
  
   to obtain a standart  llvm version for your system and
   
   ``yum install clang8.0 clang8.0-devel llvm8.0-devel llvm8.0-static clang8.0-libs libcxx libcxx-devel``
   
    to obtain a specific version (8.0 in this case).
    
- If the option above is not sufficient, or the available packages are outdated, for the 
  CentOS/RHEL/Fedora and compatible systems the llvm-toolset-7.0 toolset (or later) from
  https://www.softwarecollections.org/en/scls/rhscl/llvm-toolset-7.0/ provides . Run as root

 ``yum install llvm-toolset-7.0* libcxx libcxx-devel``

 Then the compilation can be performed using the following shell

 ``scl enable llvm-toolset-7 bash``

Note that for the CentOS8/RHEL8 the standard version of llvm is 9.0 and is available from the repositories, 
However, the ``libcxx`` and ``libcxx-devel`` packages are not available yet and  so one has to recompile them, i.e.
  ``rpm -i http://ftp.tu-chemnitz.de/pub/linux/fedora/linux/releases/31``
  ``/Everything/source/tree/Packages/l/libcxx-9.0.0-1.fc31.src.rpm``

  ``wget https://src.fedoraproject.org/rpms/libcxx/raw/f31/f/libcxx.spec``

  edit ``libcxx.spec`` to set

  ``%global bootstrap 1``
  
  Then run as user

  ``rpmbuild -bb libcxx.spec``
  
  And run as root

  ``rpm -Uvh /home/user/rpmbuild/RPMS/x86_64/libcxx-devel-9.0.0-1.el8.x86_64.rpm /home/user/rpmbuild/RPMS/x86_64/libcxx-9.0.0-1.el8.x86_64.rpm``

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

However, it is not a recommended option and should be used only for the old versions of LLVM without cmake support.
Also, in this case  itis recommended to pay an attention to the locations of clang headers and set them explicitely via the
`CLANG_INCLUDE_DIRS` cmake variable.


