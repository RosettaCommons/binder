Examples
##########

This section is to talk about examples of how you would use binder.


Examples
________
There are two examples of how to build bindings. One that builds the bindings
using a simple bash script, and another that builds the bindings using cmake.
The final lines of each script also import the ``test_struct`` module and
prints a variable of it.


Basic outline
=============
These examples follow this general workflow:

1.  Make a file that includes all ``#include`` lines

    - They must use ``<>`` not ``""``  
2.  Generate bindings with binder

    - Set the namespace(s) to bind with the flag ``--bind``  
3.  Compile the cpp files into objects separately
4.  Link all generated objects into one file with the suffix ``.so``
5.  Try importing into python!


Simple struct
=============
Building bindings for a simple struct

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

First go into the directory where we build the bindings (set by ``--prefix``) and
then run the command:

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

This however, will fail:

.. code-block:: console

    python3 -c "import sys; sys.path.append('.'); import test_struct; f = test_struct.testers.test_my_struct(); print(f.a_float); f.add_float(); print(f.a_float); print(f.a_vector)"

This fails because python doesn't understand how to interact with the std library classes like ``std::vector``
You can get around this by remaking your bindings with a config file.


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

**NOTE: ^^**
************
This will now run and print ``[1, 2, 3, 4, 5]`` **HOWEVER** there is *some*
performance loss that comes from converting your c++ vectors to python and
back. If performance is critical, it is advised that most work is done via
c++, and you just use python as the 'glue'.

As an example of this, try running the command without adding the stl bindings:

.. code-block:: console

    python3 -c "import sys; sys.path.append('.'); import test_struct; f = test_struct.testers.test_my_struct(); print(f.a_float); f.add_float(); print(f.a_float); f.append_vec()"

Since python never 'sees' the vector, it doesn't crash.
