#include <iostream>
#include <clocale>
#include <fstream>
#include "add.h"
using namespace std;
int main()
{
  setlocale(LC_ALL, "Russian");
  decimal a = "1123";
  decimal b = "2224";
  cout << "Первое число = " << a << endl;
  cout << "Второе число = " << b << endl;
  if (a == b) {
    cout << "Они равны." << endl;
  }
  else {
    cout << "Они не равны" << endl;
  }
  cout << "Их сложение:" << endl;
  cout << a << " + " << b << " = ";

  cout << endl;



  cout << "Их вычитание:" << endl;
  cout << a << " - " << b << " = ";

  cout << endl;
  return 0;
}