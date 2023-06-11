#include "myactuator_rmd_driver/protocol/requests/set_velocity_request.hpp"

#include <cstdint>
#include <cstring>
#include <string>

#include "myactuator_rmd_driver/protocol/requests/request.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  SetVelocityRequest::SetVelocityRequest(float const speed)
  : Request{} {
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
