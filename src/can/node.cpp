#include "myactuator_rmd/can/node.hpp"

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <system_error>
#include <vector>

#include <linux/can.h>
#include <linux/can/error.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "myactuator_rmd/can/exceptions.hpp"
#include "myactuator_rmd/can/frame.hpp"
#include "myactuator_rmd/can/utilities.hpp"


namespace myactuator_rmd {
  namespace can {

    Node::Node(std::string const& ifname, std::chrono::microseconds const& send_timeout, std::chrono::microseconds const& receive_timeout,
               bool const is_signal_errors)
    : ifname_{}, socket_{-1} {
      initSocket(ifname);
      setSendTimeout(send_timeout);
      setRecvTimeout(receive_timeout);
      setErrorFilters(is_signal_errors);
      return;
    }

    Node::~Node() {
      closeSocket();
      return;
    }

    void Node::setLoopback(bool const is_loopback) {
      int const recv_own_msgs {static_cast<int>(is_loopback)};
      if (::setsockopt(socket_, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS, &recv_own_msgs, sizeof(int)) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Could not configure loopback");
      }
      return;
    }

    void Node::setRecvFilter(std::vector<std::uint32_t> const& can_ids, bool const is_invert) {
      std::vector<struct ::can_filter> filters {};
      filters.resize(can_ids.size());
      for (std::size_t i = 0; i < can_ids.size(); ++i) {
        auto const& can_id {can_ids[i]};
        if (is_invert) {
          filters[i].can_id = can_id | CAN_INV_FILTER;;
        } else {
          filters[i].can_id = can_id;
        }
        filters[i].can_mask = CAN_SFF_MASK;
      }
      if (::setsockopt(socket_, SOL_CAN_RAW, CAN_RAW_FILTER, filters.data(), sizeof(::can_filter)*filters.size()) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Could not configure read filter");
      }
      return;
    }

    void Node::setSendTimeout(std::chrono::microseconds const& timeout) {
      struct ::timeval const send_timeout {myactuator_rmd::toTimeval(timeout)};
      if (::setsockopt(socket_, SOL_SOCKET, SO_SNDTIMEO, reinterpret_cast<const char*>(&send_timeout), sizeof(struct ::timeval)) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Error setting socket timeout");
      }
      return;
    }

    void Node::setRecvTimeout(std::chrono::microseconds const& timeout) {
      struct ::timeval const recv_timeout {myactuator_rmd::toTimeval(timeout)};
      if (::setsockopt(socket_, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<const char*>(&recv_timeout), sizeof(struct ::timeval)) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Error setting socket timeout");
      }
      return;
    }

    void Node::setErrorFilters(bool const is_signal_errors) {
      // See https://github.com/linux-can/can-utils/blob/master/include/linux/can/error.h
      ::can_err_mask_t err_mask {};
      if (is_signal_errors) {
        err_mask = (CAN_ERR_TX_TIMEOUT | CAN_ERR_LOSTARB | CAN_ERR_CRTL | CAN_ERR_PROT | CAN_ERR_TRX | 
                    CAN_ERR_ACK | CAN_ERR_BUSOFF | CAN_ERR_BUSERROR | CAN_ERR_RESTARTED);
      }
      if (::setsockopt(socket_, SOL_CAN_RAW, CAN_RAW_ERR_FILTER, &err_mask, sizeof(::can_err_mask_t)) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Error setting error acknowledgement");
      }
      return;
    }

    Frame Node::read() const {
      struct ::can_frame frame {};
      if (::read(socket_, &frame, sizeof(struct ::can_frame)) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Could not read CAN frame");
      }
      // We will only receive these frames if the corresponding error mask is set
      // See https://github.com/linux-can/can-utils/blob/master/include/linux/can/error.h
      if (frame.can_id & CAN_ERR_FLAG){
        std::ostringstream ss {};
        ss << frame;
        if (frame.can_id & CAN_ERR_TX_TIMEOUT) {
          throw TxTimeoutError("Send timeout");
        } else if (frame.can_id & CAN_ERR_LOSTARB) {
          throw LostArbitrationError("CAN frame '" + ss.str() + "'");
        } else if (frame.can_id & CAN_ERR_CRTL) {
          throw ControllerProblemError("CAN frame '" + ss.str() + "'");
        } else if (frame.can_id & CAN_ERR_PROT) {
          throw ProtocolViolationError("CAN frame '" + ss.str() + "'");
        } else if (frame.can_id & CAN_ERR_TRX) {
          throw TransceiverStatusError("CAN frame '" + ss.str() + "'");
        } else if (frame.can_id & CAN_ERR_ACK) {
          throw NoAcknowledgeError("No acknowledgement from receiver");
        } else if (frame.can_id & CAN_ERR_BUSOFF) {
          throw BusOffError("Bus off");
        } else if (frame.can_id & CAN_ERR_BUSERROR) {
          throw BusError("Bus error");
        } else if (frame.can_id & CAN_ERR_RESTARTED) {
          throw ControllerRestartedError("Controller restarted");
        } else {
          throw Exception("Unknown CAN protocol error: CAN frame '" + ss.str() + "'");
        }
      }
      std::array<std::uint8_t,8> data {};
      std::copy(std::begin(frame.data), std::end(frame.data), std::begin(data));
      Frame const f {frame.can_id, data};
      return f;
    }

    void Node::write(Frame const& frame) {
      return write(frame.getId(), frame.getData());
    }

    void Node::write(std::uint32_t const can_id, std::array<std::uint8_t,8> const& data) {
      struct ::can_frame frame {};
      frame.can_id = can_id;
      frame.can_dlc = 8;
      std::copy(std::begin(data), std::end(data), std::begin(frame.data));
      if (::write(socket_, &frame, sizeof(struct ::can_frame)) != sizeof(struct ::can_frame)) {
        std::ostringstream ss {};
        ss << frame;
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Could not write CAN frame '" + ss.str() + "'");
      }
      return;
    }

    void Node::initSocket(std::string const& ifname) {
      ifname_ = ifname;
      socket_ = ::socket(PF_CAN, SOCK_RAW, CAN_RAW);
      if (socket_ < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Error creating socket");
      }

      struct ::ifreq ifr {};
      std::strcpy(ifr.ifr_name, ifname.c_str());
      if (::ioctl(socket_, SIOCGIFINDEX, &ifr) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Error manipulating device parameters");
      }

      struct ::sockaddr_can addr {};
      addr.can_family = AF_CAN;
      addr.can_ifindex = ifr.ifr_ifindex;
      if (::bind(socket_, reinterpret_cast<struct ::sockaddr*>(&addr), sizeof(addr)) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Error assigning address to socket");
      }
      return;
    }

    void Node::closeSocket() noexcept {
      ::close(socket_);
      return;
    }

  }
}
