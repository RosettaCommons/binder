Examples
##########

This section is to talk about examples of how you would use binder.

**Notes:**
- All python code should be run in the directory with the generated ``.so`` file.

-------------
Basic outline
-------------

These examples follow this general workflow:

1.  Make a file that includes all ``#include`` lines

    - They must use ``<>`` not ``""``  
2.  Generate bindings with binder

    - Set the namespace(s) to bind with the flag ``--bind``  
3.  Compile the cpp files into objects separately
4.  Link all generated objects into one file with the suffix ``.so``
5.  Try importing into python!


-------------
Simple struct
-------------
There are three examples of how to build bindings in the ``example_struct``
folder. 

- ``make_bindings_via_cmake.py``
- ``make_bindings_via_bash.sh``
- ``make_bindings_via_bash_and_stl.sh``

Their names are self explanatory, but I would highly recommend that for your
own applications that you follow the ``python`` & ``cmake`` workflow.

Each script's final running lines also imports the ``test_struct`` module and
prints a variable or two of it to prove that it's working.


This example/tutorial will walk you through the step-by-step of both
``via_bash`` scripts, because they will help you better understand what needs
to be done to generate bindings.  Upon understanding the more manual ``bash``
method, the ``cmake`` code should make much more sense.

The rest of "Simple struct" will also take you through generating pybind11 stl
bindings (like making bindings for `std::vector` -> python list) and how to use
binder's bindings for `std::vector` to access `std::vector` objects without
converting them to python lists.  This allows us to benefit from the speed of
c++!

.. code-block:: python

    In [18]: timeit.timeit("l=[]\nfor x in range(1000):\n l.append(x)", number=10000)
    Out[18]: 0.6870336419997329

.. code-block:: python

    In [23]: timeit.repeat("l=std.vector_int()\nfor x in range(1000):\n l.append(x)", setup="import sys\nsys.path.append('.')\nimport test_struct.std as std", number=10000)
    Out[23]: [2.1859435529986513, 2.169744377002644, 2.17523188999985]


Building bindings basics
************************

**Using the g++/bash example we will go through how to generate bindings for
this simple struct.**

.. code-block:: C++

    #include <string>
    #include <vector>
    
    namespace testers {
    struct test_my_struct {
    	int an_int;
    	std::string a_string;
    	std::vector<int> a_vector;
    	float a_float;
    
    	test_my_struct() {
    		an_int = 27;
    		a_string = "TEST_STRING";
    		a_vector = std::vector<int>{1,2,3,4,5};
    		a_float = 88.88;
    	}
    
    	void
    	increment_int() {
    		++an_int;
    	}
    
    	void
    	add_float() {
    		a_float += 22.22;
    	}
    
    	void
    	append_vec() {
    		a_vector.push_back(a_vector.back()+1);
    	}
    
    };
    }

1. First we have to generate a file that combines all of the ``#includes``
   our project.

   - Remember, all ``#includes`` must use ``<>``

.. code-block:: console

    grep -rh "#include" include/* | sort -u > all_bash_includes.hpp

2. Next we have to generate the bindings via ``binder``

.. code-block:: console

    $PWD/../../build/llvm-4.0.0/build_4.0.0*/bin/binder \
      --root-module test_struct \
      --prefix $PWD/bash_bindings/ \
      --bind testers \
      all_bash_includes.hpp \
      -- -std=c++11 -I$PWD/include \
      -DNDEBUG

A skeleton of this would be:

.. code-block:: console

    $PWD/../../build/llvm-4.0.0/build_4.0.0*/bin/binder \
      --root-module ${my_python_module_name} \
      --prefix ${where_i_want_to_build_this} \
      --bind ${my_namespaces_to_build} \
      ${my_all_includes_file} \
      -- -std=c++11 -I${any_directores_to_include_for_compiler} \
      -DNDEBUG

3. Now that we have build bindings, we have to compile our bindings into 
   ``object files``.

First go into the directory where we build the bindings (set by ``--prefix``)
and then run the command:

.. code-block:: console

    pybase=`which python3`
    g++ \
      -O3 \
      -I${pybase::-12}/include/python3.6m -I$PWD/../../../build/pybind11/include -I$PWD/../include \
      -I$PWD/../../../source -shared  \
      -std=c++11  -c test_struct.cpp  \
      -o test_struct.o -fPIC

**NOTE ^^**
Your python directory may be different slightly, you can find out yours using
the shell command:

.. code-block:: console

    python -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())"

Again, a skeleton of this command would be:

