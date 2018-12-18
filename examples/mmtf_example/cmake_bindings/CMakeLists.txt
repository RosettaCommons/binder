project(mmtf_cpp)
include_directories(/home/danpf/git/binder/examples/mmtf_example/../../source)
include_directories(/home/danpf/git/binder/examples/mmtf_example/include)
include_directories(/home/danpf/git/binder/examples/mmtf_example/include)
include_directories(/home/danpf/git/binder/examples/mmtf_example/cmake_bindings/msgpack_include)
include_directories(/home/danpf/git/binder/examples/mmtf_example/../../build/pybind11/include)
include_directories(/home/danpf/.local/share/pyenv/versions/3.7.0/include/python3.7m)
set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)
add_definitions(-DNDEBUG)
add_library(mmtf_cpp SHARED
	mmtf_cpp.cpp
	std/exception.cpp
	std/locale_classes.cpp
	std/system_error.cpp
	std/basic_ios_tcc.cpp
	std/istream_tcc.cpp
	std/fstream_tcc.cpp
	std/fstream_tcc_1.cpp
	std/stl_vector.cpp
	std/stl_vector_1.cpp
	std/stl_vector_2.cpp
	std/stl_vector_3.cpp
	std/stl_vector_4.cpp
	std/stl_vector_5.cpp
	std/sstream_tcc.cpp
	unknown/unknown.cpp
	unknown/unknown_1.cpp
	unknown/unknown_2.cpp
	unknown/unknown_3.cpp
	std/stl_map.cpp
	unknown/unknown_4.cpp
	unknown/unknown_5.cpp
	unknown/unknown_6.cpp
	unknown/unknown_7.cpp
	unknown/unknown_8.cpp
	unknown/unknown_9.cpp
	unknown/unknown_10.cpp
	unknown/unknown_11.cpp
	unknown/unknown_12.cpp
)
set_target_properties(mmtf_cpp PROPERTIES PREFIX "")
set_target_properties(mmtf_cpp PROPERTIES SUFFIX ".so")
