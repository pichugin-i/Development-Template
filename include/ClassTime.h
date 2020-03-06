#ifndef INCLUDE_ClassTime_H_
#define INCLUDE_ClassTime_H_

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;

class Time {
public:
  Time(); // ����������� �� ���������
  Time(const Time &c); // ����������� �����������
  Time(int _hour, int _min, int _sec); // ����������� �������������
  Time(int d); // ����������� �������������� ����

  ~Time(); // ����������

  Time& operator=(const Time& c); // ������������� �������� ������������
  bool operator==(const Time& c); // ������������� �������� ���������
  friend bool operator==(const Time &left, const Time &right) {
    bool res = 0;
    if (left.hour == right.hour && left.minut == right.minut && left.sec == right.sec) {
      res = 1;
    }
    else {
      res = 0;
    }
    return res;
  }
  Time operator+(const Time& c); // ������������� �������� ��������
  Time operator-(const Time& c); // ������������� �������� ���������
  void null(int n);
  void Show();
  void plustime();
  void minustime();
  void proverka();
  int wibor(int w);
  friend ostream& operator << (ostream& stream, const Time& a);
  friend istream& operator >> (istream& stream, Time& a);

private:
  int hour;
  int minut;
  int sec;
};

#endif  // INCLUDE_CLASSTIME_H_
