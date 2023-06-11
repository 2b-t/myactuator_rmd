#include "myactuator_rmd/protocol/requests/set_position_absolute_request.hpp"

#include <cstdint>
#include <cstring>
#include <string>

#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  SetPositionAbsoluteRequest::SetPositionAbsoluteRequest(float const position, float const max_speed)
  : Request{} {
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

}
