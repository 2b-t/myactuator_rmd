/**
 * \file feedback.hpp
 * \mainpage
 *    Contains the struct for closed-loop control feedback
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__FEEDBACK
#define MYACTUATOR_RMD__FEEDBACK
#pragma once

#include "myactuator_rmd/actuator_state/motor_status_2.hpp"


namespace myactuator_rmd {

  // The feedback struct for any closed-loop control corresponds to motor status 2
  using Feedback = MotorStatus2;

}

#endif // MYACTUATOR_RMD__FEEDBACK
