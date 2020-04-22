#include "add.h"

Date::Date() {
  h_s = new int[2];
  h_e = new int[2];
  for (int i = 0; i < 2; i++) {
    h_s[i] = 0;
    h_e[i] = 0;
  }
  data = new int[3];
  for (int i = 0; i < 3; i++) {
    data[i] = 0;
  }
  st = 0;
}

Date::Date(int *_h_s, int *_h_e, int *_data, int _st) {
  h_s = new int[2];
  h_e = new int[2];
  data = new int[3];
  for (int i = 0; i < 2; i++) {
    h_s[i] = _h_s[i];
    h_e[i] = _h_e[i];
  }
  for (int i = 0; i < 3; i++) {
    data[i] = _data[i];
  }
  st = _st;
}

Date::Date(const Date &c) {
  h_s = new int[2];
  h_e = new int[2];
  data = new int[3];
  for (int i = 0; i < 2; i++) {
    h_s[i] = c.h_s[i];
    h_e[i] = c.h_e[i];
  }
  for (int i = 0; i < 3; i++) {
    data[i] = c.data[i];
  }
  st = c.st;
}

Date::~Date() {
  delete[] h_s;
  delete[] h_e;
  delete[] data;

  st = 0;
}

Pedometer::Pedometer() {
  count = 0;
}

Pedometer::Pedometer(int *_h_s, int *_h_e, int *_data, int _st) {
  num = new Date[1];
  for (int i = 0; i < 2; i++) {
    num[0].h_s[i] = _h_s[i];
    num[0].h_e[i] = _h_e[i];
  }
  for (int i = 0; i < 3; i++) {
    num[0].data[i] = _data[i];
  }
  num[0].st = _st;
}

Pedometer::Pedometer(const Pedometer &c) {
  count = c.count;
  num = new Date[count];
  for (int j = 0; j < c.count; ++j) {
    for (int i = 0; i < 2; i++) {
      num[j].h_s[i] = c.num[j].h_s[i];
      num[j].h_e[i] = c.num[j].h_e[i];
    }
    for (int i = 0; i < 3; i++) {
      num[j].data[i] = c.num[j].data[i];
    }
    num[j].st = c.num[j].st;
  }
}

Date Date::operator=(Date &c) {
  for (int i = 0; i < 2; i++) {
    h_s[i] = c.h_s[i];
    h_e[i] = c.h_e[i];
  }
  for (int i = 0; i < 3; i++) {
    data[i] = c.data[i];
  }
  st = c.st;
  return *this;
}

Pedometer::~Pedometer() {
  if (count != 0) {
    count = 0;
    delete[] num;
  }
}

Pedometer Pedometer::operator=(Pedometer &c) {
  if (count != c.count) {
    if (count != 0) delete[] num;
    num = new Date[count];
    count = c.count;
  }

  for (int i = 0; i < count; i++) {
    num[i] = c.num[i];
  }
  for (int i = 0; i < count; i++) {
    num[i].h_s[i] = c.num[i].h_s[i];
    num[i].h_e[i] = c.num[i].h_e[i];
    num[i].st = c.num[i].st;
    for (int j = 0; j < 3; j++)
      num[i].data[j] = c.num[i].data[j];
  }
  return *this;
}

void Pedometer::menu() {
  int w = 0;
  Date first_data;

  first_data.getdate();
  (*this).setdate(first_data);
  first_data.inpsetdate();

  infile(count);
  while (w != 8) {
    do {
      cout << "Меню управления вашим шагомером:" << endl;
      cout << "'1' Добавить подсчёт шагов." << endl;
      cout << "'2' Информация о добавленных подсчётах." << endl;
      cout << "'3' Найти среднее число шагов в выбранном месяце за всю историю наблюдений." << endl;
      cout << "'4' Найти максимальное число шагов в выбранном месяце за всю историю наблюдений." << endl;
      cout << "'5' Сохранить историю подсчётов в файл." << endl;
      cout << "'6' Считать из файла историю подсчётов." << endl;
      cout << "'7' Узнать информацию о первом подсчёте шагомера." << endl;
      cout << "'8' Завершить программу." << endl;
      cout << "Выбор: ";
      cin >> w;
      if (w < 1 || w>8) {
        cout << endl << "Вы ввели неправильный номер действия. Повторите:" << endl << endl;
      }
    } while (w < 1 || w>8);
    if (w == 1) {
      first_data.getdate();
      (*this).setdate(first_data);
      first_data.inpsetdate();
    }
    if (w == 2) {
      info(count);
    }
    if (w == 3) {
      srmonth(count);
    }
    if (w == 4) {
      maxmonth(count);
    }
    if (w == 5) {
      infile(count);
    }
    if (w == 6) {
      outfile();
    }
    if (w == 7) {
      onedate();
    }
    if (w == 8) {
      system("pause");
    }
  }
}

