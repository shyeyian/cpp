from cppmakelib import *

self.depend_packages = []

def build():
    for file in iterate_dir("git/Eigen"):
        Header(file).install()
    for file in iterate_dir("git/unsupported/Eigen"):
        Header(file).install()
    Module("module/eigen.cpp").precompile().install()