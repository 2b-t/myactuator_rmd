#include "myactuator_rmd_driver/messages/responses/stop_motor_response.hpp"

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  StopMotorResponse::StopMotorResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if (data[0] != CommandType::STOP_MOTOR) {
      throw ProtocolException("Unexpected response to stop motor request!");
    }
    return;
  }

}
