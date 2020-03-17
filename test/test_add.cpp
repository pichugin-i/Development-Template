#include <gtest/gtest.h>
#include "add.h"

TEST(decimal, CandecimalPrisvaivaemdecimal) {
  decimal t1("111");
  decimal t2("222");
  decimal t3("222");
  decimal res = t1 = t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, CandecimalSravneniedecimal) {
  decimal t1 = "223";
  decimal t2 = "223";
  bool res;
  if (t1 == t2) {
    res = 1;
  } else {
    res = 0;
  }
  EXPECT_EQ(res, 1);
}
