#ifndef INCLUDE_CLASSTIME_H_
#define INCLUDE_CLASSTIME_H_

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;

class Time {
public:
  Time(); // конструктор по умолчанию
  Time(const Time &c); // конструктор копирования
  Time(int _hour, int _min, int _sec); // конструктор инициализации
  Time(int d); // конструктор преобразования типа

  ~Time(); // деструктор

  Time& operator=(const Time& c); // перегруженный оператор присваивания
  bool operator==(const Time& c); // перегруженный оператор сравнения
  Time operator+(const Time& c); // перегруженный оператор сложения
  Time operator-(const Time& c); // перегруженный оператор вычитания
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
      cout << "Исходное время(Идёт вперед: операция перегрузки +):" << endl;
      Show();
      Sleep(1000); // задержка в 1 сек.
      sec = sec + 1;
      system("cls");
      proverka();
    }
  }
  void minustime() {
    for (int i = 0; i < 4; i++) {
      cout << "Исходное время(Идёт назад: операция перегрузки -):" << endl;
      Show();
      Sleep(1000); // задержка в 1 сек.
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

ostream& operator<<(ostream& stream, const Time& c)
{
  cout << c.hour << " : " << c.minut << " : " << c.sec << endl << endl;
  return stream;
}

istream& operator>>(istream& stream, Time& c)
{

  cout << "\nВведите часы: ";
  cin >> c.hour;
  cout << "Введите минуты: ";
  cin >> c.minut;
  cout << "Введите секунды: ";
  cin >> c.sec;
  return stream;
}

Time::Time() {
  hour = 0;
  minut = 0;
  sec = 0;
}

Time::Time(int _hour, int _min, int _sec) : hour(_hour), minut(_min), sec(_sec) {  }

Time::Time(int _hour) {
  hour = _hour;
  minut = 0;
  sec = 0;
}

Time::~Time() {
  hour = 0;
  minut = 0;
  sec = 0;
}

Time::Time(const Time &c) {
  hour = c.hour;
  minut = c.minut;
  sec = c.sec;
}
// операторы
Time& Time::operator=(const Time &c) {
  hour = c.hour;
  minut = c.minut;
  (*this).sec = c.sec;
  return *this;
}

bool Time::operator==(const Time &c) {
  bool res = 0;
  if (hour == c.hour && minut == c.minut && sec == c.sec) {
    res = 1;
  }
  else {
    res = 0;
  }
  return res;
}

Time Time::operator+(const Time& c) {
  Time res;
  res.sec = sec + c.sec;
  res.minut = minut + c.minut + res.minut;
  res.hour = hour + c.hour + res.hour;
  return res;
}

Time Time::operator-(const Time& c) {
  Time res;
  res.sec = sec - c.sec;
  res.minut = minut - c.minut + res.minut;
  res.hour = hour - c.hour + res.hour;
  return res;
}

int wibor(int w) {
  while (w < 1 || w > 2) {
    cout << "\nВведите правильно. 1 - Изменить время, 2 - Выйти." << endl;
    cout << "Ввод: ";
    cin >> w;
  }
  return w;
}

#endif  // INCLUDE_CLASSTIME_H_
