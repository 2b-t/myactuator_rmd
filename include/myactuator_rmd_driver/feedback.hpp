/**
 * \file feedback.hpp
 * \mainpage
 *    Contains struct for closed-loop control feedback
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__FEEDBACK
#define MYACTUATOR_RMD_DRIVER__FEEDBACK
#pragma once


namespace myactuator_rmd_driver {

  /**\class Feedback
   * \brief
   *    Closed-loop control feedback from actuator
  */
  class Feedback {
    public:
      /**\fn Feedback
       * \brief
       *    Class constructor
       * 
       * \param[in] temperature_
       *    The temperature of the actuator in degree Celsius with a resolution of 1 deg C
       * \param[in] current_
       *    The current currently used by the actuator in Ampere with a resolution of 0.01A
       * \param[in] shaft_speed_
       *    The output shaft velocity in degree per second with a resolution of 1dps
       * \param[in] shaft_angle_
       *    The output shaft angle in degrees with a resolution of 1 deg and a maximum range of 32767
      */
      constexpr Feedback(int const temperature_ = 0, float const current_ = 0.0f, float const shaft_speed_ = 0.0f, float const shaft_angle_ = 0.0f) noexcept;
      Feedback(Feedback const&) = default;
      Feedback& operator = (Feedback const&) = default;
      Feedback(Feedback&&) = default;
      Feedback& operator = (Feedback&&) = default;

      int temperature;
      float current;
      float shaft_speed;
      float shaft_angle;
  };

  constexpr Feedback::Feedback(int const temperature_, float const current_, float const shaft_speed_, float const shaft_angle_) noexcept
  : temperature{temperature_}, current{current_}, shaft_speed{shaft_speed_}, shaft_angle{shaft_angle_} {
    return;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__FEEDBACK
