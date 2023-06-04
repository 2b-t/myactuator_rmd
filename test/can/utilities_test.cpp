/**
 * \file utilities_test.cpp
 * \mainpage
 *    Tests for utilities functions for Linux structs
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#include <chrono>
#include <ratio>

#include <sys/time.h>

#include <gtest/gtest.h>

#include "myactuator_rmd_driver/can/utilities.hpp"


namespace myactuator_rmd_driver {
  namespace test {

    TEST(ToTimevalTests, conversions) {
      using namespace std::literals::chrono_literals;
      auto const t1 {2s};
      auto const tv1 {myactuator_rmd_driver::toTimeval(t1)};
      EXPECT_EQ(tv1.tv_sec, 2);
      EXPECT_EQ(tv1.tv_usec, 0);

      auto const t2 {20ms};
      auto const tv2 {myactuator_rmd_driver::toTimeval(t2)};
      EXPECT_EQ(tv2.tv_sec, 0);
      EXPECT_EQ(tv2.tv_usec, 20000);

      auto const t3 {7us};
      auto const tv3 {myactuator_rmd_driver::toTimeval(t3)};
      EXPECT_EQ(tv3.tv_sec, 0);
      EXPECT_EQ(tv3.tv_usec, 7);

      auto const t4 {2min};
      auto const tv4 {myactuator_rmd_driver::toTimeval(t4)};
      EXPECT_EQ(tv4.tv_sec, 120);
      EXPECT_EQ(tv4.tv_usec, 0);

      using TDS = std::chrono::duration<double>;
      TDS const t5 {1.0};
      auto const tv5 {myactuator_rmd_driver::toTimeval(t5)};
      EXPECT_EQ(tv5.tv_sec, 1);
      EXPECT_EQ(tv5.tv_usec, 0);

      TDS const t6 {0.5};
      auto const tv6 {myactuator_rmd_driver::toTimeval(t6)};
      EXPECT_EQ(tv6.tv_sec, 0);
      EXPECT_EQ(tv6.tv_usec, 500000);

      using TDMS = std::chrono::duration<double, std::milli>;
      TDMS const t7 {6.5};
      auto const tv7 {myactuator_rmd_driver::toTimeval(t7)};
      EXPECT_EQ(tv7.tv_sec, 0);
      EXPECT_EQ(tv7.tv_usec, 6500);
    }

  }
}
