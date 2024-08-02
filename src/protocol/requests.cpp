#include "myactuator_rmd/protocol/requests.hpp"

#include <chrono>
#include <cstdint>
#include <cstring>
#include <string>
#include <bitset>
#include <array>

#include "myactuator_rmd/actuator_state/acceleration_type.hpp"
#include "myactuator_rmd/actuator_state/can_baud_rate.hpp"
#include "myactuator_rmd/protocol/single_motor_message.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  namespace motion_mode {
    MotionModeControlRequest::MotionModeControlRequest(float const p_des,    float const v_des, std::uint16_t const kp, std::uint16_t const kd, float const t_ff)
    : Message{} {
      // Convert from float radians to uint16_t for data field.
      // Position -12.5 rad to 12.5 rad, int 0 to 65535.
      auto const p_int {static_cast<std::uint16_t>((p_des + 12.5f) * 2621.4f)};
      // Velocity -45 rad/s to 45 rad/s, int 0 to 4095 (12-bit).
      auto const v_int {static_cast<std::uint16_t>((v_des + 45.0f) * 45.5f)};
      // Ff-torque -24 Nm to 24 Nm, int 0 to 4095 (12-bit).
      auto const t_int {static_cast<std::uint16_t>((t_ff + 24.0f) * 85.3125f)};

      // Create bitsets for each parameter. 
      std::bitset<16> const p_bit {p_int};
      std::bitset<12> const v_bit {v_int};
      std::bitset<12> const kp_bit {kp};
      std::bitset<12> const kd_bit {kd};
      std::bitset<12> const t_bit {t_int};
      
      // std::cout << "p_bit\t" << p_bit << std::endl;
      // std::cout << "v_bit\t" << v_bit << std::endl;
      // std::cout << "kp_bit\t" << kp_bit << std::endl;
      // std::cout << "kd_bit\t" << kd_bit << std::endl;
      // std::cout << "t_bit\t" << t_bit << std::endl;

      // Create bitset for entire message.
      std::bitset<64> bit_msg {};

      // Copy parameter bitsets to message bitset.
      for (std::size_t i = 0; i < 16; ++i) {
        bit_msg.set(i + 48, p_bit.test(i));
      }
      for (std::size_t i = 0; i < 12; ++i) {
        bit_msg.set(i + 36, v_bit.test(i));
        bit_msg.set(i + 24, kp_bit.test(i));
        bit_msg.set(i + 12, kd_bit.test(i));
        bit_msg.set(i, t_bit.test(i));
      }

      // std::cout << "bit msg\t" << bit_msg << std::endl;
      // std::cout << std::endl;

      // Taken from https://stackoverflow.com/a/58979953
      std::bitset<64> const mask {0xff};
      // std::array<std::uint8_t, 8> msg {};
      for (std::size_t i = 0; i < bit_msg.size()/8; ++i) {
        Message::data_.at(Message::data_.size() - 1 - i) = static_cast<std::uint8_t>(((bit_msg >> (8*i)) & mask).to_ulong());
      }

      // Message::data_ = msg;
      return;
    }
  }

  bool CanIdRequest::isWrite() const noexcept {
    return (getAs<std::uint8_t>(2) == 0) ? true : false;
  }

  GetCanIdRequest::GetCanIdRequest()
  : CanIdRequest{}  {
    setAt(static_cast<std::uint8_t>(1), 2);
    return;
  }

  SetCanIdRequest::SetCanIdRequest(std::uint16_t const can_id)
  : CanIdRequest{}  {
    setAt(static_cast<std::uint8_t>(0), 2);
    setAt(static_cast<std::uint8_t>(can_id), 6);
    return;
  }

  std::uint16_t SetCanIdRequest::getCanId() const noexcept {
    return static_cast<std::uint16_t>(getAs<std::uint8_t>(7));
  }

  SetAccelerationRequest::SetAccelerationRequest(std::uint32_t const acceleration, AccelerationType const mode)
  : SingleMotorRequest{} {
    if ((acceleration != 0) && ((acceleration < 100) || (acceleration > 60000))) {
      throw ValueRangeException("Acceleration value '" + std::to_string(acceleration) + "' out of range [100, 60000]");
    }
    auto const acceleration_type {static_cast<std::uint8_t>(mode)};
    setAt(acceleration_type, 1);
    setAt(acceleration, 4);
    return;
  }

  std::uint32_t SetAccelerationRequest::getAcceleration() const noexcept {
    return getAs<std::uint32_t>(4);
  }

  AccelerationType SetAccelerationRequest::getMode() const noexcept {
    return static_cast<AccelerationType>(getAs<std::uint8_t>(1));
  }

  SetCanBaudRateRequest::SetCanBaudRateRequest(CanBaudRate const baud_rate)
  : SingleMotorRequest{} {
    setAt(static_cast<std::uint8_t>(baud_rate), 7);
    return;
  }

  CanBaudRate SetCanBaudRateRequest::getBaudRate() const noexcept {
    return static_cast<CanBaudRate>(getAs<std::uint8_t>(7));
  }

  SetEncoderZeroRequest::SetEncoderZeroRequest(std::int32_t const encoder_offset)
  : SingleMotorRequest{} {
    setAt(encoder_offset, 4);
    return;
  }

  std::int32_t SetEncoderZeroRequest::getEncoderZero() const noexcept {
    return getAs<std::int32_t>(4);
  }

  SetPositionAbsoluteRequest::SetPositionAbsoluteRequest(float const position, float const max_speed)
  : SingleMotorRequest{} {
    auto const v {static_cast<std::uint16_t>(max_speed)};
    auto const pos {static_cast<std::int32_t>(position*100.0f)};
    setAt(v, 2);
    setAt(pos, 4);
    return;
  }

  float SetPositionAbsoluteRequest::getMaxSpeed() const noexcept {
    return static_cast<float>(getAs<std::uint16_t>(2));
  }

  float SetPositionAbsoluteRequest::getPosition() const noexcept {
    return static_cast<float>(getAs<std::int32_t>(4)/100.0f);
  }

  SetTorqueRequest::SetTorqueRequest(float const current)
  : SingleMotorRequest{} {
    auto const c {static_cast<std::int16_t>(current/0.01f)};
    setAt(c, 4);
    return;
  }

  float SetTorqueRequest::getTorqueCurrent() const noexcept {
    return static_cast<float>(getAs<std::int16_t>(4))*0.01f;
  }

  SetTimeoutRequest::SetTimeoutRequest(std::chrono::milliseconds const& timeout) {
    setAt(static_cast<std::uint32_t>(timeout.count()), 4);
    return;
  }

  std::chrono::milliseconds SetTimeoutRequest::getTimeout() const noexcept {
    std::chrono::milliseconds const timeout {getAs<std::uint32_t>(4)};
    return timeout;
  }

  SetVelocityRequest::SetVelocityRequest(float const speed)
  : SingleMotorRequest{} {
    auto const s {static_cast<std::int32_t>(speed*100.0f)};
    setAt(s, 4);
    return;
  }

  float SetVelocityRequest::getSpeed() const noexcept {
    return static_cast<float>(getAs<std::int32_t>(4))/100.0f;
  }

}
