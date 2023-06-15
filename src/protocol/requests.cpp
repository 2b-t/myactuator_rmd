#include "myactuator_rmd/protocol/requests.hpp"

#include <cstdint>
#include <cstring>
#include <string>

#include "myactuator_rmd/protocol/single_motor_message.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  SetPositionAbsoluteRequest::SetPositionAbsoluteRequest(float const position, float const max_speed)
  : SingleMotorRequest{} {
    if ((position < -360.0f) || (position > 360.0f)) {
      throw ValueRangeException("Position value '" + std::to_string(position) + "' out of range [0.0, 360.0]");
    }
    if ((max_speed < -1320.0f) || (max_speed > 1320.0f)) {
      throw ValueRangeException("Maximum speed value '" + std::to_string(max_speed) + "' out of range [0.0, 1320.0]");
    }
    auto const v {static_cast<std::uint16_t>(max_speed)};
    auto const pos {static_cast<std::int32_t>(position*100.0f)};
    setAt(v, 2);
    setAt(pos, 4);
    return;
  }

  float SetPositionAbsoluteRequest::getMaxSpeed() const noexcept {
    return static_cast<float>(getAs<std::uint16_t>(2));
  }

  float SetPositionAbsoluteRequest::getPosition() const noexcept {
    return static_cast<float>(getAs<std::int32_t>(4)/100.0f);
  }

  SetTorqueRequest::SetTorqueRequest(float const current)
  : SingleMotorRequest{} {
    if ((current < -20.0f) || (current > 20.0f)) {
      throw ValueRangeException("Current value '" + std::to_string(current) + "' out of range [-20.0, 20.0]");
    }
    auto const c {static_cast<std::int16_t>(current/0.01f)};
    setAt(c, 4);
    return;
  }

  float SetTorqueRequest::getTorqueCurrent() const noexcept {
    return static_cast<float>(getAs<std::int16_t>(4))*0.01f;
  }

  SetVelocityRequest::SetVelocityRequest(float const speed)
  : SingleMotorRequest{} {
    if ((speed < -1320.0f) || (speed > 1320.0f)) {
      throw ValueRangeException("Speed value '" + std::to_string(speed) + "' out of range [-1320.0, 1320.0]");
    }
    auto const s {static_cast<std::int32_t>(speed*100.0f)};
    setAt(s, 4);
    return;
  }

  float SetVelocityRequest::getSpeed() const noexcept {
    return static_cast<float>(getAs<std::int32_t>(4))/100.0f;
  }

}
