/**
 * \file actuator_mock.hpp
 * \mainpage
 *    Contains a mock for the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__TEST__ACTUATOR_MOCK
#define MYACTUATOR_RMD_DRIVER__TEST__ACTUATOR_MOCK
#pragma once

#include <gmock/gmock.h>

#include "actuator_adaptor.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    class ActuatorMock: public ActuatorAdaptor {
    };

  }
}

#endif // MYACTUATOR_RMD_DRIVER__TEST__ACTUATOR_MOCK
