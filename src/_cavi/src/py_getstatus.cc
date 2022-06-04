#include <Python.h> // Needs to be included first

#include "../include/py_methods.hh"

#define MOCK_STATUS (cavimodule::_testing::mockStatus)

namespace cavimodule::status {

PyObject*
getArm(PyObject* self)
{
  return PyLong_FromSize_t(MOCK_STATUS->ARM);
}

PyObject*
getAbort(PyObject* self)
{
  return PyLong_FromSize_t(MOCK_STATUS->ABORT);
}

PyObject*
getQDM(PyObject* self)
{
  return PyLong_FromSize_t(MOCK_STATUS->QDM);
}

PyObject*
getLaunch(PyObject* self)
{
  return PyLong_FromSize_t(MOCK_STATUS->LAUNCH);
}

PyObject*
getStabilize(PyObject* self)
{
  return PyLong_FromSize_t(MOCK_STATUS->STABILIZE);
}

} // cavimodule::status