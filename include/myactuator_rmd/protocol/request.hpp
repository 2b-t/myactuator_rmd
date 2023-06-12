/**
 * \file request.hpp
 * \mainpage
 *    Contains base class for the requests sent from the driver to the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__REQUEST
#define MYACTUATOR_RMD__PROTOCOL__REQUEST
#pragma once

#include <array>
#include <cstdint>

#include "myactuator_rmd/protocol/message.hpp"


namespace myactuator_rmd {

  /**\class Request
   * \brief
   *    Base class for requests sent from the driver to the actuator
  */
  class Request: public Message {
    protected:
      using Message::Message;
  };

}

#endif // MYACTUATOR_RMD__PROTOCOL__REQUEST
