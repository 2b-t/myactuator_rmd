#include "myactuator_rmd/protocol/responses/get_motor_model_response.hpp"

#include <string>


namespace myactuator_rmd {

  std::string GetMotorModelResponse::getVersion() const noexcept {
    std::string const version {&data_[1], &data_[1]+7};
    return version;
  }

}
