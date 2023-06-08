/**
 * \file requests.hpp
 * \mainpage
 *    Super header for the requests sent from the driver to the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS
#define MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS
#pragma once

#include "myactuator_rmd_driver/messages/requests/get_motor_model_request.hpp"
#include "myactuator_rmd_driver/messages/requests/get_version_date_request.hpp"
#include "myactuator_rmd_driver/messages/requests/set_position_absolute_request.hpp"
#include "myactuator_rmd_driver/messages/requests/set_torque_request.hpp"
#include "myactuator_rmd_driver/messages/requests/set_velocity_request.hpp"
#include "myactuator_rmd_driver/messages/requests/shutdown_motor_request.hpp"
#include "myactuator_rmd_driver/messages/requests/stop_motor_request.hpp"

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__REQUESTS
