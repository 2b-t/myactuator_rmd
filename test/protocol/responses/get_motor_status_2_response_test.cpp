/**
 * \file get_motor_status_2_response_test.cpp
 * \mainpage
 *    Test parsing of get motor status response
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd_driver/protocol/responses/get_motor_status_2_response.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(GetMotorStatus2ResponseTest, parsing) {
      myactuator_rmd_driver::GetMotorStatus2Response const response {{0x9C, 0x32, 0x64, 0x00, 0xF4, 0x01, 0x2D, 0x00}};
      myactuator_rmd_driver::MotorStatus2 const motor_status {response.getStatus()};
      EXPECT_EQ(motor_status.temperature, 50);
      EXPECT_NEAR(motor_status.current, 1.0f, 0.1f);
      EXPECT_NEAR(motor_status.shaft_speed, 500.0f, 0.1f);
      EXPECT_NEAR(motor_status.shaft_angle, 45.0f, 0.1f);
    }

  }
}
