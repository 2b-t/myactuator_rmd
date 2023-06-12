/**
 * \file single_motor_request.hpp
 * \mainpage
 *    Contains request for a single motor
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_REQUEST
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/request.hpp"


namespace myactuator_rmd {

  /**\class Request
   * \brief
   *    Base class for requests sent from the driver to the actuator
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class SingleMotorRequest: public Request {
    public:
      /**\fn SingleMotorRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the actuator
      */
      constexpr SingleMotorRequest(std::array<std::uint8_t,8> const& data = {}) noexcept;
      SingleMotorRequest(SingleMotorRequest const&) = default;
      SingleMotorRequest& operator = (SingleMotorRequest const&) = default;
      SingleMotorRequest(SingleMotorRequest&&) = default;
      SingleMotorRequest& operator = (SingleMotorRequest&&) = default;
  };

  template <CommandType C>
  constexpr SingleMotorRequest<C>::SingleMotorRequest(std::array<std::uint8_t,8> const& data) noexcept
  : Request{data} {
    data_[0] = static_cast<std::uint8_t>(C);
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_REQUEST