.. code-block:: console

    pybase=`which python3`
    g++ \
      -O3 \
      -I${my_python_include_directory} -I${pybind11_include_directory} -I${my_project_directory} \
      -I${binder_source_directory} -shared  \
      -std=c++11  -c ${bindings_code_to_build_object_file_from}  \
      -o ${output_object_file_name} -fPIC

4. Do this again for the other generated ``.cpp`` file
   - **All** ``.cpp`` **files to compile are located in the** ``.sources`` **file.**

5. Link together all of the compiled ``object files``

.. code-block:: console

    g++ -o test_struct.so -shared test_struct/test_struct.o test_struct.o

6. Try running via python

.. code-block:: console

    python3 -c "import sys; sys.path.append('.'); import test_struct; f = test_struct.testers.test_my_struct(); print(f.an_int)"

This should yeild: ``27``

Binding STL via pybind11
************************

You may notice how ever that this will still fail:

.. code-block:: console

    python3 -c "import sys; sys.path.append('.'); import test_struct; f = test_struct.testers.test_my_struct(); print(f.a_float); f.add_float(); print(f.a_float); print(f.a_vector)"

This fails because python doesn't understand how to interact with the std
library classes like ``std::vector``. You can get around this by remaking your
bindings with this config file. **However**, you must note that when you are
returning vectors into your python environment, or pushing lists to the c++
side, there is a performance penalty when pybind converts from ``python
list[]`` -> ``std::vector``, and vice-versa. This can be a problem when dealing
with larger lists/vectors.

If performance is critical, it is advised that most work is done via c++,
and you just use python as the 'glue'. For example, the following command
doesn't fail, because python never has to 'see' the std::vector and all of
the work is done in the c++ layer.

.. code-block:: console

    python3 -c "import sys; sys.path.append('.'); import test_struct; f = test_struct.testers.test_my_struct(); print(f.a_float); f.add_float(); print(f.a_float); f.append_vec()"

But before you discount this approach completely, give it a try! It may still
yeild performance improvements!

You can do this by adding a config file, and altering your binder compile
command to read the config command like this:

**my_config_file.cfg**

.. code-block:: C

    +include <pybind11/stl.h>

**New binder compile command**

.. code-block:: console

    pybase=`which python3`
    $PWD/../../build/llvm-4.0.0/build_4.0.0*/bin/binder \
      --root-module test_struct \
      --prefix $PWD/bash_bindings/ \
      --bind testers --config my_config_file.cfg \
      all_bash_includes.hpp \
      -- -std=c++11 -I$PWD/include -I$PWD/../../../build/pybind11/include -I${pybase::-12}/include/python3.6m \
      -DNDEBUG

As an example of how the pybind11 bindings work, try running the command:


.. code-block:: console

    python3 -c "import sys; sys.path.append('.'); import test_struct; f = test_struct.testers.test_my_struct(); print(f.a_float); f.add_float(); print(f.a_float); print(f.a_vector)"

This will now run and print ``[1, 2, 3, 4, 5]`` at the end!


Binding STL via Binder
************************

Binder allows us to add another layer so that we can interact directly with
`std::vector`` for improved performance.  This is sort of a hybrid between
the above pybind11 implementation, and full on c++ code. There are a few things
that have to be changed though, before this will work.

changes to allow for binder bindings
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. We must add a function that returns the ``std::vector<>`` type of interest.
   - **std::vector bindings will be optimized out unless we add this function**

.. code-block:: C++
    
	std::vector<int>
	get_a_vector() {
		return a_vector;
	}

2. We must make a config file that tells binder to build the vector bindings
   - you can also move the ``--bind`` commandline flags here by using the format ``+namespace {what to bind}``.

.. code-block:: C++

    +include <stl_binders.hpp>
    +namespace testers
    +binder std::vector binder::vector_binder

Now if we run the following command

.. code-block:: console

    python3 -c "import sys; sys.path.append('.'); import test_struct; f = test_struct.testers.test_my_struct(); print(f.a_float); f.add_float(); print(f.a_float); print(f.a_vector)"

this will print ``vector_int[1, 2, 3, 4, 5]`` at the end!, you can see, that
unlike how pybind11 returns a python list, we have a statically typed list
that can only take ints (much like c++).

in case you were curious, if you try to append a float to this list by using a
command like ``f.a_vector.append(22.22)``. You will see an error that looks
similar to this:

.. code-block:: bash

    Traceback (most recent call last):
      File "<string>", line 1, in <module>
    TypeError: append(): incompatible function arguments. The following argument types are supported:
        1. (self: test_struct.std.vector_int, x: int) -> None
    
    Invoked with: vector_int[1, 2, 3, 4, 5], 22.22

