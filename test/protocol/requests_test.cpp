/**
 * \file requests.cpp
 * \mainpage
 *    Tests for parsing of different request messages
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <chrono>
#include <cstdint>

#include <gtest/gtest.h>

#include "myactuator_rmd/actuator_state/acceleration_type.hpp"
#include "myactuator_rmd/actuator_state/baud_rate.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/protocol/requests.hpp"


namespace myactuator_rmd {
  namespace test {

    TEST(GetCanIdRequestTest, parsing) {
      myactuator_rmd::GetCanIdRequest const request {{0x79, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}};
      bool const is_write {request.isWrite()};
      EXPECT_EQ(is_write, false);
    }

    TEST(SetBaudRate0RequestTest, parsing) {
      myactuator_rmd::SetBaudRateRequest const request {{0xB4, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}};
      BaudRate const baud_rate {request.getBaudRate()};
      EXPECT_EQ(baud_rate, BaudRate::KBPS500);
    }

    TEST(SetBaudRate1RequestTest, parsing) {
      myactuator_rmd::SetBaudRateRequest const request {{0xB4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01}};
      BaudRate const baud_rate {request.getBaudRate()};
      EXPECT_EQ(baud_rate, BaudRate::MBPS1);
    }

    TEST(SetEncoderZeroRequestTest, parsing) {
      myactuator_rmd::SetEncoderZeroRequest const response {{0x63, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00}};
      auto const encoder_zero {response.getEncoderZero()};
      EXPECT_EQ(encoder_zero, 10000);
    }

    TEST(SetPositionPlanningAccelerationRequestTest, parsing) {
      myactuator_rmd::SetAccelerationRequest const request {{0x43, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00}};
      std::uint32_t const acceleration {request.getAcceleration()};
      AccelerationType const mode {request.getMode()};
      EXPECT_EQ(acceleration, 10000);
      EXPECT_EQ(mode, AccelerationType::POSITION_PLANNING_ACCELERATION);
    }

    TEST(SetPositionPlanningDecelerationRequestTest, parsing) {
      myactuator_rmd::SetAccelerationRequest const request {{0x43, 0x01, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00}};
      std::uint32_t const acceleration {request.getAcceleration()};
      AccelerationType const mode {request.getMode()};
      EXPECT_EQ(acceleration, 10000);
      EXPECT_EQ(mode, AccelerationType::POSITION_PLANNING_DECELERATION);
    }

    TEST(SetVelocityPlanningAccelerationRequestTest, parsing) {
      myactuator_rmd::SetAccelerationRequest const request {{0x43, 0x02, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00}};
      std::uint32_t const acceleration {request.getAcceleration()};
      AccelerationType const mode {request.getMode()};
      EXPECT_EQ(acceleration, 10000);
      EXPECT_EQ(mode, AccelerationType::VELOCITY_PLANNING_ACCELERATION);
    }

    TEST(SetVelocityPlanningDecelerationRequestTest, parsing) {
      myactuator_rmd::SetAccelerationRequest const request {{0x43, 0x03, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00}};
      std::uint32_t const acceleration {request.getAcceleration()};
      AccelerationType const mode {request.getMode()};
      EXPECT_EQ(acceleration, 10000);
      EXPECT_EQ(mode, AccelerationType::VELOCITY_PLANNING_DECELERATION);
    }

    TEST(SetControllerGainsPersistentlyRequestTest, parsing) {
      myactuator_rmd::SetControllerGainsPersistentlyRequest const request {{0x32, 0x00, 0x55, 0x19, 0x55, 0x19, 0x55, 0x19}};
      myactuator_rmd::Gains const gains {request.getGains()};
      EXPECT_EQ(gains.current.kp, 85);
      EXPECT_EQ(gains.current.ki, 25);
      EXPECT_EQ(gains.speed.kp, 85);
      EXPECT_EQ(gains.speed.ki, 25);
      EXPECT_EQ(gains.position.kp, 85);
      EXPECT_EQ(gains.position.ki, 25);
    }

    TEST(SetControllerGainsRequestTest, parsing) {
      myactuator_rmd::SetControllerGainsRequest const request {{0x31, 0x00, 0x55, 0x19, 0x55, 0x19, 0x55, 0x19}};
      myactuator_rmd::Gains const gains {request.getGains()};
      EXPECT_EQ(gains.current.kp, 85);
      EXPECT_EQ(gains.current.ki, 25);
      EXPECT_EQ(gains.speed.kp, 85);
      EXPECT_EQ(gains.speed.ki, 25);
      EXPECT_EQ(gains.position.kp, 85);
      EXPECT_EQ(gains.position.ki, 25);
    }

    TEST(SetPositionAbsoluteRequestTest, parsingPositivePosition) {
      myactuator_rmd::SetPositionAbsoluteRequest const request ({0xA4, 0x00, 0xF4, 0x01, 0xA0, 0x8C, 0x00, 0x00});
      auto const position {request.getPosition()};
      EXPECT_NEAR(position, 360.0f, 0.1f);
      auto const max_speed {request.getMaxSpeed()};
      EXPECT_NEAR(max_speed, 500.0f, 0.1f);
    }

    TEST(SetPositionAbsoluteRequestTest, parsingNegativePosition) {
      myactuator_rmd::SetPositionAbsoluteRequest const request ({0xA4, 0x00, 0xF4, 0x01, 0x60, 0x73, 0xFF, 0xFF});
      auto const position {request.getPosition()};
      EXPECT_NEAR(position, -360.0f, 0.1f);
      auto const max_speed {request.getMaxSpeed()};
      EXPECT_NEAR(max_speed, 500.0f, 0.1f);
    }

    TEST(SetTimeoutOffRequestTest, parsing) {
      myactuator_rmd::SetTimeoutRequest const request {{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
      std::chrono::milliseconds const timeout {request.getTimeout()};
      EXPECT_EQ(timeout.count(), 0);
    }

    TEST(SetTimeoutRequestTest, parsing) {
      myactuator_rmd::SetTimeoutRequest const request {{0xB3, 0x00, 0x00, 0x00, 0xE8, 0x03, 0x00, 0x00}};
      std::chrono::milliseconds const timeout {request.getTimeout()};
      EXPECT_EQ(timeout.count(), 1000);
    }

    TEST(SetTorqueRequestTest, parsingPositiveCurrent) {
      myactuator_rmd::SetTorqueRequest const request ({0xA1, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00});
      auto const current {request.getTorqueCurrent()};
      EXPECT_NEAR(current, 1.0f, 0.1f);
    }

    TEST(SetTorqueRequestTest, parsingNegativeCurrent) {
      myactuator_rmd::SetTorqueRequest const request ({0xA1, 0x00, 0x00, 0x00, 0x9C, 0xFF, 0x00, 0x00});
      auto const current {request.getTorqueCurrent()};
      EXPECT_NEAR(current, -1.0f, 0.1f);
    }

    TEST(SetVelocityRequestTest, parsingPositiveVelocity) {
      myactuator_rmd::SetVelocityRequest const request ({0xA2, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00});
      auto const speed {request.getSpeed()};
      EXPECT_NEAR(speed, 100.0f, 0.1f);
    }

    TEST(SetVelocityRequestTest, parsingNegativeVelocity) {
      myactuator_rmd::SetVelocityRequest const request ({0xA2, 0x00, 0x00, 0x00, 0xF0, 0xD8, 0xFF, 0xFF});
      auto const speed {request.getSpeed()};
      EXPECT_NEAR(speed, -100.0f, 0.1f);
    }

  }
}
