Installation
============
**Binder** is written in C++11 and must be built before use. This page describes the steps for the build process.
Please note that installation require up to ~2.6+ Gb of free disk space.



Requirements
************
The following tools need to be present in order to build and use **Binder**

- CMake, https://cmake.org
  - static compilation requires version 3.13 or above, see below
- Pybind11, RosettaCommons fork: https://github.com/RosettaCommons/pybind11
- [optional] Ninja (or you can use `make` by omitting `-G Ninja` command below)


Binder has experimental support for being *statically compiled* on CentOS8,
which additionally requires:

- `libclang-static-build`: https://github.com/deech/libclang-static-build
- CMake version 3.13 or above

Go to :ref:`building-static` for the build process. Also note a caveat to
static compilation: the version of `libclang` that Binder is compiled against
may not be compatible with the header files on the system Binder where is run.


Building
********
The steps below are encoded in `binder/build.py` and `binder/build-and-run-tests.py`
files so for default install you can just run `build-and-run-tests.py` script directly.
This section describes how to build a dynamically-linked ``binder`` executable.
To *statically* compile binder, see :ref:`building-static`.


#. To build Binder execute the following command sequence in shell (replace ``$HOME/prefix`` and ``$HOME/binder`` with your paths):

.. code-block:: bash

  # clone Binder
  cd $HOME
  git clone https://github.com/RosettaCommons/binder.git

  # Create build dir
  mkdir $HOME/prefix && cd $HOME/prefix

  # Clone  LLVM
  git clone https://github.com/llvm/llvm-project.git llvm && cd llvm
  git checkout llvmorg-6.0.1

  # Create symlink pointing to binder/src dir
  ln -s $HOME/binder/source $HOME/prefix/llvm/clang-tools-extra/binder

  # Create ``llvm/tools/clang/tools/extra/CMakeLists.txt`` file with content: ``add_subdirectory(binder)``
  echo 'add_subdirectory(binder)' > $HOME/prefix/llvm/clang-tools-extra/CMakeLists.txt

  # Build Binder
  mkdir $HOME/prefix/build && cd $HOME/prefix/build
  cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_EH=1 -DLLVM_ENABLE_RTTI=ON -DLLVM_ENABLE_PROJECTS=clang  ../llvm/llvm && ninja

  # At this point, if all above steps is successful, binder should be at
  # $HOME/prefix/build/bin/binder


Installation with pre-installed LLVM
====================================
Requirements
************
The basic dependencies for this type of installation are very similar to these described above and include:

- CMake, version 3.4.3 or higher from https://cmake.org
- C++ compiler with c++11 support, e.g. gcc from  https://gcc.gnu.org/
- make or Ninja
- llvm with development packages (headers)
- clang  with development packages (headers)

The installation process of the required packages varies from system to system.
On the RHEL7/RHEL8/Fedora22+/Ubuntu18+  systems binder can be compiled with the llvm, clang and dependent packages available
for these systems from their default repositories


For RHEL7/RHEL8/Fedora22+:

- To install the needed packages   run as root

  .. code-block:: console

    yum install clang clang-devel llvm-devel llvm-static clang-libs

- If a newer or specific version of the llvm/clang is needed, it can be installed  as root

  .. code-block:: console

     yum install clang8.0 clang8.0-devel llvm8.0-devel llvm8.0-static clang8.0-libs

  to obtain a specific version (8.0 in this case).

- If the option above is not sufficient, or the available packages are outdated, for the
  CentOS/RHEL/Fedora and compatible systems the llvm-toolset-7.0 toolset (or later) from
  https://www.softwarecollections.org/en/scls/rhscl/llvm-toolset-7.0/ provides LLVM of version 7.0.
  To install it run as root

  .. code-block:: console

    yum install llvm-toolset-7.0*

  Then the compilation can be performed using the following shell

  .. code-block:: console

    scl enable llvm-toolset-7.0 bash

- Please note that binder requires cmake of version 3, therefore for some older systems
  package cmake3 should be installed and used instead of cmake.

  .. code-block:: console

    yum install cmake3


For Ubuntu18+ run, an example for LLVM/Clang 10:

  .. code-block:: console

    sudo apt-get update
    sudo apt-get -y install  clang-10 llvm-10 libclang-10-dev llvm-10-dev
    sudo apt-get -y install  cmake make gcc g++

