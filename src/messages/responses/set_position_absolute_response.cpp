#include "myactuator_rmd_driver/messages/responses/set_position_absolute_response.hpp"


namespace myactuator_rmd_driver {

      float SetPositionAbsoluteResponse::getTemperature() const noexcept {
        return static_cast<float>(getAs<std::int8_t>(1));
      }

      float SetPositionAbsoluteResponse::getTorqueCurrent() const noexcept {
        return static_cast<float>(getAs<std::int16_t>(2)*0.01f);
      }

      float SetPositionAbsoluteResponse::getShaftSpeed() const noexcept {
        return static_cast<float>(getAs<std::int16_t>(4));
      }

      float SetPositionAbsoluteResponse::getShaftAngle() const noexcept {
        return static_cast<float>(getAs<std::int16_t>(6));
      }

}
