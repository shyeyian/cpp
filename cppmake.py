from cppmakelib import *

self.require_packages |= {
    Package("beman"),
    Package("eigen"),
    Package("clblast"),
    Package("compiler"),
    Package("eigen"),
    Package("icu"),
    Package("jpeg"),
}

self.define_macros |= {
    "abstract"   : ":",
    "extends"    : ":",
    "in"         : ":",
    "reflexpr(x)": "(^^x)",
    "self"       : "(*this)",
}

def make():
    Source("main").compile()

def pybind():
    Source("pybind").compile()