For MacOSX:

  Make sure the XCode is installed. If needed, install cmake, python and other utilities, e.g. using homebrew:

  .. code-block:: console

    brew install wget coreutils xz pybind11 cmake

  Note: the pybind11 version from   https://github.com/RosettaCommons/pybind11  should be preffered ,
  but pybind11 version from homebrew might work as well.

  Download and install the llvm+clang from the official site, e.g. using ``wget`` and
  add the location of llvm config to the $PATH:

  .. code-block:: console

    wget --no-verbose https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
    tar -xJf clang+llvm-11.0.0-x86_64-apple-darwin.tar.xz
    export PATH=$PATH:$(pwd)/clang+llvm-11.0.0-x86_64-apple-darwin/bin


Building
********
To build ``binder`` run

.. code-block:: console

   cmake CMakeLists.txt -DCMAKE_INSTALL_PREFIX:PATH=/home/user/whereiwanttohaveit/
   make
   ctest
   make install

To perform the build with a specific version of LLVM, the location of LLVM and CLANG directories
should be set simultaneously via the location of their cmake configurations, i.e.

.. code-block:: console

   cmake CMakeLists.txt   -DLLVM_DIR=/usr/lib64/llvm8.0/lib/cmake/llvm -DClang_DIR=/usr/lib64/llvm8.0/lib/cmake/clang

Alternatively, the location of the llvm-config script could be set.

.. code-block:: console

   cmake CMakeLists.txt   -DLLVMCONFIG=/usr/lib64/llvm7.0/bin/llvm-config

As an example with Ubuntu 18.04 and llvm-10:

.. code-block:: console

   cmake CMakeLists.txt   -DLLVM_DIR=/usr/lib/llvm-10 -DClang_DIR=/usr/lib/llvm-10


Using ``binder`` built with pre-installed LLVM
**********************************************

Under some circumstances (e.g. on system where the default compiller is not clang)
``binder`` might emit error messages like

.. code-block:: console

   /usr/lib/gcc/x86_64-redhat-linux/10/../../../../include/c++/10/bits/cxxabi_init_exception.h:38:10: fatal error: 'stddef.h' file not found
   #include <stddef.h>
            ^~~~~~~~~~
   1 error generated.

and similar, see https://clang.llvm.org/docs/FAQ.html. To fix this issue, ``binder`` should be pointed to the location of the
appropriate clang includes. This can be archived using the clang options that are passed to binder after ``--`` flag, e.g.\

.. code-block:: console

   binder ...binder...options...  -- -x c++  ...other...options...   -iwithsysroot/where/the/directory/with/includes/is/

See https://clang.llvm.org/docs/ClangCommandLineReference.html for details.
If ``binder`` was build with some older versions of LLVM, one could also set the location of the headers with the
``C_INCLUDE_PATH`` and  ``CPLUS_INCLUDE_PATH`` environment variables, e.g.

.. code-block:: console

   export CPLUS_INCLUDE_PATH=/where/the/directory/with/includes/is/



With Docker
***********

An example `Dockerfile` for building binder can be found in the ``binder`` repository linked here: https://github.com/RosettaCommons/binder/examples


.. _building-static:

Building Statically (Linux only)
********************************

The first step in the static build is to build the ``libclang`` statically following the instructions
from https://github.com/deech/libclang-static-build. For this quite a recent version of cmake is needed (3.13+).
If the version of cmake form the used distribution is too old (e.g.  as in the CentOS8 )  a precompilled
package from the CMake site from https://cmake.org/ can be used instead.

The static build requires some other static libraries to be present in the system.
For the CentOS8  install ``libstdc++-static`` and ``ncurses-compat-libs`` runnign as root:

.. code-block:: console

   sudo yum install libstdc++-static ncurses-compat-libs


Set the environment variable ``LIBCLANG_STATIC_BUILD_DIR`` to the path of
`libclang-static-build`. Then build ``binder`` with the following procedure:

.. code-block:: console

   cmake CMakeLists.txt -DSTATIC=on -DLLVMCONFIG="${LIBCLANG_STATIC_BUILD_DIR}/build/_deps/libclang_prebuilt-src/bin/llvm-config" -DLLVM_LIBRARY_DIR="${LIBCLANG_STATIC_BUILD_DIR}/lib" -DCMAKE_INSTALL_PREFIX:PATH=/home/user/whereiwanttohaveit/

   make
   ctest
   make install
