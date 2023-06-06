/**
 * \file set_position_absolute_response.hpp
 * \mainpage
 *    Response to request for setting the absolute position of the actuator with a given maximum speed
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SET_POSITION_ABSOLUTE_RESPONSE
#define MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SET_POSITION_ABSOLUTE_RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class SetPositionAbsoluteResponse
   * \brief
   *    Response to request for setting the absolute position of the actuator with a given maximum speed
  */
  class SetPositionAbsoluteResponse: public Response {
    public:
      /**\fn SetPositionAbsoluteResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetPositionAbsoluteResponse(std::array<std::uint8_t,8> const& data);
      SetPositionAbsoluteResponse() = delete;
      SetPositionAbsoluteResponse(SetPositionAbsoluteResponse const&) = default;
      SetPositionAbsoluteResponse& operator = (SetPositionAbsoluteResponse const&) = default;
      SetPositionAbsoluteResponse(SetPositionAbsoluteResponse&&) = default;
      SetPositionAbsoluteResponse& operator = (SetPositionAbsoluteResponse&&) = default;

      /**\fn getTemperature
       * \brief
       *    Get the temperature
       * 
       * \return
       *    Temperature of the actuator in degree Celsius with a resolution of 1 deg C
      */
      [[noexcept]]
      float getTemperature() const noexcept;

      /**\fn getTorqueCurrent
       * \brief
       *    Get the torque current
       * 
       * \return
       *    Torque current of the actuator in Ampere with a resolution of 0.01A
      */
      [[noexcept]]
      float getTorqueCurrent() const noexcept;

      /**\fn getShaftSpeed
       * \brief
       *    Get the speed of the shaft
       * 
       * \return
       *    The current shaft speed in degree per second with a resolution of 1dps
      */
      [[noexcept]]
      float getShaftSpeed() const noexcept;

      /**\fn getShaftAngle
       * \brief
       *    Get the shaft angle
       * 
       * \return
       *    The current shaft angle in degrees with a resolution of 1 deg and a maximum range of 32767
      */
      [[noexcept]]
      float getShaftAngle() const noexcept;
  };

  constexpr SetPositionAbsoluteResponse::SetPositionAbsoluteResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if (data[0] != CommandType::ABSOLUTE_POSITION_CLOSED_LOOP_CONTROL) {
      throw ParsingException("Unexpected response to set absolute position request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SET_POSITION_ABSOLUTE_RESPONSE
