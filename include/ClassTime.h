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
  Time(); // конструктор по умолчанию
  Time(const Time &c); // конструктор копирования
  Time(int _hour, int _min, int _sec); // конструктор инициализации
  Time(int d); // конструктор преобразования типа

  ~Time(); // деструктор

  Time& operator=(const Time& c); // перегруженный оператор присваивания
  bool operator==(const Time& c); // перегруженный оператор сравнения
  Time operator+(const Time& c); // перегруженный оператор сложения
  Time operator-(const Time& c); // перегруженный оператор вычитания
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
