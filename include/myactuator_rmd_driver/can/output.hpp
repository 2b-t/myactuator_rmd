/**
 * \file output.hpp
 * \mainpage
 *    Contains output tools for printing information about SocketCAN structures
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__CAN__OUTPUT
#define MYACTUATOR_RMD_DRIVER__CAN__OUTPUT
#pragma once

#include <ostream>

#include <linux/can.h>


/**\fn operator <<
  * \brief
  *    Output stream operator for a Linux SocketCAN CAN frame
  *
  * \param[in,out] os
  *    The output stream that should be written to
  * \param[in] frame
  *    The CAN frame that should be written to the output stream
  * \return
  *    The output stream containing information about the CAN frame
*/
std::ostream& operator << (std::ostream& os, struct ::can_frame const& frame) noexcept;

#endif // MYACTUATOR_RMD_DRIVER__CAN__OUTPUT
