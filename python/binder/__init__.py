import os
import sys
import subprocess

try:
    from ._version import version as _default_version
except ImportError:
    _default_version = "0.0.1"

__all__ = ["binder", "__version__"]

BINDER_BIN_DIR = os.path.join(os.path.dirname(__file__), "bin")


def binder():
    raise SystemExit(subprocess.call([os.path.join(BINDER_BIN_DIR, "binder")] + sys.argv[1:], close_fds=False))


def _get_version():
    """Return the version string used for __version__."""
    # Only shell out to a git subprocess if really needed, and not on a
    # shallow clone, such as those used by CI, as the latter would trigger
    # a warning from setuptools_scm.
    root = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
    if os.path.exists(os.path.join(root, ".git")) and not os.path.exists(os.path.join(root, ".git/shallow")):
        try:
            import setuptools_scm

            return setuptools_scm.get_version(
                root=root,
                version_scheme="no-guess-dev",
                fallback_version=_default_version,
            )
        except (ImportError, LookupError):
            return _default_version
    else:  # Get the version from the _version.py setuptools_scm file.
        return _default_version


__version__ = _get_version()
