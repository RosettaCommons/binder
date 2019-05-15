project(mmtf_cpp)
include_directories(/home/danpf/git/binder/examples/mmtf_example/../../source)
include_directories(/home/danpf/git/binder/examples/mmtf_example/include)
include_directories(/home/danpf/git/binder/examples/mmtf_example/include)
include_directories(/home/danpf/git/binder/examples/mmtf_example/include/mmtf)
include_directories(/home/danpf/git/binder/examples/mmtf_example/../../build/pybind11/include)
include_directories(/home/danpf/.local/share/pyenv/versions/3.7.0/include/python3.7m)
set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)
add_definitions(-DNDEBUG)
add_library(mmtf_cpp SHARED
	mmtf_cpp.cpp
)
set_target_properties(mmtf_cpp PROPERTIES PREFIX "")
set_target_properties(mmtf_cpp PROPERTIES SUFFIX ".so")
