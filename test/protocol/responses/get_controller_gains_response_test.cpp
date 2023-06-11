/**
 * \file get_controller_gains_response_test.cpp
 * \mainpage
 *    Test parsing of get controller gains response
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/responses/get_controller_gains_response.hpp"


namespace myactuator_rmd {
  namespace test {

    TEST(GetControllerGainsResponseTest, parsing) {
      myactuator_rmd::GetControllerGainsResponse const response {{0x30, 0x00, 0x55, 0x19, 0x55, 0x19, 0x55, 0x19}};
      myactuator_rmd::Gains const gains {response.getGains()};
      EXPECT_EQ(gains.current.kp, 85);
      EXPECT_EQ(gains.current.ki, 25);
      EXPECT_EQ(gains.speed.kp, 85);
      EXPECT_EQ(gains.speed.ki, 25);
      EXPECT_EQ(gains.position.kp, 85);
      EXPECT_EQ(gains.position.ki, 25);
    }

  }
}
