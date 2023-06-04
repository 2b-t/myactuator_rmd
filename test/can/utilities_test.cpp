/**
 * \file utilities_test.cpp
 * \mainpage
 *    Tests for utilities functions for Linux structs
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <chrono>

#include <sys/time.h>

#include <gtest/gtest.h>

#include "myactuator_rmd_driver/can/utilities.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(ToTimevalTests, conversions) {
      using TD = std::chrono::duration<double>;
      using namespace std::literals::chrono_literals;
      auto const t1 {1s};
      auto const tv1 {myactuator_rmd_driver::toTimeval(t1)};
      EXPECT_EQ(tv1.tv_sec, 1);
      EXPECT_EQ(tv1.tv_usec, 0);

      TD const t2 {1.0};
      auto const tv2 {myactuator_rmd_driver::toTimeval(t2)};
      EXPECT_EQ(tv2.tv_sec, 1);
      EXPECT_EQ(tv2.tv_usec, 0);

      TD const t3 {0.5};
      auto const tv3 {myactuator_rmd_driver::toTimeval(t3)};
      EXPECT_EQ(tv3.tv_sec, 0);
      EXPECT_EQ(tv3.tv_usec, 500000);

      auto const t4 {20ms};
      auto const tv4 {myactuator_rmd_driver::toTimeval(t4)};
      EXPECT_EQ(tv4.tv_sec, 0);
      EXPECT_EQ(tv4.tv_usec, 20000);
    }

  }
}
