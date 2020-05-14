#include "add.h"

ProcCenter::ProcCenter() {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = '\0';
  }
  password = '\0';
  money = 0;
  het = 0;
}

ProcCenter::ProcCenter(string* _Dano, string _password, int _money, int _het) {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = _Dano[i];
  }
  password = _password;
  money = _money;
  het = _het;
}

ProcCenter::ProcCenter(const ProcCenter& c) {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = c.Dano[i];
  }
  password = c.password;
  money = c.money;
  het = c.het;
}

ProcCenter::~ProcCenter() {
  delete[] Dano;
  password = '\0';
  money = 0;
  het = 0;
}

Credit::Credit() {
  count = 0;
}

Credit::~Credit() {
  if (count != 0) {
    count = 0;
    delete[] arr;
  }
}

ProcCenter ProcCenter::operator=(ProcCenter& c) {
  for (int i = 0; i < 3; i++) {
    Dano[i] = c.Dano[i];
  }
  money = c.money;
  password = c.password;
  return *this;
}

Credit::Credit(string* _Dano, string _password, int _money, int _het) {
  arr = new ProcCenter[1];
  for (int i = 0; i < 3; i++) {
    arr[0].Dano[i] = _Dano[i];
  }
  arr[0].password = _password;
  arr[0].money = _money;
  arr[0].het = _het;
}

Credit::Credit(const Credit& c) {
  count = c.count;
  arr = new ProcCenter[count];
  for (int j = 0; j < c.count; ++j) {
    for (int i = 0; i < 3; i++) {
      arr[j].Dano[i] = c.arr[j].Dano[i];
    }
    arr[j].money = c.arr[j].money;
    arr[j].password = c.arr[j].password;
    arr[j].het = c.arr[j].het;
  }
}

Credit Credit::operator=(Credit& c) {
  if (count != c.count) {
    if (count != 0) delete[] arr;
    arr = new ProcCenter[count];
    count = c.count;
  }

  for (int i = 0; i < count; i++) {
    arr[i] = c.arr[i];
  }
  for (int i = 0; i < count; i++) {
    arr[i].money = c.arr[i].money;
    arr[i].password = c.arr[i].password;
    arr[i].het = c.arr[i].het;
    for (int j = 0; j < 3; j++)
      arr[i].Dano[j] = c.arr[i].Dano[j];
  }
  return *this;
}

void ProcCenter::getdate() {
  int i;
  do {
    cout << "Введите ваше <Имя>. Пример: Ivan. Длина имени от 3 до 15 символов: " << endl;
    cout << "Ввод: ";
    cin >> Dano[0];
    i = Dano[0].length();
    if (i < 3 || i>15) {
      cout << "Длина имени зашла за границу допустимого. [3-12 символов]. Повторите попытку" << endl;
    }
  } while (i < 3 || i>15);
  do {
    cout << "Введите вашу <Фамилию>. Пример: Ivanov. Длина фамилии от 3 до 20 символов: " << endl;
    cout << "Ввод: ";
    cin >> Dano[1];
    i = Dano[1].length();
    if (i < 3 || i>20) {
      cout << "Длина фамилии зашла за границу допустимого. [3-20 символов]. Повторите попытку" << endl;
    }
  } while (i < 3 || i>20);
  do {
    cout << "Введите ваше <Отчество>. Пример: Ivanovich. Длина отчества от 3 до 20 символов: " << endl;
    cout << "Ввод: ";
    cin >> Dano[2];
    i = Dano[2].length();
    if (i < 3 || i>20) {
      cout << "Длина отчества зашла за границу допустимого. [3-20 символов]. Повторите попытку" << endl;
    }
  } while (i < 3 || i>20);
  do {
    cout << "Придумайте <Пароль>. Пример: Ivan123123. Длина пароля от 6 до 20 символов: " << endl;
    cout << "Ввод: ";
    cin >> password;
    i = password.length();
    if (i < 6 || i>20) {
      cout << "Длина пароля зашла за границу допустимого. [6-20 символов]. Повторите попытку" << endl;
    }
  } while (i < 6 || i>20);
  do {
    cout << "Сколько у вас денег: " << endl;
    cout << "Ввод: ";
    cin >> money;
    if (money < 0 || money>1000000000) {
      cout << "Ваш счёт не может быть отрицательным или превышать 1.000.000.000 рублей." << endl;
      cout << "Повторите попытку ввода." << endl;
    }
  } while (money < 0 || money>1000000000);
  system("CLS");
  cout << endl << "Вы успешно зарегестрированы." << endl << endl;
  het++;
}

