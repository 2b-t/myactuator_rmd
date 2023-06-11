/**
 * \file gains_response.hpp
 * \mainpage
 *    Contains base class for all responses with controller gains
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSES__GAINS_RESPONSE
#define MYACTUATOR_RMD__PROTOCOL__RESPONSES__GAINS_RESPONSE
#pragma once

#include <cstdint>

#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/responses/response.hpp"


namespace myactuator_rmd {

  /**\class GainsResponse
   * \brief
   *    Base class for all responses with controller gains
  */
  class GainsResponse: public Response {
    public:
      /**\fn getGains
       * \brief
       *    Get the controller gains
       * 
       * \return
       *    The controller gains
      */
      [[nodiscard]]
      constexpr Gains getGains() const noexcept;

    protected:
      using Response::Response;
  };

  constexpr Gains GainsResponse::getGains() const noexcept {
    auto const current_kp {this->data_[2]};
    auto const current_ki {this->data_[3]};
    auto const speed_kp {this->data_[4]};
    auto const speed_ki {this->data_[5]};
    auto const position_kp {this->data_[6]};
    auto const position_ki {this->data_[7]};
    return Gains{current_kp, current_ki, speed_kp, speed_ki, position_kp, position_ki};
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES__GAINS_RESPONSE
