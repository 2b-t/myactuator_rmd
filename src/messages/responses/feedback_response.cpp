#include "myactuator_rmd_driver/messages/responses/feedback_response.hpp"

#include <cstdint>

#include "myactuator_rmd_driver/feedback.hpp"


namespace myactuator_rmd_driver {

  Feedback FeedbackResponse::getStatus() const noexcept {
    auto const temperature {static_cast<int>(getAs<std::int8_t>(1))};
    auto const current {static_cast<float>(getAs<std::int16_t>(2))*0.01f};
    auto const shaft_speed {static_cast<float>(getAs<std::int16_t>(4))};
    auto const shaft_angle {static_cast<float>(getAs<std::int16_t>(6))};
    return Feedback{temperature, current, shaft_speed, shaft_angle};
  }

}
