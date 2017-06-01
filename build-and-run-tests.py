#!/usr/bin/env python
# -*- coding: utf-8 -*-
# :noTabs=true:

# (c) Copyright Rosetta Commons Member Institutions.
# (c) This file is part of the Rosetta software suite and is made available under license.
# (c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
# (c) For more information, see http://www.rosettacommons.org. Questions about this can be
# (c) addressed to University of Washington CoMotion, email: license@uw.edu.

## @file   build-and-run-tests.py
## @brief  Script to build Binder and run Binder self-test's
## @author Sergey Lyskov

from __future__ import print_function

import os, sys, argparse

import build

def run_binder_self_tests(source_path):
    build.execute('Running Binder self-test script...', 'cd {source_path}/test && ./self-test.py --binder {binder} --pybind11 {pybind11}'.format(binder=Options.binder, pybind11=Options.pybind11, source_path=source_path) )


def main(args):
    ''' Binding demo build/test script '''

    parser = argparse.ArgumentParser()

    parser.add_argument('-j', '--jobs', default=1, type=int, help="Number of processors to use on when building. (default: use all avaliable memory)")
    parser.add_argument("--type", default='Release', choices=['Release', 'Debug', 'MinSizeRel', 'RelWithDebInfo'], help="Specify build type")
    parser.add_argument('--compiler', default='clang', help='Compiler to use, defualt is clang')
    parser.add_argument('--binder', default='', help='Path to Binder tool. If none is given then download, build and install binder into main/source/build. Use "--binder-debug" to control which mode of binder (debug/release) is used.')
    parser.add_argument("--binder-debug", action="store_true", help="Run binder tool in debug mode (only relevant if no '--binder' option was specified)")
    parser.add_argument('--pybind11', default='', help='Path to pybind11 source tree')
    parser.add_argument('--annotate-includes', action="store_true", help='Annotate includes in generated source files')
    parser.add_argument('--trace', action="store_true", help='Binder will add trace output to to generated source files')

    global Options
    Options = parser.parse_args()

    source_path = os.path.abspath('.')

    if not Options.binder: Options.binder = build.install_llvm_tool('binder', source_path+'/source', source_path + '/build', Options.binder_debug, jobs=Options.jobs)

    if not Options.pybind11: Options.pybind11 = build.install_pybind11(source_path + '/build')

    run_binder_self_tests(source_path)


if __name__ == "__main__":
    main(sys.argv)
