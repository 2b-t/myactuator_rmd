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
      VersionDateResponse(std::array<std::uint8_t,8> const& data);
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
      constexpr std::uint32_t getVersion() const noexcept;
  };

  constexpr std::uint32_t VersionDateResponse::getVersion() const noexcept {
    std::uint32_t version {};
    std::memcpy(&version, &data_[4], sizeof(std::uint32_t));
    return version;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES__VERSION_DATE_RESPONSE
