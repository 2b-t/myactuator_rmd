/**
 * \file shutdown_motor_response.hpp
 * \mainpage
 *    Response to request for shutting the actuator's motor down
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SHUTDOWN_MOTOR_RESPONSE
#define MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SHUTDOWN_MOTOR_RESPONSE
#pragma once

#include <array>
#include <cstdint>
#include <cstring>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"


namespace myactuator_rmd_driver {

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

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SHUTDOWN_MOTOR_RESPONSE
