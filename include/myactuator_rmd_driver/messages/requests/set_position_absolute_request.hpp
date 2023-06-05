/**
 * \file set_position_absolute_request.hpp
 * \mainpage
 *    Request for setting the absolute position of the actuator with a given maximum speed
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__SET_POSITION_ABSOLUTE_REQUEST
#define MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__SET_POSITION_ABSOLUTE_REQUEST
#pragma once

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/request.hpp"


namespace myactuator_rmd_driver {

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
      SetPositionAbsoluteRequest() = delete;
      SetPositionAbsoluteRequest(SetPositionAbsoluteRequest const&) = default;
      SetPositionAbsoluteRequest& operator = (SetPositionAbsoluteRequest const&) = default;
      SetPositionAbsoluteRequest(SetPositionAbsoluteRequest&&) = default;
      SetPositionAbsoluteRequest& operator = (SetPositionAbsoluteRequest&&) = default;
  };

}

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS__SET_POSITION_ABSOLUTE_REQUEST
