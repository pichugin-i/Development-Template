#ifndef INCLUDE_add_H_
#define INCLUDE_add_H_
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

class decimal
{
private:
  unsigned char *dec = new unsigned char;
  size_t na;
public:
  decimal();
  ~decimal();
  decimal(const char *_dec);
  decimal(const decimal &c);
  decimal& operator=(const decimal &c);
  friend bool operator==(const  decimal &l, const  decimal &r);
  decimal operator+(const decimal &c);
  decimal operator-(const decimal &c);
  friend ostream& operator<<(ostream &stream, const decimal &c);
  friend istream& operator>>(istream &stream, decimal &c);
};

#endif  // INCLUDE_ADD_H_
