/**
 * \file control_mode.hpp
 * \mainpage
 *    Contains the control modes that the actuator can be set to
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__CONTROL_MODE
#define MYACTUATOR_RMD__CONTROL_MODE
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  /**\enum ControlMode
   * \brief
   *    Strongly typed enum for all known actuator control modes
  */
  enum class ControlMode: std::uint8_t {
    NONE = 0x00,
    CURRENT = 0x01,
    VELOCITY = 0x02,
    POSITION = 0x03
  };

}

#endif // MYACTUATOR_RMD__CONTROL_MODE
