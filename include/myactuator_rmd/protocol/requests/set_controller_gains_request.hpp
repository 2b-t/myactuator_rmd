/**
 * \file set_controller_gains_request.hpp
 * \mainpage
 *    Contains request for setting controller gains
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_CONTROLLER_GAINS_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_CONTROLLER_GAINS_REQUEST
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/requests/set_gains_request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class SetControllerGainsRequest
   * \brief
   *    Request for setting controller gains persistently by writing to the actuator's RAM
  */
  class SetControllerGainsRequest: public SetGainsRequest<CommandType::WRITE_PID_PARAMETERS_TO_RAM> {
    public:
      /**\fn SetControllerGainsRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] gains
       *    Gains that the actuator should be set to
      */
      constexpr SetControllerGainsRequest(Gains const& gains) noexcept;
      /**\fn SetControllerGainsRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetControllerGainsRequest(std::array<std::uint8_t,8> const& data) noexcept;
      SetControllerGainsRequest() = delete;
      SetControllerGainsRequest(SetControllerGainsRequest const&) = default;
      SetControllerGainsRequest& operator = (SetControllerGainsRequest const&) = default;
      SetControllerGainsRequest(SetControllerGainsRequest&&) = default;
      SetControllerGainsRequest& operator = (SetControllerGainsRequest&&) = default;
  };

  constexpr SetControllerGainsRequest::SetControllerGainsRequest(Gains const& gains) noexcept
  : SetGainsRequest{gains} {
    return;
  }

  constexpr SetControllerGainsRequest::SetControllerGainsRequest(std::array<std::uint8_t,8> const& data) noexcept
  : SetGainsRequest{data} {
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_CONTROLLER_GAINS_REQUEST
