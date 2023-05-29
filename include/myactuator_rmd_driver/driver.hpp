/**
 * \file driver.hpp
 * \mainpage
 *    Contains the main driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD_DRIVER__DRIVER
#define MYACTUATOR_RMD_DRIVER__DRIVER
#pragma once

#include <cstdint>
#include <string>

#include "myactuator_rmd_driver/node.hpp"


namespace myactuator_rmd_driver {

  /**\class Driver
   * \brief
   *    Driver for commanding the MyActuator RMD actuator series
  */
  class Driver: public Node<0x140,0x240> {
    public:
      /**\fn Driver
       * \brief
       *    Class constructor
       * 
       * \param[in] ifname
       *    The name of the network interface that should communicated over
       * \param[in] id
       *    The CAN id of the node
      */
      Driver(std::string const& ifname, std::uint32_t const id);
      Driver() = delete;
      Driver(Driver const&) = delete;
      Driver& operator = (Driver const&) = default;
      Driver(Driver&&) = default;
      Driver& operator = (Driver&&) = default;

      /**\fn getVersionDate
       * \brief
       *    Reads the version date of the actuator firmware
       * 
       * \return
       *    The version date of the firmware on the actuator, e.g. '20220206'
      */
      std::uint32_t getVersionDate();
  };

}

#endif // MYACTUATOR_RMD_DRIVER__DRIVER
