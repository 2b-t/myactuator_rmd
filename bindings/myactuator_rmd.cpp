/**
 * \file myactuator_rmd.cpp
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

#include "myactuator_rmd/actuator_state/control_mode.hpp"
#include "myactuator_rmd/actuator_state/error_code.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/can/exceptions.hpp"
#include "myactuator_rmd/can/frame.hpp"
#include "myactuator_rmd/can/node.hpp"
#include "myactuator_rmd/driver.hpp"
#include "myactuator_rmd/exceptions.hpp"
#include "myactuator_rmd/io.hpp"


PYBIND11_MODULE(myactuator_rmd, m) {

  m.doc() = "MyActuator RMD driver main module";
  pybind11::class_<myactuator_rmd::Driver>(m, "Driver")
    .def(pybind11::init<std::string const&, std::uint32_t>())
    .def("getAcceleration", &myactuator_rmd::Driver::getAcceleration)
    .def("getControllerGains", &myactuator_rmd::Driver::getControllerGains)
    .def("getControlMode", &myactuator_rmd::Driver::getControlMode)
    .def("getMotorModel", &myactuator_rmd::Driver::getMotorModel)
    .def("getMotorPower", &myactuator_rmd::Driver::getMotorPower)
    .def("getMotorStatus1", &myactuator_rmd::Driver::getMotorStatus1)
    .def("getMotorStatus2", &myactuator_rmd::Driver::getMotorStatus2)
    .def("getMotorStatus3", &myactuator_rmd::Driver::getMotorStatus3)
    .def("getMultiTurnAngle", &myactuator_rmd::Driver::getMultiTurnAngle)
    .def("getMultiTurnEncoderPosition", &myactuator_rmd::Driver::getMultiTurnEncoderPosition)
    .def("getMultiTurnEncoderOriginalPosition", &myactuator_rmd::Driver::getMultiTurnEncoderOriginalPosition)
    .def("getMultiTurnEncoderZeroOffset", &myactuator_rmd::Driver::getMultiTurnEncoderZeroOffset)
    .def("getRuntime", &myactuator_rmd::Driver::getRuntime)
    .def("getSingleTurnAngle", &myactuator_rmd::Driver::getSingleTurnAngle)
    .def("getSingleTurnEncoderPosition", &myactuator_rmd::Driver::getSingleTurnEncoderPosition)
    .def("getVersionDate", &myactuator_rmd::Driver::getVersionDate)
    .def("lockBrake", &myactuator_rmd::Driver::lockBrake)
    .def("releaseBrake", &myactuator_rmd::Driver::releaseBrake)
    .def("reset", &myactuator_rmd::Driver::reset)
    .def("sendPositionAbsoluteSetpoint", &myactuator_rmd::Driver::sendPositionAbsoluteSetpoint)
    .def("sendTorqueSetpoint", &myactuator_rmd::Driver::sendTorqueSetpoint)
    .def("sendVelocitySetpoint", &myactuator_rmd::Driver::sendVelocitySetpoint)
    .def("setControllerGains", &myactuator_rmd::Driver::setControllerGains)
    .def("shutdownMotor", &myactuator_rmd::Driver::shutdownMotor)
    .def("stopMotor", &myactuator_rmd::Driver::stopMotor);
  pybind11::register_exception<myactuator_rmd::Exception>(m, "DriverException");
  pybind11::register_exception<myactuator_rmd::ProtocolException>(m, "ProtocolException");
  pybind11::register_exception<myactuator_rmd::ValueRangeException>(m, "ValueRangeException");

  auto m_actuator_state = m.def_submodule("actuator_state", "Submodule for actuator state structures");
  pybind11::enum_<myactuator_rmd::ControlMode>(m_actuator_state, "ControlMode")
    .value("NONE", myactuator_rmd::ControlMode::NONE)
    .value("CURRENT", myactuator_rmd::ControlMode::CURRENT)
    .value("VELOCITY", myactuator_rmd::ControlMode::VELOCITY)
    .value("POSITION", myactuator_rmd::ControlMode::POSITION);
  pybind11::enum_<myactuator_rmd::ErrorCode>(m_actuator_state, "ErrorCode")
    .value("NO_ERROR", myactuator_rmd::ErrorCode::NO_ERROR)
    .value("MOTOR_STALL", myactuator_rmd::ErrorCode::MOTOR_STALL)
    .value("LOW_VOLTAGE", myactuator_rmd::ErrorCode::LOW_VOLTAGE)
    .value("OVERVOLTAGE", myactuator_rmd::ErrorCode::OVERVOLTAGE)
    .value("OVERCURRENT", myactuator_rmd::ErrorCode::OVERCURRENT)
    .value("POWER_OVERRUN", myactuator_rmd::ErrorCode::POWER_OVERRUN)
    .value("SPEEDING", myactuator_rmd::ErrorCode::SPEEDING)
    .value("UNSPECIFIED_1", myactuator_rmd::ErrorCode::UNSPECIFIED_1)
    .value("UNSPECIFIED_2", myactuator_rmd::ErrorCode::UNSPECIFIED_2)
    .value("UNSPECIFIED_3", myactuator_rmd::ErrorCode::UNSPECIFIED_3)
    .value("OVERTEMPERATURE", myactuator_rmd::ErrorCode::OVERTEMPERATURE)
    .value("ENCODER_CALIBRATION_ERROR", myactuator_rmd::ErrorCode::ENCODER_CALIBRATION_ERROR);
  pybind11::class_<myactuator_rmd::Gains>(m_actuator_state, "Gains")
    .def(pybind11::init<myactuator_rmd::PiGains const&, myactuator_rmd::PiGains const&, myactuator_rmd::PiGains const&>())
    .def(pybind11::init<std::uint8_t const, std::uint8_t const, std::uint8_t const, std::uint8_t const, std::uint8_t const, std::uint8_t const>())
    .def_readwrite("current", &myactuator_rmd::Gains::current)
    .def_readwrite("speed", &myactuator_rmd::Gains::speed)
    .def_readwrite("position", &myactuator_rmd::Gains::position)
    .def("__repr__", [](myactuator_rmd::Gains const& gains) -> std::string { 
      std::ostringstream ss {};
      ss << gains;
      return ss.str();
    });
  pybind11::class_<myactuator_rmd::MotorStatus1>(m_actuator_state, "MotorStatus1")
    .def(pybind11::init<int const, bool const, float const, myactuator_rmd::ErrorCode const>())
    .def_readonly("temperature", &myactuator_rmd::MotorStatus1::temperature)
    .def_readonly("is_brake_released", &myactuator_rmd::MotorStatus1::is_brake_released)
    .def_readonly("voltage", &myactuator_rmd::MotorStatus1::voltage)
    .def_readonly("error_code", &myactuator_rmd::MotorStatus1::error_code)
    .def("__repr__", [](myactuator_rmd::MotorStatus1 const& motor_status) -> std::string { 
      std::ostringstream ss {};
      ss << motor_status;
      return ss.str();
    });
  pybind11::class_<myactuator_rmd::MotorStatus2>(m_actuator_state, "MotorStatus2")
    .def(pybind11::init<int const, float const, float const, float const>())
    .def_readonly("temperature", &myactuator_rmd::MotorStatus2::temperature)
    .def_readonly("current", &myactuator_rmd::MotorStatus2::current)
    .def_readonly("shaft_speed", &myactuator_rmd::MotorStatus2::shaft_speed)
    .def_readonly("shaft_angle", &myactuator_rmd::MotorStatus2::shaft_angle)
    .def("__repr__", [](myactuator_rmd::MotorStatus2 const& motor_status) -> std::string { 
      std::ostringstream ss {};
      ss << motor_status;
      return ss.str();
    });
  pybind11::class_<myactuator_rmd::MotorStatus3>(m_actuator_state, "MotorStatus3")
    .def(pybind11::init<int const, float const, float const, float const>())
    .def_readonly("temperature", &myactuator_rmd::MotorStatus3::temperature)
    .def_readonly("current_phase_a", &myactuator_rmd::MotorStatus3::current_phase_a)
    .def_readonly("current_phase_b", &myactuator_rmd::MotorStatus3::current_phase_b)
    .def_readonly("current_phase_c", &myactuator_rmd::MotorStatus3::current_phase_c)
    .def("__repr__", [](myactuator_rmd::MotorStatus3 const& motor_status) -> std::string { 
      std::ostringstream ss {};
      ss << motor_status;
      return ss.str();
    });
  pybind11::class_<myactuator_rmd::PiGains>(m_actuator_state, "PiGains")
    .def(pybind11::init<std::uint8_t const, std::uint8_t const>())
    .def_readwrite("kp", &myactuator_rmd::PiGains::kp)
    .def_readwrite("ki", &myactuator_rmd::PiGains::ki)
    .def("__repr__", [](myactuator_rmd::PiGains const& pi_gains) -> std::string { 
      std::ostringstream ss {};
      ss << pi_gains;
      return ss.str();
    });

  auto m_can = m.def_submodule("can", "Submodule for basic CAN communication");
  pybind11::class_<myactuator_rmd::can::Frame>(m_can, "Frame")
    .def(pybind11::init<std::uint32_t const, std::array<std::uint8_t,8> const&>())
    .def("getId", &myactuator_rmd::can::Frame::getId)
    .def("getData", &myactuator_rmd::can::Frame::getData);
  pybind11::class_<myactuator_rmd::can::Node>(m_can, "Node")
    .def(pybind11::init<std::string const&>())
    .def("setRecvFilter", &myactuator_rmd::can::Node::setRecvFilter)
    .def("read", &myactuator_rmd::can::Node::read)
    .def("write", static_cast<void (myactuator_rmd::can::Node::*)(myactuator_rmd::can::Frame const&)>(&myactuator_rmd::can::Node::write));
  pybind11::register_exception<myactuator_rmd::can::SocketException>(m_can, "SocketException");
  pybind11::register_exception<myactuator_rmd::can::Exception>(m_can, "CanException");
  pybind11::register_exception<myactuator_rmd::can::TxTimeoutError>(m_can, "TxTimeoutError");
  pybind11::register_exception<myactuator_rmd::can::LostArbitrationError>(m_can, "LostArbitrationError");
  pybind11::register_exception<myactuator_rmd::can::ControllerProblemError>(m_can, "ControllerProblemError");
  pybind11::register_exception<myactuator_rmd::can::ProtocolViolationError>(m_can, "ProtocolViolationError");
  pybind11::register_exception<myactuator_rmd::can::TransceiverStatusError>(m_can, "TransceiverStatusError");
  pybind11::register_exception<myactuator_rmd::can::NoAcknowledgeError>(m_can, "NoAcknowledgeError");
  pybind11::register_exception<myactuator_rmd::can::BusOffError>(m_can, "BusOffError");
  pybind11::register_exception<myactuator_rmd::can::BusError>(m_can, "BusError");
  pybind11::register_exception<myactuator_rmd::can::ControllerRestartedError>(m_can, "ControllerRestartedError");

}
