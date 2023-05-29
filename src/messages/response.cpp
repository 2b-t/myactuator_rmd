#include "myactuator_rmd_driver/messages/response.hpp"

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/messages/message.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  constexpr Response::Response(std::array<std::uint8_t,8> const& data) noexcept
  : Message{data} {
    return;
  }
  
  VersionDateResponse::VersionDateResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if ((data[0] != CommandType::SYSTEM_SOFTWARE_VERSION_DATE) || (data[1] != 0x00) || (data[2] != 0x00) || (data[3] != 0x00)) {
      throw ParsingException("Invalid version date response!");
    }
    return;
  }

}
