#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_

#pragma once
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;

class Date {
private:
  int h_s[2];
  int h_e[2];
  int data[3];
  int st;
public:
  void setdate(Date *num, int count);
  void info(Date *num, int count);
  void srmonth(Date *num, int count);
  void maxmonth(Date *num, int count);
  void infile(Date *num, int count);
  void outfile(Date *num, int count);
  void onedate(Date *num, int count);
};

class Pedometer {
private:
  int count = 0;
  Date *num = new Date[10000];
public:
  void menu();
};
#endif  // INCLUDE_ADD_H_
