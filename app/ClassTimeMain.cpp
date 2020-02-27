// Copyright 2020 pichugin.i
#include <iostream>
#include <clocale>
#include <cstdlib>  // Для реалистичности времени в консоли.
#include <string>
#include "ClassTime.h"
#include <windows.h>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  int w;
  Time time(23, 15, 59); // для конструктора инициализации.
  time.plustime(); // +1 секунда в секунду xD
  time.minustime(); // -1 секунда в секунду.
  cout << "Исходное время:" << endl;
  time.Show();
  cout << endl;
  cout << "Свойства:" << endl << "Введите * 1 * , чтобы изменить время." << endl << "Введите * 2 * , чтобы выйти." << endl;
  cout << "Ввод: ";
  cin >> w;
  w = wibor(w);
  if (w == 1) {
    cin >> time;
    time.Show();
    time.plustime(); // +1 секунда в секунду xD
    time.minustime(); // -1 секунда в секунду.
    cout << "Исходное время:" << endl;
    time.Show();
  }
  cout << endl;
  system("pause");
  return 0;
}