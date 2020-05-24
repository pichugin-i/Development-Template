#include "..\include\add.h"
#include "..\include\add.h"
#include "..\include\add.h"
#include "add.h"

Position::Position() {
  xp = 0;
  yp = 0;
}

Position::Position(const Position& c) {
  xp = c.xp;
  yp = c.yp;
}

Position::Position(int _xp, int _yp) {
  xp = _xp;
  yp = _yp;
}

void Position::positiontext(int xpos, int ypos) {
  if (xpos <= 0 || ypos <= 0)
    throw logic_error("Input error xpos ypos");
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cursorPos;
  cursorPos.X = xpos;
  cursorPos.Y = ypos;
  SetConsoleCursorPosition(hStdOut, cursorPos);
}

Zmeika::Zmeika()
{
  end = false;
  score = 0;
  frx = 0;
  fry = 0;
  x = hir/2;
  y = vis/2;
  count = 0;
  dir = eD::STOP;
  win = 0;
}

Zmeika::~Zmeika()
{
  delete[] tx;
  delete[] ty;
}

Zmeika::Zmeika(const Zmeika& c)
{
  if (count != 0) {
    count = c.count;
    delete[] tx;
    delete[] ty;
  }
  score = c.score;
  frx = c.frx;
  fry = c.fry;
  x = c.x;
  y = c.y;
  dir = c.dir;
  end = c.end;
  win = c.win;
}

void Zmeika::startmenu() {
  Position p;
  do {
    int w = 0;
  do {
    p.positiontext(53, 6);
    cout << "Игра <Змейка>";
    p.positiontext(51, 10);
    cout << "Уровень сложности:";
    p.positiontext(30, 12);
    cout << "<1> Лёгкий - проходить через стены, появляясь с противоположной стороны.";
    p.positiontext(30, 13);
    cout << "<2> Сложный - Столкновение со стеной - окончание игры.";
    p.positiontext(55, 14);
    cout << ">> ";
    cin >> w;
    system("CLS");
  } while (w < 1 || w>2);
    do {
      p.positiontext(53, 6);
      cout << "Игра <Змейка>";
      p.positiontext(30, 10);
      cout << "Введите число фруктов, сколько змейка должна съесть для победы:";
      p.positiontext(43, 11);
      cout << "Минимум 5 | Максимум 100 фруктов";
      p.positiontext(55, 12);
      cout << ">> ";
      cin >> win;
      system("CLS");
    } while (win < 5 || win>100);
    p.positiontext(53, 6);
    cout << "Игра <Змейка>";
    p.positiontext(45, 7);
    cout << "Управление: WASD или Стрелочки";
    p.positiontext(30, 11);
    cout << "Чтобы начать игру, нажмите любую кнопку (У вас нет выбора ._.)";
    p.positiontext(58, 12);
    _getch();
    system("CLS");
    p.positiontext(47, 13);
    cout << "Игра начнётся через <3>";
    Sleep(1000);
    system("CLS");
    p.positiontext(47, 13);
    cout << "Игра начнётся через <2>";
    Sleep(1000);
    system("CLS");
    p.positiontext(47, 13);
    cout << "Игра начнётся через <1>";
    Sleep(1000);
    system("CLS");
    p.positiontext(55, 13);
    cout << "GO";
    Sleep(1000);
    system("CLS");
    Setup();
    while (!end) {
      Draw();
      Input();
      Logic(w);
      if (score == win) end=true;
    }
    system("CLS");
    p.positiontext(43, 10);
    cout << "Вы собрали: " << score << " / " << win << " фруктов.";
    if (end == true || score == win) {
      Setup();
      p.positiontext(35, 11);
      cout << "Нажмите любую кнопку, чтобы вернуться в меню..";
      _getch();
      system("CLS");
      win = 0;
    }
  } while (!end);
}

