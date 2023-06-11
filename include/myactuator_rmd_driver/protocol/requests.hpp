/**
 * \file requests.hpp
 * \mainpage
 *    Super header for the requests sent from the driver to the actuator
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS
#define MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS
#pragma once

#include "myactuator_rmd_driver/protocol/requests/get_controller_gains_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/get_motor_status_1_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/get_motor_status_2_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/get_motor_status_3_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/set_controller_gains_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/set_controller_gains_persistently_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/get_motor_model_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/get_version_date_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/set_position_absolute_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/set_torque_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/set_velocity_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/shutdown_motor_request.hpp"
#include "myactuator_rmd_driver/protocol/requests/stop_motor_request.hpp"

#endif // MYACTUATOR_RMD_DRIVER__PROTOCOL__REQUESTS
