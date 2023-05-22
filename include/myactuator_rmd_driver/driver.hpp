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

#include "myactuator_rmd_driver/can/interface.hpp"


namespace myactuator_rmd_driver {

  class Driver: public can::Interface {
    public:
      constexpr Driver() {
        return;
      }
  };

}

#endif // MYACTUATOR_RMD_DRIVER__DRIVER
