#include "add.h"
decimal::decimal() { // По умолчанию
  dec = 0;
  na = 0;
}

decimal::~decimal() { // Деструктор
  dec = 0;
  na = 0;
}

decimal::decimal(int len) {
  na = len;
  dec = new unsigned char[len];
}

decimal& decimal::operator=(const decimal &c) { // Присваивание
  na = c.na;
  dec = new unsigned char[na];
  for (int i = 0; i < na; i++) {
    dec[i] = c.dec[i];
  }
  return *this;
}

decimal::decimal(const char* _dec) { // Инициализация
  na = strlen(_dec);
  dec = new unsigned char[na];
  for (int i = na - 1; i >= 0; i--, _dec++) {
    dec[i] = *_dec;
  }
}

decimal::decimal(const decimal &c) { // Копирование
  na = c.na;
  dec = new unsigned char[na];
  for (int i = 0; i < na; i++)
    dec[i] = c.dec[i];
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
  for (int i = c.na - 1; i < c.na; --i) {
    stream << c.dec[i];
  }
  return stream;
}

istream& operator>>(istream &stream, decimal &c) { // Ввод
  for (int i = c.na - 1; i < c.na; i--) {
    stream >> c.dec[i];
  }
  return stream;
}


decimal decimal::operator+(const decimal &c) {
  int len, lenm, lenr;
  int cout = 0;
  len = (na < c.na) ? c.na : na;
  lenm = (c.na < na) ? c.na : na;
  lenr = len - lenm;
  int *arr = new int[len];
  if (na < c.na) {
    int newlen = lenm + lenr;
    decimal tcopy(newlen);
    decimal ccopy(c);
    for (int i = 0; i < lenm; i++) {
      tcopy.dec[i] = dec[i];
    }
    for (int i = lenm; i < len; i++) {
      tcopy.dec[i] = '0';
    }
    for (int i = 0; i < len; i++) {
      arr[i] = cout + (tcopy.dec[i] - '0') + (ccopy.dec[i] - '0');
      cout = 0;
      if (arr[i] >= 10) {
        cout = 1;
        arr[i] = arr[i] % 10;
      }
    }
    if (cout == 1) {
      int plen = len + cout;
      decimal pluslen(plen);
      arr[len] = 1;
      for (int i = len; i >= 0; i--) {
        pluslen.dec[i] = arr[i];
        pluslen.dec[i] = pluslen.dec[i] + 48;
      }
      return pluslen;
    }
    else {
      decimal normlen(len);
      for (int i = len; i >= 0; i--) {
        normlen.dec[i] = arr[i];
        normlen.dec[i] = normlen.dec[i] + 48;
      }
      return normlen;
    }
  }
  if (c.na < na) {
    int newlen = lenm + lenr;
    decimal tcopy(*this);
    decimal ccopy(newlen);
    for (int i = 0; i < lenm; i++) {
      ccopy.dec[i] = c.dec[i];
    }
    for (int i = lenm; i < len; i++) {
      ccopy.dec[i] = '0';
    }
    for (int i = 0; i < len; i++) {
      arr[i] = cout + (tcopy.dec[i] - '0') + (ccopy.dec[i] - '0');
      cout = 0;
      if (arr[i] >= 10) {
        cout = 1;
        arr[i] = arr[i] % 10;
      }
    }
    if (cout == 1) {
      int plen = len + cout;
      decimal pluslen(plen);
      arr[len] = 1;
      for (int i = len; i >= 0; i--) {
        pluslen.dec[i] = arr[i];
        pluslen.dec[i] = pluslen.dec[i] + 48;
      }
      return pluslen;
    }
    else {
      decimal normlen(len);
      for (int i = len; i >= 0; i--) {
        normlen.dec[i] = arr[i];
        normlen.dec[i] = normlen.dec[i] + 48;
      }
      return normlen;
    }
  }
  if (na == c.na) {
    decimal tcopy(*this);
    decimal ccopy(c);
    for (int i = 0; i < len; i++) {
      arr[i] = cout + (tcopy.dec[i] - '0') + (ccopy.dec[i] - '0');
      cout = 0;
      if (arr[i] >= 10) {
        cout = 1;
        arr[i] = arr[i] % 10;
      }
    }
    if (cout == 1) {
      int plen = len + cout;
      decimal pluslen(plen);
      arr[len] = 1;
      for (int i = len; i >= 0; i--) {
        pluslen.dec[i] = arr[i];
        pluslen.dec[i] = pluslen.dec[i] + 48;
      }
      return pluslen;
    }
    else {
      decimal normlen(len);
      for (int i = len - 1; i >= 0; i--) {
        normlen.dec[i] = arr[i];
        normlen.dec[i] = normlen.dec[i] + 48;
      }
      return normlen;
    }
  }
}

decimal decimal::operator-(const decimal &c) {
  int len, lenm, lenr;
  int cout = 0;
  len = (na < c.na) ? c.na : na;
  lenm = (c.na < na) ? c.na : na;
  decimal r(len);
  lenr = len - lenm;
  int *arr = new int[len];
  if (na < c.na) {
    int newlen = lenm + lenr;
    decimal tcopy(newlen);
    decimal ccopy(c);
    for (int i = 0; i < lenm; i++) {
      tcopy.dec[i] = dec[i];
    }
    for (int i = lenm; i < len; i++) {
      tcopy.dec[i] = '0';
    }
    for (int i = 0; i < len; i++) {
      arr[i] = cout + (ccopy.dec[i] - '0') - (tcopy.dec[i] - '0');
      cout = 0;
      if (arr[i] < 0) {
        cout = -1;
        arr[i] = arr[i] + 10;
      }
    }
    for (int i = len - 1; i >= 0; i--) {
      r.dec[i] = arr[i];
      r.dec[i] = r.dec[i] + 48;
    }
    return r;
  }
  if (c.na < na) {
    int newlen = lenm + lenr;
    decimal tcopy(*this);
    decimal ccopy(newlen);
    for (int i = 0; i < lenm; i++) {
      ccopy.dec[i] = c.dec[i];
    }
    for (int i = lenm; i < len; i++) {
      ccopy.dec[i] = '0';
    }
    for (int i = 0; i < len; i++) {
      arr[i] = cout + (tcopy.dec[i] - '0') - (ccopy.dec[i] - '0');
      cout = 0;
      if (arr[i] < 0) {
        cout = -1;
        arr[i] = arr[i] + 10;
      }
    }
    for (int i = len - 1; i >= 0; i--) {
      r.dec[i] = arr[i];
      r.dec[i] = r.dec[i] + 48;
    }
    return r;
  }
  if (na == c.na) {
    int newlen = lenm + lenr;
    decimal tcopy(*this);
    decimal ccopy(c);
    for (int i = 0; i < lenm; i++) {
      tcopy.dec[i] = dec[i];
    }
    for (int i = lenm; i < len; i++) {
      tcopy.dec[i] = '0';
    }
    for (int i = 0; i < len; i++) {
      arr[i] = cout + (tcopy.dec[i] - '0') - (ccopy.dec[i] - '0');
      cout = 0;
      if (arr[i] < 0) {
        cout = -1;
        arr[i] = arr[i] + 10;
      }
    }
    for (int i = len - 1; i >= 0; i--) {
      r.dec[i] = arr[i];
      r.dec[i] = r.dec[i] + 48;
    }
    return r;
  }
}