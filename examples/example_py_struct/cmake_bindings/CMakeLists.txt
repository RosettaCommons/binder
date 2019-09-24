project(test_struct)
include_directories(/home/danpf/git/binder/examples/example_py_struct/../../source)
include_directories(/home/danpf/git/binder/examples/example_py_struct/include)
include_directories(/home/danpf/git/binder/examples/example_py_struct/include)
include_directories(/home/danpf/git/binder/examples/example_py_struct/../../build/pybind11/include)
include_directories(/home/danpf/.conda/envs/py3/include/python3.7m)
set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)
add_definitions(-DNDEBUG)
add_library(test_struct SHARED
	test_struct.cpp
	test_struct/test_struct.cpp
)
set_target_properties(test_struct PROPERTIES PREFIX "")
set_target_properties(test_struct PROPERTIES SUFFIX ".so")
