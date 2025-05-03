#include "myactuator_rmd/can/utilities.hpp"

#include <iomanip>
#include <ostream>
#include <string>
#include <sstream>

#include <linux/can.h>


std::ostream& operator << (std::ostream& os, struct ::can_frame const& frame) noexcept {
  os << "id: " << "0x" << std::hex << std::setfill('0') << std::setw(3) << frame.can_id << ", data: ";
  for (int i = 0; i < frame.can_dlc; i++) {
    os << std::hex << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(frame.data[i]) << " ";
  }
  os << std::dec;
  return os;
}

std::string frameToString(can_frame const & frame) {
  std::stringstream ss;
  ss << "Frame -> ID: " << std::setfill(' ') << std::setw(3) << frame.can_id
     << " DLC: " << static_cast<int>(frame.can_dlc)
     << " DATA:";
#ifdef HAVE_CAN_DLC
  for (int i = 0; i < frame.can_dlc; i++) {
    ss << " " << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(frame.data[i]);
  }
#else
  for (int i = 0; i < frame.len; i++) {
    ss << " " << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(frame.data[i]);
  }
#endif
  return ss.str();
}
