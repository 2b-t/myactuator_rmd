/**
 * \file driver_actuator_test.hpp
 * \mainpage
 *    Contains a test fixture for testing the communication between driver and actuator with a mock
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__TEST__DRIVER_ACTUATOR_TEST
#define MYACTUATOR_RMD__TEST__DRIVER_ACTUATOR_TEST
#pragma once

#include <cstdint>
#include <string>
#include <thread>

#include <gtest/gtest.h>

#include "myactuator_rmd/driver.hpp"
#include "actuator_mock.hpp"


namespace myactuator_rmd {
  namespace test {

    /**\class DriverActuatorTest
     * \brief
     *    Test fixture for testing the driver communication with a mock of the actual actuator through a
     *    (virtual) CAN loopback interface
    */
    class DriverActuatorTest: public ::testing::Test {
      public:
        /**\fn DriverActuatorTest
         * \brief
         *    Class constructor
         * 
         * \param[in] ifname
         *    The name of the (virtual) CAN network interface that should be used as a loopback device
         * \param[in] actuator_id
         *    The actuator id for driver and actuator
        */
        DriverActuatorTest(std::string const& ifname = "vcan_test", std::uint32_t const actuator_id = 1);
        DriverActuatorTest(DriverActuatorTest const&) = delete;
        DriverActuatorTest& operator = (DriverActuatorTest const&) = default;
        DriverActuatorTest(DriverActuatorTest&&) = default;
        DriverActuatorTest& operator = (DriverActuatorTest&&) = default;

        /**\fn SetUp
         * \brief
         *    Starts a thread with the mock actuator for a single request
        */
        void SetUp() override;

        /**\fn TearDown
         * \brief
         *    Joins the thread started by the fixture set-up
        */
        void TearDown() override;

      protected:
        myactuator_rmd::Driver driver_;
        ActuatorMock actuator_;
        std::thread mock_thread_;
    };

  }
}

#endif // MYACTUATOR_RMD__TEST__DRIVER_ACTUATOR_TEST
