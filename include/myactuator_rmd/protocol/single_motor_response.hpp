/**
 * \file response.hpp
 * \mainpage
 *    Contains base class for the responses sent from the actuator to the driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_RESPONSE
#define MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/response.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  /**\class SingleMotorResponse
   * \brief
   *    Base class for responses sent from the actuator to the driver
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class SingleMotorResponse: public Response {
    public:
      /**\fn SingleMotorResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SingleMotorResponse(std::array<std::uint8_t,8> const& data);
      SingleMotorResponse() = delete;
      SingleMotorResponse(SingleMotorResponse const&) = default;
      SingleMotorResponse& operator = (SingleMotorResponse const&) = default;
      SingleMotorResponse(SingleMotorResponse&&) = default;
      SingleMotorResponse& operator = (SingleMotorResponse&&) = default;
  };

  template <CommandType C>
  constexpr SingleMotorResponse<C>::SingleMotorResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if (data[0] != C) {
      throw ProtocolException("Unexpected response");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__SINGLE_MOTOR_RESPONSE
