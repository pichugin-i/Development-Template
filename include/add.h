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
  int srokk;
  int viplat = 0;
public:
  ProcCenter();
  ~ProcCenter();
  ProcCenter(string* _Dano, string _password, int _money, int _het, int _cred, int _srokk, int _viplat);
  ProcCenter(const ProcCenter& c);
  int getdate();
  void inpsetdate();
  friend bool operator==(const ProcCenter& left, const ProcCenter& right) {
    bool res = false;
    if (left.Dano[0] == right.Dano[0] && left.Dano[1] == right.Dano[1] && left.Dano[2] == right.Dano[2] &&
      left.money == right.money && left.het == right.het && left.password == right.password && left.cred == right.cred &&
      left.srokk == right.srokk && left.viplat == right.viplat) {
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
  Credit(string* _Dano, string _password, int _money, int _het, int _cred, int _srokk, int _viplat);
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
  void inf(int r);
  int creditmenu(int is, int or, int r);
  int one(int is, int or , int r, int non);
  int two(int is, int or , int r, int non);
  int three(int is, int or , int r, int non);
  int four(int is, int or , int r, int non);
  int five(int is, int or , int r, int non);
  int algoritm(int stavka, int var, int non);
  int ress(int cr, int r, int or , int is);
  void infoostkred(int is, int r, int or , int non);
  int funstav(int is, int r, int or , int non);
  void fiktcred(int is, int or , int r);
  void odinnachkred(int is, int or , int r);
  void dosrochno(int is, int or , int r);
  void getcred(int is, int or , int r);
  int ss(int is, int r, int or , int non, int s, int cred1);
  void vsegoviplat(int is, int r, int or , int s);
};

#endif  // INCLUDE_ADD_H_