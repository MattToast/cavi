#include <Python.h> // needs to be included first
#include <iostream>

#include "../include/py_methods.hh"

namespace cavimodule::data {

PyObject*
getAltitude(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getLatitude(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getLongitude(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getTemperature(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getGyroX(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getGyroY(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getGyroZ(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getAccelerationX(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getAccelerationY(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

PyObject*
getAccelerationZ(PyObject* self)
{
  if (useMockHardware()) {
    return PyFloat_FromDouble(99.99L);
  }
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
}

} // cavimodule::data
