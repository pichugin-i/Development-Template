#include "add.h"

int main()
{
  setlocale(LC_ALL, "Russian");

  decimal a = "2123";
  decimal b = "123";
  decimal res;
  cout << "Первое число = " << a << endl;
  cout << "Второе число = " << b << endl;
  if (a == b) {
    cout << "Они равны." << endl << endl;
  }
  else {
    cout << "Они не равны" << endl << endl;
  }
  cout << "Их сложение:" << endl;
  res = a + b;
  cout << a << " + " << b << " = ";
  cout << res;

  cout << endl << endl;

  cout << "Их вычитание:" << endl;
  res = a - b;
  cout << a << " - " << b << " = ";
  cout << res;

  cout << endl;

  return 0;
}