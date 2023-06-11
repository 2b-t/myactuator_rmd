/**
 * \file get_motor_status_1_response_test.cpp
 * \mainpage
 *    Test parsing of get motor status response
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/protocol/responses/get_motor_status_1_response.hpp"


namespace myactuator_rmd {
  namespace test {

    TEST(GetMotorStatus1ResponseTest, parsing) {
      myactuator_rmd::GetMotorStatus1Response const response {{0x9A, 0x32, 0x00, 0x01, 0xE5, 0x01, 0x04, 0x00}};
      myactuator_rmd::MotorStatus1 const motor_status {response.getStatus()};
      EXPECT_EQ(motor_status.temperature, 50);
      EXPECT_EQ(motor_status.is_brake_released, true);
      EXPECT_NEAR(motor_status.voltage, 48.5, 0.1);
      EXPECT_EQ(motor_status.error_code, myactuator_rmd::ErrorCode::LOW_VOLTAGE);
    }

  }
}
