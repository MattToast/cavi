
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

// Methods struct
static struct PyMethodDef methods[] = {
  // Status Getters
  { "get_arm", (PyCFunction)getArm, METH_NOARGS, "Return the current ARM status" },
  { "get_abort", (PyCFunction)getAbort, METH_NOARGS, "Return the current abort status" },
  { "get_qdm", (PyCFunction)getQDM, METH_NOARGS, "Returns the current qdm status" },
  { "get_launch", (PyCFunction)getLaunch, METH_NOARGS, "Returns the current launch status" },
  { "get_stabilize", (PyCFunction)getStabilize, METH_NOARGS, "Returns the current stabiliation status" },

  // Data Getters
  { "get_altitude", (PyCFunction)getAltitude, METH_NOARGS, "Retrun the current measured altitude" },

  // No more methods to export
  { NULL, NULL, 0, NULL }
};

} // cavimodule

#endif // CAVI_PY_METHODS_HH