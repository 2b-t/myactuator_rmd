/**
 * \file get_motor_model_request.hpp
 * \mainpage
 *    Request for reading the motor model
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__GET_MOTOR_MODEL_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__GET_MOTOR_MODEL_REQUEST
#pragma once

#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class GetMotorModelRequest
   * \brief
   *    Request for reading the motor model
  */
  class GetMotorModelRequest: public Request<CommandType::READ_MOTOR_MODEL> {
    public:
      /**\fn GetMotorModelRequest
       * \brief
       *    Class constructor
      */
      constexpr GetMotorModelRequest();
      GetMotorModelRequest(GetMotorModelRequest const&) = default;
      GetMotorModelRequest& operator = (GetMotorModelRequest const&) = default;
      GetMotorModelRequest(GetMotorModelRequest&&) = default;
      GetMotorModelRequest& operator = (GetMotorModelRequest&&) = default;
  };

  constexpr GetMotorModelRequest::GetMotorModelRequest()
  : Request{} {
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__GET_MOTOR_MODEL_REQUEST
