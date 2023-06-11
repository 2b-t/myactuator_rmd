/**
 * \file get_motor_status_2_response.hpp
 * \mainpage
 *    Response to request for getting motor status
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_MOTOR_STATUS_2_RESPONSE
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_MOTOR_STATUS_2_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/protocol/responses/feedback_response.hpp"
#include "myactuator_rmd_driver/protocol/command_type.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class GetMotorStatus2Response
   * \brief
   *    Response to request for getting motor status
  */
  class GetMotorStatus2Response: public FeedbackResponse {
    public:
      /**\fn GetMotorStatus2Response
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr GetMotorStatus2Response(std::array<std::uint8_t,8> const& data);
      GetMotorStatus2Response() = delete;
      GetMotorStatus2Response(GetMotorStatus2Response const&) = default;
      GetMotorStatus2Response& operator = (GetMotorStatus2Response const&) = default;
      GetMotorStatus2Response(GetMotorStatus2Response&&) = default;
      GetMotorStatus2Response& operator = (GetMotorStatus2Response&&) = default;
  };

  constexpr GetMotorStatus2Response::GetMotorStatus2Response(std::array<std::uint8_t,8> const& data)
  : FeedbackResponse{data} {
    if (data[0] != CommandType::READ_MOTOR_STATUS_2) {
      throw ProtocolException("Unexpected response to get motor status 2 request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_MOTOR_STATUS_2_RESPONSE
