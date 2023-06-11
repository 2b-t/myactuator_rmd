/**
 * \file set_velocity_response_test.cpp
 * \mainpage
 *    Test parsing of set velocity response
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/protocol/responses/set_velocity_response.hpp"


namespace myactuator_rmd {
  namespace test {

    TEST(SetVelocityResponseTest, parsingPositiveValues) {
      myactuator_rmd::SetVelocityResponse const response {{0xA2, 0x32, 0x64, 0x00, 0xF4, 0x01, 0x2D, 0x00}};
      myactuator_rmd::Feedback const feedback {response.getStatus()};
      EXPECT_EQ(feedback.temperature, 50);
      EXPECT_NEAR(feedback.current, 1.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_speed, 500.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_angle, 45.0f, 0.1f);
    }

    TEST(SetVelocityResponseTest, parsingNegativeValues) {
      myactuator_rmd::SetVelocityResponse const response {{0xA2, 0x32, 0x9C, 0xFF, 0x0C, 0xFE, 0xD3, 0xFF}};
      myactuator_rmd::Feedback const feedback {response.getStatus()};
      EXPECT_EQ(feedback.temperature, 50);
      EXPECT_NEAR(feedback.current, -1.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_speed, -500.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_angle, -45.0f, 0.1f);
    }

  }
}
