Configuration
#############

Binder provides two ways to supply configuration options: command-line options for overall options and a config file for specific details.



Command line options
====================

``--root-module`` specify name of generated Python root module. This name is also used as prefix for various Binder output files. Typically the following files will be generated: ``<root-module>.cpp``, ``<root-module>.sources``,
``<root-module>.modules``.


``--max-file-size`` specify maximum file size in bytes exceeding which Binder will split generated sources into multiple files.


``--prefix`` name/path prefix for generated files.


``--bind`` list of namespaces that need to binded. Works in conjunction with similar config file directives.


``--skip`` list of namespaces that should be skipped. Works in conjunction with similar config file directives.


``--config`` specify config file to use.


``--single-file`` if specified instruct Binder to put generated sources into single large file. This might be useful for small projects.


``--flat`` if specified instruct Binder to write generate code files into single directory. Generated files will be named as ``<root-module>.cpp``, ``<root-module>_1.cpp``, ``<root-module>_2.cpp``, ... etc.

``--skip-line-number`` if specified prevents Binder from writing the line numbers in the comments to the generated code.

``--bind-class-template-specialization`` specify if class-template-specialization should be bound by-default

``--suppress-errors`` if the generated bindings codes are correct but there are some fatal errors from clang and you want to get rid of them. This situation can happen when you would like to generate binding codes for a small part of a huge project and the you cannot include all the required header files with ``-I`` to the command.


``--include-pybind11-stl`` "if specified bindings for STL classes in ``<pybind11/stl.h>`` will be used instead of generating custom STL bindings. Note, STL bindings may be overkill and have potential preformance implications if data does not need to be copied between ``C++`` and ``python``. For more information, see `pybind11 STL documentation <https://pybind11.readthedocs.io/en/stable/advanced/cast/stl.html>`_.


``--annotate-includes`` [debug] if specified Binder will comment each include with type name which trigger it inclusion.
``--annotate-functions`` [debug] if specified Binder will generate an extra comment for each function/constructor bound containing its C++ type signature.


``--trace`` [debug] if specified instruct Binder to add extra debug output before binding each type. This might be useful when debugging generated code that produce seg-faults during python import.


Config file options
===================

