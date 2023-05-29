/**
 * \file frame.hpp
 * \mainpage
 *    Contains base class for a CAN data frame
 *    This frame replaces the Linux CAN frame struct in order to be portable
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__CAN__FRAME
#define MYACTUATOR_RMD_DRIVER__CAN__FRAME
#pragma once

#include <array>
#include <cstdint>


namespace myactuator_rmd_driver {
  namespace can {

    class Frame {
      public:
        /**\fn Frame
         * \brief
         *    Class constructor
         * 
         * \param[in] can_id
         *    The CAN id of the message
         * \param[in] data
         *    The data to be transmitted to the CAN node
        */
        constexpr Frame(std::uint32_t const can_id, std::array<std::uint8_t,8> const& data) noexcept;
        Frame() = delete;
        Frame(Frame const&) = default;
        Frame& operator = (Frame const&) = default;
        Frame(Frame&&) = default;
        Frame& operator = (Frame&&) = default;

        /**\fn getCanId
         * \brief
         *    Getter for the message CAN id
         * 
         * \return
         *    The CAN id of the message
        */
        inline constexpr std::uint32_t getCanId() const noexcept;

        /**\fn getData
         * \brief
         *    Getter for data to e transmitted to CAN node
         * 
         * \return
         *    The data to be transmitted to the CAN node
        */
        inline constexpr std::array<std::uint8_t,8> const& getData() const noexcept;

      protected:
        std::uint32_t can_id_;
        std::array<std::uint8_t,8> data_;
    };

    constexpr Frame::Frame(std::uint32_t const can_id, std::array<std::uint8_t,8> const& data) noexcept
    : can_id_{can_id}, data_{data} {
      return;
    }

    constexpr std::uint32_t Frame::getCanId() const noexcept {
      return can_id_;
    }
      
    constexpr std::array<std::uint8_t,8> const& Frame::getData() const noexcept {
      return data_;
    }

  }
}


#endif // MYACTUATOR_RMD_DRIVER__CAN__FRAME