void Pedometer::onedate() {

  cout << endl << "Начальная дата первого подсчёта: ";
  if (num[0].data[0] < 10) {
    cout << "0" << num[0].data[0];
  }
  else {
    cout << num[0].data[0];
  }
  if (num[0].data[1] < 10) {
    cout << ":" << "0" << num[0].data[1];
  }
  else {
    cout << ":" << num[0].data[1];
  }
  cout << ":" << num[0].data[2] << endl;
  if (num[0].h_s[0] < 10) {
    cout << "Время начала|окончания движения: " << "0" << num[0].h_s[0];
  }
  else {
    cout << "Время начала|окончания движения: " << num[0].h_s[0];
  }
  if (num[0].h_s[1] < 10) {
    cout << ":" << "0" << num[0].h_s[1] << " | ";
  }
  else {
    cout << ":" << num[0].h_s[1] << " | ";
  }
  if (num[0].h_e[0] < 10) {
    cout << "0" << num[0].h_e[0] << ":";
  }
  else {
    cout << num[0].h_e[0] << ":";
  }
  if (num[0].h_e[1] < 10) {
    cout << "0" << num[0].h_e[1] << endl;
  }
  else {
    cout << num[0].h_e[1] << endl;
  }
  cout << "Шагов сделано за данный период: " << num[0].st;
}

void Pedometer::infile(int count) {
  ofstream in;
  in.open("Info.txt");
  for (int i = 0; i < count; i++) {
    if (count == 1) {
      in << endl <<"Начальная дата: ";
    }
    else {
      in << endl;
      in << "Дата: ";
    }
    if (num[i].data[0] < 10) {
      in << "0" << num[i].data[0];
    }
    else {
      in << num[i].data[0];
    }
    if (num[i].data[1] < 10) {
      in << ":" << "0" << num[i].data[1];
    }
    else {
      in << ":" << num[i].data[1];
    }
    in << ":" << num[i].data[2] << endl;
    if (num[i].h_s[0] < 10) {
      if (count == 1)
        in << "Начальное время начала|окончания движения: " << "0" << num[i].h_s[0];
      else in << "Время начала|окончания движения: " << "0" << num[i].h_s[0];
    }
    else {
      if (count == 1)
        in << "Начальное время начала|окончания движения: " << num[i].h_s[0];
      else in << "Время начала|окончания движения: " << num[i].h_s[0];
    }
    if (num[i].h_s[1] < 10) {
      in << ":" << "0" << num[i].h_s[1] << " | ";
    }
    else {
      in << ":" << num[i].h_s[1] << " | ";
    }
    if (num[i].h_e[0] < 10) {
      in << "0" << num[i].h_e[0] << ":";
    }
    else {
      in << num[i].h_e[0] << ":";
    }
    if (num[i].h_e[1] < 10) {
      in << "0" << num[i].h_e[1] << endl;
    }
    else {
      in << num[i].h_e[1] << endl;
    }
    in << "Шагов сделано за данный период: " << num[i].st << endl << endl;
  }
  in.close();
  if(count>1)
  cout << endl << "Подсчёт сохранен в файл" << endl << endl;
}

