/**
 * \file actuator_mock.hpp
 * \mainpage
 *    Contains a mock for the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__TEST__MOCK__ACTUATOR_MOCK
#define MYACTUATOR_RMD_DRIVER__TEST__MOCK__ACTUATOR_MOCK
#pragma once

#include <array>
#include <cstdint>

#include <gmock/gmock.h>

#include "myactuator_rmd_driver/messages/response.hpp"
#include "actuator_adaptor.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    /**\class ActuatorMock
     * \brief
     *    Mock of the real actuator
    */
    class ActuatorMock: public ActuatorAdaptor {
      public:
        ActuatorMock(std::string const& ifname, std::uint32_t const actuator_id);
        ActuatorMock() = delete;
        ActuatorMock(ActuatorMock const&) = delete;
        ActuatorMock& operator = (ActuatorMock const&) = default;
        ActuatorMock(ActuatorMock&&) = default;
        ActuatorMock& operator = (ActuatorMock&&) = default;

        MOCK_METHOD(myactuator_rmd_driver::VersionDateResponse, getVersionDate, (), (const, override));
    };

  }
}

#endif // MYACTUATOR_RMD_DRIVER__TEST__MOCK__ACTUATOR_MOCK
