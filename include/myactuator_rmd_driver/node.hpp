/**
 * \file node.hpp
 * \mainpage
 *    Contains the base class for the driver as well as the actuator mock
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__NODE
#define MYACTUATOR_RMD_DRIVER__NODE
#pragma once

#include <array>
#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/can/node.hpp"
#include "myactuator_rmd_driver/exceptions.hpp"


namespace myactuator_rmd_driver {

  /**\class Node
   * \brief
   *    Base class for the driver as well as the actuator mock
   *
   * \tparam SEND_ID_OFFSET
   *    The offset of the CAN id for sending messages
   * \tparam RECEIVE_ID_OFFSET
   *    The offset of the CAN id for receiving messages 
  */
  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  class Node: protected can::Node {
    protected:
      /**\fn Node
       * \brief
       *    Class constructor
       * 
       * \param[in] ifname
       *    The name of the network interface that should communicated over
       * \param[in] id
       *    The CAN id of the node
      */
      Node(std::string const& ifname, std::uint32_t const id);
      Node() = delete;
      Node(Node const&) = delete;
      Node& operator = (Node const&) = default;
      Node(Node&&) = default;
      Node& operator = (Node&&) = default;

      /**\fn updateIds
       * \brief
       *    Updates the id as well as the send and receive ids in a consistent manner
       * 
       * \param[in] id
       *    The CAN id of the node
      */
      void updateIds(std::uint32_t const id);

      /**\fn write
       * \brief
       *    Writes a given CAN frame with the given data and the set send_id_
       * 
       * \param[in] data
       *    Data that should be sent to the corresponding send_id_
      */
      inline void write(std::array<std::uint8_t,8> const& data);

    private:
      std::uint32_t id_;
      std::uint32_t send_id_;
      std::uint32_t receive_id_;
  };

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::Node(std::string const& ifname, std::uint32_t const id)
  : can::Node{ifname} {
    updateIds(id);
    return;
  }

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  void Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::updateIds(std::uint32_t const id) {
    if ((id < 1) || (id > 32)) {
      throw Exception("Given id '" + std::to_string(id) + "' out of admittable range [1, 32]!");
    }
    id_ = id;
    send_id_ = SEND_ID_OFFSET + id_;
    receive_id_ = RECEIVE_ID_OFFSET + id_;
    setRecvFilter(receive_id_);
    return;
  }

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  void Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::write(std::array<std::uint8_t,8> const& data) {
    return can::Node::write(data, send_id_);
  }

}

#endif // MYACTUATOR_RMD_DRIVER__NODE
