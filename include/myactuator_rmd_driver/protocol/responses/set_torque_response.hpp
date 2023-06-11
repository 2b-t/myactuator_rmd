/**
 * \file set_torque_response.hpp
 * \mainpage
 *    Response to request for setting the torque of the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__SET_TORQUE_RESPONSE
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__SET_TORQUE_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/protocol/responses/feedback_response.hpp"
#include "myactuator_rmd_driver/protocol/command_type.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class SetTorqueResponse
   * \brief
   *    Response to request for setting the torque of the actuator
  */
  class SetTorqueResponse: public FeedbackResponse {
    public:
      /**\fn SetPositionAbsoluteResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetTorqueResponse(std::array<std::uint8_t,8> const& data);
      SetTorqueResponse() = delete;
      SetTorqueResponse(SetTorqueResponse const&) = default;
      SetTorqueResponse& operator = (SetTorqueResponse const&) = default;
      SetTorqueResponse(SetTorqueResponse&&) = default;
      SetTorqueResponse& operator = (SetTorqueResponse&&) = default;
  };

  constexpr SetTorqueResponse::SetTorqueResponse(std::array<std::uint8_t,8> const& data)
  : FeedbackResponse{data} {
    if (data[0] != CommandType::TORQUE_CLOSED_LOOP_CONTROL) {
      throw ProtocolException("Unexpected response to set torque request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__SET_TORQUE_RESPONSE
