#include "add.h"

using namespace std;

TextEditor::TextEditor() {
  x = 1;
  y = 1;
}

int TextEditor::options() {
  HWND window_header = GetConsoleWindow();
  SetWindowPos(window_header, HWND_TOP, 10, 10, 1000, 600, NULL);
  int op5 = 5;
  int hir, vis;
  do {
    position(50, 15);
    cout << "Настройки <Размер окна>:";
    position(50, 16);
    cout << "<1> Маленькое *600x230*";
    position(50, 17);
    cout << "<2> Среднее *1000x600*";
    position(50, 18);
    cout << "<3> Большое *1500x800*";
    position(50, 19);
    cout << "<4> Выбрать размер самостоятельно.";
    position(50, 20);
    cout << "Выбор: ";
    cin >> op5;
    system("CLS");
  } while (op5 < 1 || op5>4);
  if (op5 == 1) {
    hir = 600;
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, 430, 100, hir, 230, NULL);
  }
  if (op5 == 2) {
    hir = 1000;
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, 50, 50, hir, 600, NULL);
  }
  if (op5 == 3) {
    hir = 1500;
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, 10, 10, hir, 800, NULL);
  }
  if (op5 == 4) {
    do {
      position(45, 15);
      cout << "<Ширина>x<высота> не должны превышать <1500>x<800>";
      position(45, 16);
      cout << "<Ширина>x<высота> не должны быть меньше <600>x<230>";
      position(45, 17);
      cout << "Введите ШИРИНУ окна в пикселях: ";
      cin >> hir;
      system("CLS");
    } while (hir > 1500 || hir < 230);
    do {
      position(45, 15);
      cout << "<Ширина>x<высота> не должны превышать <1500>x<800>";
      position(45, 16);
      cout << "<Ширина>x<высота> не должны быть меньше <600>x<230>";
      position(45, 17);
      cout << "Введите ВЫСОТУ окна в пикселях: ";
      cin >> vis;
      system("CLS");
    } while (vis > 800 || vis < 230);
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, 10, 10, hir, vis, NULL);
  }
  int xx, yy;

  if (op5 == 1) {
    do {
      position(22, 4);
      cout << "Настройки <Позиция окна>:";
      position(22, 5);
      cout << "Введите позицию окна по оси в пикселях:";
      position(22, 6);
      cout << "Где X=0; Y=0 => Верхний левый угол";
      position(22, 7);
      cout << "По горизонтали <Позиция по оси X>: ";
      cin >> xx;
      system("CLS");
    } while (xx < 0 || xx >1500);
    do {
      position(22, 4);
      cout << "Настройки <Позиция окна>:";
      position(22, 5);
      cout << "Введите позицию окна по оси в пикселях:";
      position(22, 6);
      cout << "Где X=0; Y=0 => Верхний левый угол";
      position(22, 7);
      cout << "По вертикали <Позиция по оси Y>: ";
      cin >> yy;
      system("CLS");
    } while (yy < 0 || yy>1500);
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, xx, yy, 600, 230, NULL);
  }
  if (op5 == 2) {
    do {
      position(50, 15);
      cout << "Настройки <Позиция окна>:";
      position(50, 16);
      cout << "Введите позицию окна по оси в пикселях:";
      position(50, 17);
      cout << "Где X=0; Y=0 => Верхний левый угол";
      position(50, 18);
      cout << "По горизонтали <Позиция по оси X>: ";
      cin >> xx;
      system("CLS");
    } while (xx < 0 || xx >1500);
    do {
      position(50, 15);
      cout << "Настройки <Позиция окна>:";
      position(50, 16);
      cout << "Введите позицию окна по оси в пикселях:";
      position(50, 17);
      cout << "Где X=0; Y=0 => Верхний левый угол";
      position(50, 18);
      cout << "По вертикали <Позиция по оси Y>: ";
      cin >> yy;
      system("CLS");
    } while (yy < 0 || yy>1500);
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, xx, yy, 1000, 600, NULL);
  }
  if (op5 == 3) {
    do {
      position(85, 18);
      cout << "Настройки <Позиция окна>:";
      position(85, 19);
      cout << "Введите позицию окна по оси в пикселях:";
      position(85, 20);
      cout << "Где X=0; Y=0 => Верхний левый угол";
      position(85, 21);
      cout << "По горизонтали <Позиция по оси X>: ";
      cin >> xx;
      system("CLS");
    } while (xx < 0 || xx >1500);
    do {
      position(85, 18);
      cout << "Настройки <Позиция окна>:";
      position(85, 19);
      cout << "Введите позицию окна по оси в пикселях:";
      position(85, 20);
      cout << "Где X=0; Y=0 => Верхний левый угол";
      position(85, 21);
      cout << "По вертикали <Позиция по оси Y>: ";
      cin >> yy;
      system("CLS");
    } while (yy < 0 || yy>1500);
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, xx, yy, 1500, 800, NULL);
  }
  if (op5 == 4) {
    do {
      position(5, 5);
      cout << "Настройки <Позиция окна>:";
      position(5, 6);
      cout << "Введите позицию окна по оси в пикселях:";
      position(5, 7);
      cout << "Где X=0; Y=0 => Верхний левый угол";
      position(5, 8);
      cout << "По горизонтали <Позиция по оси X>: ";
      cin >> xx;
      system("CLS");
    } while (xx < 0 || xx >1500);
    do {
      position(5, 5);
      cout << "Настройки <Позиция окна>:";
      position(5, 6);
      cout << "Введите позицию окна по оси в пикселях:";
      position(5, 7);
      cout << "Где X=0; Y=0 => Верхний левый угол";
      position(5, 8);
      cout << "По вертикали <Позиция по оси Y>: ";
      cin >> yy;
      system("CLS");
    } while (yy < 0 || yy>1500);
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, xx, yy, hir, vis, NULL);
  }
  return hir;
}

