/**
 * \file request.hpp
 * \mainpage
 *    Contains base class for the requests sent from the driver to the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__REQUEST
#define MYACTUATOR_RMD_DRIVER__MESSAGES__REQUEST
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/message.hpp"


namespace myactuator_rmd_driver {

  /**\class Request
   * \brief
   *    Base class for requests sent from the driver to the actuator
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class Request: public Message {
    protected:
      /**\fn Request
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the actuator
      */
      constexpr Request(std::array<std::uint8_t,8> const& data = {}) noexcept;
      Request(Request const&) = default;
      Request& operator = (Request const&) = default;
      Request(Request&&) = default;
      Request& operator = (Request&&) = default;
  };

  template <CommandType C>
  constexpr Request<C>::Request(std::array<std::uint8_t,8> const& data) noexcept
  : Message{data} {
    data_[0] = static_cast<std::uint8_t>(C);
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__REQUEST
