#include "myactuator_rmd_driver/driver.hpp"

#include <array>
#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/request.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"
#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {

  Driver::Driver(std::string const& ifname, std::uint32_t const actuator_id)
  : Node{ifname, actuator_id} {
    return;
  }

  std::uint32_t Driver::getVersionDate() {
    VersionDateRequest const request {};
    auto const response {sendRecv<VersionDateResponse>(request)};
    return response.getVersion();
  }

}

