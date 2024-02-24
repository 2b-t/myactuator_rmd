/**
 * \file can_baud_rate.hpp
 * \mainpage
 *    Communication Baud rate of the CAN bus
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__ACTUATOR_STATE__CAN_BAUD_RATE
#define MYACTUATOR_RMD__ACTUATOR_STATE__CAN_BAUD_RATE
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  /**\enum CanBaudRate
  * \brief
  *    Communication Baud rate of the CAN bus
  */
  enum class CanBaudRate: std::uint8_t {
    KBPS500 = 0,
    MBPS1 = 1
  };

}

#endif // MYACTUATOR_RMD__ACTUATOR_STATE__CAN_BAUD_RATE
