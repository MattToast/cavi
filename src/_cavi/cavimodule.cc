#include <Python.h> // Needs to be included first

#include "include/py_methods.hh"

static struct PyModuleDef dataModule = {
  PyModuleDef_HEAD_INIT,
  "cavi._cavi.data",
  NULL,
  -1,
  cavimodule::data::methods
};

static struct PyModuleDef statusModule = {
  PyModuleDef_HEAD_INIT,
  "cavi._cavi.status",
  NULL,
  -1,
  cavimodule::status::methods
};

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT,
  "cavi._cavi",
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

  if (moduleObj == NULL || dataObj == NULL || statusObj == NULL) {
    // Should never be executed but clean up just in case
    Py_XDECREF(moduleObj);
    Py_XDECREF(dataObj);
    Py_XDECREF(statusObj);
    return NULL;
  }

  if (PyModule_AddObjectRef(moduleObj, "data", dataObj) < 0 ||
      PyModule_AddObjectRef(moduleObj, "status", statusObj) < 0) {
    // Once again should not be executed but good to clean up
    Py_DECREF(dataObj);
    Py_DECREF(statusObj);
    return NULL;
  }

  // Decref count to unsused modules
  Py_DECREF(dataObj);
  Py_DECREF(statusObj);

  // return `_cavi`
  return moduleObj;
}
