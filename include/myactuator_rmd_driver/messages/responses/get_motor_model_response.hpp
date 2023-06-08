/**
 * \file get_motor_model_response.hpp
 * \mainpage
 *    Contains response for reading the motor model
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__GET_MOTOR_MODEL_RESPONSE
#define MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__GET_MOTOR_MODEL_RESPONSE
#pragma once

#include <array>
#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

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
      throw ParsingException("Unexpected response to read motor model request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__GET_MOTOR_MODEL_RESPONSE
