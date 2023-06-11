#include "myactuator_rmd_driver/protocol/responses/shutdown_motor_response.hpp"

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/protocol/command_type.hpp"
#include "myactuator_rmd_driver/protocol/responses/response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  ShutdownMotorResponse::ShutdownMotorResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if (data[0] != CommandType::SHUTDOWN_MOTOR) {
      throw ProtocolException("Unexpected response to shutdown motor request!");
    }
    return;
  }

}
