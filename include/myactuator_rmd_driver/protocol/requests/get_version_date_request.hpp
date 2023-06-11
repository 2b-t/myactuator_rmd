/**
 * \file get_version_date_request.hpp
 * \mainpage
 *    Request for getting the actuator's version date
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__GET_VERSION_DATE_REQUEST
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__GET_VERSION_DATE_REQUEST
#pragma once

#include "myactuator_rmd_driver/protocol/requests/request.hpp"
#include "myactuator_rmd_driver/protocol/command_type.hpp"


namespace myactuator_rmd_driver {

  /**\class GetVersionDateRequest
   * \brief
   *    Request for getting the actuator's version date
  */
  class GetVersionDateRequest: public Request<CommandType::READ_SYSTEM_SOFTWARE_VERSION_DATE> {
    public:
      /**\fn VersionDateRequest
       * \brief
       *    Class constructor
      */
      constexpr GetVersionDateRequest() noexcept;
      GetVersionDateRequest(GetVersionDateRequest const&) = default;
      GetVersionDateRequest& operator = (GetVersionDateRequest const&) = default;
      GetVersionDateRequest(GetVersionDateRequest&&) = default;
      GetVersionDateRequest& operator = (GetVersionDateRequest&&) = default;
  };

  constexpr GetVersionDateRequest::GetVersionDateRequest() noexcept
  : Request{} {
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS__GET_VERSION_DATE_REQUEST
