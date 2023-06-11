/**
 * \file shutdown_motor_response.hpp
 * \mainpage
 *    Response to request for shutting the actuator's motor down
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSES__SHUTDOWN_MOTOR_RESPONSE
#define MYACTUATOR_RMD__PROTOCOL__RESPONSES__SHUTDOWN_MOTOR_RESPONSE
#pragma once

#include <array>
#include <cstdint>
#include <cstring>

#include "myactuator_rmd/protocol/responses/response.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class Response
   * \brief
   *    Response to request for shutting the actuator's motor down
  */
  class ShutdownMotorResponse: public Response {
    public:
      /**\fn ShutdownMotorResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      ShutdownMotorResponse(std::array<std::uint8_t,8> const& data);
      ShutdownMotorResponse() = delete;
      ShutdownMotorResponse(ShutdownMotorResponse const&) = default;
      ShutdownMotorResponse& operator = (ShutdownMotorResponse const&) = default;
      ShutdownMotorResponse(ShutdownMotorResponse&&) = default;
      ShutdownMotorResponse& operator = (ShutdownMotorResponse&&) = default;
  };

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES__SHUTDOWN_MOTOR_RESPONSE
