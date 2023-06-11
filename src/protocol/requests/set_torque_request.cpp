#include "myactuator_rmd/protocol/requests/set_torque_request.hpp"

#include <cstdint>
#include <cstring>
#include <string>

#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  SetTorqueRequest::SetTorqueRequest(float const current)
  : Request{} {
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

}
