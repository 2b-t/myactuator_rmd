#include "myactuator_rmd_driver/messages/request.hpp"

#include <array>
#include <cstdint>
#include <cstring>
#include <string>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/message.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  SetPositionAbsoluteRequest::SetPositionAbsoluteRequest(float const position, float const max_speed) {
    if ((position < 0.0) || (position > 360.0)) {
      throw ValueRangeException("Position value '" + std::to_string(position) + "' out of range [0.0, 360.0]");
    }
    if ((max_speed < 0.0) || (max_speed > 1320.0)) {
      throw ValueRangeException("Maximum speed value '" + std::to_string(max_speed) + "' out of range [0.0, 1320.0]");
    }
    auto const v {static_cast<std::uint16_t>(max_speed)};
    auto const pos {static_cast<std::int32_t>(position*100.0)};
    std::memcpy(&data_[2], &v, sizeof(std::uint16_t));
    std::memcpy(&data_[4], &pos, sizeof(std::int32_t));
    return;
  }

}
