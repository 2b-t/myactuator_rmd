/**
 * \file driver.hpp
 * \mainpage
 *    Contains the main driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__DRIVER
#define MYACTUATOR_RMD_DRIVER__DRIVER
#pragma once

#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {

  /**\class Driver
   * \brief
   *    Driver for commanding the MyActuator RMD actuator series
  */
  class Driver: public Node<Offset::request,Offset::response> {
    public:
      /**\fn Driver
       * \brief
       *    Class constructor
       * 
       * \param[in] ifname
       *    The name of the network interface that should communicated over
       * \param[in] actuator_id
       *    The actuator id [1, 32]
      */
      Driver(std::string const& ifname, std::uint32_t const actuator_id);
      Driver() = delete;
      Driver(Driver const&) = delete;
      Driver& operator = (Driver const&) = default;
      Driver(Driver&&) = default;
      Driver& operator = (Driver&&) = default;

      /**\fn getVersionDate
       * \brief
       *    Reads the version date of the actuator firmware
       * 
       * \return
       *    The version date of the firmware on the actuator, e.g. '20220206'
      */
      [[nodiscard]]
      std::uint32_t getVersionDate();

      /**\fn setPositionAbsolute
       * \brief
       *    Send an absolute position set-point to the actuator additionally specifying a maximum velocity
       *
       * \param[in] position
       *    The position set-point in degree [0.00, 360.00]
       * \param[in] max_speed
       *    The maximum speed for the motion in degree per second [0.0, 1320.0]
      */
      void setPositionAbsolute(float const position, float const max_speed = 500.0);

      /**\fn stopMotor
       * \brief
       *    Stop the motor if running closed loop command
      */
      void stopMotor();

      /**\fn shutdownMotor
       * \brief
       *    Turn off the motor
      */
      void shutdownMotor();
  };

}

#endif // MYACTUATOR_RMD_DRIVER__DRIVER
