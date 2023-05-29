#include "actuator_mock.hpp"

#include <cstdint>
#include <string>

#include "actuator_adaptor.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    ActuatorMock::ActuatorMock(std::string const& ifname, std::uint32_t const id)
    : ActuatorAdaptor{ifname, id} {
      return;
    }

  }
}

