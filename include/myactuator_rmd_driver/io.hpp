/**
 * \file io.hpp
 * \mainpage
 *    Contains functions for printing the different classes to console
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__IO
#define MYACTUATOR_RMD_DRIVER__IO
#pragma once

#include <ostream>

#include "myactuator_rmd_driver/feedback.hpp"


namespace myactuator_rmd_driver {

  inline std::ostream& operator << (std::ostream& os, Feedback const& f) noexcept {
    os << "temperature: " << f.temperature << ", current: " << f.current << ", shaft speed: " << f.shaft_speed << ", shaft angle: " << f.shaft_angle;
    return os;
  }

}

#endif // MYACTUATOR_RMD_DRIVER__IO
