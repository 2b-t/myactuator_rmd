/**
 * \file set_velocity_test.cpp
 * \mainpage
 *    Test parsing of set velocity request
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/messages/requests/set_velocity_request.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(SetVelocityRequestTest, parsingPositiveVelocity) {
      myactuator_rmd_driver::SetVelocityRequest const request ({0xA2, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00});
      auto const speed {request.getSpeed()};
      EXPECT_NEAR(speed, 100.0f, 0.1f);
    }

    TEST(SetVelocityRequestTest, parsingNegativeVelocity) {
      myactuator_rmd_driver::SetVelocityRequest const request ({0xA2, 0x00, 0x00, 0x00, 0xF0, 0xD8, 0xFF, 0xFF});
      auto const speed {request.getSpeed()};
      EXPECT_NEAR(speed, -100.0f, 0.1f);
    }

  }
}
