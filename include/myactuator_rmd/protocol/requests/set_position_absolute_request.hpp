/**
 * \file set_position_absolute_request.hpp
 * \mainpage
 *    Request for setting the absolute position of the actuator with a given maximum speed
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_POSITION_ABSOLUTE_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_POSITION_ABSOLUTE_REQUEST
#pragma once

#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class SetPositionAbsoluteRequest
   * \brief
   *    Request for setting the absolute position of the actuator with a given maximum speed
  */
  class SetPositionAbsoluteRequest: public Request<CommandType::ABSOLUTE_POSITION_CLOSED_LOOP_CONTROL> {
    public:
      /**\fn SetPositionAbsoluteRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] position
       *    The position set-point in degree [0.00, 360.00]
       * \param[in] max_speed
       *    The maximum speed for the motion in degree per second [0.0, 1320.0]
      */
      SetPositionAbsoluteRequest(float const position, float const max_speed);
      /**\fn SetPositionAbsoluteRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetPositionAbsoluteRequest(std::array<std::uint8_t,8> const& data);
      SetPositionAbsoluteRequest() = delete;
      SetPositionAbsoluteRequest(SetPositionAbsoluteRequest const&) = default;
      SetPositionAbsoluteRequest& operator = (SetPositionAbsoluteRequest const&) = default;
      SetPositionAbsoluteRequest(SetPositionAbsoluteRequest&&) = default;
      SetPositionAbsoluteRequest& operator = (SetPositionAbsoluteRequest&&) = default;

      /**\fn getMaxSpeed
       * \brief
       *    Get the maximum speed
       * 
       * \return
       *    The maximum speed for the motion in degree per second [-1320.0, 1320.0]
      */
      [[nodiscard]]
      float getMaxSpeed() const noexcept;

      /**\fn getPosition
       * \brief
       *    Get the position
       * 
       * \return
       *    The position set-point in degree [-360.00, 360.00]
      */
      [[nodiscard]]
      float getPosition() const noexcept;
  };

  constexpr SetPositionAbsoluteRequest::SetPositionAbsoluteRequest(std::array<std::uint8_t,8> const& data)
  : Request{data} {
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_POSITION_ABSOLUTE_REQUEST
