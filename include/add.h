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
  friend bool operator==(const Date &left, const Date &right) {
    bool res = false;
    if (left.h_s[0] == right.h_s[0] && left.h_e[0] == right.h_e[0] && left.data[0] == right.data[0] && left.st == right.st && 
      left.h_s[1] == right.h_s[1] && left.h_e[1] == right.h_e[1] && left.data[1] == right.data[1] && left.data[2] == right.data[2]) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }
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
  friend bool operator==(const Pedometer &left, const Pedometer &right) {
    bool res = false;
    if (left.count == right.count) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }
  void setdate(Date new_data);
  void info();
  int srmonth(int month);
  int maxmonth(int month);
  void show_maxmonth(int month);
  void infile();
  void outfile();
  void onedate();
  void show_srmonth(int month);
  int inpmonth();
  int inpinfoday();
  int inpinfomonth();
  int inpinfoyear();
  int inpinfoh_s0();
  int inpinfoh_s1();
  int inpinfoh_e0();
  int inpinfoh_e1();
  void menu();
};
#endif  // INCLUDE_ADD_H_