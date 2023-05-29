/**
 * \file myactuator_rmd_driver.cpp
 * \mainpage
 *    Python bindings for C++ library
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <cstdint>
#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "myactuator_rmd_driver/can/exceptions.hpp"
#include "myactuator_rmd_driver/can/frame.hpp"
#include "myactuator_rmd_driver/can/node.hpp"
#include "myactuator_rmd_driver/driver.hpp"


PYBIND11_MODULE(myactuator_rmd_driver, m) {

  m.doc() = "MyActuator RMD driver main module";
  pybind11::class_<myactuator_rmd_driver::Driver>(m, "Driver")
    .def(pybind11::init<std::string const&, std::uint32_t>());
  // TODO(tobit): Add exceptions
  // TODO(tobit): Add requests
  // TODO(tobit): Add responses

  auto m_can = m.def_submodule("can", "Submodule for basic CAN communication");
  pybind11::class_<myactuator_rmd_driver::can::Frame>(m_can, "Frame")
    .def(pybind11::init<std::uint32_t const, std::array<std::uint8_t,8> const&>())
    .def("getCanId", &myactuator_rmd_driver::can::Frame::getCanId)
    .def("getData", &myactuator_rmd_driver::can::Frame::getData);
  pybind11::class_<myactuator_rmd_driver::can::Node>(m_can, "Node")
    .def(pybind11::init<std::string const&>())
    .def("setRecvFilter", &myactuator_rmd_driver::can::Node::setRecvFilter)
    .def("read", &myactuator_rmd_driver::can::Node::read)
    .def("write", static_cast<void (myactuator_rmd_driver::can::Node::*)(myactuator_rmd_driver::can::Frame const&)>(&myactuator_rmd_driver::can::Node::write));

  pybind11::register_exception<myactuator_rmd_driver::can::SocketException>(m_can, "SocketException");
  pybind11::register_exception<myactuator_rmd_driver::can::Exception>(m_can, "CanException");
  pybind11::register_exception<myactuator_rmd_driver::can::TxTimeoutError>(m_can, "TxTimeoutError");
  pybind11::register_exception<myactuator_rmd_driver::can::LostArbitrationError>(m_can, "LostArbitrationError");
  pybind11::register_exception<myactuator_rmd_driver::can::ControllerProblemError>(m_can, "ControllerProblemError");
  pybind11::register_exception<myactuator_rmd_driver::can::ProtocolViolationError>(m_can, "ProtocolViolationError");
  pybind11::register_exception<myactuator_rmd_driver::can::TransceiverStatusError>(m_can, "TransceiverStatusError");
  pybind11::register_exception<myactuator_rmd_driver::can::NoAcknowledgeError>(m_can, "NoAcknowledgeError");
  pybind11::register_exception<myactuator_rmd_driver::can::BusOffError>(m_can, "BusOffError");
  pybind11::register_exception<myactuator_rmd_driver::can::BusError>(m_can, "BusError");
  pybind11::register_exception<myactuator_rmd_driver::can::ControllerRestartedError>(m_can, "ControllerRestartedError");

}

