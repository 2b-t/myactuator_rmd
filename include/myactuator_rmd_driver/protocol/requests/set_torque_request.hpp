/**
 * \file set_torque_request.hpp
 * \mainpage
 *    Request for setting the torque of the actuator by setting a target current
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__SET_TORQUE_REQUEST
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__SET_TORQUE_REQUEST
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/protocol/requests/request.hpp"
#include "myactuator_rmd_driver/protocol/command_type.hpp"


namespace myactuator_rmd_driver {

  /**\class SetTorqueRequest
   * \brief
   *    Request for setting the torque of the actuator by setting a target current
  */
  class SetTorqueRequest: public Request<CommandType::TORQUE_CLOSED_LOOP_CONTROL> {
    public:
      /**\fn SetTorqueRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] current
       *    The current set-point in Ampere [-20.00, 20.00]
      */
      SetTorqueRequest(float const current);
      /**\fn SetPositionAbsoluteRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetTorqueRequest(std::array<std::uint8_t,8> const& data);
      SetTorqueRequest() = delete;
      SetTorqueRequest(SetTorqueRequest const&) = default;
      SetTorqueRequest& operator = (SetTorqueRequest const&) = default;
      SetTorqueRequest(SetTorqueRequest&&) = default;
      SetTorqueRequest& operator = (SetTorqueRequest&&) = default;

      /**\fn getTorqueCurrent
       * \brief
       *    Get the torque current
       * 
       * \return
       *    The torque current in Ampere [-20.00, 20.00]
      */
      [[nodiscard]]
      float getTorqueCurrent() const noexcept;
  };

  constexpr SetTorqueRequest::SetTorqueRequest(std::array<std::uint8_t,8> const& data)
  : Request{data} {
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__SET_TORQUE_REQUEST
