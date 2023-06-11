/**
 * \file driver_test.cpp
 * \mainpage
 *    Test the communication between the driver and the actuator with a mock
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd/protocol/responses.hpp"
#include "mock/driver_actuator_test.hpp"


namespace myactuator_rmd {
  namespace test {

    TEST_F(DriverActuatorTest, getVersionDate) {
      myactuator_rmd::GetVersionDateResponse const response {{0xB2, 0x00, 0x00, 0x00, 0x2E, 0x89, 0x34, 0x01}};
      EXPECT_CALL(actuator_, getVersionDate).WillOnce(::testing::Return(response));
      auto const version {driver_.getVersionDate()};
      EXPECT_EQ(version, 20220206);
    }

  }
}
