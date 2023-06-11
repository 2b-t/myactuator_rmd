/**
 * \file address_offset.hpp
 * \mainpage
 *    Contains the address offset for requests and responses
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__ADDRESS_OFFSET
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__ADDRESS_OFFSET
#pragma once

#include <cstdint>


namespace myactuator_rmd_driver {

  /**\class AddressOffset
   * \brief
   *    Holds offsets for the request and the response messages
  */
  class AddressOffset {
    public:
      inline static constexpr std::uint32_t request {0x140};
      inline static constexpr std::uint32_t response {0x240};
  };

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__ADDRESS_OFFSET
