/**
 * \file set_position_absolute_response_test.cpp
 * \mainpage
 *    Test parsing of position absolute response
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/messages/responses/set_position_absolute_response.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(SetPositionAbsoluteResponseTest, parsing) {
      myactuator_rmd_driver::SetPositionAbsoluteResponse const response ({0xA4, 0x32, 0x64, 0x00, 0xF4, 0x01, 0x2D, 0x00});
      auto const temperature {response.getTemperature()};
      EXPECT_NEAR(temperature, 50.0f, 0.1f);
      auto const current {response.getTorqueCurrent()};
      EXPECT_NEAR(current, 1.0f, 0.1f);
      auto const speed {response.getShaftSpeed()};
      EXPECT_NEAR(speed, 500.0f, 0.1f);
      auto const angle {response.getShaftAngle()};
      EXPECT_NEAR(angle, 45.0f, 0.1f);
    }

  }
}
