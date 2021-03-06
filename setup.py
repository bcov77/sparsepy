from setuptools import setup, Extension

import os
import sys
import setuptools
import glob

__version__ = '0.2.0'

extra_compile_args_dict = {
    'linux' : ['-w', '-ftemplate-backtrace-limit=0', '-std=c++14'],
    'linux2' : ['-w', '-ftemplate-backtrace-limit=0', '-std=c++14'],
    'darwin' : ['-w', '-ftemplate-backtrace-limit=0', '-std=c++14', '-stdlib=libc++'],
}

ext_modules = [
  Extension(
    "_sparsepy",
    glob.glob('src/*.cpp'),
    include_dirs = ['lib/parallel-hashmap', 'lib/pybind11/include', 'lib/cereal/include'],
    language = 'c++',
    extra_compile_args = extra_compile_args_dict[sys.platform],
    extra_link_args = ['-lz'],
    define_macros = [('DOCTEST_CONFIG_DISABLE', None)]
  )
]

setup(
    name = 'sparsepy',
    version = __version__,
    author = 'Adam Moyer',
    author_email = 'atom.moyer@gmail.com',
    url = None,
    description = 'A Fast and Memory Efficient Hash Map for Python',
    packages = ['sparsepy'],
    package_dir={'sparsepy': 'sparsepy'},
    package_data={},
    ext_modules = ext_modules,
    install_requires = ['pytest', 'pytest-timeout', 'pytest-memprof', 'pybind11'],
    include_package_data=True,
    zip_safe = False,
)
