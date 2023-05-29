/**
 * \file response.hpp
 * \mainpage
 *    Contains base class for the responses sent from the actuator to the driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSE
#define MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSE
#pragma once

#include <array>
#include <cstdint>
#include <cstring>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/message.hpp"


namespace myactuator_rmd_driver {

  class Response: public Message {
    protected:
      /**\fn Response
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the CAN node
      */
      constexpr Response(std::array<std::uint8_t,8> const& data) noexcept;
      Response() = delete;
      Response(Response const&) = default;
      Response& operator = (Response const&) = default;
      Response(Response&&) = default;
      Response& operator = (Response&&) = default;
  };

  class VersionDateResponse: public Response {
    public:
      VersionDateResponse(std::array<std::uint8_t,8> const& data);
      VersionDateResponse() = delete;
      VersionDateResponse(VersionDateResponse const&) = default;
      VersionDateResponse& operator = (VersionDateResponse const&) = default;
      VersionDateResponse(VersionDateResponse&&) = default;
      VersionDateResponse& operator = (VersionDateResponse&&) = default;

      constexpr std::uint32_t getVersion() const noexcept;
  };

  constexpr std::uint32_t VersionDateResponse::getVersion() const noexcept {
    std::uint32_t version {};
    std::memcpy(&version, &data_[4], sizeof(std::uint32_t));
    return version;
  }

  class StopMotorResponse: public Response {
    public:
      StopMotorResponse(std::array<std::uint8_t,8> const& data);
      StopMotorResponse() = delete;
      StopMotorResponse(StopMotorResponse const&) = default;
      StopMotorResponse& operator = (StopMotorResponse const&) = default;
      StopMotorResponse(StopMotorResponse&&) = default;
      StopMotorResponse& operator = (StopMotorResponse&&) = default;
  };

  class ShutdownMotorResponse: public Response {
    public:
      ShutdownMotorResponse(std::array<std::uint8_t,8> const& data);
      ShutdownMotorResponse() = delete;
      ShutdownMotorResponse(ShutdownMotorResponse const&) = default;
      ShutdownMotorResponse& operator = (ShutdownMotorResponse const&) = default;
      ShutdownMotorResponse(ShutdownMotorResponse&&) = default;
      ShutdownMotorResponse& operator = (ShutdownMotorResponse&&) = default;
  };

  class SetPositionAbsoluteResponse: public Response {
    public:
      SetPositionAbsoluteResponse(std::array<std::uint8_t,8> const& data);
      SetPositionAbsoluteResponse() = delete;
      SetPositionAbsoluteResponse(SetPositionAbsoluteResponse const&) = default;
      SetPositionAbsoluteResponse& operator = (SetPositionAbsoluteResponse const&) = default;
      SetPositionAbsoluteResponse(SetPositionAbsoluteResponse&&) = default;
      SetPositionAbsoluteResponse& operator = (SetPositionAbsoluteResponse&&) = default;
  };

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSE