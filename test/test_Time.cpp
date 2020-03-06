#include <gtest/gtest.h>
#include "ClassTime.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

TEST(Time, CanTimeAddTime) {
  Time t1(22, 15, 50);
  Time t2(1, 2, 2);
  Time t3(23, 17, 52);
  Time res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(Time, CanTimeMinusTime) {
  Time t1(11, 45, 30);
  Time t2(1, 5, 15);
  Time t3(10, 40, 15);
  Time res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(Time, CanTimePrisvaivaemTime) {
  Time t1(11, 45, 30);
  Time t2(1, 5, 15);
  Time t3(1, 5, 15);
  Time res = t1 = t2;
  EXPECT_EQ(res, t3);
}

TEST(Time, CanTimeSravnenieTime) {
  Time t1(11, 45, 30);
  Time t2(11, 45, 30);
  Time res = t1 == t2;
  EXPECT_EQ(res, true);
}