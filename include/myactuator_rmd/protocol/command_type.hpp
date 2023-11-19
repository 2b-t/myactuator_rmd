/**
 * \file command_type.hpp
 * \mainpage
 *    Contains enum for all supported command types
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__COMMAND_TYPE
#define MYACTUATOR_RMD__PROTOCOL__COMMAND_TYPE
#pragma once

#include <cstdint>


namespace myactuator_rmd {

  /**\enum CommandType
   * \brief
   *    Strongly typed enum for all supported command types
  */
  enum class CommandType: std::uint8_t {
    READ_PID_PARAMETERS = 0x30,
    WRITE_PID_PARAMETERS_TO_RAM = 0x31,
    WRITE_PID_PARAMETERS_TO_ROM = 0x32,
    READ_ACCELERATION = 0x42,
    WRITE_ACCELERATION_TO_RAM_AND_ROM = 0x43,
    READ_MULTI_TURN_ENCODER_POSITION = 0x60,
    READ_MULTI_TURN_ENCODER_ORIGINAL_POSITION = 0x61,
    READ_MULTI_TURN_ENCODER_ZERO_OFFSET = 0x62,
    WRITE_ENCODER_MULTI_TURN_VALUE_TO_ROM_AS_ZERO = 0x63,
    WRITE_CURRENT_MULTI_TURN_POSITION_TO_ROM_AS_ZERO = 0x64,
    READ_SINGLE_TURN_ENCODER = 0x90,
    READ_MULTI_TURN_ANGLE = 0x92,
    READ_SINGLE_TURN_ANGLE = 0x94,
    READ_MOTOR_STATUS_1_AND_ERROR_FLAG = 0x9A,
    READ_MOTOR_STATUS_2 = 0x9C,
    READ_MOTOR_STATUS_3 = 0x9D,
    SHUTDOWN_MOTOR = 0x80,
    STOP_MOTOR = 0x81,
    TORQUE_CLOSED_LOOP_CONTROL = 0xA1,
    SPEED_CLOSED_LOOP_CONTROL = 0xA2,
    ABSOLUTE_POSITION_CLOSED_LOOP_CONTROL = 0xA4,
    // SINGLE_TURN_POSITION_CONTROL = 0xA6,
    // INCREMENTAL_POSITION_CLOSED_LOOP_CONTROL = 0xA8,
    READ_SYSTEM_OPERATING_MODE = 0x70,
    READ_MOTOR_POWER = 0x71,
    RESET_SYSTEM = 0x76,
    RELEASE_BRAKE = 0x77,
    LOCK_BRAKE = 0x78,
    READ_SYSTEM_RUNTIME = 0xB1,
    READ_SYSTEM_SOFTWARE_VERSION_DATE = 0xB2,
    COMMUNICATION_INTERRUPTION_PROTECTION_TIME_SETTING = 0xB3,
    COMMUNICATION_BAUD_RATE_SETTING = 0xB4,
    READ_MOTOR_MODEL = 0xB5,
    // FUNCTION_CONTROL = 0x20,
    CAN_ID_SETTING = 0x79
  };

  // Symmetric comparison operators
  constexpr bool operator == (CommandType const& c, std::uint8_t const i) noexcept {
    return i == static_cast<std::uint8_t>(c);
  }
  constexpr bool operator == (std::uint8_t const i, CommandType const& c) noexcept {
    return operator == (c, i);
  }

  constexpr bool operator != (CommandType const& c, std::uint8_t const i) noexcept {
    return !(operator == (c, i));
  }
  constexpr bool operator != (std::uint8_t const i, CommandType const& c) noexcept {
    return operator != (c, i);
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__COMMAND_TYPE
