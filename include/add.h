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
  // x,y-позиция ввода текста, len - длина ввода текста в поле.
  int x;
  int y;
public:
  void options();
  void position(int xpos, int ypos);
  void TXT();
  void showw(char *str);
  TextEditor();
  TextEditor(const TextEditor &c);
  TextEditor(int _x, int _y);
  friend ostream& operator << (ostream& stream, const TextEditor& a);
  friend istream& operator >> (istream& stream, TextEditor& a);
};
#endif  // INCLUDE_ADD_H_