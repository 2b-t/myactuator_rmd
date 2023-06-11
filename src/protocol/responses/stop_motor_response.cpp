#include "myactuator_rmd/protocol/responses/stop_motor_response.hpp"

#include <array>
#include <cstdint>

#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/responses/response.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  StopMotorResponse::StopMotorResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if (data[0] != CommandType::STOP_MOTOR) {
      throw ProtocolException("Unexpected response to stop motor request!");
    }
    return;
  }

}
