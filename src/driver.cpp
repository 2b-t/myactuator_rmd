#include "myactuator_rmd_driver/driver.hpp"

#include <array>
#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/requests/set_position_absolute_request.hpp"
#include "myactuator_rmd_driver/messages/requests/set_torque_request.hpp"
#include "myactuator_rmd_driver/messages/requests/set_velocity_request.hpp"
#include "myactuator_rmd_driver/messages/requests/shutdown_motor_request.hpp"
#include "myactuator_rmd_driver/messages/requests/stop_motor_request.hpp"
#include "myactuator_rmd_driver/messages/requests/version_date_request.hpp"
#include "myactuator_rmd_driver/messages/responses/set_position_absolute_response.hpp"
#include "myactuator_rmd_driver/messages/responses/set_torque_response.hpp"
#include "myactuator_rmd_driver/messages/responses/set_velocity_response.hpp"
#include "myactuator_rmd_driver/messages/responses/shutdown_motor_response.hpp"
#include "myactuator_rmd_driver/messages/responses/stop_motor_response.hpp"
#include "myactuator_rmd_driver/messages/responses/version_date_response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"
#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {

  Driver::Driver(std::string const& ifname, std::uint32_t const actuator_id)
  : Node{ifname, actuator_id} {
    return;
  }

  std::uint32_t Driver::getVersionDate() {
    VersionDateRequest const request {};
    auto const response {sendRecv<VersionDateResponse>(request)};
    return response.getVersion();
  }

  Feedback Driver::sendTorqueSetpoint(float const current) {
    SetTorqueRequest const request {current};
    auto const response {sendRecv<SetTorqueResponse>(request)};
    return response.getFeedback();
  }

  Feedback Driver::sendVelocitySetpoint(float const speed) {
    SetVelocityRequest const request {speed};
    auto const response {sendRecv<SetVelocityResponse>(request)};
    return response.getFeedback();
  }

  Feedback Driver::sendPositionAbsoluteSetpoint(float const position, float const max_speed) {
    SetPositionAbsoluteRequest const request {position, max_speed};
    auto const response {sendRecv<SetPositionAbsoluteResponse>(request)};
    return response.getFeedback();
  }

  void Driver::stopMotor() {
    StopMotorRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<StopMotorResponse>(request)};
    return;
  }

  void Driver::shutdownMotor() {
    ShutdownMotorRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<ShutdownMotorResponse>(request)};
    return;
  }

}
