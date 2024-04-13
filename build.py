#!/usr/bin/env python
# -*- coding: utf-8 -*-
# :noTabs=true:

# (c) Copyright Rosetta Commons Member Institutions.
# (c) This file is part of the Rosetta software suite and is made available under license.
# (c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
# (c) For more information, see http://www.rosettacommons.org. Questions about this can be
# (c) addressed to University of Washington CoMotion, email: license@uw.edu.

## @file   build.py
## @brief  Script to build Binder
## @author Sergey Lyskov

from __future__ import print_function

import os, sys, argparse, platform, subprocess, imp, shutil, distutils.dir_util, json

from collections import OrderedDict

if sys.platform.startswith("linux"): Platform = "linux" # can be linux1, linux2, etc
elif sys.platform == "darwin" : Platform = "macos"
elif sys.platform == "cygwin" : Platform = "cygwin"
elif sys.platform == "win32" : Platform = "windows"
else: Platform = "unknown"
PlatformBits = platform.architecture()[0][:2]

_machine_name_ = os.uname()[1]

_python_version_ = '{}.{}'.format(sys.version_info.major, sys.version_info.minor)  # should be formatted: 2.7, 3.5, 3.6, ...

_pybind11_version_ = 'aa304c9c7d725ffb9d10af08a3b34cb372307020'


