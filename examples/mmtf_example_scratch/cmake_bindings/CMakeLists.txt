project(mmtf_cpp)
include_directories(/home/danpf/git/binder/examples/mmtf_example_scratch/../../source)
include_directories(/home/danpf/git/binder/examples/mmtf_example_scratch/mmtf-cpp/include)
include_directories(/home/danpf/git/binder/examples/mmtf_example_scratch/mmtf-cpp/include/mmtf)
include_directories(/home/danpf/git/binder/examples/mmtf_example_scratch/msgpack-c/include)
include_directories(/home/danpf/git/binder/examples/mmtf_example_scratch/../../build/pybind11/include)
include_directories(/home/danpf/.local/share/pyenv/versions/3.7.0/include/python3.7m)
set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)
add_definitions(-DNDEBUG)
add_library(mmtf_cpp SHARED
	mmtf_cpp.cpp
)
set_target_properties(mmtf_cpp PROPERTIES PREFIX "")
set_target_properties(mmtf_cpp PROPERTIES SUFFIX ".so")
