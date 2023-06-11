/**
 * \file get_controller_gains_response.hpp
 * \mainpage
 *    Response to request for reading the current controller gains
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_CONTROLLER_GAINS_RESPONSE
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_CONTROLLER_GAINS_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/protocol/responses/gains_response.hpp"
#include "myactuator_rmd_driver/protocol/command_type.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class GetControllerGainsResponse
   * \brief
   *    Response to request for reading the current controller gains
  */
  class GetControllerGainsResponse: public GainsResponse {
    public:
      /**\fn GetControllerGainsResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr GetControllerGainsResponse(std::array<std::uint8_t,8> const& data);
      GetControllerGainsResponse() = delete;
      GetControllerGainsResponse(GetControllerGainsResponse const&) = default;
      GetControllerGainsResponse& operator = (GetControllerGainsResponse const&) = default;
      GetControllerGainsResponse(GetControllerGainsResponse&&) = default;
      GetControllerGainsResponse& operator = (GetControllerGainsResponse&&) = default;
  };

  constexpr GetControllerGainsResponse::GetControllerGainsResponse(std::array<std::uint8_t,8> const& data)
  : GainsResponse{data} {
    if (data[0] != CommandType::READ_PID_PARAMETERS) {
      throw ProtocolException("Unexpected response to get controller gains request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__RESPONSES__GET_CONTROLLER_GAINS_RESPONSE