void Zmeika::Setup() {
  end = false;
  dir = eD::STOP;
  x = hir / 2 - 1;
  y = vis / 2 - 1;
  frx = rand() % hir;
  fry = rand() % vis;
  score = 0;
  count = 0;
}

void Zmeika::Draw() {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  Sleep(100);
  system("CLS");
  cout << "Всего собрано фруктов: " << score << ". Осталось собрать: " << win - score << endl;
  for (int i = 0; i < hir+1; i++) {
    cout << "#";
  }
  cout << endl;
  for (int i = 0; i < vis; i++) {
    for (int j = 0; j < hir; j++) {
      if (j == 0 || j == hir - 1) {
        cout << "#";
      }
      if (i == y && j == x) {
        SetConsoleTextAttribute(handle, 9);
        cout << "O";
        SetConsoleTextAttribute(handle, 7);
      }
      else {
        if (i == fry && j == frx) {
          SetConsoleTextAttribute(handle, 2);
          cout << "X";
          SetConsoleTextAttribute(handle, 7);
        }
        else {
          bool go = false;
          for (int k = 0; k < count; k++) {
            if (tx[k] == j && ty[k] == i) {
              go = true;
              SetConsoleTextAttribute(handle, 14);
              cout << "o";
              SetConsoleTextAttribute(handle, 7);
            }
          }
          if (!go) {
            cout << " ";
          }
        }
      }
    }
    cout << endl;
  }
  for (int i = 0; i < hir+1; i++) {
    cout << "#";
  }
}

void Zmeika::Input() {
  if (_kbhit()) {
    switch (_getch())
    {
    case 97:
      if (dir != eD::RIGHT || count == 0) {
        dir = eD::LEFT; 
      }
      break;
    case 100:
      if (dir != eD::LEFT || count == 0) {
        dir = eD::RIGHT;
      }
      break;
    case 119:
      if (dir != eD::DOWN || count == 0) {
        dir = eD::UP;
      }
      break;
    case 115:
      if (dir != eD::UP || count == 0) {
        dir = eD::DOWN;
      }
      break;
    case 0x4B:
      if (dir != eD::RIGHT || count == 0) {
        dir = eD::LEFT;
      }
      break;
    case 0x4D:
      if (dir != eD::LEFT || count == 0) {
        dir = eD::RIGHT;
      }
      break;
    case 0x48:
      if (dir != eD::DOWN || count == 0) {
        dir = eD::UP;
      }
      break;
    case 0x50:
      if (dir != eD::UP || count == 0) {
        dir = eD::DOWN;
      }
      break;
    }
  }
}

void Zmeika::Logic(int w) {
  int pred2x, pred2y;
  int predx = tx[0];
  int predy = ty[0];
  tx[0] = x;
  ty[0] = y;
  for (int i = 1; i < count; i++) {
    pred2x = tx[i];
    pred2y = ty[i];
    tx[i] = predx;
    ty[i] = predy;
    predx = pred2x;
    predy = pred2y;
  }
  switch (dir)
  {
  case eD::LEFT:
    x--;
    if (count < 5)
    count++;
    break;
  case eD::RIGHT:
    x++;
    if (count < 5)
      count++;
    break;
  case eD::UP:
    y--;
    if (count < 5)
      count++;
    break;
  case eD::DOWN:
    y++;
    if (count < 5)
      count++;
    break;
  }
  if (w == 1) {
    if (x >= hir) {
      x = 0;
    }
    else {
      if (x < 0) {
        x = hir - 1;
      }
    }
    if (y >= vis) {
      y = 0;
    }
    else {
      if (y < 0) {
        y = vis - 1;
      }
    }
  }
  else {
    if (x > hir || x<0 || y>vis || y < 0) {
      end = true;
    }
  }
  for (int i = 0; i < count; i++) {
    if (tx[i] == x && ty[i] == y) {
      end = true;
    }
  }
  if (x == frx && y == fry) {
    score = score + 1;
    frx = rand() % hir;
    fry = rand() % vis;
    count++;
  }
}