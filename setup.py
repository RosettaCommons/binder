from setuptools import setup
from wheel.bdist_wheel import bdist_wheel as _bdist_wheel


class bdist_wheel(_bdist_wheel):
    def finalize_options(self):
        super().finalize_options()
        self.root_is_pure = False
        self.python_tag = "py3"
        self.py_limited_api = "cp38"


setup(cmdclass={"bdist_wheel": bdist_wheel})
