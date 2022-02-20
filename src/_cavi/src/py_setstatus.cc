#include <Python.h> // Needs to be included first

#include "../include/py_methods.hh"

namespace cavimodule {

PyObject*
setArm(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;

  mockStatus.ARM = newVal;
  Py_RETURN_TRUE;
}

PyObject*
setAbort(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;
  mockStatus.ABORT = newVal;
  Py_RETURN_TRUE;
}

PyObject*
setQDM(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;
  mockStatus.QDM = newVal;
  Py_RETURN_TRUE;
}

PyObject*
setLaunch(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;
  mockStatus.LAUNCH = newVal;
  Py_RETURN_TRUE;
}

PyObject*
setStabilize(PyObject* self, PyObject* args)
{
  uint32_t newVal{};
  if (!PyArg_ParseTuple(args, "i", &newVal))
    return NULL;
  mockStatus.STABILIZE = newVal;
  Py_RETURN_TRUE;
}

} // cavimodule