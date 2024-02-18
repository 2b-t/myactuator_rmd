#include "actuator_actuator_mock_test.hpp"

#include <cstdint>
#include <functional>
#include <string>
#include <thread>

#include "actuator_mock.hpp"


namespace myactuator_rmd {
  namespace test {

    ActuatorActuatorMockTest::ActuatorActuatorMockTest(std::string const& ifname, std::uint32_t const actuator_id)
    : actuator_{ifname, actuator_id}, actuator_mock_{ifname, actuator_id}, mock_thread_{} {
      return;
    }

    void ActuatorActuatorMockTest::SetUp() {
      mock_thread_ = std::thread(&myactuator_rmd::test::ActuatorMock::handleRequest, std::ref(actuator_mock_));
      return;
    }

    void ActuatorActuatorMockTest::TearDown() {
      if (mock_thread_.joinable()) {
        mock_thread_.join();
      }
      return;
    }

  }
}
