#include "actuator_adaptor.hpp"

#include <array>
#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/exceptions.hpp"
#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    void ActuatorAdaptor::handleRequest() {
      auto const request {read()};
      
      if (request[0] == 0xB2) {
        std::array<std::uint8_t,8> const data {getVersionDate()};
        write(data);
      } else {
        throw myactuator_rmd_driver::Exception("Unrecognized request");
      }
      return;
    }

    ActuatorAdaptor::ActuatorAdaptor(std::string const& ifname, std::uint32_t const id)
    : Node{ifname, id} {
      return;
    }

  }
}

