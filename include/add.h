#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_

#pragma once
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;

class Date {
  friend class Pedometer;
private:
  int* h_s;
  int* h_e;
  int* data;
  int st;
public:
  Date();
  ~Date();
  Date(int *_h_s, int *_h_e, int *_data, int _st);
  Date(const Date &c);

  void getdate();
  void inpsetdate();

  Date operator=(Date &c);
};

class Pedometer {
private:
  int count = 0;
  Date *num;
public:
  Pedometer();
  ~Pedometer();
  Pedometer(int *h_s, int *h_e, int *data, int st);
  Pedometer(const Pedometer &c);
  Pedometer operator=(Pedometer &c);
  void setdate(Date new_data);
  void info(int count);
  void srmonth(int count);
  void maxmonth(int count);
  void infile(int count);
  void outfile();
  void onedate();

  int inpmonth(int count);
  int inpinfoday(int count);
  int inpinfomonth(int count);
  int inpinfoyear(int count);
  int inpinfoh_s0(int count);
  int inpinfoh_s1(int count);
  int inpinfoh_e0(int count);
  int inpinfoh_e1(int count);
  void menu();
};
#endif  // INCLUDE_ADD_H_