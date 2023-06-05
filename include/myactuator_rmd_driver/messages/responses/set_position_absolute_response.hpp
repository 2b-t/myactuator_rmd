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

#include "myactuator_rmd_driver/messages/response.hpp"


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
      constexpr SetPositionAbsoluteResponse(std::array<std::uint8_t,8> const& data) noexcept;
      SetPositionAbsoluteResponse() = delete;
      SetPositionAbsoluteResponse(SetPositionAbsoluteResponse const&) = default;
      SetPositionAbsoluteResponse& operator = (SetPositionAbsoluteResponse const&) = default;
      SetPositionAbsoluteResponse(SetPositionAbsoluteResponse&&) = default;
      SetPositionAbsoluteResponse& operator = (SetPositionAbsoluteResponse&&) = default;
  };

  constexpr SetPositionAbsoluteResponse::SetPositionAbsoluteResponse(std::array<std::uint8_t,8> const& data) noexcept
  : Response{data} {
    // TODO(tobit)
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__SET_POSITION_ABSOLUTE_RESPONSE
