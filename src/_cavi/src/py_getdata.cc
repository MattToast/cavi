#include <Python.h> // needs to be included first

#include "../include/py_methods.hh"

namespace cavimodule::data {

PyObject*
getAltitude(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getLatitude(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getLongitude(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getTemperature(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getGyroX(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getGyroY(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getGyroZ(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getAccelerationX(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getAccelerationY(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

PyObject*
getAccelerationZ(PyObject* self)
{
  return PyFloat_FromDouble(99.99L);
}

} // cavimodule