void TextEditor::position(int xpos, int ypos) {
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cursorPos;
  cursorPos.X = xpos;
  cursorPos.Y = ypos;
  SetConsoleCursorPosition(hStdOut, cursorPos);
}

TextEditor::TextEditor(int _x, int _y) {
  x = _x;
  y = _y;
}

void TextEditor::TXT() {
  int pravila = 0;
  do {
    position(1, 1);
    cout << "Правила использования редактора [Правила тут придумывает программист! :) ]";
    position(1, 2);
    cout << "<1> Длина предложения не должна превышать длину поля окна,";
    position(1, 3);
    cout << "иначе оно будет обрезано.";
    position(1, 4);
    cout << "<2> Если вы закончили писать, поставьте в конце символ(точку) <.>";
    position(5, 6);
    cout << "Вам понятны правила? <Да> >> напишите *1* : ";
    cin >> pravila;
    system("CLS");
  } while (pravila != 1);
}

void TextEditor::showw(char *str) {
  int ab;
  do {
    position(0, 5);
    cout << "Ваш текст:";
    cout << str << ".";
    position(18, 8);
    cout << "Нажмите <1>, чтобы скрыть редактор.";
    position(18, 9);
    cout << "Нажмите <2>, чтобы завершить программу.";
    position(18, 10);
    cout << "CMD>> ";
    cin >> ab;
    if (ab != 1 || ab != 2) {
      system("CLS");
    }
    if (ab == 1) {
      HWND hWnd = GetConsoleWindow();
      ShowWindow(hWnd, SW_MINIMIZE);
    }
  } while (ab != 2);
  if (ab == 2) {
    system("pause");
  }
}

void TextEditor::iftext(char *str, int hir1) {
  //cout << "<1> Маленькое *600x230*";
  //position(50, 17);
  //cout << "<2> Среднее *1000x600*";
  //position(50, 18);
  //cout << "<3> Большое *1500x800*";
  if (hir1 == 600) {
    cin.getline(str, 76, '.');
  }
  else {
    if (hir1 == 1000) {
      cin.getline(str, 131, '.');
    }
    else {
      if (hir1 == 1500) {
        cin.getline(str, 201, '.');
      }
      else {
        if (hir1 < 800) {
          double k = 7.75;
          cin.getline(str, hir1 / k, '.');
        }
        else {
          if (hir1 < 1000 && hir1 >= 800) {
            double k = 7.68;
            cin.getline(str, hir1 / k, '.');
          }
          else {
            if (hir1 < 1200 && hir1 >= 1000) {
              double k = 7.57;
              cin.getline(str, hir1 / k, '.');
            }
            else {
              double k = 7.48;
              cin.getline(str, hir1 / k, '.');
            }
          }
        }
      }
    }
  }
}