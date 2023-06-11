/**
 * \file frame.hpp
 * \mainpage
 *    Contains class for a data frame in the CAN bus protocol
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__CAN__FRAME
#define MYACTUATOR_RMD__CAN__FRAME
#pragma once

#include <array>
#include <cstdint>


namespace myactuator_rmd {
  namespace can {

    /**\class Frame
     * \brief
     *    Class for a frame of the CAN bus protocol, see https://en.wikipedia.org/wiki/CAN_bus
     *    This class replaces the Linux SocketCAN frame struct in order to be more portable
    */
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

        /**\fn getId
         * \brief
         *    Getter for the frame CAN id
         * 
         * \return
         *    The destination frame id of the CAN frame
        */
        [[nodiscard]]
        constexpr std::uint32_t getId() const noexcept;

        /**\fn getData
         * \brief
         *    Getter for data to be transmitted to CAN node
         * 
         * \return
         *    The data to be transmitted to the CAN node
        */
        [[nodiscard]]
        constexpr std::array<std::uint8_t,8> const& getData() const noexcept;

      protected:
        std::uint32_t can_id_;
        std::array<std::uint8_t,8> data_;
    };

    constexpr Frame::Frame(std::uint32_t const can_id, std::array<std::uint8_t,8> const& data) noexcept
    : can_id_{can_id}, data_{data} {
      return;
    }

    constexpr std::uint32_t Frame::getId() const noexcept {
      return can_id_;
    }
      
    constexpr std::array<std::uint8_t,8> const& Frame::getData() const noexcept {
      return data_;
    }

  }
}

#endif // MYACTUATOR_RMD__CAN__FRAME
