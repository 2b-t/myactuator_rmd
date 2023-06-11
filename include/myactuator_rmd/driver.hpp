/**
 * \file driver.hpp
 * \mainpage
 *    Contains the main driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__DRIVER
#define MYACTUATOR_RMD__DRIVER
#pragma once

#include <cstdint>
#include <string>

#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/protocol/address_offset.hpp"
#include "myactuator_rmd/protocol/node.hpp"


namespace myactuator_rmd {

  /**\class Driver
   * \brief
   *    Driver for commanding the MyActuator RMD actuator series
  */
  class Driver: public Node<AddressOffset::request,AddressOffset::response> {
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

      /**\fn getMotorModel
       * \brief
       *    Reads the motor model currently in use by the actuator
       * 
       * \return
       *    The motor model string currently in use by the actuator, e.g. 'X8S2V10'
      */
      [[nodiscard]]
      std::string getMotorModel();

      /**\fn getMotorStatus1
       * \brief
       *    Reads the motor status 1
       * 
       * \return
       *    The motor status 1 containing temperature, voltage and error codes
      */
      [[nodiscard]]
      MotorStatus1 getMotorStatus1();

      /**\fn getMotorStatus2
       * \brief
       *    Reads the motor status 2
       * 
       * \return
       *    The motor status 2 containing current, speed and position
      */
      [[nodiscard]]
      MotorStatus2 getMotorStatus2();

      /**\fn getMotorStatus3
       * \brief
       *    Reads the motor status 3
       * 
       * \return
       *    The motor status 3 containing detailed current information
      */
      [[nodiscard]]
      MotorStatus3 getMotorStatus3();

      /**\fn getControllerGains
       * \brief
       *    Reads the currently used controller gains
       * 
       * \return
       *    The currently used controller gains for current, speed and position as unsigned 8-bit integers
      */
      [[nodiscard]]
      Gains getControllerGains();

      /**\fn setControllerGains
       * \brief
       *    Write the currently used controller gains either to RAM (not persistent after reboot) or ROM (persistent)
       * 
       * \param[in] gains
       *    The PI-gains for current, speed and position to be set
       * \param[in] is_persistent
       *    Boolean argument signaling whether the controller gains should be persistent after reboot of the actuator or not
       * \return
       *    The currently used controller gains for current, speed and position as unsigned 8-bit integers
      */
      Gains setControllerGains(Gains const& gains, bool const is_persistent = false);

      /**\fn sendTorqueSetpoint
       * \brief
       *    Send a torque set-point to the actuator by specifying the current
       *
       * \param[in] current
       *    The current set-point in Ampere [-20.00, 20.00]
       * \return
       *    Feedback control message containing actuator position, velocity, torque and temperature
      */
      Feedback sendTorqueSetpoint(float const current);

      /**\fn sendVelocitySetpoint
       * \brief
       *    Send a velocity set-point to the actuator
       *
       * \param[in] speed
       *    The speed set-point in degree per second [-1320.00, 1320.00]
       * \return
       *    Feedback control message containing actuator position, velocity, torque and temperature
      */
      Feedback sendVelocitySetpoint(float const speed);

      /**\fn sendPositionAbsoluteSetpoint
       * \brief
       *    Send an absolute position set-point to the actuator additionally specifying a maximum velocity
       *
       * \param[in] position
       *    The position set-point in degree [-360.00, 360.00]
       * \param[in] max_speed
       *    The maximum speed for the motion in degree per second [-1320.0, 1320.0]
       * \return
       *    Feedback control message containing actuator position, velocity, torque and temperature
      */
      Feedback sendPositionAbsoluteSetpoint(float const position, float const max_speed = 500.0);

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

#endif // MYACTUATOR_RMD__DRIVER