void Pedometer::outfile() {
  string str;
  ifstream out("Info.txt");
  if (!out.is_open()) {
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

int Pedometer::inpmonth(int count) {
  Date mon;
  do {
    cout << endl << "Введите месяц, по которому найдется среднее кол-во шагов за весь период времени данного месяца:" << endl;
    cout << "Месяц[1-12]: ";
    cin >> mon.data[1];
    if (mon.data[1] < 1 || mon.data[1] > 12) {
      cout << "Всего 12 календарных месяцев. Введите месяц от 1 до 12:" << endl;
    }
  } while (mon.data[1] < 1 || mon.data[1] > 12);
  cout << endl;
  return mon.data[1];
}

void Pedometer::srmonth(int count) {
  int k = 0;
  int res = 0;
  int f;
  int month = inpmonth(count);
  int *steep = new int;
  for (int i = 0; i < count; i++) {
    if (month == num[i].data[1]) {
      steep[k] = num[i].st;
      k++;
      f = i;
    }
  }
  if (count >= 2) {
    for (int i = 0; i < k; i++) {
      res = res + steep[i];
    }
    if (k > 1) {
      res = res / k;
      cout << "Среднее количество шагов: " << res << endl << endl;
    }
    else {
      for (int i = 0; i < count; i++) {
        if (month == num[i].data[1]) {
          cout << "Среднее количество шагов: " << num[i].st << endl << endl;
        }
        else {
          if (month != num[i].data[1] && i == count - 1) {
            cout << "Не найдено подсчётов в этом месяце." << endl << endl;
          }
        }
      }
    }
  }
  else {
    for (int i = 0; i < count; i++) {
      if (month == num[i].data[1]) {
        cout << "Среднее количество шагов: " << num[i].st << endl << endl;
      }
      else {
        if (month != num[i].data[1] && i == count - 1) {
          cout << "Не найдено подсчётов в этом месяце." << endl << endl;
        }
      }
    }
  }
}

void Pedometer::maxmonth(int count) {
  int *steep = new int;
  int k = 0;
  int f;
  int month = inpmonth(count);
  if (count >= 2) {
    for (int i = 0; i < count; i++) {
      if (month == num[i].data[1]) {
        steep[k] = num[i].st;
        k++;
        f = i;
      }
    }
    if (k > 1) {
      int max = steep[0];
      for (int i = 1; i < k; i++) {
        if (steep[i] > max) {
          max = steep[i];
        }
      }
      cout << "Максимальное количество шагов: " << max << endl << endl;
    }
    else {
      for (int i = 0; i < count; i++) {
        if (month == num[i].data[1]) {
          cout << "Максимальное количество шагов: " << num[i].st << endl << endl;
        }
        else {
          if (month != num[i].data[1] && i == count - 1) {
            cout << "-------------------------" << endl;
          }
        }
      }
    }
  }
  else {
    for (int i = 0; i < count; i++) {
      if (month == num[i].data[1]) {
        cout << "Максимальное количество шагов: " << num[i].st << endl << endl;
      }
      else {
        if (month != num[i].data[1] && i == count - 1) {
          cout << "Не найдено подсчётов в этом месяце." << endl << endl;
        }
      }
    }
  }
}

int Pedometer::inpinfoday(int count) {
  Date get;
  cout << "Введите дату, чтобы получить информацию о подсчётах. День,Месяц,Год:" << endl;
  do {
    cout << "День[1-31]: ";
    cin >> get.data[0];
    if (get.data[0] < 1 || get.data[0] > 31) {
      cout << "Всего 31 календарных дней. Введите день от 1 до 31:" << endl;
    }
  } while (get.data[0] < 1 || get.data[0] > 31);
  return get.data[0];
}

int Pedometer::inpinfomonth(int count) {
  Date get;
  do {
    cout << "Месяц[1-12]: ";
    cin >> get.data[1];
    if (get.data[1] < 1 || get.data[1] > 12) {
      cout << "Всего 12 календарных месяцев. Введите месяц от 1 до 12:" << endl;
    }
  } while (get.data[1] < 1 || get.data[1] > 12);
  return get.data[1];
}

int Pedometer::inpinfoyear(int count) {
  Date get;
  do {
    cout << "Год[Формат YYYY]: ";
    cin >> get.data[2];
    if (get.data[2] < 1000 || get.data[2] > 9999) {
      cout << "Введенный вами формат не соответствует с форматом длины YYYY, повторите:" << endl;
    }
  } while (get.data[2] < 1000 || get.data[2] > 9999);
  return get.data[2];
}

int Pedometer::inpinfoh_s0(int count) {
  Date get;
  cout << "Введите интервал времени активности. Час, минута (начала движения)" << endl;
  do {
    cout << "Час[0-23]: ";
    cin >> get.h_s[0];
    if (get.h_s[0] < 0 || get.h_s[0] > 23) {
      cout << "Введенное время(Час) не соответствует формату от 0 до 23, повторите:" << endl;
    }
  } while (get.h_s[0] < 0 || get.h_s[0] > 23);
  return get.h_s[0];
}

int Pedometer::inpinfoh_s1(int count) {
  Date get;
  do {
    cout << "Минута[0-59]: ";
    cin >> get.h_s[1];
    if (get.h_s[1] < 0 || get.h_s[1] > 59) {
      cout << "Введенное время(Минута) не соответствует формату от 0 до 59, повторите:" << endl;
    }
  } while (get.h_s[1] < 0 || get.h_s[1] > 59);
  return get.h_s[1];
}

int Pedometer::inpinfoh_e0(int count) {
  Date get;
  cout << "Введите интервал времени активности. Час, минута (окончания движения)" << endl;
  do {
    cout << "Час[0-23]: ";
    cin >> get.h_e[0];
    if (get.h_e[0] < 0 || get.h_e[0] > 23) {
      cout << "Введенное время(Час) не соответствует формату от 0 до 23, повторите:" << endl;
    }
  } while (get.h_e[0] < 0 || get.h_e[0] > 23);
  return get.h_e[0];
}

int Pedometer::inpinfoh_e1(int count) {
  Date get;
  do {
    cout << "Минута[0-59]: ";
    cin >> get.h_e[1];
    if (get.h_e[1] < 0 || get.h_e[1] > 59) {
      cout << "Введенное время(Минута) не соответствует формату от 0 до 59, повторите:" << endl;
    }
  } while (get.h_e[1] < 0 || get.h_e[1] > 59);
  return get.h_e[1];
}

void Pedometer::info(int count) {

  cout << endl;
  int *arr = new int[count];
  int day = inpinfoday(count);
  int month = inpinfomonth(count);
  int year = inpinfoyear(count);
  int hs0 = inpinfoh_s0(count);
  int hs1 = inpinfoh_s1(count);
  int he0 = inpinfoh_e0(count);
  int he1 = inpinfoh_e1(count);
  cout << endl;
  for (int i = 0, j = 1; i < count; i++) {
    if (day == num[i].data[0] && month == num[i].data[1] && year == num[i].data[2]) {
      if (hs0 <= num[i].h_s[0] && he0 >= num[i].h_e[0] && hs0 <= num[i].h_e[0] && he0 >= num[i].h_s[0] &&
        hs1 <= num[i].h_s[1] && he0 >= num[i].h_e[1] && hs1 <= num[i].h_e[1] && he1 >= num[i].h_s[1]) {
        cout << "Подсчёт №" << j << endl;
        if (num[i].h_s[0] < 10) {
          cout << "Время начала|окончания движения: " << "0" << num[i].h_s[0];
        }
        else {
          cout << "Время начала|окончания движения: " << num[i].h_s[0];
        }
        if (num[i].h_s[1] < 10) {
          cout << ":" << "0" << num[i].h_s[1] << " | ";
        }
        else {
          cout << ":" << num[i].h_s[1] << " | ";
        }
        if (num[i].h_e[0] < 10) {
          cout << "0" << num[i].h_e[0] << ":";
        }
        else {
          cout << num[i].h_e[0] << ":";
        }
        if (num[i].h_e[1] < 10) {
          cout << "0" << num[i].h_e[1] << endl;
        }
        else {
          cout << num[i].h_e[1] << endl;
        }
        cout << "Шагов сделано за данный период: " << num[i].st << endl << endl;
      }
      else {
        cout << endl << "Подсчётов не найдено." << endl;
      }
    }
  }
}

/*
ОТДЕЛЬНОЕ ВЫПЫТЫВАНИЕ У ПОЛЬЗОВАТЕЛЯ ДАННЫХ О ЕГО АКТИВНОСТИ
НЕ СРАЗУ В МАССИВ!!!!
*/

void Date::getdate() {
  cout << "Введите дату. День,Месяц,Год:" << endl;
  do {
    cout << "День[1-31]: ";
    cin >> data[0];
    if (data[0] < 1 || data[0] > 31) {
      cout << "Всего 31 календарных дней. Введите день от 1 до 31:" << endl;
    }
  } while (data[0] < 1 || data[0] > 31);
  do {
    cout << "Месяц[1-12]: ";
    cin >> data[1];
    if (data[1] < 1 || data[1] > 12) {
      cout << "Всего 12 календарных месяцев. Введите месяц от 1 до 12:" << endl;
    }
  } while (data[1] < 1 || data[1] > 12);
  do {
    cout << "Год[Формат YYYY]: ";
    cin >> data[2];
    if (data[2] < 1000 || data[2] > 9999) {
      cout << "Введенный вами формат не соответствует с форматом длины YYYY, повторите:" << endl;
    }
  } while (data[2] < 1000 || data[2] > 9999);

  cout << "Введите время активности. Час, минута (начала движения)" << endl;

  do {
    cout << "Час[0-23]: ";
    cin >> h_s[0];
    if (h_s[0] < 0 || h_s[0] > 23) {
      cout << "Введенное время(Час) не соответствует формату от 0 до 23, повторите:" << endl;
    }
  } while (h_s[0] < 0 || h_s[0] > 23);
  do {
    cout << "Минута[0-59]: ";
    cin >> h_s[1];
    if (h_s[1] < 0 || h_s[1] > 59) {
      cout << "Введенное время(Минута) не соответствует формату от 0 до 59, повторите:" << endl;
    }
  } while (h_s[1] < 0 || h_s[1] > 59);

  cout << "Введите время активности. Час, минута (окончания движения)" << endl;
  do {
    cout << "Час[0-23]: ";
    cin >> h_e[0];
    if (h_e[0] < 0 || h_e[0] > 23) {
      cout << "Введенное время(Час) не соответствует формату от 0 до 23, повторите:" << endl;
    }
  } while (h_e[0] < 0 || h_e[0] > 23);
  do {
    cout << "Минута[0-59]: ";
    cin >> h_e[1];
    if (h_e[1] < 0 || h_e[1] > 59) {
      cout << "Введенное время(Минута) не соответствует формату от 0 до 59, повторите:" << endl;
    }
  } while (h_e[1] < 0 || h_e[1] > 59);
  cout << "Введите количество пройденных шагов за указанный период времени:" << endl;
  do {
    cin >> st;
    if (st < 0) {
      cout << "Введенное вами количество шагов не может быть отрицательным, повторите:" << endl;
    }
  } while (st < 0);
  system("CLS");
}


/*

ОТДЕЛЬНЫЙ ВЫВОД НА ЭКРАН ОТЧЁТА О ВВЕДЁННЫХ ДАННЫХ, КОТОРЫЕ БУДУТ ДОБАВЛЕНЫ (НАВЕРНОЕ ИЗБЫТОЧНО, НО РАЗ ТЕБЕ ОЧЕНЬ НУЖНА ЭТА ФУНКЦИЯ - ПУСТЬ БУДЕТ)

*/

void Date::inpsetdate() {
  cout << "Введенные вами данные:" << endl;
  cout << "Дата: ";
  if (data[0] < 10) {
    cout << "0" << data[0];
  }
  else {
    cout << data[0];
  }
  if (data[1] < 10) {
    cout << ":" << "0" << data[1];
  }
  else {
    cout << ":" << data[1];
  }
  cout << ":" << data[2] << endl;
  if (h_s[0] < 10) {
    cout << "Время начала|окончания движения: " << "0" << h_s[0];
  }
  else {
    cout << "Время начала|окончания движения: " << h_s[0];
  }
  if (h_s[1] < 10) {
    cout << ":" << "0" << h_s[1] << " | ";
  }
  else {
    cout << ":" << h_s[1] << " | ";
  }
  if (h_e[0] < 10) {
    cout << "0" << h_e[0] << ":";
  }
  else {
    cout << h_e[0] << ":";
  }
  if (h_e[1] < 10) {
    cout << "0" << h_e[1] << endl;
  }
  else {
    cout << h_e[1] << endl;
  }
  cout << "Шагов сделано за данный период: " << st << endl << endl;
}

/*

ГЛАВНАЯ ФУНКЦИЯ ВСТАВЛЯЮЩАЯ ВЫПЫТАННЫЕ ДАННЫЕ В ТВОЙ МАССИВ ДАННЫХ

*/
void Pedometer::setdate(Date new_data) {
  Pedometer copy(*this);
  if (count != 0) {
    delete[] num;
  }
  num = new Date[count + 1];
  count = count + 1;
  for (int i = 0; i < count - 1; ++i) {
    num[i] = copy.num[i];
  }
  num[count - 1] = new_data;
}