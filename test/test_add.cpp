#include <gtest/gtest.h>
#include "add.h"

TEST(Snake, Setup) {
  Zmeika s;
  ASSERT_NO_THROW(s.Setup());
}

TEST(Snake, Logic1) {
  Zmeika s;
  int w = 1;
  ASSERT_NO_THROW(s.Logic(w));
}

TEST(Snake, Logic2) {
  Zmeika s;
  int w = 2;
  ASSERT_NO_THROW(s.Logic(w));
}

TEST(Snake, Logicerror) {
  Zmeika s;
  int w = 3;
  ASSERT_ANY_THROW(s.Logic(w));
}