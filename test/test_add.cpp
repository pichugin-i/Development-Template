#include <gtest/gtest.h>
#include "add.h"

TEST(Credit, constrcopy) {
  Credit rs;
  Credit rc(rs);
  EXPECT_EQ(rs, rc);
}

TEST(Credit, ss) {
  Credit s1;
  int res;
  int s = 1;
  int is=-1;
  int r=-10;
  int or=-10;
  int non=5000;
  int cred1=5000;
  res = s1.ss(is, r, or , non, s, cred1);
  int rs = 463;
  EXPECT_EQ(res, rs);
}

TEST(Credit, ss2) {
  Credit s1;
  int res;
  int s = 2;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 5000;
  int cred1 = 5000;
  res = s1.ss(is, r, or , non, s, cred1);
  int rs = 252;
  EXPECT_EQ(res, rs);
}

TEST(Credit, ss3) {
  Credit s1;
  int res;
  int s = 3;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 5000;
  int cred1 = 5000;
  res = s1.ss(is, r, or , non, s, cred1);
  int rs = 166;
  EXPECT_EQ(res, rs);
}

TEST(Credit, ss4) {
  Credit s1;
  int res;
  int s = 4;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 5000;
  int cred1 = 5000;
  res = s1.ss(is, r, or , non, s, cred1);
  int rs = 126;
  EXPECT_EQ(res, rs);
}

TEST(Credit, ss5) {
  Credit s1;
  int res;
  int s = 5;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 5000;
  int cred1 = 5000;
  res = s1.ss(is, r, or , non, s, cred1);
  int rs = 94;
  EXPECT_EQ(res, rs);
}

TEST(Credit, one) {
  Credit s1;
  int res = 138;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 1500;
  int cred1;
  cred1 = s1.one(is, or , r, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, two) {
  Credit s1;
  int res = 75;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 1500;
  int cred1;
  cred1 = s1.two(is, or , r, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, three) {
  Credit s1;
  int res = 49;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 1500;
  int cred1;
  cred1 = s1.three(is, or , r, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, four) {
  Credit s1;
  int res = 38;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 1500;
  int cred1;
  cred1 = s1.four(is, or , r, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, five) {
  Credit s1;
  int res = 28;
  int is = -1;
  int r = -10;
  int or = -10;
  int non = 1500;
  int cred1;
  cred1 = s1.five(is, or , r, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, algoritmone) {
  Credit s1;
  int stavka = 20;
  int var = 1;
  int res = 231;
  int non = 2500;
  int cred1;
  cred1 = s1.algoritm(stavka, var, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, algoritmtwo) {
  Credit s1;
  int stavka = 19;
  int var = 1;
  int res = 230;
  int non = 2500;
  int cred1;
  cred1 = s1.algoritm(stavka, var, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, algoritmthree) {
  Credit s1;
  int stavka = 12;
  int var = 1;
  int res = 222;
  int non = 2500;
  int cred1;
  cred1 = s1.algoritm(stavka, var, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, algoritmfour) {
  Credit s1;
  int stavka = 10;
  int var = 1;
  int res = 219;
  int non = 2500;
  int cred1;
  cred1 = s1.algoritm(stavka, var, non);
  EXPECT_EQ(res, cred1);
}

TEST(Credit, algoritmfive) {
  Credit s1;
  int stavka = 5;
  int var = 1;
  int res = 214;
  int non = 2500;
  int cred1;
  cred1 = s1.algoritm(stavka, var, non);
  EXPECT_EQ(res, cred1);
}
