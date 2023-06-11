/**
 * \file set_gains_request.hpp
 * \mainpage
 *    Contains base class for all requests for setting controller gains
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_GAINS_REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_GAINS_REQUEST
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"


namespace myactuator_rmd {

  /**\class SetGainsRequest
   * \brief
   *    Base class for all requests for setting controller gains
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class SetGainsRequest: public Request<C> {
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
      /**\fn GainsRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] gains
       *    Gains that the actuator should be set to
      */
      constexpr SetGainsRequest(Gains const& gains) noexcept;
      /**\fn GainsRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetGainsRequest(std::array<std::uint8_t,8> const& data) noexcept;
      SetGainsRequest() = delete;
      SetGainsRequest(SetGainsRequest const&) = default;
      SetGainsRequest& operator = (SetGainsRequest const&) = default;
      SetGainsRequest(SetGainsRequest&&) = default;
      SetGainsRequest& operator = (SetGainsRequest&&) = default;
  };

  template <CommandType C>
  constexpr Gains SetGainsRequest<C>::getGains() const noexcept {
    auto const current_kp {this->data_[2]};
    auto const current_ki {this->data_[3]};
    auto const speed_kp {this->data_[4]};
    auto const speed_ki {this->data_[5]};
    auto const position_kp {this->data_[6]};
    auto const position_ki {this->data_[7]};
    return Gains{current_kp, current_ki, speed_kp, speed_ki, position_kp, position_ki};
  }

  template <CommandType C>
  constexpr SetGainsRequest<C>::SetGainsRequest(Gains const& gains) noexcept
  : Request<C>{} {
    this->data_[2] = gains.current.kp;
    this->data_[3] = gains.current.ki;
    this->data_[4] = gains.speed.kp;
    this->data_[5] = gains.speed.ki;
    this->data_[6] = gains.position.kp;
    this->data_[7] = gains.position.ki;
    return;
  }

  template <CommandType C>
  constexpr SetGainsRequest<C>::SetGainsRequest(std::array<std::uint8_t,8> const& data) noexcept
  : Request<C>{data} {
    return;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS__SET_GAINS_REQUEST
