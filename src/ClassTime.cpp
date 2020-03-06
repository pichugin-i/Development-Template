#include "ClassTime.h"
#include <string>
#include <clocale>
#include <cstdlib>

void Time::plustime() {
  for (int i = 0; i < 4; i++) {
    cout << "�������� �����(��� ������: �������� ���������� +):" << endl;
    Show();
    Sleep(1000); // �������� � 1 ���.
    sec = sec + 1;
    system("cls");
    proverka();
  }
}

void Time::minustime() {
  for (int i = 0; i < 4; i++) {
    cout << "�������� �����(��� �����: �������� ���������� -):" << endl;
    Show();
    Sleep(1000); // �������� � 1 ���.
    sec = sec - 1;
    system("cls");
    proverka();
  }
}

void Time::proverka() {
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

void Time::Show()
{
  proverka();
  null(hour);
  cout << ":";
  null(minut);
  cout << ":";
  null(sec);
}

ostream& operator<<(ostream& stream, const Time& c)
{
  cout << c.hour << " : " << c.minut << " : " << c.sec << endl << endl;
  return stream;
}

istream& operator>>(istream& stream, Time& c)
{

  cout << "\n������� ����: ";
  cin >> c.hour;
  cout << "������� ������: ";
  cin >> c.minut;
  cout << "������� �������: ";
  cin >> c.sec;
  return stream;
}

void Time::null(int n) {
  if (n < 10) {
    cout << "0" << n;
  }
  else {
    cout << n;
  }
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
// ���������
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

int Time::wibor(int w) {
  while (w < 1 || w > 2) {
    cout << "\n������� ���������. 1 - �������� �����, 2 - �����." << endl;
    cout << "����: ";
    cin >> w;
  }
  return w;
}