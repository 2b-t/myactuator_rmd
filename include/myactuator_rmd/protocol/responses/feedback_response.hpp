/**
 * \file feedback_response.hpp
 * \mainpage
 *    Contains base class for all responses containing a feedback
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSES__FEEDBACK_RESPONSE
#define MYACTUATOR_RMD__PROTOCOL__RESPONSES__FEEDBACK_RESPONSE
#pragma once

#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/protocol/responses/response.hpp"


namespace myactuator_rmd {

  /**\class FeedbackResponse
   * \brief
   *    Base class for all responses containing a feedback
  */
  class FeedbackResponse: public Response {
    public:
      /**\fn getStatus
       * \brief
       *    Get the feedback
       * 
       * \return
       *    Feedback from the actuator
      */
      [[nodiscard]]
      Feedback getStatus() const noexcept;

    protected:
      using Response::Response;
  };

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES__FEEDBACK_RESPONSE
