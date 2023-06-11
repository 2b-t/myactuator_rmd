/**
 * \file get_motor_status_3_response_test.cpp
 * \mainpage
 *    Test parsing of get motor status response
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/protocol/responses/get_motor_status_3_response.hpp"


namespace myactuator_rmd {
  namespace test {

    TEST(GetMotorStatus3ResponseTest, parsing) {
      myactuator_rmd::GetMotorStatus3Response const response {{0x9D, 0x32, 0xC2, 0x0B, 0x10, 0xFA, 0xC0, 0xF9}};
      myactuator_rmd::MotorStatus3 const motor_status {response.getStatus()};
      EXPECT_EQ(motor_status.temperature, 50);
      EXPECT_NEAR(motor_status.current_phase_a, 30.1f, 0.1f);
      EXPECT_NEAR(motor_status.current_phase_b, -15.2f, 0.1f);
      EXPECT_NEAR(motor_status.current_phase_c, -16.0f, 0.1f);
    }

  }
}
