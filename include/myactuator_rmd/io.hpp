/**
 * \file io.hpp
 * \mainpage
 *    Contains functions for printing the different classes to console
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__IO
#define MYACTUATOR_RMD__IO
#pragma once

#include <iomanip>
#include <ostream>

#include "myactuator_rmd/actuator_state/acceleration_type.hpp"
#include "myactuator_rmd/actuator_state/can_baud_rate.hpp"
#include "myactuator_rmd/actuator_state/control_mode.hpp"
#include "myactuator_rmd/actuator_state/error_code.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"


namespace myactuator_rmd {

  inline std::ostream& operator << (std::ostream& os, AccelerationType const& acceleration_type) noexcept {
    os << "0x" << std::hex << std::setfill('0') << std::setw(2) << static_cast<std::uint16_t>(acceleration_type) << std::dec;
    switch(acceleration_type) {
      case AccelerationType::POSITION_PLANNING_ACCELERATION:
        os << " (position planning acceleration)";
        break;
      case AccelerationType::POSITION_PLANNING_DECELERATION:
        os << " (position planning deceleration)";
        break;
      case AccelerationType::VELOCITY_PLANNING_ACCELERATION:
        os << " (velocity planning acceleration)";
        break;
      case AccelerationType::VELOCITY_PLANNING_DECELERATION:
        os << " (velocity planning deceleration)";
        break;
      default:
        os << " (unknown acceleration type)";
    }
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, CanBaudRate const& baud_rate) noexcept {
    os << "0x" << std::hex << std::setfill('0') << std::setw(2) << static_cast<std::uint16_t>(baud_rate) << std::dec;
    switch(baud_rate) {
      case CanBaudRate::KBPS500:
        os << " (500 kbps)";
        break;
      case CanBaudRate::MBPS1:
        os << " (1 Mbps)";
        break;
      default:
        os << " (unknown baud rate)";
    }
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, ControlMode const& control_mode) noexcept {
    os << "0x" << std::hex << std::setfill('0') << std::setw(2) << static_cast<std::uint16_t>(control_mode) << std::dec;
    switch(control_mode) {
      case ControlMode::NONE:
        os << " (none)";
        break;
      case ControlMode::CURRENT:
        os << " (current control mode)";
        break;
      case ControlMode::VELOCITY:
        os << " (velocity control mode)";
        break;
      case ControlMode::POSITION:
        os << " (position control mode)";
        break;
      default:
        os << " (unknown control mode)";
    }
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, ErrorCode const& error_code) noexcept {
    os << "0x" << std::hex << std::setfill('0') << std::setw(4) << static_cast<std::uint16_t>(error_code) << std::dec;
    switch(error_code) {
      case ErrorCode::NO_ERROR:
        os << " (no error)";
        break;
      case ErrorCode::MOTOR_STALL:
        os << " (motor stall)";
        break;
      case ErrorCode::LOW_VOLTAGE:
        os << " (low voltage)";
        break;
      case ErrorCode::OVERVOLTAGE:
        os << " (overvoltage)";
        break;
      case ErrorCode::OVERCURRENT:
        os << " (overcurrent)";
        break;
      case ErrorCode::POWER_OVERRUN:
        os << " (power overrun)";
        break;
      case ErrorCode::SPEEDING:
        os << " (speeding)";
        break;
      case ErrorCode::UNSPECIFIED_1: case ErrorCode::UNSPECIFIED_2: case ErrorCode::UNSPECIFIED_3:
        os << " (unspecified error)";
        break;
      case ErrorCode::OVERTEMPERATURE:
        os << " (overtemperature)";
        break;
      case ErrorCode::ENCODER_CALIBRATION_ERROR:
        os << " (encoder calibration error)";
        break;
      default:
        os << " (unknown error)";
    }
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, PiGains const& g) noexcept {
    os << "kp: " << static_cast<int>(g.kp) << ", ki: " << static_cast<int>(g.ki);
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, Gains const& g) noexcept {
    os << "current: {" << g.current << "}, speed: {" << g.speed << "}, position: {" << g.position << "}";
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, MotorStatus1 const& motor_status) noexcept {
    os << "temperature: " << motor_status.temperature << ", brake released: " << std::boolalpha << motor_status.is_brake_released << 
          ", voltage: " << motor_status.voltage << ", error code: " << motor_status.error_code;
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, MotorStatus2 const& motor_status) noexcept {
    os << "temperature: " << motor_status.temperature << ", current: " << motor_status.current <<
          ", shaft speed: " << motor_status.shaft_speed << ", shaft angle: " << motor_status.shaft_angle;
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, MotorStatus3 const& motor_status) noexcept {
    os << "temperature: " << motor_status.temperature << ", current phase A: " << std::boolalpha << motor_status.current_phase_a << 
          ", current phase B: " << motor_status.current_phase_b << ", current phase C: " << motor_status.current_phase_c;
    return os;
  }

}

#endif // MYACTUATOR_RMD__IO
