#include "myactuator_rmd_driver/messages/responses/version_date_response.hpp"

#include <array>
#include <cstdint>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {
  
  VersionDateResponse::VersionDateResponse(std::array<std::uint8_t,8> const& data)
  : Response{data} {
    if ((data[0] != CommandType::SYSTEM_SOFTWARE_VERSION_DATE) || (data[1] != 0x00) || (data[2] != 0x00) || (data[3] != 0x00)) {
      throw ParsingException("Unexpected response to version date request!");
    }
    return;
  }

}
