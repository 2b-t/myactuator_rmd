#include "myactuator_rmd/protocol/responses.hpp"

#include <cstdint>
#include <string>

#include "myactuator_rmd/actuator_state/error_code.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  std::string GetMotorModelResponse::getVersion() const noexcept {
    std::string const version {&data_[1], &data_[1]+7};
    return version;
  }

  MotorStatus1 GetMotorStatus1Response::getStatus() const noexcept {
    auto const temperature {static_cast<int>(getAs<std::int8_t>(1))};
    auto const is_brake_released {static_cast<bool>(getAs<std::uint8_t>(3))};
    auto const voltage {static_cast<float>(getAs<std::uint16_t>(4))*0.1f};
    auto const error_code {static_cast<ErrorCode>(getAs<std::uint16_t>(6))};
    return MotorStatus1{temperature, is_brake_released, voltage, error_code};
  }

  MotorStatus3 GetMotorStatus3Response::getStatus() const noexcept {
    auto const temperature {static_cast<int>(getAs<std::int8_t>(1))};
    auto const current_phase_a {static_cast<float>(getAs<std::int16_t>(2))*0.01f};
    auto const current_phase_b {static_cast<float>(getAs<std::int16_t>(4))*0.01f};
    auto const current_phase_c {static_cast<float>(getAs<std::int16_t>(6))*0.01f};
    return MotorStatus3{temperature, current_phase_a, current_phase_b, current_phase_c};
  }

  std::uint32_t GetVersionDateResponse::getVersion() const noexcept {
    return getAs<std::uint32_t>(4);
  }

}
