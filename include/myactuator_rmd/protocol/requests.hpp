/**
 * \file requests.hpp
 * \mainpage
 *    Contains all the requests sent from the driver to the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUESTS
#define MYACTUATOR_RMD__PROTOCOL__REQUESTS
#pragma once

#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/single_motor_message.hpp"


namespace myactuator_rmd {
  
  using GetControllerGainsRequest = SingleMotorRequest<CommandType::READ_PID_PARAMETERS>;
  using GetControlModeRequest = SingleMotorRequest<CommandType::READ_SYSTEM_OPERATING_MODE>;
  using GetMotorModelRequest =  SingleMotorRequest<CommandType::READ_MOTOR_MODEL>;
  using GetMotorPowerRequest =  SingleMotorRequest<CommandType::READ_MOTOR_POWER>;
  using GetMotorStatus1Request = SingleMotorRequest<CommandType::READ_MOTOR_STATUS_1_AND_ERROR_FLAG>;
  using GetMotorStatus2Request =  SingleMotorRequest<CommandType::READ_MOTOR_STATUS_2>;
  using GetMotorStatus3Request = SingleMotorRequest<CommandType::READ_MOTOR_STATUS_3>;
  using GetSystemRuntimeRequest = SingleMotorRequest<CommandType::READ_SYSTEM_RUNTIME>;
  using GetVersionDateRequest = SingleMotorRequest<CommandType::READ_SYSTEM_SOFTWARE_VERSION_DATE>;
  using LockBrakeRequest = SingleMotorRequest<CommandType::LOCK_BRAKE>;
  using ReleaseBrakeRequest = SingleMotorRequest<CommandType::RELEASE_BRAKE>;
  using ResetRequest = SingleMotorRequest<CommandType::RESET_SYSTEM>;

  /**\class SetGainsRequest
   * \brief
   *    Base class for all requests for setting controller gains
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class SetGainsRequest: public SingleMotorRequest<C> {
    public:
      /**\fn GainsRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] gains
       *    Gains that the actuator should be set to
      */
      constexpr SetGainsRequest(Gains const& gains) noexcept;
      SetGainsRequest() = delete;
      SetGainsRequest(SetGainsRequest const&) = default;
      SetGainsRequest& operator = (SetGainsRequest const&) = default;
      SetGainsRequest(SetGainsRequest&&) = default;
      SetGainsRequest& operator = (SetGainsRequest&&) = default;
      using SingleMotorRequest<C>::SingleMotorRequest;

      /**\fn getGains
       * \brief
       *    Get the controller gains
       * 
       * \return
       *    The controller gains
      */
      [[nodiscard]]
      constexpr Gains getGains() const noexcept;
  };

  template <CommandType C>
  constexpr SetGainsRequest<C>::SetGainsRequest(Gains const& gains) noexcept
  : SingleMotorRequest<C>{} {
    this->data_[2] = gains.current.kp;
    this->data_[3] = gains.current.ki;
    this->data_[4] = gains.speed.kp;
    this->data_[5] = gains.speed.ki;
    this->data_[6] = gains.position.kp;
    this->data_[7] = gains.position.ki;
    return;
  }

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

  using SetControllerGainsPersistentlyRequest = SetGainsRequest<CommandType::WRITE_PID_PARAMETERS_TO_ROM>;
  using SetControllerGainsRequest = SetGainsRequest<CommandType::WRITE_PID_PARAMETERS_TO_RAM>;

  /**\class SetPositionAbsoluteRequest
   * \brief
   *    Request for setting the absolute position of the actuator with a given maximum speed
  */
  class SetPositionAbsoluteRequest: public SingleMotorRequest<CommandType::ABSOLUTE_POSITION_CLOSED_LOOP_CONTROL> {
    public:
      /**\fn SetPositionAbsoluteRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] position
       *    The position set-point in degree [0.00, 360.00]
       * \param[in] max_speed
       *    The maximum speed for the motion in degree per second [0.0, 1320.0]
      */
      SetPositionAbsoluteRequest(float const position, float const max_speed);
      SetPositionAbsoluteRequest() = delete;
      SetPositionAbsoluteRequest(SetPositionAbsoluteRequest const&) = default;
      SetPositionAbsoluteRequest& operator = (SetPositionAbsoluteRequest const&) = default;
      SetPositionAbsoluteRequest(SetPositionAbsoluteRequest&&) = default;
      SetPositionAbsoluteRequest& operator = (SetPositionAbsoluteRequest&&) = default;
      using SingleMotorRequest::SingleMotorRequest;

      /**\fn getMaxSpeed
       * \brief
       *    Get the maximum speed
       * 
       * \return
       *    The maximum speed for the motion in degree per second [-1320.0, 1320.0]
      */
      [[nodiscard]]
      float getMaxSpeed() const noexcept;

      /**\fn getPosition
       * \brief
       *    Get the position
       * 
       * \return
       *    The position set-point in degree [-360.00, 360.00]
      */
      [[nodiscard]]
      float getPosition() const noexcept;
  };

  /**\class SetTorqueRequest
   * \brief
   *    Request for setting the torque of the actuator by setting a target current
  */
  class SetTorqueRequest: public SingleMotorRequest<CommandType::TORQUE_CLOSED_LOOP_CONTROL> {
    public:
      /**\fn SetTorqueRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] current
       *    The current set-point in Ampere [-20.00, 20.00]
      */
      SetTorqueRequest(float const current);
      SetTorqueRequest() = delete;
      SetTorqueRequest(SetTorqueRequest const&) = default;
      SetTorqueRequest& operator = (SetTorqueRequest const&) = default;
      SetTorqueRequest(SetTorqueRequest&&) = default;
      SetTorqueRequest& operator = (SetTorqueRequest&&) = default;
      using SingleMotorRequest::SingleMotorRequest;

      /**\fn getTorqueCurrent
       * \brief
       *    Get the torque current
       * 
       * \return
       *    The torque current in Ampere [-20.00, 20.00]
      */
      [[nodiscard]]
      float getTorqueCurrent() const noexcept;
  };

  /**\class SetVelocityRequest
   * \brief
   *    Request for setting the velocity of the actuator
  */
  class SetVelocityRequest: public SingleMotorRequest<CommandType::SPEED_CLOSED_LOOP_CONTROL> {
    public:
      /**\fn SetVelocityRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] speed
       *    The velocity set-point in degree per second [-1320.00, 1320.00]
      */
      SetVelocityRequest(float const speed);
      SetVelocityRequest() = delete;
      SetVelocityRequest(SetVelocityRequest const&) = default;
      SetVelocityRequest& operator = (SetVelocityRequest const&) = default;
      SetVelocityRequest(SetVelocityRequest&&) = default;
      SetVelocityRequest& operator = (SetVelocityRequest&&) = default;
      using SingleMotorRequest::SingleMotorRequest;

      /**\fn getSpeed
       * \brief
       *    Get the velocity set-point
       * 
       * \return
       *    The speed for the motion in degree per second [-1320.0, 1320.0]
      */
      [[nodiscard]]
      float getSpeed() const noexcept;
  };

  using ShutdownMotorRequest = SingleMotorRequest<CommandType::SHUTDOWN_MOTOR>;
  using StopMotorRequest = SingleMotorRequest<CommandType::STOP_MOTOR>;

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS
