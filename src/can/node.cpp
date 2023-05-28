#include "myactuator_rmd_driver/can/node.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <sstream>
#include <string>
#include <system_error>

#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "myactuator_rmd_driver/can/exceptions.hpp"
#include "myactuator_rmd_driver/can/output.hpp"


namespace myactuator_rmd_driver {
  namespace can {

    Node::Node(std::string const& ifname)
    : ifname_{ifname} {
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

    Node::~Node() {
      ::close(socket_);
      return;
    }

    void Node::setReadFilter(std::uint32_t const& can_id, bool const is_invert) {
      struct ::can_filter filter[1] {};
      if (is_invert) {
        filter[0].can_id = can_id | CAN_INV_FILTER;;
      } else {
        filter[0].can_id = can_id;
      }
      filter[0].can_mask = CAN_SFF_MASK;
      if (::setsockopt(socket_, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter)) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Could not configure read filter");
      }
      return;
    }

    std::array<std::uint8_t,8> Node::read() const {
      struct ::can_frame frame {};
      if (::read(socket_, &frame, sizeof(struct ::can_frame)) < 0) {
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Could not read CAN frame");
      }
      std::array<std::uint8_t,8> data {};
      std::copy(std::begin(frame.data), std::end(frame.data), std::begin(data));
      return data;
    }

    void Node::write(std::array<std::uint8_t,8> const& data, std::uint32_t const& can_id) {
      struct ::can_frame frame {};
      frame.can_id = can_id;
      frame.len = 8;
      std::copy(std::begin(data), std::end(data), std::begin(frame.data));
      if (::write(socket_, &frame, sizeof(struct ::can_frame)) != sizeof(struct ::can_frame)) {
        std::ostringstream ss {};
        ss << frame;
        throw SocketException(errno, std::generic_category(), "Interface '" + ifname_ + "' - Could not write CAN frame '" + ss.str() + "'");
      }
      return;
    }

  }
}
