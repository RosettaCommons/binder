#!/usr/bin/env python3

import glob
import os
import sys
import shutil
import subprocess
from distutils.sysconfig import get_python_inc


# Overall script settings
binder_executable = glob.glob(f'{os.getcwd()}/../../build/llvm-4.0.0/build_4.0.0*/bin/binder')[0]
bindings_dir = 'cmake_bindings'
binder_source = f'{os.getcwd()}/../../source'
pybind_source = f'{os.getcwd()}/../../build/pybind11/include'
use_pybind_stl = True
# use_pybind_stl = False
this_project_source = f'{os.getcwd()}/include'
this_project_include = this_project_source
this_project_namespace_to_bind = 'testers'
python_module_name = 'test_struct'


def make_all_includes():
    all_includes = []
    all_include_filename = 'all_cmake_includes.hpp'
    for filename in (glob.glob(f'{this_project_source}/**/*.hpp', recursive=True) +
                     glob.glob(f'{this_project_source}/**/*.cpp', recursive=True) +
                     glob.glob(f'{this_project_source}/**/*.h', recursive=True) +
                     glob.glob(f'{this_project_source}/**/*.cc', recursive=True) +
                     glob.glob(f'{this_project_source}/**/*.c', recursive=True)):
        with open(filename, 'r') as fh:
            for line in fh:
                if line.startswith('#include'):
                    all_includes.append(line.strip())
    # all_includes.append("#include <test_struct/binders.hpp>")

    all_includes = [x for x in all_includes if 'pybind11.h' not in x]
    all_includes = list(set(all_includes))
    # This is to ensure that the list is always the same and doesn't
    # depend on the filesystem state.  Not technically necessary, but
    # will cause inconsistent errors without it.
    all_includes.sort()
    with open(all_include_filename, 'w') as fh:
        for include in all_includes:
            fh.write(f'{include}\n')
    return all_include_filename


def make_bindings_code(all_includes_fn):
    shutil.rmtree(bindings_dir, ignore_errors=True)
    os.mkdir(bindings_dir)
    command = (f'{binder_executable} --root-module {python_module_name} '
               f'--prefix {os.getcwd()}/{bindings_dir}/ '
               f'  --config config.cfg'
               f' {all_includes_fn} -- -std=c++11 '
               f' -I{this_project_include} -I{pybind_source} -I{get_python_inc()} -DNDEBUG -v').split()
    print('BINDER COMMAND: ' + ' '.join(command))
    subprocess.call(command)
    sources_to_compile = []
    with open(f'{bindings_dir}/{python_module_name}.sources', 'r') as fh:
        for line in fh:
            sources_to_compile.append(line.strip())
    return sources_to_compile


def compile_sources(sources_to_compile):
    os.chdir(bindings_dir)
    lines_to_write = []
    lines_to_write.append(f'project({python_module_name})')

    for include_dir in [binder_source, this_project_source, this_project_include, pybind_source, get_python_inc()]:
        lines_to_write.append(f'include_directories({include_dir})')
    lines_to_write.append('set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)')  # -fPIC
    lines_to_write.append('add_definitions(-DNDEBUG)')

    lines_to_write.append(f'add_library({python_module_name} SHARED')
    for source in sources_to_compile:
        lines_to_write.append(f'\t{source}')
    lines_to_write.append(')')
    lines_to_write.append(f'set_target_properties({python_module_name} PROPERTIES PREFIX "")')
    lines_to_write.append(f'set_target_properties({python_module_name} PROPERTIES SUFFIX ".so")')

    with open('CMakeLists.txt', 'w') as f:
        for line in lines_to_write:
            f.write(f'{line}\n')
    # Done making CMakeLists.txt
    subprocess.call('cmake -G Ninja'.split())
    subprocess.call('ninja')
    sys.path.append('.')
    if python_module_name == 'test_struct':
        sys.stdout.flush()
        print('Testing Python lib...')
        import test_struct
        test_obj = test_struct.testers.test_my_struct()
        test_obj2 = test_struct.testers.fakeie()
        print(test_obj.an_int)
        print(test_obj)
        print(test_obj2.an_int)
        print(test_obj2.a_string)
        if use_pybind_stl:
            print(test_obj.a_vector)


def main():
    all_includes_fn = make_all_includes()
    sources_to_compile = make_bindings_code(all_includes_fn)
    compile_sources(sources_to_compile)


if __name__ == '__main__':
    main()
