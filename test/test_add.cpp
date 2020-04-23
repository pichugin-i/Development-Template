#include <gtest/gtest.h>
#include "add.h"

TEST(Pemometeeeeer, openfileintrue) {
  Pedometer rs;
  ASSERT_NO_THROW(rs.infile());
}

TEST(Pemometeeeeer, openfileouttrue) {
  Pedometer rs;
  ASSERT_NO_THROW(rs.outfile());
}

TEST(Pemometeeeeer, constrcopy) {
  Pedometer rs;
  Pedometer rc(rs);
  EXPECT_EQ(rs, rc);
}

/* 

У меня с тестами, как знаете, очень туго ._. Не знаю какие писать тесты :(
Как можно писать тесты на функции(алгоритмы) без параметров??(дайте пожалуйста пример теста)

*/