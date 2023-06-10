/**
 * \file get_controller_gains_request.hpp
 * \mainpage
 *    Request for reading the currently used controller gains
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__GET_CONTROLLER_GAINS_REQUEST
#define MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__GET_CONTROLLER_GAINS_REQUEST
#pragma once

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/request.hpp"


namespace myactuator_rmd_driver {

  /**\class GetControllerGainsRequest
   * \brief
   *    Request for reading the controller gains
  */
  class GetControllerGainsRequest: public Request<CommandType::READ_PID_PARAMETERS> {
    public:
      /**\fn GetControllerGainsRequest
       * \brief
       *    Class constructor
      */
      constexpr GetControllerGainsRequest();
      GetControllerGainsRequest(GetControllerGainsRequest const&) = default;
      GetControllerGainsRequest& operator = (GetControllerGainsRequest const&) = default;
      GetControllerGainsRequest(GetControllerGainsRequest&&) = default;
      GetControllerGainsRequest& operator = (GetControllerGainsRequest&&) = default;
  };

  constexpr GetControllerGainsRequest::GetControllerGainsRequest()
  : Request{} {
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__GET_CONTROLLER_GAINS_REQUEST
