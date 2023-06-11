/**
 * \file error_code.hpp
 * \mainpage
 *    Contains the error codes of the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__ERROR_CODE
#define MYACTUATOR_RMD__ERROR_CODE
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  /**\enum ErrorCode
   * \brief
   *    Strongly typed enum for all known actuator error codes
  */
  enum class ErrorCode: std::uint16_t {
    NO_ERROR = 0x0000,
    MOTOR_STALL = 0x0002,
    LOW_VOLTAGE = 0x0004,
    OVERVOLTAGE = 0x0008,
    OVERCURRENT = 0x0010,
    POWER_OVERRUN = 0x0040,
    SPEEDING = 0x0100,
    UNSPECIFIED_1 = 0x0200, // There is no error string specified for the following three codes
    UNSPECIFIED_2 = 0x0400,
    UNSPECIFIED_3 = 0x0800,
    OVERTEMPERATURE = 0x1000,
    ENCODER_CALIBRATION_ERROR = 0x2000
  };

}

#endif // MYACTUATOR_RMD__ERROR_CODE
