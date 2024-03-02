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

#include <chrono>
#include <cstdint>

#include "myactuator_rmd/actuator_state/acceleration_type.hpp"
#include "myactuator_rmd/actuator_state/can_baud_rate.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/single_motor_message.hpp"


namespace myactuator_rmd {
  
  using GetAccelerationRequest = SingleMotorRequest<CommandType::READ_ACCELERATION>;
  using GetControllerGainsRequest = SingleMotorRequest<CommandType::READ_PID_PARAMETERS>;
  using GetControlModeRequest = SingleMotorRequest<CommandType::READ_SYSTEM_OPERATING_MODE>;
  using GetMotorModelRequest =  SingleMotorRequest<CommandType::READ_MOTOR_MODEL>;
  using GetMotorPowerRequest =  SingleMotorRequest<CommandType::READ_MOTOR_POWER>;
  using GetMotorStatus1Request = SingleMotorRequest<CommandType::READ_MOTOR_STATUS_1_AND_ERROR_FLAG>;
  using GetMotorStatus2Request =  SingleMotorRequest<CommandType::READ_MOTOR_STATUS_2>;
  using GetMotorStatus3Request = SingleMotorRequest<CommandType::READ_MOTOR_STATUS_3>;
  using GetMultiTurnAngleRequest = SingleMotorRequest<CommandType::READ_MULTI_TURN_ANGLE>;
  using GetMultiTurnEncoderPositionRequest = SingleMotorRequest<CommandType::READ_MULTI_TURN_ENCODER_POSITION>;
  using GetMultiTurnEncoderOriginalPositionRequest = SingleMotorRequest<CommandType::READ_MULTI_TURN_ENCODER_ORIGINAL_POSITION>;
  using GetMultiTurnEncoderZeroOffsetRequest = SingleMotorRequest<CommandType::READ_MULTI_TURN_ENCODER_ZERO_OFFSET>;
  using GetSingleTurnAngleRequest = SingleMotorRequest<CommandType::READ_SINGLE_TURN_ANGLE>;
  using GetSingleTurnEncoderPositionRequest = SingleMotorRequest<CommandType::READ_SINGLE_TURN_ENCODER>;
  using GetSystemRuntimeRequest = SingleMotorRequest<CommandType::READ_SYSTEM_RUNTIME>;
  using GetVersionDateRequest = SingleMotorRequest<CommandType::READ_SYSTEM_SOFTWARE_VERSION_DATE>;
  using LockBrakeRequest = SingleMotorRequest<CommandType::LOCK_BRAKE>;
  using ReleaseBrakeRequest = SingleMotorRequest<CommandType::RELEASE_BRAKE>;
  using ResetRequest = SingleMotorRequest<CommandType::RESET_SYSTEM>;
  using SetCurrentPositionAsEncoderZeroRequest = SingleMotorRequest<CommandType::WRITE_CURRENT_MULTI_TURN_POSITION_TO_ROM_AS_ZERO>;

  /**\class CanIdRequest
   * \brief
   *    Request for getting/setting the CAN ID of the actuator
  */
  class CanIdRequest: public SingleMotorRequest<CommandType::CAN_ID_SETTING> {
    public:
      using SingleMotorRequest::SingleMotorRequest;

      /**\fn isWrite
       * \brief
       *    Check if the can request reads or writes the given CAN ID
       * 
       * \return
       *    True in case this is a write command, false in case it is a read command
      */
      [[nodiscard]]
      bool isWrite() const noexcept;

    protected:
      CanIdRequest() = default;
      CanIdRequest(CanIdRequest const&) = default;
      CanIdRequest& operator = (CanIdRequest const&) = default;
      CanIdRequest(CanIdRequest&&) = default;
      CanIdRequest& operator = (CanIdRequest&&) = default;
  };

  /**\class GetCanIdRequest
   * \brief
   *    Request for getting the CAN ID of the actuator
  */
  class GetCanIdRequest: public CanIdRequest {
    public:
      GetCanIdRequest();
      GetCanIdRequest(GetCanIdRequest const&) = default;
      GetCanIdRequest& operator = (GetCanIdRequest const&) = default;
      GetCanIdRequest(GetCanIdRequest&&) = default;
      GetCanIdRequest& operator = (GetCanIdRequest&&) = default;
      using CanIdRequest::CanIdRequest;
  };

  /**\class SetCanIdRequest
   * \brief
   *    Request for setting the CAN ID of the actuator
  */
  class SetCanIdRequest: public CanIdRequest {
    public:
      SetCanIdRequest(std::uint16_t const can_id);
      SetCanIdRequest(SetCanIdRequest const&) = default;
      SetCanIdRequest& operator = (SetCanIdRequest const&) = default;
      SetCanIdRequest(SetCanIdRequest&&) = default;
      SetCanIdRequest& operator = (SetCanIdRequest&&) = default;
      using CanIdRequest::CanIdRequest;

      /**\fn getCanId
       * \brief
       *    Get the CAN ID of the actuator
       * 
       * \return
       *    The CAN ID of the actuator [1, 32]
      */
      [[nodiscard]]
      std::uint16_t getCanId() const noexcept;
  };

