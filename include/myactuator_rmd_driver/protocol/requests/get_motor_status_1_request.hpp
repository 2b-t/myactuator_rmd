/**
 * \file get_motor_status_1_request.hpp
 * \mainpage
 *    Request for reading the motor status
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__GET_MOTOR_STATUS_1_REQUEST
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__GET_MOTOR_STATUS_1_REQUEST
#pragma once

#include "myactuator_rmd_driver/protocol/requests/request.hpp"
#include "myactuator_rmd_driver/protocol/command_type.hpp"


namespace myactuator_rmd_driver {

  /**\class GetMotorStatus1Request
   * \brief
   *    Request for reading the motor status
  */
  class GetMotorStatus1Request: public Request<CommandType::READ_MOTOR_STATUS_1_AND_ERROR_FLAG> {
    public:
      /**\fn GetMotorStatus1Request
       * \brief
       *    Class constructor
      */
      constexpr GetMotorStatus1Request();
      GetMotorStatus1Request(GetMotorStatus1Request const&) = default;
      GetMotorStatus1Request& operator = (GetMotorStatus1Request const&) = default;
      GetMotorStatus1Request(GetMotorStatus1Request&&) = default;
      GetMotorStatus1Request& operator = (GetMotorStatus1Request&&) = default;
  };

  constexpr GetMotorStatus1Request::GetMotorStatus1Request()
  : Request{} {
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__GET_MOTOR_STATUS_1_REQUEST
