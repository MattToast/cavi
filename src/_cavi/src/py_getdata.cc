#include <Python.h>

#include "../include/py_methods.hh"

namespace cavimodule {

PyObject*
getAltitude(PyObject* self)
{
  return PyUnicode_FromString("Hello Wrold From C");
}

} // cavimodule
