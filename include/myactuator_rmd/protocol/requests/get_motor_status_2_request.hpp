/**
 * \file get_motor_status_2_request.hpp
 * \mainpage
 *    Request for reading the motor status
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__GET_MOTOR_STATUS_2_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__GET_MOTOR_STATUS_2_REQUEST
#pragma once

#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

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

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__GET_MOTOR_STATUS_2_REQUEST
