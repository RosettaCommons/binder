#!/usr/bin/env python3

import glob
import os
import sys
import shutil
import subprocess
from distutils.sysconfig import get_python_inc


def make_all_includes():
    all_includes = []
    all_include_filename = "all_cmake_includes.hpp"
    for filename in glob.glob("include/**/*.hpp", recursive=True):
        with open(filename, 'r') as fh:
            for line in fh:
                if line.startswith("#include"):
                    all_includes.append(line.strip())
    all_includes = list(set(all_includes))
    with open(all_include_filename, 'w') as fh:
        for include in all_includes:
            fh.write(f"{include}\n")
    return all_include_filename


def make_bindings_code(all_includes_fn):
    bindings_dir = "cmake_bindings"
    shutil.rmtree(bindings_dir, ignore_errors=True)
    os.mkdir(bindings_dir)
    binder_executable = glob.glob(f"{os.getcwd()}/../../build/llvm-4.0.0/build_4.0.0*/bin/binder")[0]
    command = f'{binder_executable} --root-module test_struct --prefix {os.getcwd()}/{bindings_dir}/ --bind testers -trace {all_includes_fn}  -- -std=c++11 -I{os.getcwd()}/include -DMY_PROJECT_DEFINE -DNDEBUG'.split()
    print(" ".join(command))
    ret = subprocess.call(command)
    sources_to_compile = []
    with open(f"{bindings_dir}/test_struct.sources", 'r') as fh:
        for line in fh:
            sources_to_compile.append(line.strip())
    return sources_to_compile


def compile_sources(sources_to_compile):
    bindings_dir = "cmake_bindings"
    og_dir = os.getcwd()
    os.chdir(bindings_dir)
    lines_to_write = []
    lines_to_write.append("project(test_struct)")

    binder_source = f"{os.getcwd()}/../../../source"
    this_project_source = f"{os.getcwd()}/../include"
    pybind_source = f"{os.getcwd()}/../../../build/pybind11/include"
    compiled_sources = []
    include_directories = []
    for include_dir in [binder_source, this_project_source, pybind_source, get_python_inc()]:
        lines_to_write.append(f"include_directories({include_dir})")
    lines_to_write.append("set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)")
    lines_to_write.append("add_definitions(-DNDEBUG)")

    lines_to_write.append("add_library(test_struct SHARED")
    for source in sources_to_compile:
        lines_to_write.append(f"\t{source}")
    lines_to_write.append(")")
    lines_to_write.append('set_target_properties(test_struct PROPERTIES PREFIX "")')
    lines_to_write.append("set_target_properties(test_struct PROPERTIES SUFFIX \".so\")")

    with open("CMakeLists.txt", 'w') as f:
        for line in lines_to_write:
            f.write(f"{line}\n")
    # Done making CMakeLists.txt
    subprocess.call("cmake -G Ninja".split())
    subprocess.call("ninja")
    sys.path.append('.')
    import test_struct
    test_obj = test_struct.testers.test_my_struct()
    print(test_obj.an_int)


def main():
   all_includes_fn =  make_all_includes()
   sources_to_compile = make_bindings_code(all_includes_fn)
   compile_sources(sources_to_compile)


if __name__ == "__main__":
    main()
