/**
 * \file feedback.hpp
 * \mainpage
 *    Contains class for closed-loop control feedback
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
       * \param[in] temperature
       *    The temperature of the actuator
       * \param[in] current
       *    The current currently used by the actuator
       * \param[in] shaft_speed
       *    The output shaft velocity
       * \param[in] shaft_angle
       *    The output shaft angle
      */
      constexpr Feedback(float const temperature, float const current, float const shaft_speed, float const shaft_angle) noexcept;
      Feedback() = delete;
      Feedback(Feedback const&) = default;
      Feedback& operator = (Feedback const&) = default;
      Feedback(Feedback&&) = default;
      Feedback& operator = (Feedback&&) = default;

      /**\fn getTemperature
       * \brief
       *    Get the temperature
       * 
       * \return
       *    Temperature of the actuator in degree Celsius with a resolution of 1 deg C
      */
      [[nodiscard]]
      constexpr float getTemperature() const noexcept;

      /**\fn getTorqueCurrent
       * \brief
       *    Get the torque current
       * 
       * \return
       *    Torque current of the actuator in Ampere with a resolution of 0.01A
      */
      [[nodiscard]]
      constexpr float getTorqueCurrent() const noexcept;

      /**\fn getShaftSpeed
       * \brief
       *    Get the speed of the shaft
       * 
       * \return
       *    The current shaft speed in degree per second with a resolution of 1dps
      */
      [[nodiscard]]
      constexpr float getShaftSpeed() const noexcept;

      /**\fn getShaftAngle
       * \brief
       *    Get the shaft angle
       * 
       * \return
       *    The current shaft angle in degrees with a resolution of 1 deg and a maximum range of 32767
      */
      [[nodiscard]]
      constexpr float getShaftAngle() const noexcept;

    protected:
      float temperature_;
      float current_;
      float shaft_speed_;
      float shaft_angle_;
  };

  constexpr Feedback::Feedback(float const temperature, float const current, float const shaft_speed, float const shaft_angle) noexcept
  : temperature_{temperature}, current_{current}, shaft_speed_{shaft_speed}, shaft_angle_{shaft_angle} {
    return;
  }

  constexpr float Feedback::getTemperature() const noexcept {
    return temperature_;
  }

  constexpr float Feedback::getTorqueCurrent() const noexcept {
    return current_;
  }

  constexpr float Feedback::getShaftSpeed() const noexcept {
    return shaft_speed_;
  }

  constexpr float Feedback::getShaftAngle() const noexcept {
    return shaft_angle_;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__FEEDBACK
