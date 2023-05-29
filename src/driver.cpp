#include "myactuator_rmd_driver/driver.hpp"

#include <array>
#include <cstdint>
#include <cstring>
#include <string>

#include "myactuator_rmd_driver/exceptions.hpp"
#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {

  Driver::Driver(std::string const& ifname, std::uint32_t const id)
  : Node{ifname, id} {
    return;
  }

  std::uint32_t Driver::getVersionDate() {
    std::array<std::uint8_t,8> request {};
    request[0] = 0xB2;
    write(request);
    auto const reply {read()};
    if ((reply[0] != 0xB2) || (reply[1] != 0x00) || (reply[2] != 0x00) || (reply[3] != 0x00)) {
      throw ParsingException("Unexpected reply to read version date request!");
    }
    std::uint32_t version {};
    std::memcpy(&version, &reply[4], sizeof(std::uint32_t));
    return version;
  }

}