void Credit::menu() {
  int w = 0;
  cout << "У вас еще нет аккаунта для интернет-банка. Зарегистрируйтесь:" << endl;
  ProcCenter first_data;
  first_data.getdate();
  (*this).setdate(first_data);
  first_data.infile();

  while (w != 8) {
    do {
      cout << endl << "Меню действий интернет-банка:" << endl;
      cout << "<1> Показать информацию об аккаунте" << endl;
      cout << "<2> Выйти из аккаунта" << endl;
      cout << ".....Тут будут еще много действий......" << endl;
      cout << "<8> Выйти" << endl;
      cout << "Выбор: ";
      cin >> w;
      if (w < 1 || w>8) {
        cout << endl << "Вы ввели неправильный номер действия. Повторите:" << endl << endl;
      }
    } while (w < 1 || w>8);
    if (w == 1) {
      cout << endl;
      first_data.outfile();
    }
    if (w == 2) {
      system("CLS");
      exitandpreset();
    }
    if (w == 8) {
      system("pause");
    }
  }
}

void ProcCenter::infile() {
  ofstream in;
  in.open("Info.txt");
    in << "Ваше Имя: "<< Dano[0] << endl;
    in << "Ваша Фамилия: "<< Dano[1] << endl;
    in << "Ваше Отчество: "<< Dano[2] << endl;
    in << "Всего денег: "<< money << " RUB."<< endl;
  in.close();
}

void ProcCenter::outfile() {
  string str;
  ifstream out("Info.txt");
  if (!out.is_open()) {
    throw logic_error("not find file");
    cout << "Не удалось открыть файл" << endl;
  }
  else {
    while (!out.eof()) {
      str = "";
      getline(out, str);
      cout << str << endl;
    }
  }
  out.close();
}

void Credit::exitandpreset() {
  int pre;
  int nomer;
  int index;
  ProcCenter get;
  cout << "Вам доступны следущие действия: " << endl;
  do {
    cout << "<1> Войти в существующую учётную запись." << endl;
    cout << "<2> Зарегистрировать новый аккаунт." << endl;
    cout << "Выбор: ";
    cin >> pre;
  } while (pre < 1 || pre>2);
  if (pre == 1) {
    do {
      system("CLS");
      cout << "Введите ваш номер счёта:(Например если у вас номер счёта 0007, Ввод: 7 " << endl;
      cout << "Номер счёта: ";
      cin >> nomer;
      cout << endl;
      if (nomer < 1 || nomer > 9999) {
        cout << "Номер счёта не может быть отрицательным и больше допустимого значения(9999)" << endl;
        cout << "Повторите попытку." << endl;
      }
    } while (nomer < 1 || nomer > 9999);
    if (nomer <= count) {
      char p[20];
      cout << "Введите пароль от данного номера счёта: ";
      cin >> p;
      for (int i = 0; i < count; i++) {
        if (p == arr[i].password) {
          index = i;
          system("CLS");
          cout << "Вы успешно вошли в аккаунт." << endl << endl;

        }
        else {
          if (p != arr[i].password && i + 1 <= count) {
            if (nomer < 10) {
              cout << "Вы ввели неверный пароль для счёта #000" << nomer << endl;
              cout << "Возвращение в меню действий." << endl << endl;
            }
            else {
              if (nomer >= 10 && nomer < 100) {
                cout << "Вы ввели неверный пароль для счёта #00" << nomer << endl;
                cout << "Возвращение в меню действий." << endl << endl;
              }
              else {
                if (nomer >= 100 && nomer < 1000) {
                  cout << "Вы ввели неверный пароль для счёта #0" << nomer << endl;
                  cout << "Возвращение в меню действий." << endl << endl;
                }
                else {
                  cout << "Вы ввели неверный пароль для счёта #" << nomer << endl;
                  cout << "Возвращение в меню действий." << endl << endl;
                }
              }
            }
          }
          exitandpreset();
        }
      }
    }
    else {
      cout << "Номер счёта не найден." << endl;
      exitandpreset();
    }
  }
  if (pre == 2) {
    system("CLS");
    get.getdate();
    get.infile();
  }
}

void ProcCenter::inpsetdate() {
  system("CLS");
  for (int i = 0; i < het; i++) {
    cout << endl << "Текущая информация об аккаунте." << endl;
    if (het < 10) {
      cout << "Номер счёта: 000" << het << endl;
    }
    else {
      if (het >= 10 && het < 100) {
        cout << "Номер счёта: 00" << het << endl;
      }
      else {
        if (het >= 100 && het < 1000) {
          cout << "Номер счёта: 0" << het << endl;
        }
        else {
          cout << "Номер счёта: " << het << endl << endl;
        }
      }
    }
    cout << "Имя: " << Dano[0] << endl;
    cout << "Фамилия: " << Dano[1] << endl;
    cout << "Отчество: " << Dano[2] << endl;
    cout << "Всего денег: " << money << endl;
  }
}

void Credit::setdate(ProcCenter new_data) {
  Credit copy(*this);
  if (count != 0) {
    delete[] arr;
  }
  arr = new ProcCenter[count + 1];
  count = count + 1;
  for (int i = 0; i < count - 1; ++i) {
    arr[i] = copy.arr[i];
  }
  arr[count - 1] = new_data;
}