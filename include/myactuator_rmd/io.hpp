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

#include "myactuator_rmd/actuator_state/error_code.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"


namespace myactuator_rmd {

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

  inline std::ostream& operator << (std::ostream& os, MotorStatus1 const& motor_status) noexcept {
    os << "temperature: " << motor_status.temperature << ", brake released: " << std::boolalpha << motor_status.is_brake_released << 
          ", voltage: " << motor_status.voltage << ", error code: " << motor_status.error_code;
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, Feedback const& f) noexcept {
    os << "temperature: " << f.temperature << ", current: " << f.current << ", shaft speed: " << f.shaft_speed << ", shaft angle: " << f.shaft_angle;
    return os;
  }

  inline std::ostream& operator << (std::ostream& os, MotorStatus3 const& motor_status) noexcept {
    os << "temperature: " << motor_status.temperature << ", current phase A: " << std::boolalpha << motor_status.current_phase_a << 
          ", current phase B: " << motor_status.current_phase_b << ", current phase C: " << motor_status.current_phase_c;
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

}

#endif // MYACTUATOR_RMD__IO
