/**
 * \file actuator_actuator_mock_test.hpp
 * \mainpage
 *    Contains a test fixture for testing the communication to the actuator with a mock
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__TEST__ACTUATOR_ACTUATOR_MOCK_TEST
#define MYACTUATOR_RMD__TEST__ACTUATOR_ACTUATOR_MOCK_TEST
#pragma once

#include <cstdint>
#include <string>
#include <thread>

#include <gtest/gtest.h>

#include "myactuator_rmd/actuator.hpp"
#include "actuator_mock.hpp"


namespace myactuator_rmd {
  namespace test {

    /**\class DriverActuatorTest
     * \brief
     *    Test fixture for testing the communication with a mock of the actual actuator through a
     *    (virtual) CAN loopback interface
    */
    class ActuatorActuatorMockTest: public ::testing::Test {
      public:
        /**\fn ActuatorActuatorMockTest
         * \brief
         *    Class constructor
         * 
         * \param[in] ifname
         *    The name of the (virtual) CAN network interface that should be used as a loopback device
         * \param[in] actuator_id
         *    The actuator id for the actuator and the actuator mock
        */
        ActuatorActuatorMockTest(std::string const& ifname = "vcan_test", std::uint32_t const actuator_id = 1);
        ActuatorActuatorMockTest(ActuatorActuatorMockTest const&) = delete;
        ActuatorActuatorMockTest& operator = (ActuatorActuatorMockTest const&) = default;
        ActuatorActuatorMockTest(ActuatorActuatorMockTest&&) = default;
        ActuatorActuatorMockTest& operator = (ActuatorActuatorMockTest&&) = default;

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
        myactuator_rmd::Actuator actuator_;
        ActuatorMock actuator_mock_;
        std::thread mock_thread_;
    };

  }
}

#endif // MYACTUATOR_RMD__TEST__ACTUATOR_ACTUATOR_MOCK_TEST
