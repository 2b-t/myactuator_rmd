#include "actuator_mock.hpp"

#include <cstdint>
#include <string>

#include "actuator_adaptor.hpp"


namespace myactuator_rmd {
  namespace test {

    ActuatorMock::ActuatorMock(std::string const& ifname, std::uint32_t const actuator_id)
    : ActuatorAdaptor{ifname, actuator_id} {
      return;
    }

  }
}

