#include "myactuator_rmd/protocol/responses/get_motor_status_1_response.hpp"

#include <cstdint>

#include "myactuator_rmd/actuator_state/error_code.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  MotorStatus1 GetMotorStatus1Response::getStatus() const noexcept {
    auto const temperature {static_cast<int>(getAs<std::int8_t>(1))};
    auto const is_brake_released {static_cast<bool>(getAs<std::uint8_t>(3))};
    auto const voltage {static_cast<float>(getAs<std::uint16_t>(4))*0.1f};
    auto const error_code {static_cast<ErrorCode>(getAs<std::uint16_t>(6))};
    return MotorStatus1{temperature, is_brake_released, voltage, error_code};
  }

}
