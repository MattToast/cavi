#include <Python.h> // Needs to be included first

#include "../include/py_methods.hh"

namespace cavimodule::status {

PyObject*
getArm(PyObject* self)
{
  return PyLong_FromSize_t(mockStatus.ARM);
}

PyObject*
getAbort(PyObject* self)
{
  return PyLong_FromSize_t(mockStatus.ABORT);
}

PyObject*
getQDM(PyObject* self)
{
  return PyLong_FromSize_t(mockStatus.QDM);
}

PyObject*
getLaunch(PyObject* self)
{
  return PyLong_FromSize_t(mockStatus.LAUNCH);
}

PyObject*
getStabilize(PyObject* self)
{
  return PyLong_FromSize_t(mockStatus.STABILIZE);
}

} // cavimodule