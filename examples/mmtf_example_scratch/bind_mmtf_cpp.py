#!/usr/bin/env python

import glob
import os
import sys
import shutil
import subprocess
from distutils.sysconfig import get_python_inc


# Overall script settings
BINDER_EXE = glob.glob(f'{os.getcwd()}/../../build/llvm-4.0.0/build_4.0.0*/bin/binder')[0]
BINDER_SOURCE = f'{os.getcwd()}/../../source'
PYBIND_SOURCE = f'{os.getcwd()}/../../build/pybind11/include'
OUTPUT_DIR = 'cmake_bindings'
MMTF_INCLUDE = os.path.join(os.getcwd(), 'mmtf-cpp', 'include')
MSGPACK_INCLUDE = os.path.join(os.getcwd(), 'msgpack-c', 'include')

this_project_namespace_to_bind = 'mmtf'
PYTHON_MODULE_NAME = 'mmtf_cpp'
single_file = True

# msgpack_includes = glob.glob("msgpack_include/**", recursive=True)
# msgpack_includes = [os.path.abspath(x) for x in msgpack_includes if os.path.isdir(x)] + [os.path.abspath("msgpack_include")]


def setup_dir():
    subprocess.call(["rm", "-rf", "mmtf-cpp"])
    subprocess.call(["rm", "-rf", "msgpack-c"])
    subprocess.call(["rm", "-rf", OUTPUT_DIR])
    subprocess.call(["git", "clone", "https://github.com/rcsb/mmtf-cpp.git"])
    subprocess.call(["git", "clone", "https://github.com/msgpack/msgpack-c.git"])


def get_all_MMTF_files():
    fns = []
    for filename in (glob.glob(f'{MMTF_INCLUDE}/**/*.hpp', recursive=True) +
                     glob.glob(f'{MMTF_INCLUDE}/**/*.cpp', recursive=True) +
                     glob.glob(f'{MMTF_INCLUDE}/**/*.h', recursive=True) +
                     glob.glob(f'{MMTF_INCLUDE}/**/*.cc', recursive=True) +
                     glob.glob(f'{MMTF_INCLUDE}/**/*.c', recursive=True) +
                     glob.glob(f'{MMTF_INCLUDE}/mmtf.hpp', recursive=True)):
        fns.append(filename)
    fns = list(set(fns))
    fns.sort()
    return fns


def get_all_MSGPACK_files():
    fns = []
    for filename in (glob.glob(f'{MSGPACK_INCLUDE}/**/*.hpp', recursive=True) +
                     glob.glob(f'{MSGPACK_INCLUDE}/**/*.cpp', recursive=True) +
                     glob.glob(f'{MSGPACK_INCLUDE}/**/*.h', recursive=True) +
                     glob.glob(f'{MSGPACK_INCLUDE}/**/*.hh', recursive=True) +
                     glob.glob(f'{MSGPACK_INCLUDE}/**/*.cc', recursive=True) +
                     glob.glob(f'{MSGPACK_INCLUDE}/**/*.c', recursive=True) +
                     glob.glob(f'{MSGPACK_INCLUDE}/msgpack.hpp', recursive=True)):
        fns.append(filename)
    fns = list(set(fns))
    fns.sort()
    f_fns = []
    for fn in fns:
        if 'gcc_atomic.' in fn:
            continue
        f_fns.append(fn)
    return f_fns


def alter_msgpack_includes(all_MSGPACK_files):
    """
        binder requires `#include <xx>`
        we must switch all to this
    """
    for filename in all_MSGPACK_files:
        lines = open(filename).read().split('\n')
        for i, line in enumerate(lines):
            if line.startswith('#include "'):
                if "msgpack" not in line:
                    line = line.replace('include "', 'include <msgpack/')
                else:
                    line = line.replace('include "', 'include <')
                lines[i] = line.replace('"', '>')
            elif line.startswith('#include"'):
                if "msgpack" not in line:
                    line = line.replace('include"', 'include <msgpack/')
                else:
                    line = line.replace('include"', 'include <')
                lines[i] = line.replace('"', '>')
        with open(filename, 'w') as fh:
            fh.write('\n'.join(lines))


def alter_mmtf_includes(all_MMTF_files):
    """
        binder requires `#include <xx>`
        we must switch all to this
    """
    for filename in all_MMTF_files:
        lines = open(filename).read().split('\n')
        for i, line in enumerate(lines):
            if line.startswith('#include "'):
                if 'mmtf.hpp' not in filename:
                    line = line.replace('include "', 'include <mmtf')
                else:
                    line = line.replace('include "', 'include <')
                lines[i] = line.replace('"', '>')
        with open(filename, 'w') as fh:
            fh.write('\n'.join(lines))


def make_all_includes(all_MMTF_files):
    all_includes = []
    all_include_filename = 'all_cmake_includes.hpp'
    for filename in all_MMTF_files:
        with open(filename, 'r') as fh:
            for line in fh:
                if line.startswith('#include'):
                    all_includes.append(line.strip())
    all_includes = [x for x in all_includes if 'winsock' not in x]
    all_includes = [x for x in all_includes if 'boost' not in x]
    all_includes.append("#include <mmtf.hpp>")
    all_includes = list(set(all_includes))
    # This is to ensure that the list is always the same and doesn't
    # depend on the filesystem state.  Not technically necessary, but
    # will cause inconsistent errors without it.
    all_includes.sort()
    with open(all_include_filename, 'w') as fh:
        for include in all_includes:
            fh.write(f'{include}\n')
    return all_include_filename


def make_config_file():
    s = ("+include <mmtf.hpp>\n"
         "+namespace mmtf\n"
         "+class mmtf::Transform\n"
         "+class mmtf::StructureData\n"
         "+class mmtf::BioAssembly\n"
         "+class mmtf::Entity\n"
         "+class mmtf::GroupType\n"
         "-class std::basic_ios\n"
         "+class msgpack::object\n"
         "+class msgpack::zone\n"
         "+binder mmtf::StructureData msgpack_sd_binder\n")
    with open("config.cfg", 'w') as fh:
        fh.write(s)


def make_bindings_code(all_includes_fn):
    shutil.rmtree(OUTPUT_DIR, ignore_errors=True)
    os.mkdir(OUTPUT_DIR)
    command = (f'{BINDER_EXE} --root-module {PYTHON_MODULE_NAME}'
               f' --prefix {os.getcwd()}/{OUTPUT_DIR}/'
               f' --bind="mmtf" --single-file --annotate-includes'
               ' --config config.cfg'
               f' {all_includes_fn} -- -std=c++11'
               f' -I{MMTF_INCLUDE} -I{get_python_inc()}'
               f' -I{MSGPACK_INCLUDE} -I{PYBIND_SOURCE} -DNDEBUG -v').split()
    print('BINDER COMMAND: ' + ' '.join(command))
    subprocess.call(command)


def compile_sources(sources_to_compile):
    os.chdir(OUTPUT_DIR)
    lines_to_write = []
    lines_to_write.append(f'project({PYTHON_MODULE_NAME})')

    for include_dir in [BINDER_SOURCE, MMTF_INCLUDE, os.path.join(MMTF_INCLUDE, "mmtf"),
                        MSGPACK_INCLUDE, PYBIND_SOURCE, get_python_inc()]:
        lines_to_write.append(f'include_directories({include_dir})')
    lines_to_write.append('set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)')  # -fPIC
    lines_to_write.append('add_definitions(-DNDEBUG)')

    lines_to_write.append(f'add_library({PYTHON_MODULE_NAME} SHARED')
    for source in sources_to_compile:
        lines_to_write.append(f'\t{source}')
    lines_to_write.append(')')
    lines_to_write.append(f'set_target_properties({PYTHON_MODULE_NAME} PROPERTIES PREFIX "")')
    lines_to_write.append(f'set_target_properties({PYTHON_MODULE_NAME} PROPERTIES SUFFIX ".so")')

    with open('CMakeLists.txt', 'w') as f:
        for line in lines_to_write:
            f.write(f'{line}\n')
    # Done making CMakeLists.txt
    subprocess.call('cmake -G Ninja'.split())
    subprocess.call('ninja')
    sys.path.append('.')
    if PYTHON_MODULE_NAME == 'mmtf_cpp':
        sys.stdout.flush()
        print('Testing Python lib...')
        import mmtf_cpp
        print(mmtf_cpp.__dir__())


def main():
    # setup_dir()
    all_MMTF_files = get_all_MMTF_files()
    all_MSGPACK_files = get_all_MSGPACK_files()
    alter_msgpack_includes(all_MSGPACK_files)
    # alter_mmtf_includes(all_MMTF_files)
    all_include_filename = make_all_includes(all_MMTF_files+all_MSGPACK_files)
    sources_to_compile = [f"{PYTHON_MODULE_NAME}.cpp"]
    make_config_file()
    make_bindings_code(all_include_filename)
    compile_sources(sources_to_compile)


if __name__ == '__main__':
    main()
