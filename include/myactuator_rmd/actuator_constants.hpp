/**
 * \file actuator_constants.hpp
 * \mainpage
 *    Contains technical specifications for the different actuators
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__ACTUATOR_CONSTANTS
#define MYACTUATOR_RMD__ACTUATOR_CONSTANTS
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  /**\class X10S2V3
   * \brief
   *    Constants for the X10 S2 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x10-s2-1-35
  */
  class X10S2V3 {
    public:
      static constexpr float reducer_ratio {35/1};
      static constexpr float speed_constant {30}; // in rpm/V
      static constexpr float torque_constant {0.32}; // in Nm/A
      static constexpr float rotor_inertia {5675}; // in gcm2
  };

  /**\class X4V3
   * \brief
   *    Constants for the X4 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x4-1-6
  */
  class X4V3 {
    public:
      static constexpr float reducer_ratio {6/1};
      static constexpr float speed_constant {200}; // in rpm/V
      static constexpr float torque_constant {0.35}; // in Nm/A
      static constexpr float rotor_inertia {200}; // in gcm2
  };

  /**\class X6V3
   * \brief
   *    Constants for the X6 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x6-1-8
  */
  class X6V3 {
    public:
      static constexpr float reducer_ratio {8/1};
      static constexpr float speed_constant {62}; // in rpm/V
      static constexpr float torque_constant {0.17}; // in Nm/A
      static constexpr float rotor_inertia {850}; // in gcm2
  };

  /**\class X8ProV2
   * \brief
   *    Constants for the X8 Pro V2 actuator
   *    See https://www.myactuator.com/product-page/x8-pro-1-9
  */
  class X8ProV2 {
    public:
      static constexpr float reducer_ratio {9/1};
      static constexpr float speed_constant {30}; // in rpm/V
      static constexpr float torque_constant {2.6}; // in Nm/A
      static constexpr float rotor_inertia {3400}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {20};
  };

  /**\class X8S2V3
   * \brief
   *    Constants for the X8 S2 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x8-s2-1-36
  */
  class X8S2V3 {
    public:
      static constexpr float reducer_ratio {36/1};
      static constexpr float speed_constant {33}; // in rpm/V
      static constexpr float torque_constant {0.30}; // in Nm/A
      static constexpr float rotor_inertia {2670}; // in gcm2
  };

  /**\class X6V2
   * \brief
   *    Constants for the X6 V2 actuator
   *    See https://www.myactuator.com/product-page/rmd-x6
  */
  class X6V2 {
    public:
      static constexpr float reducer_ratio {6/1};
      static constexpr float speed_constant {60}; // in rpm/V
      static constexpr float torque_constant {0.88}; // in Nm/A
      static constexpr float rotor_inertia {800}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };

  /**\class X8V2
   * \brief
   *    Constants for the X8 V2 actuator
   *    See https://www.myactuator.com/product-page/rmd-x8-1-9
  */
  class X8V2 {
    public:
      static constexpr float reducer_ratio {9/1};
      static constexpr float speed_constant {40}; // in rpm/V
      static constexpr float torque_constant {2.09}; // in Nm/A
      static constexpr float rotor_inertia {2600}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {21};
  };

  /**\class X10V3
   * \brief
   *    Constants for the X10 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x10
  */
  class X10V3 {
    public:
      static constexpr float reducer_ratio {7/1};
      static constexpr float speed_constant {30}; // in rpm/V
      static constexpr float torque_constant {0.32}; // in Nm/A
      static constexpr float rotor_inertia {5675}; // in gcm2
  };

  /**\class X4V2
   * \brief
   *    Constants for the X4 V2 actuator
   *    See https://www.myactuator.com/product-page/rmd-x4-1-10
  */
  class X4V2 {
    public:
      static constexpr float reducer_ratio {10/1};
      static constexpr float speed_constant {12.5}; // in rpm/V
      static constexpr float torque_constant {0.625}; // in Nm/A
      static constexpr float rotor_inertia {105}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };

  /**\class X6S2V2
   * \brief
   *    Constants for the X6-S2 V2 actuator
   *    See https://www.myactuator.com/product-page/rmd-x6-s2
  */
  class X6S2V2 {
    public:
      static constexpr float reducer_ratio {36/1};
      static constexpr float speed_constant {135}; // in rpm/V
      static constexpr float torque_constant {6.92}; // in Nm/A
      static constexpr float rotor_inertia {800}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };

  /**\class X8HV3
   * \brief
   *    Constants for the X8-H V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x8
  */
  class X8HV3 {
    public:
      static constexpr float reducer_ratio {6.2/1};
      static constexpr float speed_constant {33}; // in rpm/V
      static constexpr float torque_constant {0.30}; // in Nm/A
      static constexpr float rotor_inertia {2670}; // in gcm2
  };

  /**\class X8ProHV3
   * \brief
   *    Constants for the X8-Pro-H V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x8-pro
  */
  class X8ProHV3 {
    public:
      static constexpr float reducer_ratio {6.2/1};
      static constexpr float speed_constant {30}; // in rpm/V
      static constexpr float torque_constant {0.29}; // in Nm/A
      static constexpr float rotor_inertia {3400}; // in gcm2
  };

}

#endif // MYACTUATOR_RMD__ACTUATOR_CONSTANTS
