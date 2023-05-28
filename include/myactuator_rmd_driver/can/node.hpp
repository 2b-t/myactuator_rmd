/**
 * \file node.hpp
 * \mainpage
 *    Contains a basic CAN interface class wrapping SocketCAN
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__CAN__NODE
#define MYACTUATOR_RMD_DRIVER__CAN__NODE
#pragma once

#include <array>
#include <cstdint>
#include <string>


namespace myactuator_rmd_driver {
  namespace can {

    /**\class Node
     *  \brief
     *     Base class for sending basic CAN frames over SocketCAN
    */
    class Node {
      public:
        /**\fn Node
         * \brief
         *    Class constructor, initialises the socket that should be used for communication
         * 
         * \param[in] ifname
         *    The name of the network interface that should communicated over
        */
        Node(std::string const& ifname);
        Node() = delete;
        Node(Node const&) = delete;
        Node& operator = (Node const&) = default;
        Node(Node&&) = default;
        Node& operator = (Node&&) = default;
        ~Node();

        /**\fn setReadFilter
         * \brief
         *    Set a filter for receiving CAN frames only for specific IDs
         * 
         * \param[in] can_id
         *    The CAN id that should be accepted (discarded if \p is_invert set to true)
         * \param[in] is_invert
         *    Invert the CAN id. If set to true all messages of the given ID are discarded
        */
        void setReadFilter(std::uint32_t const& can_id, bool const is_invert = false);

        /**\fn read
         * \brief
         *    Blocking read a CAN frame
         * 
         * \return
         *    The read CAN frame if any
        */
        [[nodiscard]]
        std::array<std::uint8_t,8> read() const;

        /**\fn write
        * \brief
        *    Write the given data to a CAN frame with the corresponding can_id and enqueue it
        * 
        * \param[in] data
        *    The data to be sent
        * \param[in] can_id
        *   The CAN id that the data should be sent to
        */
        void write(std::array<std::uint8_t,8> const& data, std::uint32_t const& can_id);

      protected:
        std::string ifname_;
        int socket_;
    };

  }
}

#endif // MYACTUATOR_RMD_DRIVER__CAN__NODE
