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
#include <chrono>
#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/can/frame.hpp"


namespace myactuator_rmd_driver {
  namespace can {

    /**\class Node
     *  \brief
     *     Base class for sending and receiving CAN frames over SocketCAN with a default 8*uint8 length
     *     in a blocking manner
    */
    class Node {
      public:
        /**\fn Node
         * \brief
         *    Class constructor, initialises the socket that should be used for communication and sets up debugging
         * 
         * \param[in] ifname
         *    The name of the network interface that should communicated over
         * \param[in] send_timeout
         *    The send timeout for the underlying socket
         * \param[in] receive_timeout
         *    The receive timeout for the underlying socket
        */
        Node(std::string const& ifname, std::chrono::microseconds const& send_timeout = std::chrono::seconds(1), 
             std::chrono::microseconds const& receive_timeout = std::chrono::seconds(1));
        Node() = delete;
        Node(Node const&) = delete;
        Node& operator = (Node const&) = default;
        Node(Node&&) = default;
        Node& operator = (Node&&) = default;
        ~Node();

        /**\fn setLoopback
         * \brief
         *    Set the socket to also receive its own messages, this can be desirable for debugging
         * 
         * \param[in] is_loopback
         *    If set to true the node will also receive its own messages
        */
        void setLoopback(bool const is_loopback);

        /**\fn setRecvFilter
         * \brief
         *    Set a filter for receiving CAN frames only for specific IDs
         * 
         * \param[in] can_id
         *    The CAN id that should be accepted (discarded if \p is_invert set to true)
         * \param[in] is_invert
         *    Invert the CAN id filter: If set to true all messages of the given ID are discarded
        */
        void setRecvFilter(std::uint32_t const& can_id, bool const is_invert = false);

        /**\fn setSendTimeout
         * \brief
         *    Set socket timeout for sending frames
         * 
         * \param[in] timeout
         *    Timeout that the socket should be set to for sending frames
        */
        void setSendTimeout(std::chrono::microseconds const& timeout);

        /**\fn setRecvTimeout
         * \brief
         *    Set socket timeout for receiving frames
         * 
         * \param[in] timeout
         *    Timeout that the socket should be set to for receiving frames
        */
        void setRecvTimeout(std::chrono::microseconds const& timeout);

        /**\fn setErrorFilters
         * \brief
         *    Set error filters for the socket. We will only receive error frames if we explicitly activate it!
         * 
         * \param[in] timeout
         *    Timeout that the socket should be set to for receiving frames
        */
        void setErrorFilters(bool const is_signal_errors);

        /**\fn read
         * \brief
         *    Blocking read a CAN frame
         *    Only CAN frames that a receive filter was set for can be read
         * 
         * \return
         *    The read CAN frame if any
        */
        [[nodiscard]]
        Frame read() const;

        /**\fn write
         * \brief
         *   Write the given CAN frame by calling the implementation below
         * 
         * \param[in] frame
         *    The CAN frame to be written
        */
        void write(Frame const& frame);

        /**\fn write
         * \brief
         *    Write the given data to a CAN frame with the corresponding can_id and enqueue it
         * 
         * \param[in] can_id
         *   The CAN id that the data should be sent to
         * \param[in] data
         *    The data to be sent
        */
        void write(std::uint32_t const can_id, std::array<std::uint8_t,8> const& data);

      protected:
        /**\fn initSocket
         * \brief
         *    Initialise a socket for the given network interface
         * 
         * \param[in] ifname
         *    The name of the network interface that should communicated over
        */
        void initSocket(std::string const& ifname);

        /**\fn closeSocket
         * \brief
         *    Close the underlying socket
        */
        void closeSocket() noexcept;

        std::string ifname_;
        int socket_;
    };

  }
}

#endif // MYACTUATOR_RMD_DRIVER__CAN__NODE
