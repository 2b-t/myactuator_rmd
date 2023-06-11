/**
 * \file motor_status_3.hpp
 * \mainpage
 *    Contains struct with motor status
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__MOTOR_STATUS_3
#define MYACTUATOR_RMD__MOTOR_STATUS_3
#pragma once


namespace myactuator_rmd {

  /**\class MotorStatus3
   * \brief
   *    Motor status
  */
  class MotorStatus3 {
    public:
      /**\fn MotorStatus3
       * \brief
       *    Class constructor
       * 
       * \param[in] temperature_
       *    The temperature of the actuator in degree Celsius with a resolution of 1 deg C
       * \param[in] current_phase_a_
       *    The current in phase A in Ampere with a resolution of 0.01A
       * \param[in] current_phase_b_
       *    The current in phase B in Ampere with a resolution of 0.01A
       * \param[in] current_phase_c_
       *    The current in phase C in Ampere with a resolution of 0.01A
      */
      constexpr MotorStatus3(int const temperature_ = 0, float const current_phase_a_ = 0.0f, 
                             float const current_phase_b_ = 0.0f, float const current_phase_c_ = 0.0f) noexcept;
      MotorStatus3(MotorStatus3 const&) = default;
      MotorStatus3& operator = (MotorStatus3 const&) = default;
      MotorStatus3(MotorStatus3&&) = default;
      MotorStatus3& operator = (MotorStatus3&&) = default;

      int temperature;
      float current_phase_a;
      float current_phase_b;
      float current_phase_c;
  };

  constexpr MotorStatus3::MotorStatus3(int const temperature_, float const current_phase_a_, 
                                       float const current_phase_b_, float const current_phase_c_) noexcept
  : temperature{temperature_}, current_phase_a{current_phase_a_}, current_phase_b{current_phase_b_}, 
    current_phase_c{current_phase_c_} {
    return;
  }

}

#endif // MYACTUATOR_RMD__MOTOR_STATUS_3
