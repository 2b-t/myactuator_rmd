/**
 * \file responses.hpp
 * \mainpage
 *    Super header for all responses sent from the actuator to the driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__PROTOCOL__RESPONSES
#define MYACTUATOR_RMD__PROTOCOL__RESPONSES
#pragma once

#include "myactuator_rmd/protocol/responses/get_controller_gains_response.hpp"
#include "myactuator_rmd/protocol/responses/get_motor_status_1_response.hpp"
#include "myactuator_rmd/protocol/responses/get_motor_status_2_response.hpp"
#include "myactuator_rmd/protocol/responses/get_motor_status_3_response.hpp"
#include "myactuator_rmd/protocol/responses/set_controller_gains_response.hpp"
#include "myactuator_rmd/protocol/responses/set_controller_gains_persistently_response.hpp"
#include "myactuator_rmd/protocol/responses/get_motor_model_response.hpp"
#include "myactuator_rmd/protocol/responses/get_version_date_response.hpp"
#include "myactuator_rmd/protocol/responses/set_position_absolute_response.hpp"
#include "myactuator_rmd/protocol/responses/set_torque_response.hpp"
#include "myactuator_rmd/protocol/responses/set_velocity_response.hpp"
#include "myactuator_rmd/protocol/responses/shutdown_motor_response.hpp"
#include "myactuator_rmd/protocol/responses/stop_motor_response.hpp"

#endif // MYACTUATOR_RMD__PROTOCOL__RESPONSES
