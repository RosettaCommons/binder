import os
import subprocess
import sys


def binder():
    BINDER_BIN_DIR = os.path.join(os.path.dirname(__file__), "bin")
    raise SystemExit(subprocess.call([os.path.join(BINDER_BIN_DIR, "binder"), *sys.argv[1:]], close_fds=False))
