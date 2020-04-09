#include "add.h"

using namespace std;

NOTIFYICONDATA pnid;
int main() {
  SetConsoleTitle("TextEditor");
  setlocale(LC_ALL, "Russian");
  char str[300];
  TextEditor a;
  TextEditor t1;
  TextEditor put;
  TextEditor show;
  TextEditor iff;
  int hir1 = a.options();
  put.TXT();
  t1.position(1, 4);
  cout << "¬ведите текст:";
  t1.position(1, 5);
  cout << ">> ";
  iff.iftext(str, hir1);
  system("CLS");
  show.showw(str);
}