/**
 * \file exceptions.hpp
 * \mainpage
 *    Contains the exceptions that might be thrown by the driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__EXCEPTIONS
#define MYACTUATOR_RMD_DRIVER__EXCEPTIONS
#pragma once

#include <stdexcept>


namespace myactuator_rmd_driver {

  /**\class Exception
   * \brief
   *    Exception class for driver-level errors
  */
  class Exception: public std::runtime_error {
    public:
      using std::runtime_error::runtime_error;
  };

  /**\class ParsingException
   * \brief
   *    Exception class for driver parsing error
  */
  class ParsingException: public Exception {
    public:
      using Exception::Exception;
  };

}

#endif // MYACTUATOR_RMD_DRIVER__EXCEPTIONS
