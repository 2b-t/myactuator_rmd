/**
 * \file can_address_offset.hpp
 * \mainpage
 *    Contains the address offset for CAN requests and responses
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__DRIVER__CAN_ADDRESS_OFFSET
#define MYACTUATOR_RMD__DRIVER__CAN_ADDRESS_OFFSET
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  /**\class CanAddressOffset
   * \brief
   *    Holds offsets for the CAN request and the response messages
  */
  class CanAddressOffset {
    public:
      inline static constexpr std::uint32_t request {0x140};
      inline static constexpr std::uint32_t response {0x240};
  };

}

#endif // MYACTUATOR_RMD__DRIVER__CAN_ADDRESS_OFFSET
