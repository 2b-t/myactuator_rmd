/**
 * \file node.hpp
 * \mainpage
 *    Contains the base class for the driver as well as the actuator mock
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__NODE
#define MYACTUATOR_RMD__NODE
#pragma once

#include <cstdint>
#include <string>

#include "myactuator_rmd/can/frame.hpp"
#include "myactuator_rmd/can/node.hpp"
#include "myactuator_rmd/protocol/message.hpp"
#include "myactuator_rmd/protocol/requests/request.hpp"
#include "myactuator_rmd/protocol/responses/response.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  /**\class Node
   * \brief
   *    Base class for the driver as well as the actuator mock
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
       * \param[in] actuator_id
       *    The id of the actuator [0, 32]
      */
      Node(std::string const& ifname, std::uint32_t const actuator_id);
      Node() = delete;
      Node(Node const&) = delete;
      Node& operator = (Node const&) = default;
      Node(Node&&) = default;
      Node& operator = (Node&&) = default;

      /**\fn updateIds
       * \brief
       *    Updates the id as well as the send and receive ids in a consistent manner
       * 
       * \param[in] actuator_id
       *    The id of the actuator [0, 32]
      */
      void updateIds(std::uint32_t const actuator_id);

      /**\fn send
       * \brief
       *    Writes a given CAN frame based on the request to the internally saved send_id_
       * 
       * \param[in] msg
       *    The message that should be sent to the corresponding send_id_
      */
      inline void send(Message const& msg);

      /**\fn sendRecv
       * \brief
       *    Writes a given CAN frame based on the request to the internally saved send_id_
       *    and waits for a corresponding reply
       * 
       * \tparam RESPONSE_TYPE
       *    Type of the response
       * \param[in] request
       *    Request that should be sent to the corresponding send_id_
       * \return
       *    The parsed response message
      */
      template <typename RESPONSE_TYPE, typename REQUEST_TYPE>
      [[nodiscard]]
      inline RESPONSE_TYPE sendRecv(REQUEST_TYPE const& request);

    private:
      std::uint32_t actuator_id_;
      std::uint32_t can_send_id_;
      std::uint32_t can_receive_id_;
  };

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::Node(std::string const& ifname, std::uint32_t const actuator_id)
  : can::Node{ifname} {
    updateIds(actuator_id);
    return;
  }

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  void Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::updateIds(std::uint32_t const actuator_id) {
    if ((actuator_id < 1) || (actuator_id > 32)) {
      throw Exception("Given actuator id '" + std::to_string(actuator_id) + "' out of admittable range [1, 32]!");
    }
    actuator_id_ = actuator_id;
    can_send_id_ = SEND_ID_OFFSET + actuator_id_;
    can_receive_id_ = RECEIVE_ID_OFFSET + actuator_id_;
    setRecvFilter(can_receive_id_);
    return;
  }

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  void Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::send(Message const& msg) {
    write(can_send_id_, msg.getData());
    return;
  }

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  template <typename RESPONSE_TYPE, typename REQUEST_TYPE>
  RESPONSE_TYPE Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::sendRecv(REQUEST_TYPE const& request) {
    write(can_send_id_, request.getData());
    can::Frame const frame {can::Node::read()};
    RESPONSE_TYPE const response {frame.getData()};
    return response;
  }

}

#endif // MYACTUATOR_RMD__NODE
