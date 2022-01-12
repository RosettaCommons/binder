# Binder

**Binder** is a tool for automatic generation of Python bindings for C++11 projects using [Pybind11](https://github.com/pybind/pybind11) and [Clang LibTooling](http://clang.llvm.org/docs/LibTooling.html) libraries.  That is, Binder, takes a C++ project and compiles it into objects and functions that are all usable within Python.  Binder is different from prior tools in that it handles special features new in C++11.

[![Documentation Status](https://readthedocs.org/projects/cppbinder/badge/?version=latest)](http://cppbinder.readthedocs.org/en/latest/?badge=latest)
![](https://github.com/RosettaCommons/binder/workflows/build/badge.svg)

Reference documentation is provided at
[http://cppbinder.readthedocs.org/en/latest](http://cppbinder.readthedocs.org/en/latest).
A PDF version of the manual is available
[here](https://media.readthedocs.org/pdf/cppbinder/latest/cppbinder.pdf).

## Generate Debian Package

1. Clone this repo:
   ``` bash
   mkdir ~/git && cd ~/git
   git clone git@github.com:ANYbotics/binder.git
   ```
2. Apply your changes.
3. Move the repository to a versioned folder.
   ``` bash
   mv ~/git/binder ~/git/binder-X.Y.Z
   ```
   Replace X.Y.Z with the version number to release (e.g. 1.2.1).
4. Change the file `debian/changelog` to reflect the changes for the new version.
5. Run `debuild` to generate the debian:
   ``` bash
   debuild
   ```
   You can omit tests by prefixing `DEB_BUILD_OPTIONS=nocheck`.
6. The debian is not available in the parent folder. To test it, you can install it with:
   ``` bash
   sudo apt install ~/git/binder_X.Y.Z-R_amd64.deb
   ```
   Replace X.Y.Z-R with the version number and revision to release (e.g. 1.2.1-1).
