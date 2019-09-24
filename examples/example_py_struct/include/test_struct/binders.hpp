
#ifndef TEST_STRUCT_BINDERS_H
#define TEST_STRUCT_BINDERS_H
#include <test_struct/test_struct.hpp>

#include <pybind11/pybind11.h>
// #include <pybind11/numpy.h>


namespace pybind11 { namespace detail {
		template <> struct type_caster<testers::thingy> {
		public:
				/**
				 * This macro establishes the name 'testers::thingy' in
				 * function signatures and declares a local variable
				 * 'value' of type testers::thingy
				 */
				PYBIND11_TYPE_CASTER(testers::thingy, _("testers::thingy"));

				/**
				 * Conversion part 1 (Python->C++): convert a PyObject into a testers::thingy
				 * instance or return false upon failure. The second argument
				 * indicates whether implicit conversions should be applied.
				 */
				bool load(handle src, bool) {
						/* Extract PyObject from handle */
						PyObject *source = src.ptr();
						/* Try converting into a Python integer value */
					if (!PyUnicode_Check(source)) return false;
						/* Now try to convert into a C++ int */
						value.hello = std::string(PyUnicode_AsUTF8(source));
						/* Ensure return code was OK (to avoid out-of-range errors etc) */
						return !PyErr_Occurred();
				}

				/**
				 * Conversion part 2 (C++ -> Python): convert an testers::thingy instance into
				 * a Python object. The second and third arguments are used to
				 * indicate the return value policy and parent object (for
				 * ``return_value_policy::reference_internal``) and are generally
				 * ignored by implicit casters.
				 */
				static handle cast(testers::thingy src, return_value_policy /* policy */, handle /* parent */) {
						return PyUnicode_FromString(src.hello.data());;
				}
		};
}} // namespace pybind11::detail

#endif
