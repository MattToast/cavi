from pathlib import Path
from typing import List

from setuptools import Extension, setup


def find_cpp(root_dir: str, strict: bool = False) -> List[str]:
    """Find all C++ files in dir relative to project root"""
    cpp_suffixs = [".cc", ".cpp"]
    if not strict:
        cpp_suffixs.append(".c")
    return [
        str(path)
        for path in (Path(__file__).parent.resolve() / root_dir).rglob("*")
        if path.is_file() and path.suffix in cpp_suffixs
    ]


_cavi = Extension(
    name="cavi._cavi",
    language="c++",
    sources=find_cpp("src/_cavi"),
    optional=False,
    define_macros=[("CAVI_TEST_BUILD", None)],
)

if __name__ == "__main__":
    setup(ext_modules=[_cavi])
