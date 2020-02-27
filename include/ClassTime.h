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
  Time operator+(const Time& c); // ������������� �������� ��������
  Time operator-(const Time& c); // ������������� �������� ���������
  void null(int n);
  void Show();
  void plustime();
  void minustime();
  void proverka();

  friend ostream& operator << (ostream& stream, const Time& a);
  friend istream& operator >> (istream& stream, Time& a);

private:
  int hour;
  int minut;
  int sec;
};

#endif  // INCLUDE_CLASSTIME_H_
