/**
 * \file responses.hpp
 * \mainpage
 *    Super header for all responses sent from the actuator to the driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES
#define MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES
#pragma once

#include "myactuator_rmd_driver/messages/responses/get_controller_gains_response.hpp"
#include "myactuator_rmd_driver/messages/responses/get_motor_status_1_response.hpp"
#include "myactuator_rmd_driver/messages/responses/get_motor_status_2_response.hpp"
#include "myactuator_rmd_driver/messages/responses/get_motor_status_3_response.hpp"
#include "myactuator_rmd_driver/messages/responses/set_controller_gains_response.hpp"
#include "myactuator_rmd_driver/messages/responses/set_controller_gains_persistently_response.hpp"
#include "myactuator_rmd_driver/messages/responses/get_motor_model_response.hpp"
#include "myactuator_rmd_driver/messages/responses/get_version_date_response.hpp"
#include "myactuator_rmd_driver/messages/responses/set_position_absolute_response.hpp"
#include "myactuator_rmd_driver/messages/responses/set_torque_response.hpp"
#include "myactuator_rmd_driver/messages/responses/set_velocity_response.hpp"
#include "myactuator_rmd_driver/messages/responses/shutdown_motor_response.hpp"
#include "myactuator_rmd_driver/messages/responses/stop_motor_response.hpp"

#endif // MYACTUATOR_RMD_DRIVER__MESSAGES__RESPONSES
