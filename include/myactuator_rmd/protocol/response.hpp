/**
 * \file response.hpp
 * \mainpage
 *    Contains base class for the responses sent from the actuator to the driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSE
#define MYACTUATOR_RMD__PROTOCOL__RESPONSE
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/protocol/message.hpp"


namespace myactuator_rmd {

  /**\class Response
   * \brief
   *    Base class for responses sent from the actuator to the driver
  */
  class Response: public Message {
    protected:
      using Message::Message;
  };

}

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSE
