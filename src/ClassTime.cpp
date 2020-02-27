#include "ClassTime.h"
#include <string>
#include <clocale>
#include <cstdlib>

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