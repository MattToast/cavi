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

  MOCK_STATUS->ARM = newVal;
  Py_RETURN_TRUE;
}

PyObject*
setAbort(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;
  MOCK_STATUS->ABORT = newVal;
  Py_RETURN_TRUE;
}

PyObject*
setQDM(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;
  MOCK_STATUS->QDM = newVal;
  Py_RETURN_TRUE;
}

PyObject*
setLaunch(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;
  MOCK_STATUS->LAUNCH = newVal;
  Py_RETURN_TRUE;
}

PyObject*
setStabilize(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;
  MOCK_STATUS->STABILIZE = newVal;
  Py_RETURN_TRUE;
}

} // cavimodule::status