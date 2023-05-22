#include "myactuator_rmd_driver/driver.hpp"

#include <pybind11/pybind11.h>


PYBIND11_MODULE(myactuator_rmd_driver, m) {
  pybind11::class_<myactuator_rmd_driver::Driver>(m, "Driver")
    .def(pybind11::init());
}

