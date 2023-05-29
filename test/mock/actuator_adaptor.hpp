/**
 * \file actuator_adaptor.hpp
 * \mainpage
 *    Contains an adaptor for the actuator mock
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__TEST__MOCK__ACTUATOR_ADAPTOR
#define MYACTUATOR_RMD_DRIVER__TEST__MOCK__ACTUATOR_ADAPTOR
#pragma once

#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/messages/definitions.hpp"
#include "myactuator_rmd_driver/messages/response.hpp"
#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    /**\class ActuatorAdaptor
     * \brief
     *    Counter-part to the driver and parent class of the mock
    */
    class ActuatorAdaptor: protected myactuator_rmd_driver::Node<Offset::response,Offset::request> {
      public:
        void handleRequest();

        virtual myactuator_rmd_driver::VersionDateResponse getVersionDate() const = 0;

      protected:
        ActuatorAdaptor(std::string const& ifname, std::uint32_t const actuator_id);
        ActuatorAdaptor() = delete;
        ActuatorAdaptor(ActuatorAdaptor const&) = delete;
        ActuatorAdaptor& operator = (ActuatorAdaptor const&) = default;
        ActuatorAdaptor(ActuatorAdaptor&&) = default;
        ActuatorAdaptor& operator = (ActuatorAdaptor&&) = default;
    };

  }
}

#endif // MYACTUATOR_RMD_DRIVER__TEST__MOCK__ACTUATOR_ADAPTOR
