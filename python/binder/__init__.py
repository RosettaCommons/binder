import os
import subprocess
import sys
from re import error as RegexError

__all__ = ["binder", "__version__"]

BINDER_BIN_DIR = os.path.join(os.path.dirname(__file__), "bin")


def binder():
    raise SystemExit(subprocess.call([os.path.join(BINDER_BIN_DIR, "binder"), *sys.argv[1:]], close_fds=False))


def _get_version():
    root = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
    if os.path.exists(os.path.join(root, ".git")) and not os.path.exists(
        os.path.join(root, ".git/shallow")
    ):
        try:
            import setuptools_scm

            return setuptools_scm.get_version(root=str(root))
        except (ImportError, RegexError, LookupError):
            pass
    try:
        from ._version import version

        return version
    except ImportError:
        return "0.0.1"


__version__: str = _get_version()
