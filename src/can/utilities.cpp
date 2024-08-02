#include "myactuator_rmd/can/utilities.hpp"

#include <iomanip>
#include <ostream>

#include <linux/can.h>


std::ostream& operator << (std::ostream& os, struct ::can_frame const& frame) noexcept {
  os << "id: " << "0x" << std::hex << std::setfill('0') << std::setw(3) << frame.can_id << ", data: ";
  for (int i = 0; i < frame.can_dlc; i++) {
    os << std::hex << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(frame.data[i]) << " ";
  }
  os << std::dec;
  return os;
}
