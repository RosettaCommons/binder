About this project
==================
**Binder** is tool a for automatic generation of Python bindings for C++11 projects using `Pybind11 <https://github.com/pybind/pybind11>`_ and `Clang LibTooling <http://clang.llvm.org/docs/LibTooling.html>`_ libraries.  That is, Binder, takes a C++ project and compiles it into objects and functions that are all usable within Python.  Binder is different from prior tools in that it handles special features new in C++11.


Core features
*************
Automatically determine which types/functions could be bound and generate bindings for the following C++ code:

* functions
* enums
* C++ classes and structs, including:

 * read/write access to public data members, including static data members
 * class member functions including static functions
 * class inner enums
 * class operators

* automatically determine which template classes should be instantiated and generate bindings for it
* generate single shared library which on Python-import act as collection of Python modules representing hierarchy of C++ namespaces
* generated bindings for both Python-2.6+ and Python-3+

Goodies
*******
Bindings generation is guided thought config file which allows to configure:

- bindings for which namespace/type/function bindings should be generated

- default return policy for functions returning pointer, lvalue and rvalue references

- additional includes which should be added to generated code

- includes which should be ignored in generated codes

- specify custom bindings functions for type/template

- specify add-on bindings functions which will be called after automatic bindings was generated
