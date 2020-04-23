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

/* 

У меня с тестами, как знаете, очень туго ._. Не знаю какие писать тесты :(
Первым делом хотел сделать тесты openfile, но и тут у меня проблемка с пониманием, хотелось бы конечно понять..
Как можно писать тесты на функции без параметров??(дайте пожалуйста пример теста) Единственное что я могу, это позитивные тесты((
Подскажите пожалуйста какие тесты нужны(

*/