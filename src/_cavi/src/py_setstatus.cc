#include <Python.h> // Needs to be included first

#include "../include/py_methods.hh"

#define MOCK_STATUS (cavimodule::_testing::mockStatus)

namespace cavimodule::status {

PyObject*
setArm(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;

  if (useMockHardware()) {
    MOCK_STATUS->ARM = newVal;
  } else {
    // TODO: do something to change status on hardware
    Py_RETURN_FALSE;
  }
  Py_RETURN_TRUE;
}

PyObject*
setAbort(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;

  if (useMockHardware()) {
    MOCK_STATUS->ABORT = newVal;
  } else {
    // TODO: do something to change status on hardware
    Py_RETURN_FALSE;
  }
  Py_RETURN_TRUE;
}

PyObject*
setQDM(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;

  if (useMockHardware()) {
    MOCK_STATUS->QDM = newVal;
  } else {
    // TODO: do something to change status on hardware
    Py_RETURN_FALSE;
  }
  Py_RETURN_TRUE;
}

PyObject*
setLaunch(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;

  if (useMockHardware()) {
    MOCK_STATUS->LAUNCH = newVal;
  } else {
    // TODO: do something to change status on hardware
    Py_RETURN_FALSE;
  }
  Py_RETURN_TRUE;
}

PyObject*
setStabilize(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;

  if (useMockHardware()) {
    MOCK_STATUS->STABILIZE = newVal;
  } else {
    // TODO: do something to change status on hardware
    Py_RETURN_FALSE;
  }
  Py_RETURN_TRUE;
}

} // cavimodule::status