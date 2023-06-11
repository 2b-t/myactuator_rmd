/**
 * \file get_motor_model_response.hpp
 * \mainpage
 *    Contains response for reading the motor model
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSES__GET_MOTOR_MODEL_RESPONSE
#define MYACTUATOR_RMD__PROTOCOL__RESPONSES__GET_MOTOR_MODEL_RESPONSE
#pragma once

#include <array>
#include <cstdint>
#include <string>

#include "myactuator_rmd/protocol/responses/response.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  /**\class GetMotorModelResponse
   * \brief
   *    Response to request for reading the motor model
  */
  class GetMotorModelResponse: public Response {
    public:
      /**\fn GetMotorModelResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr GetMotorModelResponse(std::array<std::uint8_t,8> const& data);
      GetMotorModelResponse() = delete;
      GetMotorModelResponse(GetMotorModelResponse const&) = default;
      GetMotorModelResponse& operator = (GetMotorModelResponse const&) = default;
      GetMotorModelResponse(GetMotorModelResponse&&) = default;
      GetMotorModelResponse& operator = (GetMotorModelResponse&&) = default;

      /**\fn getMotorModel
       * \brief
       *    Get the motor model
       * 
       * \return
       *    The version string of the motor model
      */
      [[nodiscard]]
      std::string getVersion() const noexcept;
  };

  constexpr GetMotorModelResponse::GetMotorModelResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if (data[0] != CommandType::READ_MOTOR_MODEL) {
      throw ProtocolException("Unexpected response to read motor model request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES__GET_MOTOR_MODEL_RESPONSE
