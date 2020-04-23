#include <gtest/gtest.h>
#include "add.h"

TEST(Testss, openfileintrue) {
  Pedometer rs;
  ASSERT_NO_THROW(rs.infile());
}

TEST(Testss, openfileouttrue) {
  Pedometer rs;
  ASSERT_NO_THROW(rs.outfile());
}

TEST(Testss, constrcopy) {
  Pedometer rs;
  Pedometer rc(rs);
  EXPECT_EQ(rs, rc);
}


TEST(Testss, constr1) {
  int* h_s = new int[2];
  h_s[0] = 0;
  h_s[1] = 0;
  int *h_e = new int[2];
  h_e[0] = 0;
  h_e[1] = 0;
  int *data = new int[3];
  data[0] = 0;
  data[1] = 0;
  data[2] = 0;
  int st = 0;
  Date d(h_s, h_e, data, st);
  Date d1;
  EXPECT_EQ(d, d1);
}

TEST(Testss, constr2) {
  int* h_s = new int[2];
  h_s[0] = 0;
  h_s[1] = 0;
  int *h_e = new int[2];
  h_e[0] = 0;
  h_e[1] = 0;
  int *data = new int[3];
  data[0] = 0;
  data[1] = 0;
  data[2] = 0;
  int st = 0;
  Date d(h_s, h_e, data, st);
  Date d1;
  EXPECT_EQ(d1, d);
}

TEST(Testss, srmonthtrue) {
  int* h_s = new int[2];
  h_s[0] = 20;
  h_s[1] = 30;
  int *h_e = new int[2];
  h_e[0] = 21;
  h_e[1] = 30;
  int *data = new int[3];
  data[0] = 12;
  data[1] = 12;
  data[2] = 2012;
  int st = 240;

  Pedometer d(h_s, h_e, data, st);

  int res = d.srmonth(12);
  EXPECT_EQ(res, 240);
}

TEST(Testss, srmonthtruebolseodnogo) {
  int* h_s = new int[2];
  h_s[0] = 20;
  h_s[1] = 30;
  int *h_e = new int[2];
  h_e[0] = 21;
  h_e[1] = 30;
  int *data = new int[3];
  data[0] = 12;
  data[1] = 12;
  data[2] = 2012;
  int st = 240;

  int* h_s1 = new int[2];
  h_s1[0] = 10;
  h_s1[1] = 30;
  int *h_e1 = new int[2];
  h_e1[0] = 13;
  h_e1[1] = 30;
  int *data1 = new int[3];
  data1[0] = 2;
  data1[1] = 12;
  data1[2] = 2013;
  int st1 = 246;

  Pedometer d(h_s, h_e, data, st);
  Pedometer d1(h_s1, h_e1, data1, st1);
  int res1 = d.srmonth(12);
  int res2 = d1.srmonth(12);
  int res3 = (res1 + res2) / 2;
  EXPECT_EQ(res3, 243);
}

TEST(Testss, srmonthnotfindmonth) {
  int* h_s = new int[2];
  h_s[0] = 20;
  h_s[1] = 30;
  int *h_e = new int[2];
  h_e[0] = 21;
  h_e[1] = 30;
  int *data = new int[3];
  data[0] = 12;
  data[1] = 12;
  data[2] = 2012;
  int st = 240;

  Pedometer d(h_s, h_e, data, st);

  int res = d.srmonth(5);
  EXPECT_EQ(res, false);
}

TEST(Testss, maxmonthtrue) {
  int* h_s = new int[2];
  h_s[0] = 15;
  h_s[1] = 20;
  int *h_e = new int[2];
  h_e[0] = 17;
  h_e[1] = 30;
  int *data = new int[3];
  data[0] = 5;
  data[1] = 10;
  data[2] = 2000;
  int st = 323;

  Pedometer d(h_s, h_e, data, st);

  int res = d.maxmonth(10);
  EXPECT_EQ(res, 323);
}

TEST(Testss, maxmonthfalse) {
  int* h_s = new int[2];
  h_s[0] = 15;
  h_s[1] = 20;
  int *h_e = new int[2];
  h_e[0] = 17;
  h_e[1] = 30;
  int *data = new int[3];
  data[0] = 5;
  data[1] = 10;
  data[2] = 2000;
  int st = 323;

  Pedometer d(h_s, h_e, data, st);

  int res = d.maxmonth(12);
  EXPECT_EQ(res, false);
}