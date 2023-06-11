/**
 * \file feedback.hpp
 * \mainpage
 *    Contains the struct for closed-loop control feedback
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__FEEDBACK
#define MYACTUATOR_RMD_DRIVER__FEEDBACK
#pragma once

#include "myactuator_rmd_driver/actuator_state/motor_status_2.hpp"


namespace myactuator_rmd_driver {

  // The feedback struct for any closed-loop control corresponds to motor status 2
  using Feedback = MotorStatus2;

}

#endif // MYACTUATOR_RMD_DRIVER__FEEDBACK
