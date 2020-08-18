Testing
##########

This section  describes the testing suite for binder.
The testing suite has two implementations, both using the same set of tests
located in the ``test`` subdirectory.
The first implementation is located inside the script ``build-and-run-tests.py`` and is
designed to be used for the builds inside the LLVM source tree. This implementation 
is briefly described above.
The second implementation uses ``cmake/ctest`` and is used in the CI with the extrnal LLVM 
installation. To configure this testing suite, use
``cmake ...  -DBINDER_ENABLE_TEST=ON ...``

Multiple python versions can be and should be used in parallel. The versions are set as a 
comma-separated list passed by the ``BINDER_TEST_PYTHON_VERSIONS`` option. The default list is ``0,2,3``.
The Python version "0" corresponds to a "plain diff" of the output vs. reference. 
The versions of Python2/Python3 will be the first versions found by cmake, see 
https://cmake.org/cmake/help/latest/module/FindPython.html and https://cmake.org/cmake/help/latest/module/FindPython3.html
for your cmake version. 
To use specific python versions one can use the following
``cmake .... -DBINDER_TEST_PYTHON_VERSIONS=0,2.7.15,3.8.0,3.7.0 ...``

The generated codes will be compiled and loaded using the corresponding interpreter.
With an option ``-DBINDER_MOCK_TEST=ON`` one can mock the code generation by binder. 
In this case the reference codes will be used in the python tests.

