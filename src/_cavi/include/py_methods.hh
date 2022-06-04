
#ifndef CAVI_PY_METHODS_HH
#define CAVI_PY_METHODS_HH

#include <Python.h> // Nedds to be included first
#include <memory>

#include "mock_status.hh"

namespace cavimodule {

// Status Methods
namespace status {

// Getters
PyObject* getArm(PyObject* self);
PyObject* getAbort(PyObject* self);
PyObject* getQDM(PyObject* self);
PyObject* getLaunch(PyObject* self);
PyObject* getStabilize(PyObject* self);

// Setters
PyObject* setArm(PyObject* self, PyObject* args);
PyObject* setAbort(PyObject* self, PyObject* args);
PyObject* setQDM(PyObject* self, PyObject* args);
PyObject* setLaunch(PyObject* self, PyObject* args);
PyObject* setStabilize(PyObject* self, PyObject* args);

static inline struct PyMethodDef methods[] = {
  { "get_arm", (PyCFunction)getArm, METH_NOARGS, "Return the current ARM status" },
  { "get_abort", (PyCFunction)getAbort, METH_NOARGS, "Return the current abort status" },
  { "get_qdm", (PyCFunction)getQDM, METH_NOARGS, "Returns the current qdm status" },
  { "get_launch", (PyCFunction)getLaunch, METH_NOARGS, "Returns the current launch status" },
  { "get_stabilize", (PyCFunction)getStabilize, METH_NOARGS, "Returns the current stabiliation status" },
  { "set_arm", (PyCFunction)setArm, METH_VARARGS, "Set the Launch Station armed flag, returns bool based on success" },
  { "set_abort", (PyCFunction)setAbort, METH_VARARGS, "Set the Launch Station abort flag, returns bool based on success" },
  { "set_qdm", (PyCFunction)setQDM, METH_VARARGS, "Set the Launch Station QDM flag, returns bool based on success" },
  { "set_launch", (PyCFunction)setLaunch, METH_VARARGS, "Set the Launch Station launch flag, returns bool based on success" },
  { "set_stabilize", (PyCFunction)setStabilize, METH_VARARGS, "Set the Launch Station stabilization flag, returns bool based on success" },
  { NULL, NULL, 0, NULL } // sentinel
};

} // status

namespace data {

// Getters
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

static inline struct PyMethodDef methods[] = {
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
  { NULL, NULL, 0, NULL } // sentinel
};

} // data

namespace _testing {
inline auto mockStatus = std::make_unique<MockLaunchStatus>();

static PyObject*
resetTestStatus() {
  mockStatus->reset();
  Py_RETURN_NONE;
}

static inline struct PyMethodDef methods[] = {
    { "reset_mock_status", (PyCFunction)resetTestStatus, METH_NOARGS, "Reset the test status to initial state" },
    { NULL, NULL, 0, NULL } // sentinel
};

} // _testing

// Methods struct
static inline struct PyMethodDef methods[] = {
  { NULL, NULL, 0, NULL } // sentinel
};

} // cavimodule

#endif // CAVI_PY_METHODS_HH