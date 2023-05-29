/**
 * \file driver_actuator_test.hpp
 * \mainpage
 *    Contains a test fixture for testing the driver with an actuator mock
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__TEST__DRIVER_ACTUATOR_TEST
#define MYACTUATOR_RMD_DRIVER__TEST__DRIVER_ACTUATOR_TEST
#pragma once

#include <cstdint>
#include <string>

#include <gtest/gtest.h>

#include "myactuator_rmd_driver/driver.hpp"
#include "mock/actuator_mock.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    /**\class DriverActuatorTest
     * \brief
     *    Test fixture for testing the driver with a mock of the actuator
    */
    class DriverActuatorTest: public ::testing::Test {
      public:
        DriverActuatorTest(std::string const& ifname = "vcan_test", std::uint32_t const id = 1);
        DriverActuatorTest(DriverActuatorTest const&) = delete;
        DriverActuatorTest& operator = (DriverActuatorTest const&) = default;
        DriverActuatorTest(DriverActuatorTest&&) = default;
        DriverActuatorTest& operator = (DriverActuatorTest&&) = default;

      protected:
        myactuator_rmd_driver::Driver driver_;
        ActuatorMock actuator_;
    };

    DriverActuatorTest::DriverActuatorTest(std::string const& ifname, std::uint32_t const id)
    : driver_{ifname, id}, actuator_{ifname,id} {
      return;
    }

  }
}

#endif // MYACTUATOR_RMD_DRIVER__TEST__DRIVER_ACTUATOR_TEST
