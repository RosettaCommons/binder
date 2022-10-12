Binder Limitations
##################

This section lists some of ``binder``'s more prominent limitations.

------------------
External Operators
------------------

Unlike C++, which allows operators to be defined outside of classes and redefined across different namespaces, python requires operators be member functions and thus lacks the ability to choose which overload to use based on context.
In line with this, ``binder`` will only bind (most) C++ operators if they are member functions (i.e. they cannot be defined externally).

These operators include, but are not necessarily limited to:

.. code-block:: console
    operator~ (__invert__)

    operator+ (__add__)
    operator- (__sub__)
    operator* (__mul__)
    operator/ (__div__)
    operator% (__mod__)

    operator& (__and__)
    operator| (__or__)
    operator^ (__xor__)
    operator<< (__lshift__)
    operator>> (__rshift__)

    operator+= (__iadd__)
    operator-= (__isub__)
    operator*= (__imul__)
    operator/= (__idiv__)
    operator%= (__imod__)

    operator&= (__iand__)
    operator|= (__ior__)
    operator^= (__ixor__)
    operator<<= (__ilshift__)
    operator>>= (__irshift__)

    operator() (__call__)
    operator== (__eq__)
    operator!= (__ne__)
    operator[] (__getitem__)
    operator= (assign)
    operator++ (plus_plus)
    operator-- (minus_minus)

-----------------
Ignored Operators
-----------------

The following operators will be ignored by binder:

.. code-block:: console

    // Logical
    &&
    ||

    // Cast to T
    explicit operator T()
    operator T()

    // Misc
    ,
    new
    new[]
    delete
    delete[]

-------------
Miscellaneous
-------------

1.   The pre/post increment operators both map to ``plus_plus`, with the pre-increment operator being invoked via ``a.plus_plus()`` and post-increment via ``.plus_plus(0)``; just as the operators are technically defined in C++. The same is true for the pre/post decrement operators, both called ``minus_minus``.

2.   User defined literals ``operator"" _foo`` end up being named as ``operator_foo``.
