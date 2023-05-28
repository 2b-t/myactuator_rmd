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
     * \brief
     *    Exception class for errors with Linux SocketCAN sockets
    */
    class SocketException: public std::system_error {
      public:
        using std::system_error::system_error;
    };

    /**\class Exception
     * \brief
     *    Exception class for CAN specific errors
     *    See https://github.com/linux-can/can-utils/blob/master/include/linux/can/error.h for more details
    */
    class Exception: public std::runtime_error {
      public:
        using std::runtime_error::runtime_error;
    };

    class TxTimeoutError: public Exception {
      public:
        using Exception::Exception;
    };

    class LostArbitrationError: public Exception {
      public:
        using Exception::Exception;
    };

    class ControllerProblemError: public Exception {
      public:
        using Exception::Exception;
    };

    class ProtocolViolationError: public Exception {
      public:
        using Exception::Exception;
    };

    class TransceiverStatusError: public Exception {
      public:
        using Exception::Exception;
    };

    class NoAcknowledgeError: public Exception {
      public:
        using Exception::Exception;
    };

    class BusOffError: public Exception {
      public:
        using Exception::Exception;
    };

    class BusError: public Exception {
      public:
        using Exception::Exception;
    };

    class ControllerRestartedError: public Exception {
      public:
        using Exception::Exception;
    };

  }
}

#endif // MYACTUATOR_RMD_DRIVER__CAN__EXCEPTIONS
