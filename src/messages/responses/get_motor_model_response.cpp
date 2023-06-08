#include "myactuator_rmd_driver/messages/responses/get_motor_model_response.hpp"

#include <string>


namespace myactuator_rmd_driver {

  std::string GetMotorModelResponse::getVersion() const noexcept {
    std::string const version {&data_[1], &data_[1]+7};
    return version;
  }

}
