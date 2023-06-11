/**
 * \file shutdown_motor_request.hpp
 * \mainpage
 *    Request for shutting the actuator's motor down
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__SHUTDOWN_MOTOR_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__SHUTDOWN_MOTOR_REQUEST
#pragma once

#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class ShutdownMotorRequest
   * \brief
   *    Request for shutting the actuator's motor down
  */
  class ShutdownMotorRequest: public Request<CommandType::SHUTDOWN_MOTOR> {
    public:
      /**\fn ShutdownMotorRequest
       * \brief
       *    Class constructor
      */
      constexpr ShutdownMotorRequest() noexcept;
      ShutdownMotorRequest(ShutdownMotorRequest const&) = default;
      ShutdownMotorRequest& operator = (ShutdownMotorRequest const&) = default;
      ShutdownMotorRequest(ShutdownMotorRequest&&) = default;
      ShutdownMotorRequest& operator = (ShutdownMotorRequest&&) = default;
  };

  constexpr ShutdownMotorRequest::ShutdownMotorRequest() noexcept
  : Request{} {
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__SHUTDOWN_MOTOR_REQUEST
