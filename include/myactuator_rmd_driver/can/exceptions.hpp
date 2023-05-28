/**
 * \file exceptions.hpp
 * \mainpage
 *    Contains the exceptions that might be thrown by the CAN communication
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__CAN__EXCEPTIONS
#define MYACTUATOR_RMD_DRIVER__CAN__EXCEPTIONS
#pragma once

#include <stdexcept>
#include <system_error>


namespace myactuator_rmd_driver {
  namespace can {

    /**\class SocketException
    *  \brief
    *     Exception class for errors with Linux CAN Socket
    */
    class SocketException: public std::system_error {
      public:
        using std::system_error::system_error;
    };

  }
}

#endif // MYACTUATOR_RMD_DRIVER__CAN__EXCEPTIONS
