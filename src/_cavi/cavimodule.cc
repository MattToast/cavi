#include <Python.h> // Needs to be included first

#include "include/py_methods.hh"

static struct PyModuleDef dataModule = {
  PyModuleDef_HEAD_INIT,
  "_cavi.data",
  NULL,
  -1,
  cavimodule::data::methods
};

static struct PyModuleDef statusModule = {
  PyModuleDef_HEAD_INIT,
  "_cavi.status",
  NULL,
  -1,
  cavimodule::status::methods
};

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
  PyObject* moduleObj = PyModule_Create(&module);
  PyObject* dataObj = PyModule_Create(&dataModule);
  PyObject* statusObj = PyModule_Create(&statusModule);

  // TODO: Needs better error handling
  if (moduleObj == NULL || dataObj == NULL || statusObj == NULL)
    return NULL;

  if (PyModule_AddObjectRef(moduleObj, "data", dataObj) < 0 ||
      PyModule_AddObjectRef(moduleObj, "status", statusObj) < 0) {
    return NULL;
  }

  return moduleObj;
}
