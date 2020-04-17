#include "add.h"
decimal::decimal() { // По умолчанию
  dec = 0;
  na = 0;
}

decimal::~decimal() { // Деструктор
  dec = 0;
  na = 0;
}

decimal& decimal::operator=(const decimal &c) { // Присваивание
  for (int i = 0; i < na; i++)
    dec[i] = c.dec[i];
  na = c.na;
  return *this;
}

decimal::decimal(const char* _dec) { // Инициализация
  na = strlen(_dec);
  for (int i = na - 1; i >= 0; i--, _dec++) {
    dec[i] = *_dec;
  }
}

decimal::decimal(const decimal &c) { // Копирование
  na = c.na;
  for (int i = 0; i < na; i++) {
    dec[i] = c.dec[i];
    }
}

bool operator==(const  decimal &l, const  decimal &r) { // Пер.сравнения
  bool result = 0;
  int i;

  for (i = 0; (i < l.na) && (i < r.na); i++) {
    if (l.dec[i] == r.dec[i]) {
      result = 1;
    }
    else {
      result = 0;
    }
    return result;
  }

}

ostream& operator<<(ostream &stream, const decimal &c) { // Вывод
  int i;
  for (i = c.na - 1; i < c.na; i--) {
    stream << c.dec[i];
  }
  return stream;
}

istream& operator>>(istream &stream, decimal &c) { // Ввод
  int i;
  for (i = c.na - 1; i < c.na; i--) {
    stream >> c.dec[i];
  }
  return stream;
}


//decimal decimal::operator+(const decimal &c) {
//  int l, lm;
//}