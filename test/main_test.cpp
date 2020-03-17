#include <gtest/gtest.h>
#include <iostream>
#include <clocale>
#include <fstream>
#include "add.h"
using namespace std;
decimal::decimal() {
  dec = 0;
  na = 0;
}

decimal::~decimal() {
  dec = 0;
  na = 0;
}

decimal& decimal::operator=(const decimal &c) {
  (*this).dec = c.dec;
  (*this).na = c.na;
  return *this;
}

decimal::decimal(const char* _dec) {
  na = strlen(_dec);
  for (int i = na - 1; i >= 0; i--, _dec++) {
    dec[i] = *_dec;
  }
}

decimal::decimal(const decimal& c) {
  dec = c.dec;
  na = c.na;
}

bool decimal::operator==(const decimal& c) {
  bool res = 0;
  for (int i = 0; i < na && i < c.na; i++) {
    if (dec[i] == c.dec[i] && na == c.na && res == 1) {
      res = 1;
    }
    else {
      res = 0;
    }
  }
  return res;
}

ostream& operator<<(ostream& stream, const decimal& c) {
  for (int i = c.na - 1; i < c.na; i--) {
    stream << c.dec[i];
  }
  return stream;
}

istream& operator>>(istream& stream, decimal& c)
{
  for (int i = c.na - 1; i < c.na; i--) {
    stream >> c.dec[i];
  }
  return stream;
}
