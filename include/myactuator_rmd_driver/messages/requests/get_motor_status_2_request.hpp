/**
 * \file get_motor_status_2_request.hpp
 * \mainpage
 *    Request for reading the motor status
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__GET_MOTOR_STATUS_2_REQUEST
#define MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__GET_MOTOR_STATUS_2_REQUEST
#pragma once

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/request.hpp"


namespace myactuator_rmd_driver {

  /**\class GetMotorStatus2Request
   * \brief
   *    Request for reading the motor status
  */
  class GetMotorStatus2Request: public Request<CommandType::READ_MOTOR_STATUS_2> {
    public:
      /**\fn GetMotorStatus2Request
       * \brief
       *    Class constructor
      */
      constexpr GetMotorStatus2Request();
      GetMotorStatus2Request(GetMotorStatus2Request const&) = default;
      GetMotorStatus2Request& operator = (GetMotorStatus2Request const&) = default;
      GetMotorStatus2Request(GetMotorStatus2Request&&) = default;
      GetMotorStatus2Request& operator = (GetMotorStatus2Request&&) = default;
  };

  constexpr GetMotorStatus2Request::GetMotorStatus2Request()
  : Request{} {
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__GET_MOTOR_STATUS_2_REQUEST
