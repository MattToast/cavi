#include <Python.h> // Needs to be included first

#include "../include/py_methods.hh"
#include <cstdint>

namespace cavimodule {

PyObject*
getArm(PyObject* self)
{
  return PyLong_FromSize_t((uint32_t)1);
}

PyObject*
getAbort(PyObject* self)
{
  return PyLong_FromSize_t((uint32_t)1);
}

PyObject*
getQDM(PyObject* self)
{
  return PyLong_FromSize_t((uint32_t)1);
}

PyObject*
getLaunch(PyObject* self)
{
  return PyLong_FromSize_t((uint32_t)1);
}

PyObject*
getStabilize(PyObject* self)
{
  return PyLong_FromSize_t((uint32_t)1);
}

} // cavimodule