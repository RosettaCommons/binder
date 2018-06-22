# Building bindings for a simple struct
This is an example of how you might make python bindings for a simple cpp
struct.

## Basic outline
1.  Make a file that includes all `#include` lines
  a.  They must use `<>` not `""`
2.  Generate bindings with binder
  a.  Set the namespace(s) to bind after the flag `--bind`
3.  Compile the cpp files into objects separately
4.  Link all generated objects into one file with the suffix `.so`
5.  Try importing into python!


## Examples
There are two examples, one that builds the bindings using a simple bash script,
and another that builds the bindings using cmake.  The final lines of each script
also import the `test_struct` module and prints a variable of it.

