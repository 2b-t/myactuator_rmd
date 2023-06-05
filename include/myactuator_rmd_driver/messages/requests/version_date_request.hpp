/**
 * \file version_date_request.hpp
 * \mainpage
 *    Request for getting the actuator's version date
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__VERSION_DATE_REQUEST
#define MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__VERSION_DATE_REQUEST
#pragma once

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/request.hpp"


namespace myactuator_rmd_driver {

  /**\class VersionDateRequest
   * \brief
   *    Request for getting the actuator's version date
  */
  class VersionDateRequest: public Request<CommandType::SYSTEM_SOFTWARE_VERSION_DATE> {
    public:
      /**\fn VersionDateRequest
       * \brief
       *    Class constructor
      */
      constexpr VersionDateRequest() noexcept;
      VersionDateRequest(VersionDateRequest const&) = default;
      VersionDateRequest& operator = (VersionDateRequest const&) = default;
      VersionDateRequest(VersionDateRequest&&) = default;
      VersionDateRequest& operator = (VersionDateRequest&&) = default;
  };

  constexpr VersionDateRequest::VersionDateRequest() noexcept
  : Request{} {
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__VERSION_DATE_REQUEST
