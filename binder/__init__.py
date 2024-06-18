import os
import sys
import subprocess


__all__ = ["binder"]


BINDER_BIN_DIR = os.path.join(os.path.dirname(__file__), "bin")


def binder():
    raise SystemExit(subprocess.call([os.path.join(BINDER_BIN_DIR, "binder")] + sys.argv[1:], close_fds=False))
