/**
 * \file set_velocity_response.hpp
 * \mainpage
 *    Response to request for setting the velocity of the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SET_VELOCITY_RESPONSE
#define MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SET_VELOCITY_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/responses/feedback_response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class SetVelocityResponse
   * \brief
   *    Response to request for setting the velocity of the actuator
  */
  class SetVelocityResponse: public FeedbackResponse {
    public:
      /**\fn SetVelocityResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetVelocityResponse(std::array<std::uint8_t,8> const& data);
      SetVelocityResponse() = delete;
      SetVelocityResponse(SetVelocityResponse const&) = default;
      SetVelocityResponse& operator = (SetVelocityResponse const&) = default;
      SetVelocityResponse(SetVelocityResponse&&) = default;
      SetVelocityResponse& operator = (SetVelocityResponse&&) = default;
  };

  constexpr SetVelocityResponse::SetVelocityResponse(std::array<std::uint8_t,8> const& data)
  : FeedbackResponse{data} {
    if (data[0] != CommandType::SPEED_CLOSED_LOOP_CONTROL) {
      throw ParsingException("Unexpected response to set velocity request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SET_VELOCITY_RESPONSE
