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
  void null(int n) {
    if (n < 10) {
      cout << "0" << n;
    }
    else {
      cout << n;
    }
  }
  void Show()
  {
    proverka();
    null(hour);
    cout << ":";
    null(minut);
    cout << ":";
    null(sec);
  }
  void plustime() {
    for (int i = 0; i < 4; i++) {
      cout << "�������� �����(��� ������: �������� ���������� +):" << endl;
      Show();
      Sleep(1000); // �������� � 1 ���.
      sec = sec + 1;
      system("cls");
      proverka();
    }
  }
  void minustime() {
    for (int i = 0; i < 4; i++) {
      cout << "�������� �����(��� �����: �������� ���������� -):" << endl;
      Show();
      Sleep(1000); // �������� � 1 ���.
      sec = sec - 1;
      system("cls");
      proverka();
    }
  }
  void proverka() {
    while (sec > 59) {
      sec = sec - 60;
      minut++;
    }
    while (minut > 59) {
      minut = minut - 60;
      hour++;
    }
    while (hour > 23) {
      hour = hour - 24;
    }
    while (sec < 0) {
      sec = 59;
      minut--;
    }
    while (minut < 0) {
      minut = 59;
      hour--;
    }
    while (hour < 0) {
      hour = 23;
    }
  }

  friend ostream& operator << (ostream& stream, const Time& a);
  friend istream& operator >> (istream& stream, Time& a);

private:
  int hour;
  int minut;
  int sec;
};

#endif  // INCLUDE_CLASSTIME_H_
