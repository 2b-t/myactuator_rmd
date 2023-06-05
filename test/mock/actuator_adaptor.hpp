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
#include "myactuator_rmd_driver/messages/responses/version_date_response.hpp"
#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    /**\class ActuatorAdaptor
     * \brief
     *    Counter-part to the driver and parent class of the mock that can be used for testing the driver
     *    over a (virtual) CAN network interface
    */
    class ActuatorAdaptor: protected myactuator_rmd_driver::Node<Offset::response,Offset::request> {
      public:
        /**\fn handleRequest
         * \brief
         *    Read a single CAN frame and handle the request by calling one of the virtual member functions
        */
        void handleRequest();

        /**\fn getVersionDate
         * \brief
         *    Get the version date of the actuator
         *
         * \return
         *    The response that should be sent to the driver
        */
        [[nodiscard]]
        virtual myactuator_rmd_driver::VersionDateResponse getVersionDate() const = 0;

      protected:
        /**\fn ActuatorAdaptor
         * \brief
         *    Class constructor
         * 
         * \param[in] ifname
         *    The name of the (virtual) CAN network interface that should be used as a loopback device
         * \param[in] actuator_id
         *    The actuator id for driver and actuator
        */
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
