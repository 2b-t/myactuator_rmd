/**
 * \file exceptions.hpp
 * \mainpage
 *    Contains exceptions that might be thrown by the CAN communication
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__CAN__EXCEPTIONS
#define MYACTUATOR_RMD__CAN__EXCEPTIONS
#pragma once

#include <stdexcept>
#include <system_error>


namespace myactuator_rmd {
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
     *    Exception base class for CAN specific errors
     *    See https://github.com/linux-can/can-utils/blob/master/include/linux/can/error.h for more details
     *    Use derived exception classes if possible!
    */
    class Exception: public std::runtime_error {
      public:
        using std::runtime_error::runtime_error;
    };

    /**\class TxTimeoutError
     * \brief
     *    Exception class for transfer timeout when sending CAN frame
    */
    class TxTimeoutError: public Exception {
      public:
        using Exception::Exception;
    };

    /**\class LostArbitrationError
     * \brief
     *    Exception class for arbitration errors, may often be safely ignored
     *    See https://www.cancapture.com/article/arbitration-lost-error-messages
    */
    class LostArbitrationError: public Exception {
      public:
        using Exception::Exception;
    };

    /**\class ControllerProblemError
     * \brief
     *    Exception class for CAN bus controller problems
    */
    class ControllerProblemError: public Exception {
      public:
        using Exception::Exception;
    };

    /**\class ProtocolViolationError
     * \brief
     *    Exception class for violations of the CAN bus protocol
     *    See https://www.influxtechnology.com/post/can-errors-basics
    */
    class ProtocolViolationError: public Exception {
      public:
        using Exception::Exception;
    };

    /**\class TransceiverStatusError
     * \brief
     *    Exception class for transceiver errors
    */
    class TransceiverStatusError: public Exception {
      public:
        using Exception::Exception;
    };

    /**\class NoAcknowledgeError
     * \brief
     *    Exception class for messages that are not acknowledged by the receiver
    */
    class NoAcknowledgeError: public Exception {
      public:
        using Exception::Exception;
    };

    /**\class BusOffError
     * \brief
     *    Exception class if the node is in bus off state (stops transmitting on the network)
    */
    class BusOffError: public Exception {
      public:
        using Exception::Exception;
    };

    /**\class BusError
     * \brief
     *    Exception class for general bus errors (e.g. faulty cables, noise, incorrect termination, 
     *    malfunctioning CAN nodes)
    */
    class BusError: public Exception {
      public:
        using Exception::Exception;
    };

    /**\class ControllerRestartedError
     * \brief
     *    Exception class in case the controller is restarted
    */
    class ControllerRestartedError: public Exception {
      public:
        using Exception::Exception;
    };

  }
}

#endif // MYACTUATOR_RMD__CAN__EXCEPTIONS
