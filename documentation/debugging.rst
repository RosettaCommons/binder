Debugging and troubleshooting 
##########

This section is dedicated to the description of problems that 
might appear while creating the python bindings with binder and the ways to avoid them.

Below are some helpful tips that might help to make the bindings.


---------------
Inconsistencies
---------------

Binder moves down the ``all_includes_file`` file sequentially, sometimes ending up with errors.  
This is almost always caused by the ``all_includes_file`` being
different between runs.  The order shouldn't be important, but nail it down to at least be
consistent, and then move on to the next step.

--------------
Build failures
--------------

Even when the bindings were generated successfully,  there might be compilation errors when building the modules from the generated sources.
Quite often  the errors are caused by the implementation of the С++standard library, when the headers of the standard library 
include each other, or include implementation-specific headers. 
Many cases like that are already handled in the functions from the ``source/types.cpp`` file, 
using the knowledge of the existing STL implementations.
However some cases might still be missing, e.g. for the newest or not wide-spread versions of STL. 
An example of debugging for these cases is described below.


On systems with GNU STL, the compilation errors for the cases not handled by the ``source/types.cpp``,
would manifest itself with an abundance of long and cryptic messages

For instance, the compilation could fail with the following error messages:

.. code-block:: console

    FAILED: CMakeFiles/statvec.dir/std/complex.o 
    In file included from std/complex.cpp:1:0:
    /usr/include/c++/7/bits/stl_construct.h: In function ‘void std::_Destroy(_ForwardIterator, _ForwardIterator)’:
    **long and cryptic error message**

The ways to handle this error:

1.  Rebuild bindings adding the flag ``--annotate-includes`` which will provide much
    more information on the binded classes.

2.  Since the includes from the ``bits`` directory should not appear in the generated code,  one can grep for ``bits`` in the generated codes, 
   i.e. ``grep -r "bits" cmake_bindings/*`` could yield:

.. code-block:: console

    cmake_bindings/std/complex.cpp:#include <bits/stl_construct.h> // std::_Construct
    cmake_bindings/std/complex.cpp:#include <bits/stl_construct.h> // std::_Destroy
    cmake_bindings/std/complex.cpp:#include <bits/stl_construct.h> // std::_Destroy_aux
    cmake_bindings/std/complex.cpp:#include <bits/stl_construct.h> // std::_Destroy_aux<true>::__destroy
    cmake_bindings/std/complex.cpp:#include <bits/stl_construct.h> // std::_Destroy_n_aux
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_copy
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_copy<false>::__uninit_copy
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_copy<true>::__uninit_copy
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_copy_a
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_default_1
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_default_n
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_default_n_1
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_default_n_1<false>::__uninit_default_n
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_default_n_1<true>::__uninit_default_n
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_default_n_a
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_default_novalue_1
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_default_novalue_n_1
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_fill
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_fill_n
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::__uninitialized_move_if_noexcept_a
    cmake_bindings/std/complex.cpp:#include <bits/stl_uninitialized.h> // std::uninitialized_copy
  
The important information in the output is the ``std::`` types/functions without the leading underscores.
 Those are STL-implementation independent types/functions that should be defined elsewhere, not in the headers from the ``bits`` directory.
In this particular example, the function of interest is ``std::uninitialized_copy``.  

A quick search in the C++ documentation at https://en.cppreference.com or other resources tells that this function is defined in the <memory> header.
Therefore, this information should be hardcoded into the binder.


3.  The internal binder function that handles the STL library mappings is located in ``source/types.cpp``:``add_relevant_include_for_decl``.  
Briefly, the function has a map with the STL headers and the types those contain. That should look similar to this:

.. code-block:: python

    { "<algorithm>", {"std::move_backward", "std::iter_swap", "std::min"} },
    { "<exception>", {"std::nested_exception"} }


If there is a need to make a simple change, like in our case,  the map for the ``<memory>`` can be added like this:

.. code-block:: python

    { "<algorithm>", {"std::move_backward", "std::iter_swap", "std::min"} },
    { "<exception>", {"std::nested_exception"} },
    { "<memory>", {"std::uninitialized_copy"} },


In addition to that, to ensure a better portability, some of the implementation-specific headers are replaced in binder with the standard ones.
The map that holds the replacements is located in the ``source/types.cpp`` file as well. It should look similar to this:

.. code-block:: python

       static vector< std::pair<string, string> > const include_map = {
        make_pair("<bits/ios_base.h>",     "<ios>"),
        make_pair("<bits/istream.tcc>",    "<istream>"),
        make_pair("<bits/ostream.tcc>",    "<ostream>"),
        make_pair("<bits/postypes.h>",     "<ios>"),


4.  After the changes are done, the binder executable should be recompilled and re-used to create the desired bindings. 
    In some cases, many iterations of the described procedure will be needed till all the STL types/functions will be mapped to the correct includes. 
    
    If this fixes your problem please let us know, or make a pull request!
    