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

#include <array>
#include <cstdint>

#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/single_motor_message.hpp"


namespace myactuator_rmd {
  
  using GetControllerGainsRequest = SingleMotorMessage<CommandType::READ_PID_PARAMETERS>;
  using GetMotorModelRequest =  SingleMotorMessage<CommandType::READ_MOTOR_MODEL>;
  using GetMotorStatus1Request = SingleMotorMessage<CommandType::READ_MOTOR_STATUS_1_AND_ERROR_FLAG>;
  using GetMotorStatus2Request =  SingleMotorMessage<CommandType::READ_MOTOR_STATUS_2>;
  using GetMotorStatus3Request = SingleMotorMessage<CommandType::READ_MOTOR_STATUS_3>;
  using GetVersionDateRequest = SingleMotorMessage<CommandType::READ_SYSTEM_SOFTWARE_VERSION_DATE>;

  /**\class SetGainsRequest
   * \brief
   *    Base class for all requests for setting controller gains
   *
   * \tparam C
   *    Type of the command to be requested
  */
  template <CommandType C>
  class SetGainsRequest: public SingleMotorMessage<C> {
    public:
      /**\fn GainsRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] gains
       *    Gains that the actuator should be set to
      */
      constexpr SetGainsRequest(Gains const& gains) noexcept;
      /**\fn GainsRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetGainsRequest(std::array<std::uint8_t,8> const& data) noexcept;
      SetGainsRequest() = delete;
      SetGainsRequest(SetGainsRequest const&) = default;
      SetGainsRequest& operator = (SetGainsRequest const&) = default;
      SetGainsRequest(SetGainsRequest&&) = default;
      SetGainsRequest& operator = (SetGainsRequest&&) = default;

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
  : SingleMotorMessage<C>{} {
    this->data_[2] = gains.current.kp;
    this->data_[3] = gains.current.ki;
    this->data_[4] = gains.speed.kp;
    this->data_[5] = gains.speed.ki;
    this->data_[6] = gains.position.kp;
    this->data_[7] = gains.position.ki;
    return;
  }

  template <CommandType C>
  constexpr SetGainsRequest<C>::SetGainsRequest(std::array<std::uint8_t,8> const& data) noexcept
  : SingleMotorMessage<C>{data} {
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
  class SetPositionAbsoluteRequest: public SingleMotorMessage<CommandType::ABSOLUTE_POSITION_CLOSED_LOOP_CONTROL> {
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
      /**\fn SetPositionAbsoluteRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetPositionAbsoluteRequest(std::array<std::uint8_t,8> const& data);
      SetPositionAbsoluteRequest() = delete;
      SetPositionAbsoluteRequest(SetPositionAbsoluteRequest const&) = default;
      SetPositionAbsoluteRequest& operator = (SetPositionAbsoluteRequest const&) = default;
      SetPositionAbsoluteRequest(SetPositionAbsoluteRequest&&) = default;
      SetPositionAbsoluteRequest& operator = (SetPositionAbsoluteRequest&&) = default;

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

  constexpr SetPositionAbsoluteRequest::SetPositionAbsoluteRequest(std::array<std::uint8_t,8> const& data)
  : SingleMotorMessage{data} {
    return;
  }

  /**\class SetTorqueRequest
   * \brief
   *    Request for setting the torque of the actuator by setting a target current
  */
  class SetTorqueRequest: public SingleMotorMessage<CommandType::TORQUE_CLOSED_LOOP_CONTROL> {
    public:
      /**\fn SetTorqueRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] current
       *    The current set-point in Ampere [-20.00, 20.00]
      */
      SetTorqueRequest(float const current);
      /**\fn SetPositionAbsoluteRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetTorqueRequest(std::array<std::uint8_t,8> const& data);
      SetTorqueRequest() = delete;
      SetTorqueRequest(SetTorqueRequest const&) = default;
      SetTorqueRequest& operator = (SetTorqueRequest const&) = default;
      SetTorqueRequest(SetTorqueRequest&&) = default;
      SetTorqueRequest& operator = (SetTorqueRequest&&) = default;

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

  constexpr SetTorqueRequest::SetTorqueRequest(std::array<std::uint8_t,8> const& data)
  : SingleMotorMessage{data} {
    return;
  }

  /**\class SetVelocityRequest
   * \brief
   *    Request for setting the velocity of the actuator
  */
  class SetVelocityRequest: public SingleMotorMessage<CommandType::SPEED_CLOSED_LOOP_CONTROL> {
    public:
      /**\fn SetVelocityRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] speed
       *    The velocity set-point in degree per second [-1320.00, 1320.00]
      */
      SetVelocityRequest(float const speed);
      /**\fn SetVelocityRequest
       * \brief
       *    Class constructor
       * 
       * \param[in] data
       *    The data to be transmitted to the driver
      */
      constexpr SetVelocityRequest(std::array<std::uint8_t,8> const& data);
      SetVelocityRequest() = delete;
      SetVelocityRequest(SetVelocityRequest const&) = default;
      SetVelocityRequest& operator = (SetVelocityRequest const&) = default;
      SetVelocityRequest(SetVelocityRequest&&) = default;
      SetVelocityRequest& operator = (SetVelocityRequest&&) = default;

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

  constexpr SetVelocityRequest::SetVelocityRequest(std::array<std::uint8_t,8> const& data)
  : SingleMotorMessage{data} {
    return;
  }

  using ShutdownMotorRequest = SingleMotorMessage<CommandType::SHUTDOWN_MOTOR>;
  using StopMotorRequest = SingleMotorMessage<CommandType::STOP_MOTOR>;

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUESTS
