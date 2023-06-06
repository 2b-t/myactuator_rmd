/**
 * \file set_position_absolute_request_test.cpp
 * \mainpage
 *    Test parsing of position absolute request
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/messages/requests/set_position_absolute_request.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(SetPositionAbsoluteRequestTest, parsing) {
      myactuator_rmd_driver::SetPositionAbsoluteRequest const request ({0xA4, 0x00, 0xF4, 0x01, 0xA0, 0x8C, 0x00, 0x00});
      auto const position {request.getPosition()};
      EXPECT_NEAR(position, 360.0f, 0.1f);
      auto const max_speed {request.getMaxSpeed()};
      EXPECT_NEAR(max_speed, 500.0f, 0.1f);
    }

  }
}