  /**\class SetAccelerationRequest
   * \brief
   *    Request for setting the maximum acceleration/deceleration of the actuator
  */
  class SetAccelerationRequest: public SingleMotorRequest<CommandType::WRITE_ACCELERATION_TO_RAM_AND_ROM> {
    public:
      /**\fn SetAccelerationRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] acceleration
       *    The desired acceleration/deceleration in dps with a resolution of 1 dps [100, 60000]
       * \param[in] mode
       *    The mode of the desired acceleration/deceleration to be set
      */
      SetAccelerationRequest(std::uint32_t const acceleration, AccelerationType const mode);
      SetAccelerationRequest() = delete;
      SetAccelerationRequest(SetAccelerationRequest const&) = default;
      SetAccelerationRequest& operator = (SetAccelerationRequest const&) = default;
      SetAccelerationRequest(SetAccelerationRequest&&) = default;
      SetAccelerationRequest& operator = (SetAccelerationRequest&&) = default;
      using SingleMotorRequest::SingleMotorRequest;

      /**\fn getAcceleration
       * \brief
       *    Get the acceleration
       * 
       * \return
       *    The acceleration in degree per second**2 [100, 60000]
      */
      [[nodiscard]]
      std::uint32_t getAcceleration() const noexcept;

      /**\fn getMode
       * \brief
       *    Get the acceleration mode
       * 
       * \return
       *    The acceleration mode
      */
      [[nodiscard]]
      AccelerationType getMode() const noexcept;
  };

  /**\class SetCanBaudRateRequest
   * \brief
   *    Request for setting the Baud rate of the actuator
  */
  class SetCanBaudRateRequest: public SingleMotorRequest<CommandType::COMMUNICATION_BAUD_RATE_SETTING> {
    public:
      SetCanBaudRateRequest(CanBaudRate const baud_rate);
      SetCanBaudRateRequest(SetCanBaudRateRequest const&) = default;
      SetCanBaudRateRequest& operator = (SetCanBaudRateRequest const&) = default;
      SetCanBaudRateRequest(SetCanBaudRateRequest&&) = default;
      SetCanBaudRateRequest& operator = (SetCanBaudRateRequest&&) = default;
      using SingleMotorRequest::SingleMotorRequest;

      /**\fn getBaudRate
       * \brief
       *    Get the Baud rate that should be set to the actuator
       * 
       * \return
       *    The Baud rate that the actuator should be using
      */
      [[nodiscard]]
      CanBaudRate getBaudRate() const noexcept;
  };

  /**\class SetEncoderZeroRequest
   * \brief
   *    Request for setting the encoder zero to a given value
  */
  class SetEncoderZeroRequest: public SingleMotorRequest<CommandType::WRITE_ENCODER_MULTI_TURN_VALUE_TO_ROM_AS_ZERO> {
    public:
      SetEncoderZeroRequest(std::int32_t const encoder_offset);
      SetEncoderZeroRequest(SetEncoderZeroRequest const&) = default;
      SetEncoderZeroRequest& operator = (SetEncoderZeroRequest const&) = default;
      SetEncoderZeroRequest(SetEncoderZeroRequest&&) = default;
      SetEncoderZeroRequest& operator = (SetEncoderZeroRequest&&) = default;
      using SingleMotorRequest::SingleMotorRequest;

      /**\fn getEncoderZero
       * \brief
       *    Get the encoder zero value
       * 
       * \return
       *    The encoder zero value
      */
      [[nodiscard]]
      std::int32_t getEncoderZero() const noexcept;
  };

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
       *    The position set-point in degree
       * \param[in] max_speed
       *    The maximum speed for the motion in degree per second
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
       *    The maximum speed for the motion in degree per second
      */
      [[nodiscard]]
      float getMaxSpeed() const noexcept;

      /**\fn getPosition
       * \brief
       *    Get the position
       * 
       * \return
       *    The position set-point in degree
      */
      [[nodiscard]]
      float getPosition() const noexcept;
  };

  /**\class SetTimeoutRequest
   * \brief
   *    Request for setting the communication interruption protection time setting
  */
  class SetTimeoutRequest: public SingleMotorRequest<CommandType::COMMUNICATION_INTERRUPTION_PROTECTION_TIME_SETTING> {
    public:
      /**\fn SetTimeoutRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] timeout
       *    The communication interruption protection time setting in milliseconds, 0 if this feature should be de-activated
      */
      SetTimeoutRequest(std::chrono::milliseconds const& timeout);
      SetTimeoutRequest() = delete;
      SetTimeoutRequest(SetTimeoutRequest const&) = default;
      SetTimeoutRequest& operator = (SetTimeoutRequest const&) = default;
      SetTimeoutRequest(SetTimeoutRequest&&) = default;
      SetTimeoutRequest& operator = (SetTimeoutRequest&&) = default;
      using SingleMotorRequest::SingleMotorRequest;

      /**\fn getTimeout
       * \brief
       *    Get the communication interruption protection time to be set
       * 
       * \return
       *    The communication interruption protection time to be set
      */
      [[nodiscard]]
      std::chrono::milliseconds getTimeout() const noexcept;
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
       *    The current set-point in Ampere
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
       *    The torque current in Ampere
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
       *    The velocity set-point in degree per second
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
       *    The speed for the motion in degree per second
      */
      [[nodiscard]]
      float getSpeed() const noexcept;
  };

  using ShutdownMotorRequest = SingleMotorRequest<CommandType::SHUTDOWN_MOTOR>;
  using StopMotorRequest = SingleMotorRequest<CommandType::STOP_MOTOR>;

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS
