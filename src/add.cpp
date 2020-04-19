#include "add.h"

void Pedometer::menu() {
  int w = 0, raz = 0;
  while (w != 7) {
    do {
      cout << "Меню управления вашим шагомером:" << endl;
      cout << "'1' Добавить подсчёт шагов." << endl;
      cout << "'2' Информация о добавленных подсчётах." << endl;
      cout << "'3' Найти среднее число шагов в выбранном месяце за всю историю наблюдений." << endl;
      cout << "'4' Найти максимальное число шагов в выбранном месяце за всю историю наблюдений." << endl;
      cout << "'5' Сохранить историю подсчётов в файл." << endl;
      cout << "'6' Считать из файла историю подсчётов." << endl;
      cout << "'7' Завершить программу." << endl;
      cout << "Выбор: ";
      cin >> w;
      if (w < 1 || w>7) {
        cout << endl << "Вы ввели неправильный номер действия. Повторите:" << endl << endl;
      }
    } while (w < 1 || w>7);
    if (w == 1) {
      num[count].setdate(num, count);
      count++;
      raz = 1;
    }
    if (raz == 1) {
      if (w == 2) {
        num[count].info(num, count);
      }
      if (w == 3) {
        num[count].srmonth(num, count);
      }
      if (w == 4) {
        num[count].maxmonth(num, count);
      }
      if (w == 5) {
        num[count].infile(num, count);
      }
      if (w == 6) {
        num[count].outfile(num, count);
      }
    }
    else {
      cout << "Сначала добавьте подсчёт. У вас их нет.." << endl;
    }
    if (w == 7) {
      system("pause");
    }
  }
}

