/**
 * \file set_controller_gains_persistently_request.hpp
 * \mainpage
 *    Contains request for setting controller gains persistently
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_CONTROLLER_GAINS_PERSISTENTLY_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_CONTROLLER_GAINS_PERSISTENTLY_REQUEST
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/requests/set_gains_request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class SetControllerGainsPersistentlyRequest
   * \brief
   *    Request for setting controller gains persistently by writing to the actuator's ROM
  */
  class SetControllerGainsPersistentlyRequest: public SetGainsRequest<CommandType::WRITE_PID_PARAMETERS_TO_ROM> {
    public:
      /**\fn SetControllerGainsPersistentlyRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] gains
       *    Gains that the actuator should be set to
      */
      constexpr SetControllerGainsPersistentlyRequest(Gains const& gains) noexcept;
      /**\fn SetControllerGainsPersistentlyRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetControllerGainsPersistentlyRequest(std::array<std::uint8_t,8> const& data) noexcept;
      SetControllerGainsPersistentlyRequest() = delete;
      SetControllerGainsPersistentlyRequest(SetControllerGainsPersistentlyRequest const&) = default;
      SetControllerGainsPersistentlyRequest& operator = (SetControllerGainsPersistentlyRequest const&) = default;
      SetControllerGainsPersistentlyRequest(SetControllerGainsPersistentlyRequest&&) = default;
      SetControllerGainsPersistentlyRequest& operator = (SetControllerGainsPersistentlyRequest&&) = default;
  };

  constexpr SetControllerGainsPersistentlyRequest::SetControllerGainsPersistentlyRequest(Gains const& gains) noexcept
  : SetGainsRequest{gains} {
    return;
  }

  constexpr SetControllerGainsPersistentlyRequest::SetControllerGainsPersistentlyRequest(std::array<std::uint8_t,8> const& data) noexcept
  : SetGainsRequest{data} {
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_CONTROLLER_GAINS_PERSISTENTLY_REQUEST
