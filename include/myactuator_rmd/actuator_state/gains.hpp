/**
 * \file gains.hpp
 * \mainpage
 *    Contains struct for control loop gains
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__GAINS
#define MYACTUATOR_RMD__GAINS
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  /**\class PiGains
   * \brief
   *    Proportional and integral gains for a PI-controller
  */
  class PiGains {
    public:
      /**\fn PiGains
       * \brief
       *    Class constructor
       * 
       * \param[in] kp_
       *    The proportional gain
       * \param[in] ki_
       *    The integral gain
      */
      constexpr PiGains(std::uint8_t const& kp_ = 0, std::uint8_t const& ki_ = 0) noexcept;
      PiGains(PiGains const&) = default;
      PiGains& operator = (PiGains const&) = default;
      PiGains(PiGains&&) = default;
      PiGains& operator = (PiGains&&) = default;

      std::uint8_t kp;
      std::uint8_t ki;
  };

  /**\class Gains
   * \brief
   *    Control loop gains
  */
  class Gains {
    public:
      /**\fn Gains
       * \brief
       *    Class constructor
       * 
       * \param[in] current_
       *    The PI-gains for current control
       * \param[in] speed_
       *    The PI-gains for speed control
       * \param[in] position_
       *    The PI-gains for position control
      */
      constexpr Gains(PiGains const& current_, PiGains const& speed_, PiGains const& position_) noexcept;
      /**\fn Gains
       * \brief
       *    Class constructor
       * 
       * \param[in] current_kp
       *    The proportional gain for current control
       * \param[in] current_ki
       *    The integral gain for current control
       * \param[in] speed_kp
       *    The proportional gain for speed control
       * \param[in] speed_ki
       *    The integral gain for speed control
       * \param[in] position_kp
       *    The proportional gain for position control
       * \param[in] position_ki
       *    The integral gain for position control
      */
      constexpr Gains(std::uint8_t const current_kp = 0, std::uint8_t const current_ki = 0,
                      std::uint8_t const speed_kp = 0, std::uint8_t const speed_ki = 0,
                      std::uint8_t const position_kp = 0, std::uint8_t const position_ki = 0) noexcept;
      Gains(Gains const&) = default;
      Gains& operator = (Gains const&) = default;
      Gains(Gains&&) = default;
      Gains& operator = (Gains&&) = default;

      PiGains current;
      PiGains speed;
      PiGains position;
  };

  constexpr PiGains::PiGains(std::uint8_t const& kp_, std::uint8_t const& ki_) noexcept
  : kp{kp_}, ki{ki_} {
    return;
  }

  constexpr Gains::Gains(PiGains const& current_, PiGains const& speed_, PiGains const& position_) noexcept
  : current{current_}, speed{speed_}, position{position_} {
    return;
  }

  constexpr Gains::Gains(std::uint8_t const current_kp, std::uint8_t const current_ki,
                         std::uint8_t const speed_kp, std::uint8_t const speed_ki,
                         std::uint8_t const position_kp, std::uint8_t const position_ki) noexcept
  : current{current_kp, current_ki}, speed{speed_kp, speed_ki}, position{position_kp, position_ki} {
    return;
  }

}

#endif // MYACTUATOR_RMD__GAINS
