/**
 * \file set_controller_gains_response.hpp
 * \mainpage
 *    Response to request for writing the current controller gains to the actuator's RAM
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__SET_CONTROLLER_GAINS_RESPONSE
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__SET_CONTROLLER_GAINS_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/protocol/responses/gains_response.hpp"
#include "myactuator_rmd_driver/protocol/command_type.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class SetControllerGainsResponse
   * \brief
   *    Response to request for writing the current controller gains to the actuator's RAM
  */
  class SetControllerGainsResponse: public GainsResponse {
    public:
      /**\fn SetControllerGainsResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetControllerGainsResponse(std::array<std::uint8_t,8> const& data);
      SetControllerGainsResponse() = delete;
      SetControllerGainsResponse(SetControllerGainsResponse const&) = default;
      SetControllerGainsResponse& operator = (SetControllerGainsResponse const&) = default;
      SetControllerGainsResponse(SetControllerGainsResponse&&) = default;
      SetControllerGainsResponse& operator = (SetControllerGainsResponse&&) = default;
  };

  constexpr SetControllerGainsResponse::SetControllerGainsResponse(std::array<std::uint8_t,8> const& data)
  : GainsResponse{data} {
    if (data[0] != CommandType::WRITE_PID_PARAMETERS_TO_RAM) {
      throw ProtocolException("Unexpected response to set controller gains request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__SET_CONTROLLER_GAINS_RESPONSE
