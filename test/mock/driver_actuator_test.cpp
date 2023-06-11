#include "driver_actuator_test.hpp"

#include <cstdint>
#include <functional>
#include <string>
#include <thread>

#include "actuator_mock.hpp"


namespace myactuator_rmd {
  namespace test {

    DriverActuatorTest::DriverActuatorTest(std::string const& ifname, std::uint32_t const actuator_id)
    : driver_{ifname, actuator_id}, actuator_{ifname, actuator_id}, mock_thread_{} {
      return;
    }

    void DriverActuatorTest::SetUp() {
      mock_thread_ = std::thread(&myactuator_rmd::test::ActuatorMock::handleRequest, std::ref(actuator_));
      return;
    }

    void DriverActuatorTest::TearDown() {
      if (mock_thread_.joinable()) {
        mock_thread_.join();
      }
      return;
    }

  }
}
