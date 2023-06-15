#include "myactuator_rmd/driver.hpp"

#include <chrono>
#include <cstdint>
#include <string>

#include "myactuator_rmd/actuator_state/control_mode.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/protocol/node.hpp"
#include "myactuator_rmd/protocol/requests.hpp"
#include "myactuator_rmd/protocol/responses.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  Driver::Driver(std::string const& ifname, std::uint32_t const actuator_id)
  : Node{ifname, actuator_id} {
    return;
  }

  std::int32_t Driver::getAcceleration() {
    GetAccelerationRequest const request {};
    auto const response {sendRecv<GetAccelerationResponse>(request)};
    return response.getAcceleration();
  }

  Gains Driver::getControllerGains() {
    GetControllerGainsRequest const request {};
    auto const response {sendRecv<GetControllerGainsResponse>(request)};
    return response.getGains();
  }

  ControlMode Driver::getControlMode() {
    GetControlModeRequest const request {};
    auto const response {sendRecv<GetControlModeResponse>(request)};
    return response.getMode();
  }

  std::string Driver::getMotorModel() {
    GetMotorModelRequest const request {};
    auto const response {sendRecv<GetMotorModelResponse>(request)};
    return response.getModel();
  }

  float Driver::getMotorPower() {
    GetMotorPowerRequest const request {};
    auto const response {sendRecv<GetMotorPowerResponse>(request)};
    return response.getPower();
  }

  MotorStatus1 Driver::getMotorStatus1() {
    GetMotorStatus1Request const request {};
    auto const response {sendRecv<GetMotorStatus1Response>(request)};
    return response.getStatus();
  }

  MotorStatus2 Driver::getMotorStatus2() {
    GetMotorStatus2Request const request {};
    auto const response {sendRecv<GetMotorStatus2Response>(request)};
    return response.getStatus();
  }

  MotorStatus3 Driver::getMotorStatus3() {
    GetMotorStatus3Request const request {};
    auto const response {sendRecv<GetMotorStatus3Response>(request)};
    return response.getStatus();
  }

  float Driver::getMultiTurnAngle() {
    GetMultiTurnAngleRequest const request {};
    auto const response {sendRecv<GetMultiTurnAngleResponse>(request)};
    return response.getAngle();
  }

  std::int32_t Driver::getMultiTurnEncoderPosition() {
    GetMultiTurnEncoderPositionRequest const request {};
    auto const response {sendRecv<GetMultiTurnEncoderPositionResponse>(request)};
    return response.getPosition();
  }

  std::int32_t Driver::getMultiTurnEncoderOriginalPosition() {
    GetMultiTurnEncoderOriginalPositionRequest const request {};
    auto const response {sendRecv<GetMultiTurnEncoderOriginalPositionResponse>(request)};
    return response.getPosition();
  }

  std::int32_t Driver::getMultiTurnEncoderZeroOffset() {
    GetMultiTurnEncoderZeroOffsetRequest const request {};
    auto const response {sendRecv<GetMultiTurnEncoderZeroOffsetResponse>(request)};
    return response.getPosition();
  }

  std::chrono::milliseconds Driver::getRuntime() {
    GetSystemRuntimeRequest const request {};
    auto const response {sendRecv<GetSystemRuntimeResponse>(request)};
    return response.getRuntime();
  }

  float Driver::getSingleTurnAngle() {
    GetSingleTurnAngleRequest const request {};
    auto const response {sendRecv<GetSingleTurnAngleResponse>(request)};
    return response.getAngle();
  }

  std::int16_t Driver::getSingleTurnEncoderPosition() {
    GetSingleTurnEncoderPositionRequest const request {};
    auto const response {sendRecv<GetSingleTurnEncoderPositionResponse>(request)};
    return response.getPosition();
  }

  std::uint32_t Driver::getVersionDate() {
    GetVersionDateRequest const request {};
    auto const response {sendRecv<GetVersionDateResponse>(request)};
    return response.getVersion();
  }

  void Driver::lockBrake() {
    LockBrakeRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<LockBrakeResponse>(request)};
    return;
  }

  void Driver::releaseBrake() {
    ReleaseBrakeRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<ReleaseBrakeResponse>(request)};
    return;
  }

  void Driver::reset() {
    ResetRequest const request {};
    send(request);
    return;
  }

  Feedback Driver::sendPositionAbsoluteSetpoint(float const position, float const max_speed) {
    SetPositionAbsoluteRequest const request {position, max_speed};
    auto const response {sendRecv<SetPositionAbsoluteResponse>(request)};
    return response.getStatus();
  }

  Feedback Driver::sendTorqueSetpoint(float const current) {
    SetTorqueRequest const request {current};
    auto const response {sendRecv<SetTorqueResponse>(request)};
    return response.getStatus();
  }

  Feedback Driver::sendVelocitySetpoint(float const speed) {
    SetVelocityRequest const request {speed};
    auto const response {sendRecv<SetVelocityResponse>(request)};
    return response.getStatus();
  }

  Gains Driver::setControllerGains(Gains const& gains, bool const is_persistent) {
    if (is_persistent) {
      SetControllerGainsPersistentlyRequest const request {gains};
      auto const response {sendRecv<SetControllerGainsPersistentlyResponse>(request)};
      return response.getGains();
    } else {
      SetControllerGainsRequest const request {gains};
      auto const response {sendRecv<SetControllerGainsResponse>(request)};
      return response.getGains();
    }
  }

  void Driver::shutdownMotor() {
    ShutdownMotorRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<ShutdownMotorResponse>(request)};
    return;
  }

  void Driver::stopMotor() {
    StopMotorRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<StopMotorResponse>(request)};
    return;
  }

}
