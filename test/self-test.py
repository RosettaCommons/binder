#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# :noTabs=true: :collapseFolds=10:
#
# Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
#
# All rights reserved. Use of this source code is governed by a
# MIT license that can be found in the LICENSE file.

## @file   self-test.py
## @brief  Script to run Binder tool self-test
## @author Sergey Lyskov


import os, sys, argparse, platform, subprocess, shutil

def execute(message, command_line, return_='status', until_successes=False, terminate_on_failure=True):
    print(message);  print(command_line)
    while True:

        p = subprocess.Popen(command_line, bufsize=0, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output, errors = p.communicate()

        output = output.decode('utf-8') + errors.decode('utf-8')
        exit_code = p.returncode

        print(output)

        if exit_code and until_successes: pass  # Thats right - redability COUNT!
        else: break

        print( "Error while executing {}: {}\n".format(message, output) )
        print("Sleeping 60s... then I will retry...")
        time.sleep(60)

    if return_ == 'tuple': return(exit_code, output)

    if exit_code and terminate_on_failure:
        print("\nEncounter error while executing: " + command_line)
        if return_==True: return True
        else: print("\nEncounter error while executing: " + command_line + '\n' + output); sys.exit(1)

    if return_ == 'output': return output
    else: return exit_code


class NT:  # named tuple
    def __init__(self, **entries): self.__dict__.update(entries)
    def __repr__(self):
        r = 'NT: |'
        for i in dir(self):
            print(i)
            if not i.startswith('__') and i != '_as_dict' and not isinstance(getattr(self, i), types_module.MethodType): r += '%s --> %s, ' % (i, getattr(self, i))
        return r[:-2]+'|'

    @property
    def _as_dict(self):
        return { a: getattr(self, a) for a in dir(self) if not a.startswith('__') and a != '_as_dict' and not isinstance(getattr(self, a), types_module.MethodType)}


def get_test_files(dir_):
        return [dir_ + '/' + f for f in os.listdir(dir_) if f.startswith('T') and f.endswith('.hpp')]


def remover_absolute_paths(source):
    ''' search and replace .cpp file and replace all occurrence with absolute file path with TEST
    '''
    data = open(source).read()

    path = os.path.dirname( os.path.abspath(source) )
    with open(source, 'w') as f: f.write(data.replace(path, 'TEST'))


def get_python_environment():
    ''' calculate python include dir and lib dir from given python executable path
    '''
    python = sys.executable
    python_bin_dir = python.rpartition('/')[0]
    python_config = f'{python} {python}-config' if python.endswith('2.7') else f'{python}-config'

    info = execute('Getting python configuration info...', f'unset __PYVENV_LAUNCHER__ && cd {python_bin_dir} && PATH=.:$PATH && {python_config} --prefix --includes', return_='output').replace('\r', '').split('\n')  # Python-3 only: --abiflags
    python_prefix = info[0]
    python_include_dir = info[1].split()[0][len('-I'):]
    python_lib_dir = python_prefix + '/lib'

    return NT(python=python, python_include_dir=python_include_dir, python_lib_dir=python_lib_dir)



def run_test(test_path, build_dir, pyenv):
    if not os.path.isfile(test_path): print('Could not find test file: {} ... Exiting...'.format(test_path)); sys.exit(1)

    test = os.path.basename(test_path)
    test_name = test[:-len('.hpp')]

    source_dir = os.path.dirname(test_path)
    if not source_dir: source_dir = '.'

    source_include = build_dir + '/' + test + '.include'
    with open(source_include, 'w') as f: f.write( '#include <{}>\n'.format(test) )

    root_module = test[:-len('.hpp')].replace('.', '_')

    config = test_path[:-len('.hpp')] + '.config'
    if not os.path.isfile(config): config = ''

    cli_file_name = test_path[:-len('.hpp')] + '.cli'
    try:
        with open(cli_file_name) as f: cli = ' ' + f.read()
    except FileNotFoundError as e: cli = ''

    python = pyenv.python
    python_includes = '-I'+pyenv.python_include_dir #'-I/usr/include/python2.7'

    extras = '--annotate-functions' if Options.annotate else ''

    command_line = '{binder} --bind "" --skip-line-number --root-module {root_module} --prefix {build_dir} --single-file --annotate-includes {extras} {config}{cli} {source} -- -x c++ -std=c++11 -I {source_dir} -I {source_dir}/.. -isystem {pybind11} {python_includes}' \
        .format(binder=Options.binder, root_module=root_module, build_dir=build_dir, source_dir=source_dir, cli=cli, source=source_include,
                config='--config {}'.format(config) if config else '', pybind11=Options.pybind11, python_includes=python_includes, extras=extras)

    execute('{} Running test...'.format(test), command_line);

    command_line = 'cd {build_dir} && clang++ -O3 -shared -std=c++11 -isystem {pybind11} {python_includes} -I./.. -I./../.. -I./../../source {root_module}.cpp -o {root_module}.so -fPIC'.format(pybind11=Options.pybind11, root_module=root_module, build_dir=build_dir, python_includes=python_includes)
    execute('{} Compiling binding results...'.format(test), command_line);

    command_line = f"cd {build_dir} && {python} -c 'import {root_module}'"
    execute('{} Testing imports...'.format(test), command_line);

    ref = source_dir + '/' + test_name + '.ref.cpp'
    new = build_dir + '/' + root_module + '.cpp'
    command_line = 'diff {ref} {new}'.format(**vars())

    remover_absolute_paths(new)
    r = execute('Comparing results for test {}...'.format(test), command_line, terminate_on_failure=not (Options.accept or Options.accept_all ));

    not_binded = [l for l in open(new).read().split('\n') if 'not_binded' in l]
    if not_binded: print('{}\n"not_binded" string found in results for test {}!!!\n'.format('\n'.join(not_binded), test)); sys.exit(1)

    if r:
        if Options.accept and not Options.accept_all:
            a = input( 'Accept new results from test {test} as reference? [Y/n] '.format(test=test) )
            if a in ['', 'y', 'yes']: shutil.copyfile(new, ref)
        if Options.accept_all:
            shutil.copyfile(new, ref)



def main():
    ''' Binder tool self-test script '''

    parser = argparse.ArgumentParser()

    parser.add_argument('--binder', default='binder', help='Path to Binder tool')

    parser.add_argument('--pybind11', default='', help='Path to pybind11 source tree')

    parser.add_argument("--accept", action="store_true", help="Run tests and ask to accept new tests results as reference")
    parser.add_argument("--accept-all", action="store_true", help="Run tests and automatically accept all new tests results as reference")
    parser.add_argument("--annotate", action="store_true", help="Run Binder with extra annotation options")

    parser.add_argument('args', nargs=argparse.REMAINDER, help='Optional: list of tests to run')

    global Options
    Options = parser.parse_args()

    test_source_dir = os.path.dirname( os.path.abspath(__file__) )

    tests = Options.args or [ t for t in sorted( get_test_files(test_source_dir) ) if 'T61.smart_holder.hpp' not in t ]
    print('Found {ntests} test cases'.format( ntests=len(tests) ))

    build_dir = test_source_dir + '/build'
    if os.path.isdir(build_dir): print('Removing old test dir {0} ...'.format(build_dir));  shutil.rmtree(build_dir)  # remove old dir if any
    os.makedirs(build_dir)
    #if not os.path.isdir(build_dir): os.makedirs(build_dir)

    pyenv = get_python_environment()
    for t in tests: run_test(t, build_dir, pyenv)

    print('Done!')


if __name__ == "__main__":
    main()
