#include "actuator_adaptor.hpp"

#include <array>
#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/can/frame.hpp"
#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/responses/version_date_response.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"
#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    void ActuatorAdaptor::handleRequest() {
      can::Frame const frame {read()};
      std::array<std::uint8_t,8> const data {frame.getData()};
      
      if (data[0] == myactuator_rmd_driver::CommandType::SYSTEM_SOFTWARE_VERSION_DATE) {
        myactuator_rmd_driver::VersionDateResponse const response {getVersionDate()};
        send(response);
      } else {
        throw myactuator_rmd_driver::Exception("Unrecognized request");
      }
      return;
    }

    ActuatorAdaptor::ActuatorAdaptor(std::string const& ifname, std::uint32_t const actuator_id)
    : Node{ifname, actuator_id} {
      return;
    }

  }
}
