/**
 * \file single_motor_message.hpp
 * \mainpage
 *    Contains request for a single motor
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_MESSAGE
#define MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_MESSAGE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/message.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  /**\class SingleMotorMessage
   * \brief
   *    Base class for message for a single actuator
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class SingleMotorMessage: public Message {
    public:
      /**\fn SingleMotorMessage
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the actuator
      */
      constexpr SingleMotorMessage(std::array<std::uint8_t,8> const& data);
      constexpr SingleMotorMessage() noexcept;
      SingleMotorMessage(SingleMotorMessage const&) = default;
      SingleMotorMessage& operator = (SingleMotorMessage const&) = default;
      SingleMotorMessage(SingleMotorMessage&&) = default;
      SingleMotorMessage& operator = (SingleMotorMessage&&) = default;
  };

  template <CommandType C>
  constexpr SingleMotorMessage<C>::SingleMotorMessage(std::array<std::uint8_t,8> const& data)
  : Message{data} {
    if (data[0] != C) {
      throw ProtocolException("Unexpected response");
    }
    return;
  }

  template <CommandType C>
  constexpr SingleMotorMessage<C>::SingleMotorMessage() noexcept
  : Message{} {
    data_[0] = static_cast<std::uint8_t>(C);
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_MESSAGE
