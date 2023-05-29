#include "driver_actuator_test.hpp"

#include <array>
#include <cstdint>
#include <functional>
#include <thread>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "myactuator_rmd_driver/messages/response.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST_F(DriverActuatorTest, getVersionDate) {
      myactuator_rmd_driver::VersionDateResponse const response ({0xB2, 0x00, 0x00, 0x00, 0x2E, 0x89, 0x34, 0x01});
      EXPECT_CALL(actuator_, getVersionDate).WillOnce(::testing::Return(response));
      std::thread t {&myactuator_rmd_driver::test::ActuatorMock::handleRequest, std::ref(actuator_)};
      auto const version {driver_.getVersionDate()};
      EXPECT_EQ(version, 20220206);
      if (t.joinable()) {
        t.join();
      }
    }

  }
}
