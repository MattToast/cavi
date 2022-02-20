
#ifndef CAVI_PY_METHODS_HH
#define CAVI_PY_METHODS_HH

#include <Python.h> // Nedds to be included first

namespace cavimodule {

// Status Getters
PyObject* getArm(PyObject* self);
PyObject* getAbort(PyObject* self);
PyObject* getQDM(PyObject* self);
PyObject* getLaunch(PyObject* self);
PyObject* getStabilize(PyObject* self);

// Data Getters
PyObject* getAltitude(PyObject* self);
PyObject* getLatitude(PyObject* self);
PyObject* getLongitude(PyObject* self);
PyObject* getTemperature(PyObject* self);
PyObject* getGyroX(PyObject* self);
PyObject* getGyroY(PyObject* self);
PyObject* getGyroZ(PyObject* self);
PyObject* getAccelerationX(PyObject* self);
PyObject* getAccelerationY(PyObject* self);
PyObject* getAccelerationZ(PyObject* self);

// Methods struct
static struct PyMethodDef methods[] = {
  // Status Getters
  { "get_arm", (PyCFunction)getArm, METH_NOARGS, "Return the current ARM status" },
  { "get_abort", (PyCFunction)getAbort, METH_NOARGS, "Return the current abort status" },
  { "get_qdm", (PyCFunction)getQDM, METH_NOARGS, "Returns the current qdm status" },
  { "get_launch", (PyCFunction)getLaunch, METH_NOARGS, "Returns the current launch status" },
  { "get_stabilize", (PyCFunction)getStabilize, METH_NOARGS, "Returns the current stabiliation status" },

  // Data Getters
  { "get_altitude", (PyCFunction)getAltitude, METH_NOARGS, "Return the current measured altitude" },
  { "get_latitude", (PyCFunction)getLatitude, METH_NOARGS, "Return the current measured latitude" },
  { "get_longitude", (PyCFunction)getLongitude, METH_NOARGS, "Return the current measured longitude" },
  { "get_temperature", (PyCFunction)getTemperature, METH_NOARGS, "Return the current measured temperature" },
  { "get_gyro_x", (PyCFunction)getGyroX, METH_NOARGS, "Return the current measured gyro in x" },
  { "get_gyro_y", (PyCFunction)getGyroY, METH_NOARGS, "Return the current measured gyro in y" },
  { "get_gyro_z", (PyCFunction)getGyroZ, METH_NOARGS, "Return the current measured gyro in z" },
  { "get_acceleration_x", (PyCFunction)getAccelerationX, METH_NOARGS, "Return the current measured acceleration in x" },
  { "get_acceleration_y", (PyCFunction)getAccelerationY, METH_NOARGS, "Return the current measured acceleration in y" },
  { "get_acceleration_z", (PyCFunction)getAccelerationZ, METH_NOARGS, "Return the current measured acceleration in z" },


  // No more methods to export
  { NULL, NULL, 0, NULL }
};

} // cavimodule

#endif // CAVI_PY_METHODS_HH