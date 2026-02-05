from cppmakelib import *

self.depend_packages |= {
    Package("package/beman"),
    Package("package/eigen"),
    Package("package/clblast"),
    Package("package/compiler"),
    Package("package/eigen"),
    Package("package/icu"),
    Package("package/jpeg"),
}

self.define_macros |= {
    "abstract"   : ":",
    "extends"    : ":",
    "in"         : ":",
    "reflexpr(x)": "(^^x)",
    "self"       : "(*this)",
}

def build():
    Module("module/cppcore.cpp").precompile()

def install():
    Header("header/my_header.hpp").install()

def make():
    Source("source/main.cpp").compile().link()

def test():
    for file in iterate_dir(Path("source/test"))
        Source(file).compile().link().test()

def pybind():
    dynamic_library = Source("source/pybind.cpp").compile().share()
    copy_file(dynamic_library, 'cpp.libpython.3.14.so')