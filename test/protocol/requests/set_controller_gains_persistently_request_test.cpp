/**
 * \file set_controller_gains_persistently_request_test.cpp
 * \mainpage
 *    Test parsing of set controller gains persistently_request
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/actuator_state/gains.hpp"
#include "myactuator_rmd_driver/protocol/requests/set_controller_gains_persistently_request.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(SetControllerGainsPersistentlyRequestTest, parsing) {
      myactuator_rmd_driver::SetControllerGainsPersistentlyRequest const request {{0x31, 0x00, 0x55, 0x19, 0x55, 0x19, 0x55, 0x19}};
      myactuator_rmd_driver::Gains const gains {request.getGains()};
      EXPECT_EQ(gains.current.kp, 85);
      EXPECT_EQ(gains.current.ki, 25);
      EXPECT_EQ(gains.speed.kp, 85);
      EXPECT_EQ(gains.speed.ki, 25);
      EXPECT_EQ(gains.position.kp, 85);
      EXPECT_EQ(gains.position.ki, 25);
    }

  }
}
