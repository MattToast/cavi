#include <Python.h> // needs to be included first
#include <iostream>

#include "../include/py_methods.hh"

namespace cavimodule::data {

PyObject*
getAltitude(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getLatitude(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getLongitude(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getTemperature(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getGyroX(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getGyroY(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getGyroZ(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getAccelerationX(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getAccelerationY(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

PyObject*
getAccelerationZ(PyObject* self)
{
#ifdef CAVI_TEST_BUILD
  return PyFloat_FromDouble(99.99L);
#else
  // TODO: Add something to read from sensor data
  return PyFloat_FromDouble(0.0L);
#endif
}

} // cavimodule::data
