The Basics
##########

In this sections we describe basic Binder usage.


Principles
==========

In order to create shareed library that will provide bindings to C++ code we need to:

1. Gather data about what classes/functions are available and acquire in-depth information of class heritage, member functions
   and standalone functions type signatures.

2. Generate bindings code

3. Compile code into shared library


Binder is tool that aim to automate steps 1 and 2.



Preparing the input file
------------------------

In order to feed Binder infromation our underlying C++ code we need to create special C++ include file that in turn include all
header files from our project. For example: suppose that our C++ project conatin the following header files: `frutes/apple.hpp`,
`frutes/orange.hpp` and `vegetables/tomato.hpp`. In this call our special include file should contain something like this:

.. code-block:: C++

  #include <frutes/apple.hpp>
  #include <frutes/orange.hpp>
  #include <vegetables/tomato.hpp>


.. Note::

   Make sure to specify complete-relative-to-project-root path to includes and use ``#include <file>`` and avoid using ``#include "file"`` form. That
   way Binder will be able to determine correct include paths for each include which is essential for generating correct include sets on step 2.


For small projects such file could be simply typed by-hands and for large project it might be more practical to use a scripts to
do so.


Running the Binder
------------------

After the input file is ready the next step is to run Binder. Assuming that our include file conatining all headers from the
project is named as ``all_includes.hpp`` it could be done as:

.. code-block:: bash

	binder --root-module my_project	--prefix $HOME/my_project/bindings/source \
	  --bind my_root_namespace \
	  all_includes.hpp \
          -- -std=c++11 -I$HOME/my_project/include -I$HOME/extra/some_libs \
	  -DMY_PROJECT_DEFINE -DNDEBUG


Note that we have to specify project-wide include path so Binder could find includes specifies in ``all_includes.hpp`` as well
as path to any aditional C++ include headers that is used in project.

Most big project will probably require fine tunning of bindings generation process. This can be done by creating Binder config
file and specifying it when calling Binder as ``--config my_project.config``. For detailed reference of config file options
please see :any:`config`.



Compiling generated code
------------------------

If all goes well and Binder finished its run without error the path spefied by ``--prefix`` option should contain geneated source code and auxiliary files:

``<root_module_name>.sources`` list of generated source files

``<root_module_name>.cpp`` main file for binding code

``<root_module_name>.modules`` file contatining the list of Python modules that was generated
