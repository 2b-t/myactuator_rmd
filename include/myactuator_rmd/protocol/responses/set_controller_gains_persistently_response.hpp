/**
 * \file set_controller_gains_persistently_response.hpp
 * \mainpage
 *    Response to request for writing the current controller gains to the actuator's ROM
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSES__SET_CONTROLLER_GAINS_PERSISTENTLY_RESPONSE
#define MYACTUATOR_RMD__PROTOCOL__RESPONSES__SET_CONTROLLER_GAINS_PERSISTENTLY_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/protocol/responses/gains_response.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  /**\class SetControllerGainsPersistentlyResponse
   * \brief
   *    Response to request for writing the current controller gains to the actuator's ROM
  */
  class SetControllerGainsPersistentlyResponse: public GainsResponse {
    public:
      /**\fn SetControllerGainsPersistentlyResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetControllerGainsPersistentlyResponse(std::array<std::uint8_t,8> const& data);
      SetControllerGainsPersistentlyResponse() = delete;
      SetControllerGainsPersistentlyResponse(SetControllerGainsPersistentlyResponse const&) = default;
      SetControllerGainsPersistentlyResponse& operator = (SetControllerGainsPersistentlyResponse const&) = default;
      SetControllerGainsPersistentlyResponse(SetControllerGainsPersistentlyResponse&&) = default;
      SetControllerGainsPersistentlyResponse& operator = (SetControllerGainsPersistentlyResponse&&) = default;
  };

  constexpr SetControllerGainsPersistentlyResponse::SetControllerGainsPersistentlyResponse(std::array<std::uint8_t,8> const& data)
  : GainsResponse{data} {
    if (data[0] != CommandType::WRITE_PID_PARAMETERS_TO_ROM) {
      throw ProtocolException("Unexpected response to set controller gains request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES__SET_CONTROLLER_GAINS_PERSISTENTLY_RESPONSE
