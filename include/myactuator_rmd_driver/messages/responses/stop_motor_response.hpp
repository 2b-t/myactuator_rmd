/**
 * \file stop_motor_response.hpp
 * \mainpage
 *    Response to request for stopping the actuator's motor
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__STOP_MOTOR_RESPONSE
#define MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__STOP_MOTOR_RESPONSE
#pragma once

#include <array>
#include <cstdint>
#include <cstring>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"


namespace myactuator_rmd_driver {

  /**\class StopMotorResponse
   * \brief
   *    Response to request for stopping the actuator's motor
  */
  class StopMotorResponse: public Response {
    public:
      /**\fn StopMotorResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      StopMotorResponse(std::array<std::uint8_t,8> const& data);
      StopMotorResponse() = delete;
      StopMotorResponse(StopMotorResponse const&) = default;
      StopMotorResponse& operator = (StopMotorResponse const&) = default;
      StopMotorResponse(StopMotorResponse&&) = default;
      StopMotorResponse& operator = (StopMotorResponse&&) = default;
  };

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__STOP_MOTOR_RESPONSE
