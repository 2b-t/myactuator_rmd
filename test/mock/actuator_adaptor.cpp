#include "actuator_adaptor.hpp"

#include <array>
#include <cstdint>
#include <string>

#include "myactuator_rmd/can/frame.hpp"
#include "myactuator_rmd/protocol/command_type.hpp"
#include "myactuator_rmd/protocol/node.hpp"
#include "myactuator_rmd/protocol/responses.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {
  namespace test {

    void ActuatorAdaptor::handleRequest() {
      can::Frame const frame {read()};
      std::array<std::uint8_t,8> const data {frame.getData()};
      
      if (data[0] == myactuator_rmd::CommandType::READ_SYSTEM_SOFTWARE_VERSION_DATE) {
        myactuator_rmd::GetVersionDateResponse const response {getVersionDate()};
        send(response);
      } else {
        throw myactuator_rmd::Exception("Unrecognized request");
      }
      return;
    }

    ActuatorAdaptor::ActuatorAdaptor(std::string const& ifname, std::uint32_t const actuator_id)
    : Node{ifname, actuator_id} {
      return;
    }

  }
}
