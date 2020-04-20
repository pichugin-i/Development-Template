#include <gtest/gtest.h>
#include "add.h"

TEST(decimal, pluspervoebolshevtorogoosnova) {
  decimal t1("3911");
  decimal t2("911");
  decimal t3("4822");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, plusravnieosnova) {
  decimal t1("2911");
  decimal t2("2212");
  decimal t3("5123");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, plusperviemenshevtorogoosnova) {
  decimal t1("151");
  decimal t2("1291");
  decimal t3("1442");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, pluspervoebolshevtorogocount1) {
  decimal t1("99");
  decimal t2("9");
  decimal t3("108");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, plusravniecount1) {
  decimal t1("99");
  decimal t2("22");
  decimal t3("121");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, plusperviemenshevtorogocount1) {
  decimal t1("15");
  decimal t2("999");
  decimal t3("1014");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, pluspervoebolshevtorogocount0) {
  decimal t1("30");
  decimal t2("9");
  decimal t3("39");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, plusravniecount0) {
  decimal t1("20");
  decimal t2("22");
  decimal t3("42");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, plusperviemenshevtorogocount0) {
  decimal t1("15");
  decimal t2("120");
  decimal t3("135");
  decimal res = t1 + t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minusosnovapervoemenshevtorogo) {
  decimal t1("155");
  decimal t2("200");
  decimal t3("45");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minusosnovaravine) {
  decimal t1("1555");
  decimal t2("1201");
  decimal t3("354");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minusosnovapervoebolshevtorogo) {
  decimal t1("15511");
  decimal t2("1500");
  decimal t3("14011");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minuspervoebolshevtorogocountm) {
  decimal t1("155");
  decimal t2("89");
  decimal t3("66");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minuspervoebolshevtorogocount0) {
  decimal t1("155");
  decimal t2("44");
  decimal t3("111");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minusravniecount0) {
  decimal t1("222");
  decimal t2("111");
  decimal t3("111");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minusravniecountm) {
  decimal t1("222");
  decimal t2("199");
  decimal t3("23");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minuspervoemenshevtorogocount0) {
  decimal t1("22");
  decimal t2("111");
  decimal t3("89");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, minuspervoemenshevtorogocountm) {
  decimal t1("99");
  decimal t2("191");
  decimal t3("92");
  decimal res = t1 - t2;
  EXPECT_EQ(res, t3);
}

TEST(decimal, copirovanie) {
  decimal t1 = "224";
  decimal t2(t1);
  EXPECT_EQ(t1, t2);
}

TEST(decimal, Candecimalprisvaivanie) {
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

TEST(decimal, Candecimal1Sravneniedecimal) {
  decimal t1 = "223";
  decimal t2 = "224";
  bool res;
  if (t1 == t2) {
    res = 1;
  }
  else {
    res = 0;
  }
  EXPECT_EQ(res, 0);
}

