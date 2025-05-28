import re
import subprocess


def test_check_binder_llvm_version():
    # Check the output of the `binder -version` command to obtain the versions of Binder and LLVM
    output = subprocess.check_output(["binder", "-version"]).decode()
    pattern = r"binder ([\d\.]+)\nLLVM ([\d\.]+)"
    binder_version, llvm_version = re.match(pattern, output).groups()

    # Check the versions of LLVM
    assert llvm_version == "6.0.1", f"LLVM version mismatch: {llvm_version} != 6.0.1"
