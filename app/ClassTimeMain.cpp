// Copyright 2020 pichugin.i
#include <iostream>
#include <clocale>
#include <cstdlib>  // ��� �������������� ������� � �������.
#include <string>
#include "ClassTime.h"
#include <windows.h>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  int w;
  Time time(23, 15, 59); // ��� ������������ �������������.
  time.plustime(); // +1 ������� � ������� xD
  time.minustime(); // -1 ������� � �������.
  cout << "�������� �����:" << endl;
  time.Show();
  cout << endl;
  cout << "��������:" << endl << "������� * 1 * , ����� �������� �����." << endl << "������� * 2 * , ����� �����." << endl;
  cout << "����: ";
  cin >> w;
  w = wibor(w);
  if (w == 1) {
    cin >> time;
    time.Show();
    time.plustime(); // +1 ������� � ������� xD
    time.minustime(); // -1 ������� � �������.
    cout << "�������� �����:" << endl;
    time.Show();
  }
  cout << endl;
  system("pause");
  return 0;
}