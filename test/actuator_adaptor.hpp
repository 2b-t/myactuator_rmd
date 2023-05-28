/**
 * \file actuator_adaptor.hpp
 * \mainpage
 *    Contains an adaptor for the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__TEST__ACTUATOR_ADAPTOR
#define MYACTUATOR_RMD_DRIVER__TEST__ACTUATOR_ADAPTOR
#pragma once

#include "myactuator_rmd_driver/can/node.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    class ActuatorAdaptor: public myactuator_rmd_driver::can::Node {
    };

  }
}

#endif // MYACTUATOR_RMD_DRIVER__TEST__ACTUATOR_ADAPTOR
