/**
 * \file driver.hpp
 * \mainpage
 *    Contains the main driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__DRIVER
#define MYACTUATOR_RMD_DRIVER__DRIVER
#pragma once

#include <string>

#include "myactuator_rmd_driver/can/node.hpp"


namespace myactuator_rmd_driver {

  class Driver: protected can::Node {
    public:
      Driver(std::string const& ifname)
      : can::Node{ifname} {
        return;
      }
  };

}

#endif // MYACTUATOR_RMD_DRIVER__DRIVER
