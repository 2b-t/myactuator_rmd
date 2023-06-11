/**
 * \file response.hpp
 * \mainpage
 *    Contains base class for the responses sent from the actuator to the driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSE
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/protocol/message.hpp"


namespace myactuator_rmd_driver {

  /**\class Response
   * \brief
   *    Base class for responses sent from the actuator to the driver
  */
  class Response: public Message {
    protected:
      /**\fn Response
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr Response(std::array<std::uint8_t,8> const& data) noexcept;
      Response() = delete;
      Response(Response const&) = default;
      Response& operator = (Response const&) = default;
      Response(Response&&) = default;
      Response& operator = (Response&&) = default;
  };

  constexpr Response::Response(std::array<std::uint8_t,8> const& data) noexcept
  : Message{data} {
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSE
