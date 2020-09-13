Debugging
##########

This section is to talk about examples of how you would debug your config.

---------------
Basic knowledge
---------------

Sometimes, things aren't as point and click as you might expect it to be.  
Here are some helpful tips that might help you on your way to making bindings.


---------------
inconsistencies
---------------

Binder moves down your ``all_includes_file`` sequentially, sometimes you might end up with errors,
and sometimes you might not.  This is almost always caused by your ``all_includes_file`` being
different between runs.  The order shouldn't really matter, but nail it down to at least be
consistent, and then move on to the next step.

--------------
Build failures
--------------

Sometimes you might get an error when building your compiled module.  binder has trouble  
when standard libraries include eachother.  We have already mapped many of these
interactions in ``types.cc``, but we still might be missing some internal knowledge about
all of the c++ std library modules out there.  An error like this almost always
manifests itself with an abundance of errors complaining about ``std::bits`` or ``bits``.


So let's go through something I just debugged. Binder seemed to work fine, however the actual
compiling step failed with the error:

.. code-block:: console

    FAILED: CMakeFiles/statvec.dir/std/complex.o 
    In file included from std/complex.cpp:1:0:
    /usr/include/c++/7/bits/stl_construct.h: In function ‘void std::_Destroy(_ForwardIterator, _ForwardIterator)’:
    **bunch of garbage below here**

1.  Rebuild bindings, but now add the flag ``--annotate-includes`` which will give us much
    more information than we would normally get

2.  Since we know that ``bits`` is bad for binder, we can just grep for bits in the directory where we
    generate and compile the bindings.  In the ``examples`` section, this is the same as the directory
    ``cmake_bindings``.

3.  We then run the ``grep -r "bits" cmake_bindings/*`` which yields:

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
  
Wow that's a lot, but we are really only interested in the std modules without ``_`` in them,
usually located near the bottom! in this case, we are interested in
``std::uninitialized_copy``.  A quick google tells us that this is part of the
``#include <memory>`` library.  Something that binder (in this case) hadn't seen before.

Let's fix that!

4.  The internal binder function that we have made all std library mappings for is located
    in ``source/types.cpp``:``add_relevant_include_for_decl``.  It has a vector that is
    instantiated via something that looks a lot like this:

.. code-block:: python

    { "<algorithm>", {"std::move_backward", "std::iter_swap", "std::min"} },
    { "<exception>", {"std::nested_exception"} }

In this case, we needed to make a simple change that added a map for ``<memory>``


.. code-block:: python

    { "<algorithm>", {"std::move_backward", "std::iter_swap", "std::min"} },
    { "<exception>", {"std::nested_exception"} },
    { "<memory>", {"std::uninitialized_copy"} },


5.  Recompile binder, and then rebuild and see if your build works, if not and you still see ``bits``
    rinse, and repeat.  If this fixes your problem please let us know, or make a pull request!
