import re
import subprocess

from binder import __version__
from packaging.version import Version


def test_check_binder_llvm_version():
    # Check the output of the `binder -version` command to obtain the versions of Binder and LLVM
    output = subprocess.check_output(["binder", "-version"]).decode()
    pattern = r"binder ([\d\.]+)\nLLVM ([\d\.]+)"
    binder_version, llvm_version = re.match(pattern, output).groups()

    # Check the versions of Binder and LLVM
    binder_base_version = Version(__version__).base_version
    assert binder_base_version == binder_version, f"Binder version mismatch: {binder_base_version} != {binder_version}"
    assert llvm_version == "6.0.1", f"LLVM version mismatch: {llvm_version} != 6.0.1"
