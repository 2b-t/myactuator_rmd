/**
 * \file set_torque_request_test.cpp
 * \mainpage
 *    Test parsing of set torque request
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/protocol/requests/set_torque_request.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(SetTorqueRequestTest, parsingPositiveCurrent) {
      myactuator_rmd_driver::SetTorqueRequest const request ({0xA1, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00});
      auto const current {request.getTorqueCurrent()};
      EXPECT_NEAR(current, 1.0f, 0.1f);
    }

    TEST(SetTorqueRequestTest, parsingNegativeCurrent) {
      myactuator_rmd_driver::SetTorqueRequest const request ({0xA1, 0x00, 0x00, 0x00, 0x9C, 0xFF, 0x00, 0x00});
      auto const current {request.getTorqueCurrent()};
      EXPECT_NEAR(current, -1.0f, 0.1f);
    }

  }
}
