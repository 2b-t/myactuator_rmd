/**
 * \file acceleration_type.hpp
 * \mainpage
 *    Index of the acceleration/deceleration types
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__ACTUATOR_STATE__ACCELERATION_TYPE
#define MYACTUATOR_RMD__ACTUATOR_STATE__ACCELERATION_TYPE
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  /**\enum AccelerationType
   * \brief
   *    Strongly typed enum for the different acceleration (from initial to maximum speed)/
   *    deceleration (from maximum speed to stop) types
  */
  enum class AccelerationType: std::uint8_t {
    POSITION_PLANNING_ACCELERATION = 0x00,
    POSITION_PLANNING_DECELERATION = 0x01,
    VELOCITY_PLANNING_ACCELERATION = 0x02,
    VELOCITY_PLANNING_DECELERATION = 0x03
  };

}

#endif // MYACTUATOR_RMD__ACTUATOR_STATE__ACCELERATION_TYPE
