#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_

#include <iostream>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

class ProcCenter {
  friend class Credit;
private:
  string* Dano;
  string password;
  int money;
  int het = 0;
  int cred = 0;
public:
  ProcCenter();
  ~ProcCenter();
  ProcCenter(string* _Dano, string _password, int _money, int _het, int _cred);
  ProcCenter(const ProcCenter& c);
  int getdate();
  void inpsetdate();
  friend bool operator==(const ProcCenter& left, const ProcCenter& right) {
    bool res = false;
    if (left.Dano[0] == right.Dano[0] && left.Dano[1] == right.Dano[1] && left.Dano[2] == right.Dano[2] &&
      left.money == right.money && left.het == right.het && left.password == right.password && left.cred == right.cred) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }
  ProcCenter operator=(ProcCenter& c);
};

class Credit {
private:
  int count = 0;
  ProcCenter* arr;
public:
  Credit();
  ~Credit();
  Credit(string* _Dano, string _password, int _money, int _het, int _cred);
  Credit(const Credit& c);
  Credit operator=(Credit& c);
  friend bool operator==(const Credit& left, const Credit& right) {
    bool res = false;
    if (left.count == right.count) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }
  void setdate(ProcCenter first);
  void menu();
  int exitandpreset();
  //void infile();
  //void outfile();
  void inf(int r);
  void creditmenu(int is, int or, int r);
};

#endif  // INCLUDE_ADD_H_
