#include "myactuator_rmd_driver/protocol/responses/get_motor_status_3_response.hpp"

#include <cstdint>

#include "myactuator_rmd_driver/actuator_state/error_code.hpp"
#include "myactuator_rmd_driver/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  MotorStatus3 GetMotorStatus3Response::getStatus() const noexcept {
    auto const temperature {static_cast<int>(getAs<std::int8_t>(1))};
    auto const current_phase_a {static_cast<float>(getAs<std::int16_t>(2))*0.01f};
    auto const current_phase_b {static_cast<float>(getAs<std::int16_t>(4))*0.01f};
    auto const current_phase_c {static_cast<float>(getAs<std::int16_t>(6))*0.01f};
    return MotorStatus3{temperature, current_phase_a, current_phase_b, current_phase_c};
  }

}
