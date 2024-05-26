/**
 * \file actuator_constants.hpp
 * \mainpage
 *    Contains technical specifications for the different actuators
 *    In 2024 the actuators were re-branded, see https://www.myactuator.com/downloads-x-series
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__ACTUATOR_CONSTANTS
#define MYACTUATOR_RMD__ACTUATOR_CONSTANTS
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  ///< X4-series actuators

  /**\class X4V2
   * \brief
   *    Constants for the X4 V2 actuator
   *    See https://www.myactuator.com/product-page/rmd-x4-1-10
  */
  class X4V2 {
    public:
      static constexpr float reducer_ratio {10/1};
      static constexpr float no_load_speed {300}; // in rpm
      static constexpr float rated_speed {250}; // in rpm
      static constexpr float rated_current {1.6}; // in A
      static constexpr float rated_power {27}; // in W
      static constexpr float rated_torque {1}; // in Nm
      static constexpr float speed_constant {12.5}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (manufacturer: 0.625) in Nm/A
      static constexpr float rotor_inertia {105}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };

  /**\class X4V3
   * \brief
   *    Constants for the X4 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x4-1-6
  */
  class X4V3 {
    public:
      static constexpr float reducer_ratio {6/1};
      static constexpr float no_load_speed {600}; // in rpm
      static constexpr float rated_speed {400}; // in rpm
      static constexpr float rated_current {3}; // in A
      static constexpr float rated_power {80}; // in W
      static constexpr float rated_torque {1.2}; // in Nm
      static constexpr float speed_constant {200}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (0.4, manufacturer: 0.35) in Nm/A
      static constexpr float rotor_inertia {200}; // in gcm2
  };

  /**\class X4_3
   * \brief
   *    Constants for the X4-3 actuator
   *    See https://www.myactuator.com/x4-3-details
   *    Replacement for X4 V3
  */
  class X4_3 {
    public:
      static constexpr float reducer_ratio {6/1};
      static constexpr float rated_speed {200}; // in rpm
      static constexpr float rated_current {2}; // in A
      static constexpr float rated_power {30}; // in W
      static constexpr float rated_torque {1.5}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (0.75) in Nm/A
      static constexpr float rotor_inertia {1200}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };

  /**\class X4_24
   * \brief
   *    Constants for the X4-24 actuator
   *    See https://www.myactuator.com/x4-24-details
  */
  class X4_24 {
    public:
      static constexpr float reducer_ratio {36/1};
      static constexpr float rated_speed {100}; // in rpm
      static constexpr float rated_current {3.5}; // in A
      static constexpr float rated_power {150}; // in W
      static constexpr float rated_torque {9}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (2.57) in Nm/A
      static constexpr float rotor_inertia {6800}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };


  ///< X6-series actuators

  /**\class X6V2
   * \brief
   *    Constants for the X6 V2 actuator
   *    See https://www.myactuator.com/product-page/rmd-x6
  */
  class X6V2 {
    public:
      static constexpr float reducer_ratio {6/1};
      static constexpr float no_load_speed {240}; // in rpm (@24V)
      static constexpr float rated_speed {190}; // in rpm
      static constexpr float rated_current {4}; // in A
      static constexpr float rated_power {70}; // in W
      static constexpr float rated_torque {3.5}; // in Nm
      static constexpr float speed_constant {60}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (manufacturer: 0.88) in Nm/A
      static constexpr float rotor_inertia {800}; // in gcm2
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
      static constexpr float no_load_speed {90}; // in rpm (@24V)
      static constexpr float rated_speed {70}; // in rpm
      static constexpr float rated_current {2.6}; // in A
      static constexpr float rated_power {132}; // in W
      static constexpr float rated_torque {18}; // in Nm
      static constexpr float speed_constant {135}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (manufacturer: 6.92) in Nm/A
      static constexpr float rotor_inertia {800}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };

  /**\class X6V3
   * \brief
   *    Constants for the X6 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x6-1-8
  */
  class X6V3 {
    public:
      static constexpr float reducer_ratio {8/1};
      static constexpr float no_load_speed {360}; // in rpm
      static constexpr float rated_speed {310}; // in rpm
      static constexpr float rated_current {3.6}; // in A
      static constexpr float rated_power {135}; // in W
      static constexpr float rated_torque {4.5}; // in Nm
      static constexpr float speed_constant {62}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (1.25, manufacturer: 0.17) in Nm/A
      static constexpr float rotor_inertia {850}; // in gcm2
  };

  /**\class X6_7
   * \brief
   *    Constants for the X6-7 actuator
   *    See https://www.myactuator.com/x6-7-details
   *    Replacement for X6 V2
  */
  class X6_7 {
    public:
      static constexpr float reducer_ratio {6/1};
      static constexpr float rated_speed {400}; // in rpm
      static constexpr float rated_current {4}; // in A
      static constexpr float rated_power {150}; // in W
      static constexpr float rated_torque {3.5}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (0.875) in Nm/A
      static constexpr float rotor_inertia {4800}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };

  /**\class X6_8
   * \brief
   *    Constants for the X6-8 actuator
   *    See https://www.myactuator.com/x6-8-details
   *    Replacement for X6 V3
  */
  class X6_8 {
    public:
      static constexpr float reducer_ratio {8/1};
      static constexpr float rated_speed {310}; // in rpm
      static constexpr float rated_current {3.6}; // in A
      static constexpr float rated_power {135}; // in W
      static constexpr float rated_torque {4.5}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (1.25) in Nm/A
      static constexpr float rotor_inertia {6800}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };

  /**\class X6_40
   * \brief
   *    Constants for the X6-40 actuator
   *    See https://www.myactuator.com/x6-40-details
   *    Replacement for X6-S2 V2
  */
  class X6_40 {
    public:
      static constexpr float reducer_ratio {36/1};
      static constexpr float rated_speed {90}; // in rpm
      static constexpr float rated_current {5.2}; // in A
      static constexpr float rated_power {170}; // in W
      static constexpr float rated_torque {18}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (3.46) in Nm/A
      static constexpr float rotor_inertia {28800}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {14};
  };


  ///< X8-series actuators

  /**\class X8V2
   * \brief
   *    Constants for the X8 V2 actuator
   *    See https://www.myactuator.com/product-page/rmd-x8-1-9
  */
  class X8V2 {
    public:
      static constexpr float reducer_ratio {9/1};
      static constexpr float no_load_speed {215}; // in rpm (@48V)
      static constexpr float rated_speed {170}; // in rpm
      static constexpr float rated_current {4.3}; // in A
      static constexpr float rated_power {160}; // in W
      static constexpr float rated_torque {9}; // in Nm
      static constexpr float speed_constant {40}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (manufacturer: 2.09) in Nm/A
      static constexpr float rotor_inertia {2600}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {21};
  };

  /**\class X8ProV2
   * \brief
   *    Constants for the X8 Pro V2 actuator
   *    See https://www.myactuator.com/product-page/x8-pro-1-9
  */
  class X8ProV2 {
    public:
      static constexpr float reducer_ratio {9/1};
      static constexpr float no_load_speed {160}; // in rpm (@48V)
      static constexpr float rated_speed {122}; // in rpm
      static constexpr float rated_current {5}; // in A
      static constexpr float rated_power {166}; // in W
      static constexpr float rated_torque {13}; // in Nm
      static constexpr float speed_constant {30}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (manufacturer: 2.6) in Nm/A
      static constexpr float rotor_inertia {3400}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {20};
  };

  /**\class X8S2V3
   * \brief
   *    Constants for the X8-S2 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x8-s2-1-36
  */
  class X8S2V3 {
    public:
      static constexpr float reducer_ratio {36/1};
      static constexpr float no_load_speed {46}; // in rpm
      static constexpr float rated_speed {40}; // in rpm
      static constexpr float rated_current {3.2}; // in A
      static constexpr float rated_power {110}; // in W
      static constexpr float rated_torque {25}; // in Nm
      static constexpr float speed_constant {33}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (7.81, manufacturer: 0.30) in Nm/A
      static constexpr float rotor_inertia {2670}; // in gcm2
  };

  /**\class X8HV3
   * \brief
   *    Constants for the X8-H V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x8
  */
  class X8HV3 {
    public:
      static constexpr float reducer_ratio {6.2/1};
      static constexpr float no_load_speed {260}; // in rpm
      static constexpr float rated_speed {190}; // in rpm
      static constexpr float rated_current {3.5}; // in A
      static constexpr float rated_power {120}; // in W
      static constexpr float rated_torque {6}; // in Nm
      static constexpr float speed_constant {33}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (1.71, manufacturer: 0.30) in Nm/A
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
      static constexpr float no_load_speed {220}; // in rpm
      static constexpr float rated_speed {160}; // in rpm
      static constexpr float rated_current {3.75}; // in A
      static constexpr float rated_power {135}; // in W
      static constexpr float rated_torque {8}; // in Nm
      static constexpr float speed_constant {30}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (2.13, manufacturer: 0.29) in Nm/A
      static constexpr float rotor_inertia {3400}; // in gcm2
  };

  /**\class X8_20
   * \brief
   *    Constants for the X8-20 actuator
   *    See https://www.myactuator.com/x8-20-details
   *    Replacement for X8-Pro-H V3
  */
  class X8_20 {
    public:
      static constexpr float reducer_ratio {6/1};
      static constexpr float rated_speed {190}; // in rpm
      static constexpr float rated_current {5.2}; // in A
      static constexpr float rated_power {200}; // in W
      static constexpr float rated_torque {10}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (1.92) in Nm/A
      static constexpr float rotor_inertia {20000}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {20};
  };

  /**\class X8_25
   * \brief
   *    Constants for the X8-25 actuator
   *    See https://www.myactuator.com/x8-25-details
   *   Replacement for X8-Pro V2
  */
  class X8_25 {
    public:
      static constexpr float reducer_ratio {9/1};
      static constexpr float rated_speed {110}; // in rpm
      static constexpr float rated_current {3.2}; // in A
      static constexpr float rated_power {125}; // in W
      static constexpr float rated_torque {10}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (3.13) in Nm/A
      static constexpr float rotor_inertia {30600}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {21};
  };

  /**\class X8_60
   * \brief
   *    Constants for the X8-60 actuator
   *    See https://www.myactuator.com/x8-60-details
   *    Replacement for X8-S2 V3
  */
  class X8_60 {
    public:
      static constexpr float reducer_ratio {36/1};
      static constexpr float rated_speed {40}; // in rpm
      static constexpr float rated_current {4}; // in A
      static constexpr float rated_power {130}; // in W
      static constexpr float rated_torque {30}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (7.5) in Nm/A
      static constexpr float rotor_inertia {96000}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {20};
  };

  /**\class X8_90
   * \brief
   *    Constants for the X8-90 actuator
   *    See https://www.myactuator.com/x8-90-details
  */
  class X8_90 {
    public:
      static constexpr float reducer_ratio {18/1};
      static constexpr float rated_speed {130}; // in rpm
      static constexpr float rated_current {10}; // in A
      static constexpr float rated_power {500}; // in W
      static constexpr float rated_torque {25}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (2.5) in Nm/A
      static constexpr float rotor_inertia {26000}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {21};
  };


  ///< X10-series actuators

  /**\class X10V3
   * \brief
   *    Constants for the X10 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x10
  */
  class X10V3 {
    public:
      static constexpr float reducer_ratio {7/1};
      static constexpr float no_load_speed {190}; // in rpm
      static constexpr float rated_speed {170}; // in rpm
      static constexpr float rated_current {5.3}; // in A
      static constexpr float rated_power {215}; // in W
      static constexpr float rated_torque {12}; // in Nm
      static constexpr float speed_constant {30}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (2.26, manufacturer: 0.32) in Nm/A
      static constexpr float rotor_inertia {5675}; // in gcm2
  };

  /**\class X10S2V3
   * \brief
   *    Constants for the X10-S2 V3 actuator
   *    See https://www.myactuator.com/product-page/rmd-x10-s2-1-35
  */
  class X10S2V3 {
    public:
      static constexpr float reducer_ratio {35/1};
      static constexpr float no_load_speed {55}; // in rpm
      static constexpr float rated_speed {50}; // in rpm
      static constexpr float rated_current {6.7}; // in A
      static constexpr float rated_power {265}; // in W
      static constexpr float rated_torque {50}; // in Nm
      static constexpr float speed_constant {30}; // in rpm/V
      static constexpr float torque_constant {rated_torque/rated_current}; // (7.46, manufacturer: 0.32) in Nm/A
      static constexpr float rotor_inertia {5675}; // in gcm2
  };

  /**\class X10_40
   * \brief
   *    Constants for the X10-40 actuator
   *    See https://www.myactuator.com/x10-40-details
   *    Replacement for X10 V3
  */
  class X10_40 {
    public:
      static constexpr float reducer_ratio {7/1};
      static constexpr float rated_speed {165}; // in rpm
      static constexpr float rated_current {6.5}; // in A
      static constexpr float rated_power {265}; // in W
      static constexpr float rated_torque {15}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (2.31) in Nm/A
      static constexpr float rotor_inertia {39700}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {21};
  };

  /**\class X10_100
   * \brief
   *    Constants for the X10-100 actuator
   *    See https://www.myactuator.com/x10-100-details
   *    Replacement for X10-S2 V3
  */
  class X10_100 {
    public:
      static constexpr float reducer_ratio {35/1};
      static constexpr float rated_speed {50}; // in rpm
      static constexpr float rated_current {6.7}; // in A
      static constexpr float rated_power {265}; // in W
      static constexpr float rated_torque {50}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (7.46) in Nm/A
      static constexpr float rotor_inertia {198600}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {21};
  };


  ///< X12-series actuators

  /**\class X12_150
   * \brief
   *    Constants for the X12-150 actuator
   *    See https://www.myactuator.com/x12-150-details
  */
  class X12_150 {
    public:
      static constexpr float reducer_ratio {12/1};
      static constexpr float rated_speed {100}; // in rpm
      static constexpr float rated_current {15}; // in A
      static constexpr float rated_power {780}; // in W
      static constexpr float rated_torque {50}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (3.33) in Nm/A
      static constexpr float rotor_inertia {59000}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {21};
  };


  ///< X15-series actuators

  /**\class X15_400
   * \brief
   *    Constants for the X15-400 actuator
   *    See https://www.myactuator.com/x15-400-details
  */
  class X15_400 {
    public:
      static constexpr float reducer_ratio {11.4/1};
      static constexpr float rated_speed {80}; // in rpm
      static constexpr float rated_current {23}; // in A
      static constexpr float rated_power {1500}; // in W
      static constexpr float rated_torque {130}; // in Nm
      static constexpr float torque_constant {rated_torque/rated_current}; // (5.65) in Nm/A
      static constexpr float rotor_inertia {175000}; // in gcm2
      static constexpr std::int16_t number_of_pole_pairs {21};
  };

}

#endif // MYACTUATOR_RMD__ACTUATOR_CONSTANTS
