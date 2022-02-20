#include <Python.h> // Needs to be included first

#include "include/py_methods.hh"

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT,
  "_cavi",
  NULL,
  -1,
  cavimodule::methods
};

PyMODINIT_FUNC
PyInit__cavi()
{
  return PyModule_Create(&module);
}
