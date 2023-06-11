/**
 * \file get_motor_status_1_response.hpp
 * \mainpage
 *    Response to request for getting motor status
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_MOTOR_STATUS_1_RESPONSE
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_MOTOR_STATUS_1_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd_driver/protocol/responses/response.hpp"
#include "myactuator_rmd_driver/protocol/command_type.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class GetMotorStatus1Response
   * \brief
   *    Response to request for getting motor status
  */
  class GetMotorStatus1Response: public Response {
    public:
      /**\fn GetMotorStatus1Response
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr GetMotorStatus1Response(std::array<std::uint8_t,8> const& data);
      GetMotorStatus1Response() = delete;
      GetMotorStatus1Response(GetMotorStatus1Response const&) = default;
      GetMotorStatus1Response& operator = (GetMotorStatus1Response const&) = default;
      GetMotorStatus1Response(GetMotorStatus1Response&&) = default;
      GetMotorStatus1Response& operator = (GetMotorStatus1Response&&) = default;

      /**\fn getStatus
       * \brief
       *    Get the motor status
       * 
       * \return
       *    Motor status of the actuator
      */
      [[nodiscard]]
      MotorStatus1 getStatus() const noexcept;
  };

  constexpr GetMotorStatus1Response::GetMotorStatus1Response(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if (data[0] != CommandType::READ_MOTOR_STATUS_1_AND_ERROR_FLAG) {
      throw ProtocolException("Unexpected response to get motor status 1 request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_MOTOR_STATUS_1_RESPONSE
