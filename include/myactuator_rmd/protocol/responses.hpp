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

#include <array>
#include <cstdint>

#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/single_motor_message.hpp"


namespace myactuator_rmd {

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

  using ShutdownMotorResponse = SingleMotorResponse<CommandType::SHUTDOWN_MOTOR>;
  using StopMotorResponse = SingleMotorResponse<CommandType::STOP_MOTOR>;

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES
