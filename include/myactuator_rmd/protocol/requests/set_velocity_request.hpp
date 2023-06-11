/**
 * \file set_velocity_request.hpp
 * \mainpage
 *    Request for setting the velocity of the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_VELOCITY_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_VELOCITY_REQUEST
#pragma once

#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class SetVelocityRequest
   * \brief
   *    Request for setting the velocity of the actuator
  */
  class SetVelocityRequest: public Request<CommandType::SPEED_CLOSED_LOOP_CONTROL> {
    public:
      /**\fn SetVelocityRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] speed
       *    The velocity set-point in degree per second [-1320.00, 1320.00]
      */
      SetVelocityRequest(float const speed);
      /**\fn SetVelocityRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetVelocityRequest(std::array<std::uint8_t,8> const& data);
      SetVelocityRequest() = delete;
      SetVelocityRequest(SetVelocityRequest const&) = default;
      SetVelocityRequest& operator = (SetVelocityRequest const&) = default;
      SetVelocityRequest(SetVelocityRequest&&) = default;
      SetVelocityRequest& operator = (SetVelocityRequest&&) = default;

      /**\fn getSpeed
       * \brief
       *    Get the velocity set-point
       * 
       * \return
       *    The speed for the motion in degree per second [-1320.0, 1320.0]
      */
      [[nodiscard]]
      float getSpeed() const noexcept;
  };

  constexpr SetVelocityRequest::SetVelocityRequest(std::array<std::uint8_t,8> const& data)
  : Request{data} {
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_VELOCITY_REQUEST
