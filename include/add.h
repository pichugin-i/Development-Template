#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#pragma once
#include <iostream>
#include <clocale>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>

using namespace std;

class TextEditor {
private:
  int x;
  int y;
public:
  int options();
  void position(int xpos, int ypos);
  void TXT();
  void showw(char *str);
  void iftext(char *str, int hir1);
  TextEditor();
  TextEditor(const TextEditor &c);
  TextEditor(int _x, int _y);
  bool operator==(const TextEditor& c);
  friend bool operator==(const TextEditor &left, const TextEditor &right) {
    bool res = false;
    if (left.x == right.x && left.y == right.y) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }
};
#endif  // INCLUDE_ADD_H_