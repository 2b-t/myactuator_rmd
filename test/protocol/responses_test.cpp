/**
 * \file responses.cpp
 * \mainpage
 *    Tests for parsing of different response messages
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <gtest/gtest.h>

#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/protocol/responses.hpp"


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

    TEST(GetMotorModelResponseTest, parsing) {
      myactuator_rmd::GetMotorModelResponse const response {{0xB5, 0x58, 0x38, 0x53, 0x32, 0x56, 0x31, 0x30}};
      std::string const version {response.getVersion()};
      EXPECT_EQ(version, "X8S2V10");
    }

    TEST(GetMotorStatus1ResponseTest, parsing) {
      myactuator_rmd::GetMotorStatus1Response const response {{0x9A, 0x32, 0x00, 0x01, 0xE5, 0x01, 0x04, 0x00}};
      myactuator_rmd::MotorStatus1 const motor_status {response.getStatus()};
      EXPECT_EQ(motor_status.temperature, 50);
      EXPECT_EQ(motor_status.is_brake_released, true);
      EXPECT_NEAR(motor_status.voltage, 48.5, 0.1);
      EXPECT_EQ(motor_status.error_code, myactuator_rmd::ErrorCode::LOW_VOLTAGE);
    }

    TEST(GetMotorStatus2ResponseTest, parsing) {
      myactuator_rmd::GetMotorStatus2Response const response {{0x9C, 0x32, 0x64, 0x00, 0xF4, 0x01, 0x2D, 0x00}};
      myactuator_rmd::MotorStatus2 const motor_status {response.getStatus()};
      EXPECT_EQ(motor_status.temperature, 50);
      EXPECT_NEAR(motor_status.current, 1.0f, 0.1f);
      EXPECT_NEAR(motor_status.shaft_speed, 500.0f, 0.1f);
      EXPECT_NEAR(motor_status.shaft_angle, 45.0f, 0.1f);
    }

    TEST(GetMotorStatus3ResponseTest, parsing) {
      myactuator_rmd::GetMotorStatus3Response const response {{0x9D, 0x32, 0xC2, 0x0B, 0x10, 0xFA, 0xC0, 0xF9}};
      myactuator_rmd::MotorStatus3 const motor_status {response.getStatus()};
      EXPECT_EQ(motor_status.temperature, 50);
      EXPECT_NEAR(motor_status.current_phase_a, 30.1f, 0.1f);
      EXPECT_NEAR(motor_status.current_phase_b, -15.2f, 0.1f);
      EXPECT_NEAR(motor_status.current_phase_c, -16.0f, 0.1f);
    }

    TEST(GetVersionDateResponseTest, parsing) {
      myactuator_rmd::GetVersionDateResponse const response {{0xB2, 0x00, 0x00, 0x00, 0x2E, 0x89, 0x34, 0x01}};
      auto const version {response.getVersion()};
      EXPECT_EQ(version, 20220206);
    }

    TEST(SetPositionAbsoluteResponseTest, parsingPositiveValues) {
      myactuator_rmd::SetPositionAbsoluteResponse const response {{0xA4, 0x32, 0x64, 0x00, 0xF4, 0x01, 0x2D, 0x00}};
      myactuator_rmd::Feedback const feedback {response.getStatus()};
      EXPECT_EQ(feedback.temperature, 50);
      EXPECT_NEAR(feedback.current, 1.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_speed, 500.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_angle, 45.0f, 0.1f);
    }

    TEST(SetPositionAbsoluteResponseTest, parsingNegativeValues) {
      myactuator_rmd::SetPositionAbsoluteResponse const response {{0xA4, 0x32, 0x9C, 0xFF, 0x0C, 0xFE, 0xD3, 0xFF}};
      myactuator_rmd::Feedback const feedback {response.getStatus()};
      EXPECT_EQ(feedback.temperature, 50);
      EXPECT_NEAR(feedback.current, -1.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_speed, -500.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_angle, -45.0f, 0.1f);
    }

    TEST(SetTorqueResponseTest, parsingPositiveValues) {
      myactuator_rmd::SetTorqueResponse const response {{0xA1, 0x32, 0x64, 0x00, 0xF4, 0x01, 0x2D, 0x00}};
      myactuator_rmd::Feedback const feedback {response.getStatus()};
      EXPECT_EQ(feedback.temperature, 50);
      EXPECT_NEAR(feedback.current, 1.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_speed, 500.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_angle, 45.0f, 0.1f);
    }

    TEST(SetTorqueResponseTest, parsingNegativeValues) {
      myactuator_rmd::SetTorqueResponse const response {{0xA1, 0x32, 0x9C, 0xFF, 0x0C, 0xFE, 0xD3, 0xFF}};
      myactuator_rmd::Feedback const feedback {response.getStatus()};
      EXPECT_EQ(feedback.temperature, 50);
      EXPECT_NEAR(feedback.current, -1.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_speed, -500.0f, 0.1f);
      EXPECT_NEAR(feedback.shaft_angle, -45.0f, 0.1f);
    }

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