The config file is a text file containing either a comment-line (starts with ``#``) or a directive line started with either ``+`` or ``-`` signs followed by a directive's name and optional parameters. Some directives will accept only the ``+`` while others can be used with
both prefixes.

Selective bindings
------------------

These directives select which bindings shall be generated or skipped.

* ``namespace``, specify if functions/classes/enums from particular namespace should be bound. Can be used with both ``+`` and ``-``
  prefixes. This directive works recursively so for example if you specify ``+namespace root`` and later ``-namespace root::a`` then
  all objects in ``root`` will be bound with exception of ``root::a`` and its descendants.

.. code-block:: bash

  -namespace boost
  +namespace utility


* ``enum``, specify if particular enum should be bound. Purpose of this directive is to allow developer to cherry-pick
  particular enum from otherwise binded/skipped namespaces and mark it for binding/skipping.

.. code-block:: bash

  -enum utility::pointer::State
  +enum protocols::CDR_Type



* ``class``, specify if particular class/struct should be bound. Purpose of this directive is to allow developer to cherry-pick
  particular class from otherwise binded/skipped namespaces and mark it for binding/skipping.

.. code-block:: bash

  -class utility::pointer::ReferenceCount
  -class std::__weak_ptr

* ``field``, specify if a particular field should be skipped (only with ``-``).

.. code-block:: bash

  -field MyClass::some_field


* ``function``, specify if particular function should be bound (``+``) or skipped (``-``). This can be used for both template and normal function. Functions can be specified by just their name, or for more specific control, via their full argument list. To get the exact rendering of the argument list correct, it is recommended to run Binder first to see its output, and then use the generated function name here.

.. code-block:: bash

  -function ObjexxFCL::FArray<std::string>::operator-=
  -function core::id::swap
  -function aaa::foo(const std::string &)


* ``python_builtin``, specify if particular class/struct should be considered a python builtin and assume existing bindings for it already exist.
  The purpose of this directive is to allow developer to allow developers to toggle if bindings for types like ``std::optional`` or ``pybind11::dict`` should be
  generated, or if binder should assume such bindings already exist somewhere else. Alternatively, a developer can declare a type as not-builtin if they
  would prefer to force binder to generate bindings for it. Note that removing a builtin (``-python_builtin abc``) always overrides everything else (such as adding a builtin via ``+python_builtin abc``).

.. code-block:: bash

  -python_builtin std::less
  +python_builtin std::vector


Header includes
---------------

These directives allow to include additional headers in the generated code.

* ``include``, directive to control C++ include directives. Force Binder to either skip adding particular include into generated
  source files (``-`` prefix) or force Binder to always add some include files into each generated file. Normally Binder can
  automatically determine which C++ header files is needed in order to specify type/functions but in some cases it might be
  useful to be able to control this process. For example forcing some includes is particularly useful when you want to provide
  custom-binder-functions with either ``+binder`` or ``+add_on_binder`` directives.

.. code-block:: bash

  -include <boost/format/internals.hpp>
  +include <python/PyRosetta/binder/stl_binders.hpp>



* ``include_for_class``, directive to control C++ include directives on a per-class basis. Force Binder to add particular include
  into generated source files when a given target class is present. This allows the inclusion of custom binding code, which may
  then be referenced with either ``+binder`` or ``+add_on_binder`` directives.

.. code-block:: bash

  +include_for_class example::class <example/class_binding.hpp>



* ``include_for_namespace``, directive to control C++ include directives on a per-namespace basis. Force Binder to add particular include
  into generated source files when generating bindings for specified namespace. This allows the inclusion of custom binding code, which may
  then be referenced with either ``+binder``, ``+add_on_binder``,  ``binder_for_namespace`` or ``add_on_binder_for_namespace`` directives.

.. code-block:: bash

  +include_for_namespace aaaa::bbbb <aaaa/bbbb/namespace_binding.hpp>


Additional bindings
-------------------

These directives allow to specify add-ons and other custom binding code to augment or replace the generated code.


* ``binder``, specify custom binding function for particular concrete or template class. In the example below all
  specializations of template std::vector will be handled by ``binder::vector_binder`` function. For template classes binder
  function should be a template function taking the same number of types as original type and having the following type
  signature: pybind11 module, then std::string for each template argument provided. So for ``std::vector`` it will be:

.. code-block:: c++

  template <typename T, class Allocator>
  vector_binder(pybind11::module &m, std::string const &name, std::string const & /*allocator name*/) {...}



* ``+add_on_binder``, similar to ``binder``: specify custom binding function for class/struct that will be called `after` Binder
  generated code bound it. This allow developer to create extra bindings for particular type (bind special Python methods,
  operators, etc.) The expected type signature of specified function should be `void f(pybind11::class_<T, std::shared_ptr<T> > &)`

.. code-block:: bash

  +binder std::vector my_binders::vector_binder
  +binder std::map    my_binders::map_binder

  +add_on_binder numeric::xyzVector rosetta_binders::xyzVector_add_on_binder



* ``+binder_for_namespace``, similar to ``binder``: specify custom binding function for namespace. Call to specified function will be generated
  `instead` of generating bindings for namaspace. Where expected type signature of specified function should be `void f(pybind11::module &)`

.. code-block:: bash

  +binder_for_namespace aaaa binder_for_namespace_aaaa



* ``+add_on_binder_for_namespace``, similar to ``add_on_binder``: specify custom binding function for namespace that will be called `before` Binder
  generated code bound it. This allow developer to create extra bindings for particular namespace.

.. code-block:: bash

  +add_on_binder_for_namespace aaaa::bbbb binder_for_namespace_aaaa_bbbb


Return Value Policy
-------------------

By default, Binder will add a return value policy statement whereever needed, but keep it at the defaults. These directives allow to overwrite this behavior for particular types of functions.


For class member functions:


* ``default_static_pointer_return_value_policy``, specify the default return value policy for static member functions returning a pointer to an object. Default is
  `pybind11::return_value_policy::automatic`.


* ``default_static_lvalue_reference_return_value_policy``, specify the default return value policy for static member functions returning an l-value reference. Default
  is `pybind11::return_value_policy::automatic`.


* ``default_static_rvalue_reference_return_value_policy``, specify the default return value policy for static member functions returning an r-value reference. Default
  is `pybind11::return_value_policy::automatic`.


* ``default_member_pointer_return_value_policy``, specify the default return value policy for member functions returning a pointer to an object. Default is
  `pybind11::return_value_policy::automatic`.


* ``default_member_lvalue_reference_return_value_policy``, specify the default return value policy for member functions returning an l-value reference. Default
  is `pybind11::return_value_policy::automatic`.


* ``default_member_rvalue_reference_return_value_policy``, specify the default return value policy for member functions returning an r-value reference. Default
  is `pybind11::return_value_policy::automatic`.


* ``default_member_assignment_operator_return_value_policy``, specify the default return value policy for assignment operators (`operator=`, `operator+=`, `operator-=`, `operator*=`, `operator/=`, `operator%=`, `operator<<=`, `operator>>=`, `operator&=`, `operator|=`, `operator^=`). This is used only if all the following conditions are met: A non-static member function, taking exactly one parameter, and returning an lvalue reference to the class type itself. In particular, the `default` copy and move assignment operators fulfill these requirements. Typically, other such assignemnt operators also end in ``return *this;``, returning a reference to the assigned-to instance. This is thus a special case where the above return value policy defaults might not be the correct choice. Default is empty, in which case this is not used, in order to maintain backwards compatibility with previous Binder verions. It is recommended to set this to `pybind11::return_value_policy::reference_internal`.

.. code-block:: bash

  +default_member_pointer_return_value_policy           pybind11::return_value_policy::reference
  +default_member_lvalue_reference_return_value_policy  pybind11::return_value_policy::reference_internal
  +default_member_rvalue_reference_return_value_policy  pybind11::return_value_policy::move


For free functions, Binder offers separate defaults. This is for instance useful for functions that create objects and return a pointer to them. Returning references from free functions is likely not common, but offered for completeness as well.


* ``default_function_pointer_return_value_policy``, specify the default return value policy for free functions returning a pointer to an object. Default is
  `pybind11::return_value_policy::automatic`.


* ``default_function_lvalue_reference_return_value_policy``, specify the default return value policy for free functions returning an l-value reference. Default
  is `pybind11::return_value_policy::automatic`.


* ``default_function_rvalue_reference_return_value_policy``, specify the default return value policy for free functions returning an r-value reference. Default
  is `pybind11::return_value_policy::automatic`.

.. code-block:: bash

  +default_function_pointer_return_value_policy           pybind11::return_value_policy::move
  +default_function_lvalue_reference_return_value_policy  pybind11::return_value_policy::reference
  +default_function_rvalue_reference_return_value_policy  pybind11::return_value_policy::move


In verbose mode, Binder prints functions that use any of those default return value policies. This is meant as a check for developers to see if any of them need custom policies instead.

* ``return_value_policy_for_class``, specify a custom return value policy for all functions in a class that require one (i.e., that return a reference or pointer type). For class templates, it is also possible to specify a policy for all instantiations (by leaving out the template arguments), and then refine this by overwriting the policy for specific instantiations again.

.. code-block:: bash

  +return_value_policy_for_class aaa::A      pybind11::return_value_policy::move
  +return_value_policy_for_class aaa::A<int> pybind11::return_value_policy::copy


* ``return_value_policy``, specify a custom return value policy for a member function or free function. This overwrites the default or class-specific policies above. This can be specified for all overloads of a function at once, and again separately refined per overload by providing the fully specified name with arguments (and potentially template specializations).

.. code-block:: bash

  +return_value_policy aaa::foo                      pybind11::return_value_policy::move
  +return_value_policy aaa::foo(const std::string &) pybind11::return_value_policy::copy
  +return_value_policy aaa::A::bar                   pybind11::return_value_policy::reference
  +return_value_policy aaa::A::baz(int, int)         pybind11::return_value_policy::reference_internal


Miscellaneous
-------------

* ``default_call_guard``, optionally specify a call guard applied to all function definitions. See `pybind11 documentation <https://pybind11.readthedocs.io/en/stable/advanced/functions.html#call-guard>`_. Default None.

.. code-block:: bash

  +default_call_guard pybind11::gil_scoped_release

* ``+custom_shared``: specify a custom shared pointer class that Binder should use instead of ``std::shared_ptr``.

* ``module_local_namespace``: use to add (or remove) the extra argument module_local to the pybind11 classes and enum of a namespace. This option can be used for all the namaspaces of a given project using `+module_local_namespace @all_namespaces`.

.. code-block:: bash

  +module_local_namespace @all_namespaces
  -module_local_namespace std

* ``trampoline_member_function_binder``: use to specify a custom trampoline member function defined by the user in a given header file

.. code-block:: bash

  +include_for_class aaa::A <T81.custom_trampoline_with_args.include>
  +trampoline_member_function_binder aaa::A::foo myFoo


* ``+prefix_for_static_member_functions``: specify name prefix to use for static member functions, could be useful as workaround Pybind11 limitation restricting having both virtual and static member functions having the same name

* ``smart_holder``: use to specify that a class requires the usage of the progressive mode of the pybind11 smart_holder branch (https://github.com/pybind/pybind11/tree/smart_holder). As discussed in https://github.com/pybind/pybind11/blob/smart_holder/README_smart_holder.rst, the smart_holder branch is a strict superset of the pybind11 master branch that supports safely passing trampoline objects back to C++: associated Python objects are automatically kept alive for the lifetime of the smart-pointer. This config file directive has been added to fulfil https://github.com/RosettaCommons/binder/issues/263.

.. code-block:: bash

  +smart_holder example::class

* ``pybind11_include_file``: use to specify which header file of pybind11 should be included. The header pybind11/pybind11.h is used by default.

.. code-block:: bash

  +pybind11_include_file pybind11/smart_holder.h
