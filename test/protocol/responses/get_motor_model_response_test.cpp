/**
 * \file get_motor_model_response_test.cpp
 * \mainpage
 *    Test parsing of read motor model response
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/actuator_state/feedback.hpp"
#include "myactuator_rmd_driver/protocol/responses/get_motor_model_response.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(GetMotorModelResponseTest, parsing) {
      myactuator_rmd_driver::GetMotorModelResponse const response {{0xB5, 0x58, 0x38, 0x53, 0x32, 0x56, 0x31, 0x30}};
      std::string const version {response.getVersion()};
      EXPECT_EQ(version, "X8S2V10");
    }

  }
}
