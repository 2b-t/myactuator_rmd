/**
 * \file can_node.cpp
 * \mainpage
 *    Test program for testing Linux SocketCAN communication
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <array>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "myactuator_rmd_driver/can/node.hpp"
#include "myactuator_rmd_driver/can/output.hpp"


void removeSubstr(std::string& str, std::string const& substr) noexcept { 
  std::string::size_type n {substr.length()};
  for (std::string::size_type i = str.find(substr); i != std::string::npos; i = str.find(substr)) {
    str.erase(i, n);
  }
  return;
}


int main(int argc, char** argv) {
  std::string ifname {};
  std::string can_id {};
  std::string data {};

  boost::program_options::options_description desc {"Allowed options"};
  desc.add_options()
    ("help", "Visualize help message")
    ("send,s", "Send a CAN frame")
    ("receive,r", "Read a CAN frame")
    ("ifname", boost::program_options::value(&ifname)->required(), "CAN interface name, e.g. 'can0'")
    ("can_id", boost::program_options::value(&can_id), "The CAN node id, e.g. '0x141'")
    ("data", boost::program_options::value(&data), "The data to be sent, e.g. '0xA400F40100000000'")
  ;
  boost::program_options::variables_map vm {};
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << std::endl;
    return EXIT_FAILURE;
  }

  myactuator_rmd_driver::can::Node node {ifname};
  if (vm.count("send") && !vm.count("receive") && vm.count("can_id") && vm.count("data")) {
    std::uint32_t const id {static_cast<std::uint32_t>(std::stoul(can_id, nullptr, 16))};
    removeSubstr(data, "0x");
    if ((data.size() % 2) || (data.size() > 16)) {
      throw std::runtime_error("Data has wrong format!");
    }
    std::array<std::uint8_t,8> arr {};
    for (std::size_t i = 0; i < data.size()/2; ++i) {
      arr.at(i) = static_cast<std::uint8_t>(std::stoul(data.substr(2*i, 2), nullptr, 16));
    }
    node.write(arr, id);
  } else if (vm.count("receive") && !vm.count("send")) {
    if (vm.count("can_id")) {
      std::uint32_t const id {static_cast<std::uint32_t>(std::stoul(can_id, nullptr, 16))};
      node.setRecvFilter(id);
    }
    while (true) {
      auto const d {node.read()};
      for (int i = 0; i < d.size(); ++i) {
        std::cout << std::hex << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(d.at(i)) << " ";
      }
      std::cout << std::dec << std::endl;
    }
  } else {
    std::cerr << "Unknown combination of options!" << std::endl;
  }
  

  return EXIT_SUCCESS;
}
