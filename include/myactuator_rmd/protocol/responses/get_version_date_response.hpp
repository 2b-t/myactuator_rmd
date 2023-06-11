/**
 * \file get_version_date_response.hpp
 * \mainpage
 *    Response to request for getting the actuator's version date
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSES__GET_VERSION_DATE_RESPONSE
#define MYACTUATOR_RMD__PROTOCOL__RESPONSES__GET_VERSION_DATE_RESPONSE
#pragma once

#include <array>
#include <cstdint>
#include <cstring>

#include "myactuator_rmd/protocol/responses/response.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  /**\class GetVersionDateResponse
   * \brief
   *    Response to request for getting the actuator's version date
  */
  class GetVersionDateResponse: public Response {
    public:
      /**\fn VersionDateResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr GetVersionDateResponse(std::array<std::uint8_t,8> const& data);
      GetVersionDateResponse() = delete;
      GetVersionDateResponse(GetVersionDateResponse const&) = default;
      GetVersionDateResponse& operator = (GetVersionDateResponse const&) = default;
      GetVersionDateResponse(GetVersionDateResponse&&) = default;
      GetVersionDateResponse& operator = (GetVersionDateResponse&&) = default;

      /**\fn getVersion
       * \brief
       *    Get the version date as an integer
       * 
       * \return
       *    The version date as an integer number
      */
      [[nodiscard]]
      std::uint32_t getVersion() const noexcept;
  };

  constexpr GetVersionDateResponse::GetVersionDateResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if ((data[0] != CommandType::READ_SYSTEM_SOFTWARE_VERSION_DATE) || (data[1] != 0x00) || (data[2] != 0x00) || (data[3] != 0x00)) {
      throw ProtocolException("Unexpected response to read version date request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES__GET_VERSION_DATE_RESPONSE
