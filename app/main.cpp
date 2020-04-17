#include "add.h"

int main()
{
  setlocale(LC_ALL, "Russian");

  decimal a = "24";
  decimal b = "21";
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
  cout << a << " + " << b << " = ";

  cout << endl << endl;

  cout << "Их вычитание:" << endl;
  cout << a << " - " << b << " = ";

  cout << endl;

  return 0;
}