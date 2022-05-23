from setuptools import setup, Extension


_cavi = Extension(
    name="_cavi",
    language="c++",
    sources=[
        "src/_cavi/cavimodule.cc",
        "src/_cavi/src/py_getdata.cc",
        "src/_cavi/src/py_getstatus.cc",
        "src/_cavi/src/py_setstatus.cc",
    ],
    optional=False,
)

if __name__ == "__main__":
    setup(ext_modules=[_cavi])
