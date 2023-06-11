/**
 * \file myactuator_rmd_driver.cpp
 * \mainpage
 *    Python bindings for C++ library
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <cstdint>
#include <string>
#include <sstream>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "myactuator_rmd_driver/can/exceptions.hpp"
#include "myactuator_rmd_driver/can/frame.hpp"
#include "myactuator_rmd_driver/can/node.hpp"
#include "myactuator_rmd_driver/driver.hpp"
#include "myactuator_rmd_driver/error_codes.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"
#include "myactuator_rmd_driver/feedback.hpp"
#include "myactuator_rmd_driver/motor_status_1.hpp"
#include "myactuator_rmd_driver/motor_status_2.hpp"
#include "myactuator_rmd_driver/motor_status_3.hpp"
#include "myactuator_rmd_driver/gains.hpp"
#include "myactuator_rmd_driver/io.hpp"


PYBIND11_MODULE(myactuator_rmd_driver, m) {

  m.doc() = "MyActuator RMD driver main module";
  pybind11::class_<myactuator_rmd_driver::Driver>(m, "Driver")
    .def(pybind11::init<std::string const&, std::uint32_t>())
    .def("getVersionDate", &myactuator_rmd_driver::Driver::getVersionDate)
    .def("getMotorModel", &myactuator_rmd_driver::Driver::getMotorModel)
    .def("getMotorStatus1", &myactuator_rmd_driver::Driver::getMotorStatus1)
    .def("getMotorStatus2", &myactuator_rmd_driver::Driver::getMotorStatus2)
    .def("getMotorStatus3", &myactuator_rmd_driver::Driver::getMotorStatus3)
    .def("getControllerGains", &myactuator_rmd_driver::Driver::getControllerGains)
    .def("setControllerGains", &myactuator_rmd_driver::Driver::setControllerGains)
    .def("sendTorqueSetpoint", &myactuator_rmd_driver::Driver::sendTorqueSetpoint)
    .def("sendVelocitySetpoint", &myactuator_rmd_driver::Driver::sendVelocitySetpoint)
    .def("sendPositionAbsoluteSetpoint", &myactuator_rmd_driver::Driver::sendPositionAbsoluteSetpoint)
    .def("stopMotor", &myactuator_rmd_driver::Driver::stopMotor)
    .def("shutdownMotor", &myactuator_rmd_driver::Driver::shutdownMotor);
  pybind11::enum_<myactuator_rmd_driver::ErrorCode>(m, "ErrorCode")
    .value("NO_ERROR", myactuator_rmd_driver::ErrorCode::NO_ERROR)
    .value("MOTOR_STALL", myactuator_rmd_driver::ErrorCode::MOTOR_STALL)
    .value("LOW_VOLTAGE", myactuator_rmd_driver::ErrorCode::LOW_VOLTAGE)
    .value("OVERVOLTAGE", myactuator_rmd_driver::ErrorCode::OVERVOLTAGE)
    .value("OVERCURRENT", myactuator_rmd_driver::ErrorCode::OVERCURRENT)
    .value("POWER_OVERRUN", myactuator_rmd_driver::ErrorCode::POWER_OVERRUN)
    .value("SPEEDING", myactuator_rmd_driver::ErrorCode::SPEEDING)
    .value("UNSPECIFIED_1", myactuator_rmd_driver::ErrorCode::UNSPECIFIED_1)
    .value("UNSPECIFIED_2", myactuator_rmd_driver::ErrorCode::UNSPECIFIED_2)
    .value("UNSPECIFIED_3", myactuator_rmd_driver::ErrorCode::UNSPECIFIED_3)
    .value("OVERTEMPERATURE", myactuator_rmd_driver::ErrorCode::OVERTEMPERATURE)
    .value("ENCODER_CALIBRATION_ERROR", myactuator_rmd_driver::ErrorCode::ENCODER_CALIBRATION_ERROR);
  pybind11::class_<myactuator_rmd_driver::Gains>(m, "Gains")
    .def(pybind11::init<myactuator_rmd_driver::PiGains const&, myactuator_rmd_driver::PiGains const&, myactuator_rmd_driver::PiGains const&>())
    .def(pybind11::init<std::uint8_t const, std::uint8_t const, std::uint8_t const, std::uint8_t const, std::uint8_t const, std::uint8_t const>())
    .def_readwrite("current", &myactuator_rmd_driver::Gains::current)
    .def_readwrite("speed", &myactuator_rmd_driver::Gains::speed)
    .def_readwrite("position", &myactuator_rmd_driver::Gains::position)
    .def("__repr__", [](myactuator_rmd_driver::Gains const& gains) -> std::string { 
      std::ostringstream ss {};
      ss << gains;
      return ss.str();
    });
  pybind11::class_<myactuator_rmd_driver::MotorStatus1>(m, "MotorStatus1")
    .def(pybind11::init<int const, bool const, float const, myactuator_rmd_driver::ErrorCode const>())
    .def_readonly("temperature", &myactuator_rmd_driver::MotorStatus1::temperature)
    .def_readonly("is_brake_released", &myactuator_rmd_driver::MotorStatus1::is_brake_released)
    .def_readonly("voltage", &myactuator_rmd_driver::MotorStatus1::voltage)
    .def_readonly("error_code", &myactuator_rmd_driver::MotorStatus1::error_code)
    .def("__repr__", [](myactuator_rmd_driver::MotorStatus1 const& motor_status) -> std::string { 
      std::ostringstream ss {};
      ss << motor_status;
      return ss.str();
    });
  pybind11::class_<myactuator_rmd_driver::MotorStatus2>(m, "MotorStatus2")
    .def(pybind11::init<int const, float const, float const, float const>())
    .def_readonly("temperature", &myactuator_rmd_driver::MotorStatus2::temperature)
    .def_readonly("current", &myactuator_rmd_driver::MotorStatus2::current)
    .def_readonly("shaft_speed", &myactuator_rmd_driver::MotorStatus2::shaft_speed)
    .def_readonly("shaft_angle", &myactuator_rmd_driver::MotorStatus2::shaft_angle)
    .def("__repr__", [](myactuator_rmd_driver::MotorStatus2 const& motor_status) -> std::string { 
      std::ostringstream ss {};
      ss << motor_status;
      return ss.str();
    });
  pybind11::class_<myactuator_rmd_driver::MotorStatus3>(m, "MotorStatus3")
    .def(pybind11::init<int const, float const, float const, float const>())
    .def_readonly("temperature", &myactuator_rmd_driver::MotorStatus3::temperature)
    .def_readonly("current_phase_a", &myactuator_rmd_driver::MotorStatus3::current_phase_a)
    .def_readonly("current_phase_b", &myactuator_rmd_driver::MotorStatus3::current_phase_b)
    .def_readonly("current_phase_c", &myactuator_rmd_driver::MotorStatus3::current_phase_c)
    .def("__repr__", [](myactuator_rmd_driver::MotorStatus3 const& motor_status) -> std::string { 
      std::ostringstream ss {};
      ss << motor_status;
      return ss.str();
    });
  pybind11::class_<myactuator_rmd_driver::PiGains>(m, "PiGains")
    .def(pybind11::init<std::uint8_t const, std::uint8_t const>())
    .def_readwrite("kp", &myactuator_rmd_driver::PiGains::kp)
    .def_readwrite("ki", &myactuator_rmd_driver::PiGains::ki)
    .def("__repr__", [](myactuator_rmd_driver::PiGains const& pi_gains) -> std::string { 
      std::ostringstream ss {};
      ss << pi_gains;
      return ss.str();
    });

  pybind11::register_exception<myactuator_rmd_driver::Exception>(m, "DriverException");
  pybind11::register_exception<myactuator_rmd_driver::ProtocolException>(m, "ProtocolException");
  pybind11::register_exception<myactuator_rmd_driver::ValueRangeException>(m, "ValueRangeException");

  auto m_can = m.def_submodule("can", "Submodule for basic CAN communication");
  pybind11::class_<myactuator_rmd_driver::can::Frame>(m_can, "Frame")
    .def(pybind11::init<std::uint32_t const, std::array<std::uint8_t,8> const&>())
    .def("getId", &myactuator_rmd_driver::can::Frame::getId)
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