void Date::infile(Date *num, int count) {
  ofstream in;
  in.open("Info.txt");
  for (int i = 0; i < count; i++) {
    in << "Дата: ";
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
      in << "Время начала|окончания движения: " << "0" << num[i].h_s[0];
    }
    else {
      in << "Время начала|окончания движения: " << num[i].h_s[0];
    }
    if (h_s[1] < 10) {
      in << ":" << "0" << num[i].h_s[1] << " | ";
    }
    else {
      in << ":" << num[i].h_s[1] << " | ";
    }
    if (h_e[0] < 10) {
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
}

void Date::outfile(Date *num, int count) {
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

void Date::srmonth(Date *num, int count) {
  Date mon;
  int k = 0;
  int res;
  int *steep = new int;
  do {
    cout << "Введите месяц, по которому найдется среднее кол-во шагов за весь период времени данного месяца:" << endl;
    cout << "Месяц[1-12]: ";
    cin >> mon.data[1];
    if (mon.data[1] < 1 || mon.data[1] > 12) {
      cout << "Всего 12 календарных месяцев. Введите месяц от 1 до 12:" << endl;
    }
  } while (mon.data[1] < 1 || mon.data[1] > 12);
  for (int i = 0; i < count; i++) {
    if (mon.data[1] == num[i].data[1]) {
      k++;
      steep[i] = num[i].st;
    }
  }
  if (count >= 2) {
    for (int i = 0; i < k - 1; i++) {
      res = steep[i] + steep[i + 1];
    }
    res = res / k;
    cout << "Среднее количество шагов: " << res << endl << endl;
  }
  else {
    if (mon.data[1] == num[0].data[1]) {
      cout << "Среднее количество шагов: " << num[0].st << endl;
    }
    else {
      cout << "Не найдено подсчётов в этом месяце." << endl;
    }
  }
}

void Date::maxmonth(Date *num, int count) {
  Date mon;
  int *steep = new int;
  int k = 0;
  if (count >= 2) {
    do {
      cout << "Введите месяц, по которому найдется среднее кол-во шагов за весь период времени данного месяца:" << endl;
      cout << "Месяц[1-12]: ";
      cin >> mon.data[1];
      if (mon.data[1] < 1 || mon.data[1] > 12) {
        cout << "Всего 12 календарных месяцев. Введите месяц от 1 до 12:" << endl;
      }
    } while (mon.data[1] < 1 || mon.data[1] > 12);
    for (int i = 0; i < count; i++) {
      if (mon.data[1] == num[i].data[1]) {
        k++;
        steep[i] = num[i].st;
      }
    }
    int max = steep[0];
    for (int i = 1; i < k; i++) {
      if (steep[i] > max) {
        max = steep[i];
      }
    }
    cout << "Максимальное количество шагов: " << max << endl;
  }
  else {
    if (mon.data[1] == num[0].data[1]) {
      cout << "Максимальное количество шагов: " << num[0].st << endl;
    }
    else {
      cout << "Не найдено подсчётов в этом месяце." << endl;
    }
  }
}

void Date::info(Date *num, int count) {
  Date get;
  cout << "Введите дату, чтобы получить информацию о подсчётах. День,Месяц,Год:" << endl;
  do {
    cout << "День[1-31]: ";
    cin >> get.data[0];
    if (get.data[0] < 1 || get.data[0] > 31) {
      cout << "Всего 31 календарных дней. Введите день от 1 до 31:" << endl;
    }
  } while (get.data[0] < 1 || get.data[0] > 31);
  do {
    cout << "Месяц[1-12]: ";
    cin >> get.data[1];
    if (get.data[1] < 1 || get.data[1] > 12) {
      cout << "Всего 12 календарных месяцев. Введите месяц от 1 до 12:" << endl;
    }
  } while (get.data[1] < 1 || get.data[1] > 12);
  do {
    cout << "Год[Формат YYYY]: ";
    cin >> get.data[2];
    if (get.data[2] < 1000 || get.data[2] > 9999) {
      cout << "Введенный вами формат не соответствует с форматом длины YYYY, повторите:" << endl;
    }
  } while (get.data[2] < 1000 || get.data[2] > 9999);
  cout << "Введите интервал времени активности. Час, минута (начала движения)" << endl;
  do {
    cout << "Час[0-23]: ";
    cin >> get.h_s[0];
    if (get.h_s[0] < 0 || get.h_s[0] > 23) {
      cout << "Введенное время(Час) не соответствует формату от 0 до 23, повторите:" << endl;
    }
  } while (get.h_s[0] < 0 || get.h_s[0] > 23);
  do {
    cout << "Минута[0-59]: ";
    cin >> get.h_s[1];
    if (get.h_s[1] < 0 || get.h_s[1] > 59) {
      cout << "Введенное время(Минута) не соответствует формату от 0 до 59, повторите:" << endl;
    }
  } while (get.h_s[1] < 0 || get.h_s[1] > 59);
  cout << "Введите интервал времени активности. Час, минута (окончания движения)" << endl;
  do {
    cout << "Час[0-23]: ";
    cin >> get.h_e[0];
    if (get.h_e[0] < 0 || get.h_e[0] > 23) {
      cout << "Введенное время(Час) не соответствует формату от 0 до 23, повторите:" << endl;
    }
  } while (get.h_e[0] < 0 || get.h_e[0] > 23);
  do {
    cout << "Минута[0-59]: ";
    cin >> get.h_e[1];
    if (get.h_e[1] < 0 || get.h_e[1] > 59) {
      cout << "Введенное время(Минута) не соответствует формату от 0 до 59, повторите:" << endl;
    }
  } while (get.h_e[1] < 0 || get.h_e[1] > 59);

  cout << endl;
  int *arr = new int[count];
  for (int i = 0, j = 1; i < count; i++) {
    if (get.data[0] == num[i].data[0] && get.data[1] == num[i].data[1] && get.data[2] == num[i].data[2]) {
      if (get.h_s[0] <= num[i].h_s[0] && get.h_e[0] >= num[i].h_e[0] && get.h_s[0] <= num[i].h_e[0] && get.h_e[0] >= num[i].h_s[0] &&
        get.h_s[1] <= num[i].h_s[1] && get.h_e[1] >= num[i].h_e[1] && get.h_s[1] <= num[i].h_e[1] && get.h_e[1] >= num[i].h_s[1]) {
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
        if (h_e[0] < 10) {
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

void Date::setdate(Date *num, int count) {
  cout << "Введите дату. День,Месяц,Год:" << endl;
  do {
    cout << "День[1-31]: ";
    cin >> num[count].data[0];
    if (num[count].data[0] < 1 || num[count].data[0] > 31) {
      cout << "Всего 31 календарных дней. Введите день от 1 до 31:" << endl;
    }
  } while (num[count].data[0] < 1 || num[count].data[0] > 31);
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