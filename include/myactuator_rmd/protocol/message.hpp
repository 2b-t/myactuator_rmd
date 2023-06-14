/**
 * \file message.hpp
 * \mainpage
 *    Contains base class for any message to be exchanged between driver and actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__MESSAGE
#define MYACTUATOR_RMD__PROTOCOL__MESSAGE
#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <type_traits>


namespace myactuator_rmd {

  /**\class Message
   * \brief
   *    Base class for any message exchanged between the driver and the actuator
  */
  class Message {
    public:
      /**\fn getData
       * \brief
       *    Getter for data to e transmitted to CAN node
       * 
       * \param[in] data
       *    The data to be transmitted to the CAN node
      */
      [[nodiscard]]
      constexpr std::array<std::uint8_t,8> const& getData() const noexcept;

    protected:
      /**\fn Message
       * \brief
       *    Class constructor
       * 
       * \param[in] can_id
       *    The CAN id of the message
       * \param[in] data
       *    The data to be transmitted to the CAN node
      */
      constexpr Message(std::array<std::uint8_t,8> const& data = {}) noexcept;
      Message(Message const&) = default;
      Message& operator = (Message const&) = default;
      Message(Message&&) = default;
      Message& operator = (Message&&) = default;

      /**\fn setAt
       * \brief
       *    Sets the given value to the data values located at [i, i + sizeof(T)[ by reinterpret-casting
       * 
       * \tparam T
       *    Signed or unsigned integer type
       * \param[in] val
       *    The value that the data array at position \p i should be set to
       * \param[in] i
       *    The first index of the underlying data array that the value should be set to
      */
      template <typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
      void setAt(T const val, std::size_t const i);

      /**\fn getAs
       * \brief
       *    Convert elements of the array to a larger integer value by reinterpret-casting the underlying data
       * 
       * \tparam T
       *    Signed or unsigned integer type
       * \param[in] i
       *    The first index of the underlying data array that the value should be extracted from
       * \return
       *    The data values located at [i, i + sizeof(T)[ as an integer of type T
      */
      template <typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
      T getAs(std::size_t const i) const;

      std::array<std::uint8_t,8> data_;
  };

  constexpr std::array<std::uint8_t,8> const& Message::getData() const noexcept {
    return data_;
  }

  constexpr Message::Message(std::array<std::uint8_t,8> const& data) noexcept
  : data_{data} {
    return;
  }

  template <typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
  void Message::setAt(T const val, std::size_t const i) {
    if (i + sizeof(T)/sizeof(std::uint8_t) > data_.size()) {
      throw std::out_of_range("Requested index out of range!");
    }
    std::memcpy(&data_[i], &val, sizeof(T));
    return;
  }

  template <typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
  T Message::getAs(std::size_t const i) const {
    if (i + sizeof(T)/sizeof(std::uint8_t) > data_.size()) {
      throw std::out_of_range("Requested index out of range!");
    }
    T val {};
    std::memcpy(&val, &data_[i], sizeof(T));
    return val;
  }

}

#endif // MYACTUATOR_RMD__PROTOCOL__MESSAGE
