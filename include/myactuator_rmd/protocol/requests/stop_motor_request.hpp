/**
 * \file stop_motor_request.hpp
 * \mainpage
 *    Request for stopping the actuator's motor
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__STOP_MOTOR_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__STOP_MOTOR_REQUEST
#pragma once

#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class StopMotorRequest
   * \brief
   *    Request for stopping the actuator's motor
  */
  class StopMotorRequest: public Request<CommandType::STOP_MOTOR> {
    public:
      /**\fn StopMotorRequest
       * \brief
       *    Class constructor
      */
      constexpr StopMotorRequest() noexcept;
      StopMotorRequest(StopMotorRequest const&) = default;
      StopMotorRequest& operator = (StopMotorRequest const&) = default;
      StopMotorRequest(StopMotorRequest&&) = default;
      StopMotorRequest& operator = (StopMotorRequest&&) = default;
  };

  constexpr StopMotorRequest::StopMotorRequest() noexcept
  : Request{} {
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__STOP_MOTOR_REQUEST
