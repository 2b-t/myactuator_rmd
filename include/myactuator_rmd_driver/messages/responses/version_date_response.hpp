/**
 * \file version_date_response.hpp
 * \mainpage
 *    Response to request for getting the actuator's version date
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__VERSION_DATE_RESPONSE
#define MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__VERSION_DATE_RESPONSE
#pragma once

#include <array>
#include <cstdint>
#include <cstring>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class VersionDateResponse
   * \brief
   *    Response to request for getting the actuator's version date
  */
  class VersionDateResponse: public Response {
    public:
      /**\fn VersionDateResponse
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr VersionDateResponse(std::array<std::uint8_t,8> const& data);
      VersionDateResponse() = delete;
      VersionDateResponse(VersionDateResponse const&) = default;
      VersionDateResponse& operator = (VersionDateResponse const&) = default;
      VersionDateResponse(VersionDateResponse&&) = default;
      VersionDateResponse& operator = (VersionDateResponse&&) = default;

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

  constexpr VersionDateResponse::VersionDateResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if ((data[0] != CommandType::SYSTEM_SOFTWARE_VERSION_DATE) || (data[1] != 0x00) || (data[2] != 0x00) || (data[3] != 0x00)) {
      throw ParsingException("Unexpected response to version date request!");
    }
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__VERSION_DATE_RESPONSE
