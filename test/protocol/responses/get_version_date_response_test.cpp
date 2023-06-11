/**
 * \file get_version_date_response_test.cpp
 * \mainpage
 *    Test parsing of get version date response
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/actuator_state/feedback.hpp"
#include "myactuator_rmd_driver/protocol/responses/get_version_date_response.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(GetVersionDateResponseTest, parsing) {
      myactuator_rmd_driver::GetVersionDateResponse const response {{0xB2, 0x00, 0x00, 0x00, 0x2E, 0x89, 0x34, 0x01}};
      auto const version {response.getVersion()};
      EXPECT_EQ(version, 20220206);
    }

  }
}
