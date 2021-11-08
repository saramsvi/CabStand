
#include <iostream>
#include <ctime>
using namespace std;
//ОБЩИЕ ФУНКЦИИ
int unnumericInputProtection();//защита от некорректного ввода
int unnumericInputDay();//защита от некорректного ввода дня рождения
int unnumericInputMonth();//защита от некорректного ввода месяца рождения
int unnumericInputYear();//защита от некорректного ввода года рождения
string input_password();//Ввод строки с проверкой
struct Date
{
    int day;
    int month;
    int year;
};