def execute(message, command_line, return_='status', until_successes=False, terminate_on_failure=True, silent=False, silence_output=False):
    if not silent: print(message);  print(command_line); sys.stdout.flush();
    while True:

        p = subprocess.Popen(command_line, bufsize=0, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output, errors = p.communicate()

        output = output + errors

        output = output.decode(encoding="utf-8", errors="replace")

        exit_code = p.returncode

        if exit_code  or  not (silent or silence_output): print(output); sys.stdout.flush();

        if exit_code and until_successes: pass  # Thats right - redability COUNT!
        else: break

        print( "Error while executing {}: {}\n".format(message, output) )
        print("Sleeping 60s... then I will retry...")
        sys.stdout.flush();
        time.sleep(60)

    if return_ == 'tuple': return(exit_code, output)

    if exit_code and terminate_on_failure:
        print("\nEncounter error while executing: " + command_line)
        if return_==True: return True
        else: print("\nEncounter error while executing: " + command_line + '\n' + output); sys.exit(1)

    if return_ == 'output': return output
    else: return False


def update_source_file(file_name, data):
    ''' write data to a file but only if file does not exist or it content different from data '''
    if( not os.path.isfile(file_name)  or  open(file_name).read() != data ):
        print('Writing '+ file_name)
        with open(file_name, 'w') as f: f.write(data)


def get_compiler_family():
    ''' Try to guess compiler family using Options.compiler '''
    if 'clang' in Options.compiler: return 'clang'
    if 'gcc'   in Options.compiler: return 'gcc'
    if 'cl'    in Options.compiler: return 'cl'
    return 'unknown'


def get_cmake_compiler_options(compiler):
    ''' Get cmake compiler flags from Options.compiler '''
    if Platform == "linux" and compiler == 'clang': return ' -DCMAKE_C_COMPILER=`which clang` -DCMAKE_CXX_COMPILER=`which clang++`'
    if Platform == "linux" and compiler == 'gcc': return ' -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_COMPILER=`which g++`'

    return ''


def install_llvm_tool(name, source_location, prefix_root, debug, compiler, jobs, gcc_install_prefix, clean=True):
    ''' Install and update (if needed) custom LLVM tool at given prefix (from config).
        Return absolute path to executable on success and terminate with error on failure
    '''
    if not os.path.isdir(prefix_root): os.makedirs(prefix_root)

    # llvm_version='9.0.0'  # v8 and v9 can not be build with Clang-3.4, we if need upgrade to v > 7 then we should probably dynamicly change LLVM version based on complier versions
    # llvm_version='7.1.0'  # compiling v7.* on clang-3.4 lead to lockup while compiling tools/clang/lib/Sema/SemaChecking.cpp
    llvm_version, headers = ('13.0.0', 'tools/clang/lib/Headers/clang-resource-headers clang') if Platform == 'macos' and platform.machine() == 'arm64' else ('6.0.1', 'tools/clang/lib/Headers/clang-headers')
    #llvm_version, headers = ('13.0.0', 'tools/clang/lib/Headers/clang-resource-headers clang') if Platform == 'macos' else ('6.0.1', 'tools/clang/lib/Headers/clang-headers')
    #llvm_version, headers = ('13.0.0', 'tools/clang/lib/Headers/clang-resource-headers clang')
    #if Platform == 'macos': headers += ' clang'

    prefix = prefix_root + '/llvm-' + llvm_version

    build_dir = prefix+'/llvm-' + llvm_version + '.' + platform.platform() + ('.debug' if debug else '.release') # + '.' + _machine_name_

    res, output = execute('Getting binder HEAD commit SHA1...', 'cd {} && git rev-parse HEAD'.format(source_location), return_='tuple', silent=True)
    if res: binder_head = 'unknown'
    else: binder_head = output.split('\n')[0]

    signature = dict(config = 'LLVM install by install_llvm_tool version: 1.5.1, HTTPS', binder = binder_head, llvm_version=llvm_version, compiler=compiler, gcc_install_prefix=gcc_install_prefix)
    signature_file_name = build_dir + '/.signature.json'

    disk_signature = dict(config = 'unknown', binder = 'unknown')
    if os.path.isfile(signature_file_name):
        with open(signature_file_name) as f: disk_signature = json.load(f)

    if signature == disk_signature:
        print('LLVM:{} + Binder install is detected at {}, skipping LLVM installation and Binder building procedures...\n'.format(llvm_version, build_dir))

    else:
        print('LLVM build detected, but config/binder version has changed, perfoming a clean rebuild...')
        if os.path.isdir(build_dir): shutil.rmtree(build_dir)

        clang_path = "{prefix}/tools/clang".format(**locals())

        llvm_url, clang_url = {
            '6.0.1'  : ('https://releases.llvm.org/6.0.1/llvm-6.0.1.src.tar.xz', 'https://releases.llvm.org/6.0.1/cfe-6.0.1.src.tar.xz'),
            '13.0.0' : ('https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.0/llvm-13.0.0.src.tar.xz', 'https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.0/clang-13.0.0.src.tar.xz'),
        }[llvm_version]

        if not os.path.isfile(prefix + '/CMakeLists.txt'):
            #execute('Download LLVM source...', 'cd {prefix_root} && curl https://releases.llvm.org/{llvm_version}/llvm-{llvm_version}.src.tar.xz | tar -Jxom && mv llvm-{llvm_version}.src {prefix}'.format(**locals()) )
            execute('Download LLVM source...', 'cd {prefix_root} && mkdir llvm-{llvm_version}.src && curl -LJ {llvm_url} | tar --strip-components=1 -Jxom -C llvm-{llvm_version}.src && mv llvm-{llvm_version}.src {prefix}'.format(**locals()) )

        if not os.path.isdir(clang_path):
            #execute('Download Clang source...', 'cd {prefix_root} && curl https://releases.llvm.org/{llvm_version}/cfe-{llvm_version}.src.tar.xz | tar -Jxom && mv cfe-{llvm_version}.src {clang_path}'.format(**locals()) )
            execute('Download Clang source...', 'cd {prefix_root} && mkdir clang-{llvm_version}.src && curl -LJ {clang_url} | tar --strip-components=1 -Jxom -C clang-{llvm_version}.src && mv clang-{llvm_version}.src {clang_path}'.format(**locals()) )

        if not os.path.isdir(prefix+'/tools/clang/tools/extra'): os.makedirs(prefix+'/tools/clang/tools/extra')


        # if signature['config'] != disk_signature['config']:
        #     print( 'LLVM build detected, but config version mismatched: was:"{}" current:"{}", perfoming a clean rebuild...'.format(disk_signature['config'], signature['config']) )
        #     if os.path.isdir(build_dir): shutil.rmtree(build_dir)
        # else: print( 'Binder build detected, but source version mismatched: was:{} current:{}, rebuilding...'.format(disk_signature['binder'], signature['binder']) )
        '''
        git_checkout = '( git checkout {0} && git reset --hard {0} )'.format(release) if clean else 'git checkout {}'.format(release)

        #if os.path.isdir(prefix) and  (not os.path.isdir(prefix+'/.git')): shutil.rmtree(prefix)  # removing old style checkoiut

        if not os.path.isdir(prefix):
            print( 'No LLVM:{} + Binder install is detected! Going to check out LLVM and install Binder. This procedure will require ~1Gb of free disk space and will only be needed to be done once...\n'.format(release) )
            os.makedirs(prefix)

        if not os.path.isdir(prefix+'/.git'): execute('Clonning llvm...', 'cd {} && git clone git@github.com:llvm-mirror/llvm.git .'.format(prefix) )
        execute('Checking out LLVM revision: {}...'.format(release), 'cd {prefix} && ( {git_checkout} || ( git fetch && {git_checkout} ) )'.format(prefix=prefix, git_checkout=git_checkout) )

        if not os.path.isdir(prefix+'/tools/clang'): execute('Clonning clang...', 'cd {}/tools && git clone git@github.com:llvm-mirror/clang.git clang'.format(prefix) )
        execute('Checking out Clang revision: {}...'.format(release), 'cd {prefix}/tools/clang && ( {git_checkout} || ( git fetch && {git_checkout} ) )'.format(prefix=prefix, git_checkout=git_checkout) )

        if not os.path.isdir(prefix+'/tools/clang/tools/extra'): os.makedirs(prefix+'/tools/clang/tools/extra')
        '''

        tool_link_path = '{prefix}/tools/clang/tools/extra/{name}'.format(prefix=prefix, name=name)
        if os.path.islink(tool_link_path): os.unlink(tool_link_path)
        os.symlink(source_location, tool_link_path)

        cmake_lists = prefix + '/tools/clang/tools/extra/CMakeLists.txt'
        tool_build_line = 'add_subdirectory({})'.format(name)

        if not os.path.isfile(cmake_lists):
            with open(cmake_lists, 'w') as f: f.write(tool_build_line + '\n')

        config = '-DCMAKE_BUILD_TYPE={build_type}'.format(build_type='Debug' if debug else 'Release')
        config += get_cmake_compiler_options(compiler)

        if not os.path.isdir(build_dir): os.makedirs(build_dir)
        execute(
            'Building tool: {}...'.format(name), # -DLLVM_TEMPORARILY_ALLOW_OLD_TOOLCHAIN=1
            'cd {build_dir} && cmake -G Ninja {config} -DLLVM_ENABLE_EH=1 -DLLVM_ENABLE_RTTI=ON {gcc_install_prefix} .. && ninja binder {headers} {jobs}'.format( # was 'binder clang', we need to build Clang so lib/clang/<version>/include is also built
                build_dir=build_dir, config=config,
                jobs=f'-j{jobs}' if jobs else '',
                gcc_install_prefix='-DGCC_INSTALL_PREFIX='+gcc_install_prefix if gcc_install_prefix else '',
                headers=headers,
            ),
            silence_output=True)
        print()
        # build_dir = prefix+'/build-ninja-' + release
        # if not os.path.isdir(build_dir): os.makedirs(build_dir)
        # execute('Building tool: {}...'.format(name), 'cd {build_dir} && cmake -DCMAKE_BUILD_TYPE={build_type} .. -G Ninja && ninja -j{jobs}'.format(build_dir=build_dir, jobs=Options.jobs, build_type='Debug' if debug else 'Release')) )

        with open(signature_file_name, 'w') as f: json.dump(signature, f, sort_keys=True, indent=2)

    executable = build_dir + '/bin/' + name
    if not os.path.isfile(executable): print("\nEncounter error while running install_llvm_tool: Build is complete but executable {} is not there!!!".format(executable) ); sys.exit(1)

    return executable


def install_pybind11(prefix, clean=True):
    ''' Download and install PyBind11 library at given prefix. Install version specified by _pybind11_version_ sha1
    '''
    #git_checkout = '( git fetch && git checkout {0} && git reset --hard {0} && git pull )'.format(_pybind11_version_) if clean else 'git checkout {}'.format(_pybind11_version_)
    git_checkout = '( git fetch && git reset --hard {0} )'.format(_pybind11_version_) if clean else 'git checkout {}'.format(_pybind11_version_)

    if not os.path.isdir(prefix): os.makedirs(prefix)
    package_dir = prefix + '/pybind11'

    if not os.path.isdir(package_dir): execute('Clonning pybind11...', 'cd {} && git clone https://github.com/RosettaCommons/pybind11.git'.format(prefix) )
    execute('Checking out PyBind11 revision: {}...'.format(_pybind11_version_), 'cd {package_dir} && ( {git_checkout} )'.format(package_dir=package_dir, git_checkout=git_checkout), silent=True)
    print()

    include = package_dir + '/include/pybind11/pybind11.h'
    if not os.path.isfile(include): print("\nEncounter error while running install_pybind11: Install is complete but include file {} is not there!!!".format(include) ); sys.exit(1)

    return package_dir + '/include'


def main(args):
    ''' Binding demo build/test script '''

    parser = argparse.ArgumentParser()

    parser.add_argument('-j', '--jobs', default=1, const=0, nargs="?", type=int, help="Number of processors to use on when building, use '-j' with no arguments to launch job-per-core. (default: 1) ")
    parser.add_argument("--type", default='Release', choices=['Release', 'Debug', 'MinSizeRel', 'RelWithDebInfo'], help="Specify build type")
    parser.add_argument('--compiler', default='clang', help='Compiler to use, defualt is clang')
    parser.add_argument('--binder', default='', help='Path to Binder tool. If none is given then download, build and install binder into build/ directory. Use "--binder-debug" to control which mode of binder (debug/release) is used.')
    parser.add_argument("--binder-debug", action="store_true", help="Run binder tool in debug mode (only relevant if no '--binder' option was specified)")
    parser.add_argument('--pybind11', default='', help='Path to pybind11 source tree')
    parser.add_argument('--annotate-includes', action="store_true", help='Annotate includes in generated source files')
    parser.add_argument('--trace', action="store_true", help='Binder will add trace output to to generated source files')

    global Options
    Options = parser.parse_args()

    source_path = os.path.abspath('.')

    if not Options.binder: Options.binder = install_llvm_tool('binder', source_path+'/source', source_path + '/build', debug=Options.binder_debug, compiler=Options.compiler, jobs=Options.jobs, gcc_install_prefix=None)

    if not Options.pybind11: Options.pybind11 = install_pybind11(source_path + '/build')

    print( 'Binder binaries now ready at: {}\nPybind11 clone is ready at: {}'.format(Options.binder, Options.pybind11) )


if __name__ == "__main__":
    main(sys.argv)
