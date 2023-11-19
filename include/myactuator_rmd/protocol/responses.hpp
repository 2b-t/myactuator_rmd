/**
 * \file responses.hpp
 * \mainpage
 *    Contains all the responses sent from the actuator to the driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSES
#define MYACTUATOR_RMD__PROTOCOL__RESPONSES
#pragma once

#include <chrono>
#include <cstdint>

#include "myactuator_rmd/actuator_state/control_mode.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/single_motor_message.hpp"


namespace myactuator_rmd {

  /**\class GetCanIdResponse
   * \brief
   *    Request for getting the CAN ID of the actuator
  */
  class GetCanIdResponse: public SingleMotorResponse<CommandType::CAN_ID_SETTING> {
    public:
      GetCanIdResponse() = delete;
      GetCanIdResponse(GetCanIdResponse const&) = default;
      GetCanIdResponse& operator = (GetCanIdResponse const&) = default;
      GetCanIdResponse(GetCanIdResponse&&) = default;
      GetCanIdResponse& operator = (GetCanIdResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getCanId
       * \brief
       *    Get the CAN ID of the actuator
       * 
       * \return
       *    The CAN ID of the actuator starting at 0x240
      */
      [[nodiscard]]
      virtual std::uint16_t getCanId() const noexcept;
  };

  /**\class GetAccelerationResponse
   * \brief
   *    Response to request for reading the motor model
  */
  class GetAccelerationResponse: public SingleMotorResponse<CommandType::READ_ACCELERATION> {
    public:
      GetAccelerationResponse() = delete;
      GetAccelerationResponse(GetAccelerationResponse const&) = default;
      GetAccelerationResponse& operator = (GetAccelerationResponse const&) = default;
      GetAccelerationResponse(GetAccelerationResponse&&) = default;
      GetAccelerationResponse& operator = (GetAccelerationResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getAcceleration
       * \brief
       *    Get the current acceleration
       * 
       * \return
       *    The current acceleration with a resolution of 1 dps
      */
      [[nodiscard]]
      std::int32_t getAcceleration() const noexcept;
  };

  /**\class GetMultiTurnAngleResponse
   * \brief
   *    Response to request for reading a multi-turn angle
  */
  class GetMultiTurnAngleResponse: public SingleMotorResponse<CommandType::READ_MULTI_TURN_ANGLE> {
    public:
      GetMultiTurnAngleResponse() = delete;
      GetMultiTurnAngleResponse(GetMultiTurnAngleResponse const&) = default;
      GetMultiTurnAngleResponse& operator = (GetMultiTurnAngleResponse const&) = default;
      GetMultiTurnAngleResponse(GetMultiTurnAngleResponse&&) = default;
      GetMultiTurnAngleResponse& operator = (GetMultiTurnAngleResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getPosition
       * \brief
       *    Get the multi-turn angle
       * 
       * \return
       *    The multi-turn angle with a resolution of 0.01 deg
      */
      [[nodiscard]]
      float getAngle() const noexcept;
  };

  /**\class GetMultiTurnEncoderPositionResponse
   * \brief
   *    Response to request for reading a multi-turn encoder position
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class MultiTurnEncoderPositionResponse: public SingleMotorResponse<C> {
    public:
      MultiTurnEncoderPositionResponse() = delete;
      MultiTurnEncoderPositionResponse(MultiTurnEncoderPositionResponse const&) = default;
      MultiTurnEncoderPositionResponse& operator = (MultiTurnEncoderPositionResponse const&) = default;
      MultiTurnEncoderPositionResponse(MultiTurnEncoderPositionResponse&&) = default;
      MultiTurnEncoderPositionResponse& operator = (MultiTurnEncoderPositionResponse&&) = default;
      using SingleMotorResponse<C>::SingleMotorResponse;

      /**\fn getPosition
       * \brief
       *    Get the encoder position
       * 
       * \return
       *    The current encoder position
      */
      [[nodiscard]]
      std::int32_t getPosition() const noexcept;
  };

  template <CommandType C>
  std::int32_t MultiTurnEncoderPositionResponse<C>::getPosition() const noexcept {
    auto const encoder_position {this->template getAs<std::int32_t>(4)};
    return encoder_position;
  }

  using GetMultiTurnEncoderPositionResponse = MultiTurnEncoderPositionResponse<CommandType::READ_MULTI_TURN_ENCODER_POSITION>;
  using GetMultiTurnEncoderOriginalPositionResponse = MultiTurnEncoderPositionResponse<CommandType::READ_MULTI_TURN_ENCODER_ORIGINAL_POSITION>;
  using GetMultiTurnEncoderZeroOffsetResponse = MultiTurnEncoderPositionResponse<CommandType::READ_MULTI_TURN_ENCODER_ZERO_OFFSET>;

  /**\class GetSingleTurnAngleResponse
   * \brief
   *    Response to request for reading a single-turn angle
  */
  class GetSingleTurnAngleResponse: public SingleMotorResponse<CommandType::READ_SINGLE_TURN_ANGLE> {
    public:
      GetSingleTurnAngleResponse() = delete;
      GetSingleTurnAngleResponse(GetSingleTurnAngleResponse const&) = default;
      GetSingleTurnAngleResponse& operator = (GetSingleTurnAngleResponse const&) = default;
      GetSingleTurnAngleResponse(GetSingleTurnAngleResponse&&) = default;
      GetSingleTurnAngleResponse& operator = (GetSingleTurnAngleResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getPosition
       * \brief
       *    Get the single-turn angle
       * 
       * \return
       *    The single-turn angle with a resolution of 0.01 deg
      */
      [[nodiscard]]
      float getAngle() const noexcept;
  };

  /**\class GetSingleTurnEncoderPositionResponse
   * \brief
   *    Response to request for reading a single-turn encoder position
  */
  class GetSingleTurnEncoderPositionResponse: public SingleMotorResponse<CommandType::READ_SINGLE_TURN_ENCODER> {
    public:
      GetSingleTurnEncoderPositionResponse() = delete;
      GetSingleTurnEncoderPositionResponse(GetSingleTurnEncoderPositionResponse const&) = default;
      GetSingleTurnEncoderPositionResponse& operator = (GetSingleTurnEncoderPositionResponse const&) = default;
      GetSingleTurnEncoderPositionResponse(GetSingleTurnEncoderPositionResponse&&) = default;
      GetSingleTurnEncoderPositionResponse& operator = (GetSingleTurnEncoderPositionResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getPosition
       * \brief
       *    Get the encoder position
       * 
       * \return
       *    The current encoder position
      */
      [[nodiscard]]
      std::int16_t getPosition() const noexcept;

      /**\fn getRawPosition
       * \brief
       *    Get the encoder raw position
       * 
       * \return
       *    The current raw encoder position
      */
      [[nodiscard]]
      std::int16_t getRawPosition() const noexcept;

      /**\fn getOffset
       * \brief
       *    Get the encoder position offset
       * 
       * \return
       *    The current encoder position offset
      */
      [[nodiscard]]
      std::int16_t getOffset() const noexcept;
  };

  using LockBrakeResponse = SingleMotorResponse<CommandType::LOCK_BRAKE>;
  using ReleaseBrakeResponse = SingleMotorResponse<CommandType::RELEASE_BRAKE>;

  /**\class FeedbackResponse
   * \brief
   *    Base class for all responses containing a feedback
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class FeedbackResponse: public SingleMotorResponse<C> {
    public:
      FeedbackResponse() = delete;
      FeedbackResponse(FeedbackResponse const&) = default;
      FeedbackResponse& operator = (FeedbackResponse const&) = default;
      FeedbackResponse(FeedbackResponse&&) = default;
      FeedbackResponse& operator = (FeedbackResponse&&) = default;
      using SingleMotorResponse<C>::SingleMotorResponse;

      /**\fn getStatus
       * \brief
       *    Get the feedback
       * 
       * \return
       *    Feedback from the actuator
      */
      [[nodiscard]]
      Feedback getStatus() const noexcept;
  };

  template <CommandType C>
  Feedback FeedbackResponse<C>::getStatus() const noexcept {
    auto const temperature {static_cast<int>(this->template getAs<std::int8_t>(1))};
    auto const current {static_cast<float>(this->template getAs<std::int16_t>(2))*0.01f};
    auto const shaft_speed {static_cast<float>(this->template getAs<std::int16_t>(4))};
    auto const shaft_angle {static_cast<float>(this->template getAs<std::int16_t>(6))};
    return Feedback{temperature, current, shaft_speed, shaft_angle};
  }

  using GetMotorStatus2Response = FeedbackResponse<CommandType::READ_MOTOR_STATUS_2>;
  using SetPositionAbsoluteResponse = FeedbackResponse<CommandType::ABSOLUTE_POSITION_CLOSED_LOOP_CONTROL>;
  using SetTorqueResponse = FeedbackResponse<CommandType::TORQUE_CLOSED_LOOP_CONTROL>;
  using SetVelocityResponse = FeedbackResponse<CommandType::SPEED_CLOSED_LOOP_CONTROL>;

  /**\class GainsResponse
   * \brief
   *    Base class for all responses with controller gains
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class GainsResponse: public SingleMotorResponse<C> {
    public:
      GainsResponse() = delete;
      GainsResponse(GainsResponse const&) = default;
      GainsResponse& operator = (GainsResponse const&) = default;
      GainsResponse(GainsResponse&&) = default;
      GainsResponse& operator = (GainsResponse&&) = default;
      using SingleMotorResponse<C>::SingleMotorResponse;

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
  constexpr Gains GainsResponse<C>::getGains() const noexcept {
    auto const current_kp {this->data_[2]};
    auto const current_ki {this->data_[3]};
    auto const speed_kp {this->data_[4]};
    auto const speed_ki {this->data_[5]};
    auto const position_kp {this->data_[6]};
    auto const position_ki {this->data_[7]};
    return Gains{current_kp, current_ki, speed_kp, speed_ki, position_kp, position_ki};
  }

  using GetControllerGainsResponse = GainsResponse<CommandType::READ_PID_PARAMETERS>;
  using SetControllerGainsPersistentlyResponse = GainsResponse<CommandType::WRITE_PID_PARAMETERS_TO_ROM>;
  using SetControllerGainsResponse = GainsResponse<CommandType::WRITE_PID_PARAMETERS_TO_RAM>;

  /**\class GetControlModeResponse
   * \brief
   *    Get the current control mode the actuator is operating in
  */
  class GetControlModeResponse: public SingleMotorResponse<CommandType::READ_SYSTEM_OPERATING_MODE> {
    public:
      GetControlModeResponse() = delete;
      GetControlModeResponse(GetControlModeResponse const&) = default;
      GetControlModeResponse& operator = (GetControlModeResponse const&) = default;
      GetControlModeResponse(GetControlModeResponse&&) = default;
      GetControlModeResponse& operator = (GetControlModeResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getMode
       * \brief
       *    Get the current control mode
       * 
       * \return
       *    The current control mode
      */
      [[nodiscard]]
      constexpr ControlMode getMode() const noexcept;
  };

  constexpr ControlMode GetControlModeResponse::getMode() const noexcept {
    return static_cast<ControlMode>(data_[7]);
  }

  /**\class GetMotorModelResponse
   * \brief
   *    Response to request for reading the motor model
  */
  class GetMotorModelResponse: public SingleMotorResponse<CommandType::READ_MOTOR_MODEL> {
    public:
      GetMotorModelResponse() = delete;
      GetMotorModelResponse(GetMotorModelResponse const&) = default;
      GetMotorModelResponse& operator = (GetMotorModelResponse const&) = default;
      GetMotorModelResponse(GetMotorModelResponse&&) = default;
      GetMotorModelResponse& operator = (GetMotorModelResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getModel
       * \brief
       *    Get the motor model
       * 
       * \return
       *    The version string of the motor model
      */
      [[nodiscard]]
      std::string getModel() const noexcept;
  };

  /**\class GetMotorPowerResponse
   * \brief
   *    Response to request for reading the motor model
  */
  class GetMotorPowerResponse: public SingleMotorResponse<CommandType::READ_MOTOR_POWER> {
    public:
      GetMotorPowerResponse() = delete;
      GetMotorPowerResponse(GetMotorPowerResponse const&) = default;
      GetMotorPowerResponse& operator = (GetMotorPowerResponse const&) = default;
      GetMotorPowerResponse(GetMotorPowerResponse&&) = default;
      GetMotorPowerResponse& operator = (GetMotorPowerResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getPower
       * \brief
       *    Get the current motor power
       * 
       * \return
       *    The current motor power in Watt with a resolution of 0.1
      */
      [[nodiscard]]
      float getPower() const noexcept;
  };

  /**\class GetMotorStatus1Response
   * \brief
   *    Response to request for getting motor status
  */
  class GetMotorStatus1Response: public SingleMotorResponse<CommandType::READ_MOTOR_STATUS_1_AND_ERROR_FLAG> {
    public:
      GetMotorStatus1Response() = delete;
      GetMotorStatus1Response(GetMotorStatus1Response const&) = default;
      GetMotorStatus1Response& operator = (GetMotorStatus1Response const&) = default;
      GetMotorStatus1Response(GetMotorStatus1Response&&) = default;
      GetMotorStatus1Response& operator = (GetMotorStatus1Response&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getStatus
       * \brief
       *    Get the motor status
       * 
       * \return
       *    Motor status of the actuator
      */
      [[nodiscard]]
      MotorStatus1 getStatus() const noexcept;
  };

  /**\class GetMotorStatus3Response
   * \brief
   *    Response to request for getting motor status
  */
  class GetMotorStatus3Response: public SingleMotorResponse<CommandType::READ_MOTOR_STATUS_3> {
    public:
      GetMotorStatus3Response() = delete;
      GetMotorStatus3Response(GetMotorStatus3Response const&) = default;
      GetMotorStatus3Response& operator = (GetMotorStatus3Response const&) = default;
      GetMotorStatus3Response(GetMotorStatus3Response&&) = default;
      GetMotorStatus3Response& operator = (GetMotorStatus3Response&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getStatus
       * \brief
       *    Get the motor status
       * 
       * \return
       *    Motor status of the actuator
      */
      [[nodiscard]]
      MotorStatus3 getStatus() const noexcept;
  };

  /**\class GetSystemRuntimeResponse
   * \brief
   *    Response to request for getting the actuator's runtime
  */
  class GetSystemRuntimeResponse: public SingleMotorResponse<CommandType::READ_SYSTEM_RUNTIME> {
    public:
      GetSystemRuntimeResponse() = delete;
      GetSystemRuntimeResponse(GetSystemRuntimeResponse const&) = default;
      GetSystemRuntimeResponse& operator = (GetSystemRuntimeResponse const&) = default;
      GetSystemRuntimeResponse(GetSystemRuntimeResponse&&) = default;
      GetSystemRuntimeResponse& operator = (GetSystemRuntimeResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getRuntime
       * \brief
       *    Get the actuator's runtime in milliseconds
       * 
       * \return
       *    The actuators runtime in milliseconds
      */
      [[nodiscard]]
      std::chrono::milliseconds getRuntime() const noexcept;
  };

  /**\class GetVersionDateResponse
   * \brief
   *    Response to request for getting the actuator's version date
  */
  class GetVersionDateResponse: public SingleMotorResponse<CommandType::READ_SYSTEM_SOFTWARE_VERSION_DATE> {
    public:
      GetVersionDateResponse() = delete;
      GetVersionDateResponse(GetVersionDateResponse const&) = default;
      GetVersionDateResponse& operator = (GetVersionDateResponse const&) = default;
      GetVersionDateResponse(GetVersionDateResponse&&) = default;
      GetVersionDateResponse& operator = (GetVersionDateResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

      /**\fn getVersion
       * \brief
       *    Get the version date as an integer
       * 
       * \return
       *    The version date as an integer number
      */
      [[nodiscard]]
      std::uint32_t getVersion() const noexcept;
  };

  using SetAccelerationResponse = SingleMotorResponse<CommandType::WRITE_ACCELERATION_TO_RAM_AND_ROM>;
  using SetCanIdResponse = SingleMotorResponse<CommandType::CAN_ID_SETTING>;

  /**\class SetCurrentPositionAsEncoderZeroResponse
   * \brief
   *    Response to request for setting the current position as the encoder zero position
  */
  class SetCurrentPositionAsEncoderZeroResponse: public SingleMotorResponse<CommandType::WRITE_CURRENT_MULTI_TURN_POSITION_TO_ROM_AS_ZERO> {
    public:
      SetCurrentPositionAsEncoderZeroResponse() = delete;
      SetCurrentPositionAsEncoderZeroResponse(SetCurrentPositionAsEncoderZeroResponse const&) = default;
      SetCurrentPositionAsEncoderZeroResponse& operator = (SetCurrentPositionAsEncoderZeroResponse const&) = default;
      SetCurrentPositionAsEncoderZeroResponse(SetCurrentPositionAsEncoderZeroResponse&&) = default;
      SetCurrentPositionAsEncoderZeroResponse& operator = (SetCurrentPositionAsEncoderZeroResponse&&) = default;
      using SingleMotorResponse::SingleMotorResponse;

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

  using SetEncoderZeroResponse = SingleMotorRequest<CommandType::WRITE_ENCODER_MULTI_TURN_VALUE_TO_ROM_AS_ZERO>;
  using SetTimeoutResponse = SingleMotorResponse<CommandType::COMMUNICATION_INTERRUPTION_PROTECTION_TIME_SETTING>;
  using ShutdownMotorResponse = SingleMotorResponse<CommandType::SHUTDOWN_MOTOR>;
  using StopMotorResponse = SingleMotorResponse<CommandType::STOP_MOTOR>;

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES
