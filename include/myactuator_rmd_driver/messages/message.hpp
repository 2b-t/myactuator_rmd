/**
 * \file message.hpp
 * \mainpage
 *    Contains base class for any message to be exchanged between driver and actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__MESSAGE
#define MYACTUATOR_RMD_DRIVER__MESSAGES__MESSAGE
#pragma once

#include <array>
#include <cstdint>


namespace myactuator_rmd_driver {

  class Message {
    public:
      /**\fn getData
       * \brief
       *    Getter for data to e transmitted to CAN node
       * 
       * \param[in] data
       *    The data to be transmitted to the CAN node
      */
      std::array<std::uint8_t,8> const& getData() const noexcept;

    protected:
      /**\fn Message
       * \brief
       *    Class constructor
       * 
       * \param[in] can_id
       *    The CAN id of the message
       * \param[in] data
       *    The data to be transmitted to the CAN node
      */
      constexpr Message(std::array<std::uint8_t,8> const& data = {}) noexcept;
      Message() = delete;
      Message(Message const&) = default;
      Message& operator = (Message const&) = default;
      Message(Message&&) = default;
      Message& operator = (Message&&) = default;

      std::array<std::uint8_t,8> data_;
  };

  constexpr Message::Message(std::array<std::uint8_t,8> const& data) noexcept
  : data_{data} {
    return;
  }

}


#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__MESSAGE