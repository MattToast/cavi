#include <Python.h> // Needs to be included first

#include "../include/py_methods.hh"

#define MOCK_STATUS (cavimodule::_testing::mockStatus)

namespace cavimodule::status {

PyObject*
getArm(PyObject* self)
{
  if (useMockHardware()) {
    return PyLong_FromSize_t(MOCK_STATUS->ARM);
  }
  // TODO: Add something to read status from hardware
  return PyLong_FromDouble(-1);
}

PyObject*
getAbort(PyObject* self)
{
  if (useMockHardware()) {
    return PyLong_FromSize_t(MOCK_STATUS->ABORT);
  }
  // TODO: Add something to read status from hardware
  return PyLong_FromDouble(-1);
}

PyObject*
getQDM(PyObject* self)
{
  if (useMockHardware()) {
    return PyLong_FromSize_t(MOCK_STATUS->QDM);
  }
  // TODO: Add something to read status from hardware
  return PyLong_FromDouble(-1);
}

PyObject*
getLaunch(PyObject* self)
{
  if (useMockHardware()) {
    return PyLong_FromSize_t(MOCK_STATUS->LAUNCH);
  }
  // TODO: Add something to read status from hardware
  return PyLong_FromDouble(-1);
}

PyObject*
getStabilize(PyObject* self)
{
  if (useMockHardware()) {
    return PyLong_FromSize_t(MOCK_STATUS->STABILIZE);
  }
  // TODO: Add something to read status from hardware
  return PyLong_FromDouble(-1);
}

} // cavimodule::status