#include "buffer_protocol.hpp"
#include <pybind11/pybind11.h>
namespace py = pybind11;

template<class T>
void addon_Matrix(T &c)
{
	c.def_buffer([](buffer_protocol_example::Matrix &m) -> py::buffer_info {
			return py::buffer_info(
				m.data(),                               /* Pointer to buffer */
				sizeof(float),                          /* Size of one scalar */
				py::format_descriptor<float>::format(), /* Python struct-style format descriptor */
				2,                                      /* Number of dimensions */
				{ m.rows(), m.cols() },                 /* Buffer dimensions */
				{ sizeof(float) * m.cols(),             /* Strides (in bytes) for each index */
				sizeof(float) }
			);
		});
}