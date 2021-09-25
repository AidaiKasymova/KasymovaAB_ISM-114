#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Account
{
private: {                                             //Закрытые объекты
    string name;
    int accNum;
    double percent;
    double sum;

public:                                                //Открытые методы     
    Account() { accNum = 0; percent = 0; sum = 0 };    //Конструктор
    void vvod();
    void ReplaceName();
    double WithDraw();
    double AddTheAmount();
    double ChargeInterest();
    double ConvertToDollar();
    double ConvertToEuro();

};

       void Account::vvod() 
       {
           cout << "Enter the last name of the owner" << endl;
           cin >> name;
           cout << "Enter the account number" << endl;
           cin >> accNum;
           cout << "Enter the account interest" << endl;
           cin >> percent;
           cout << "Enter the amount in rubles" << endl;
           cin >> sum;
       };

       void Account::ReplaceName() {
           cout << "Enter a new last name" << endl;
           cin >> name;
       }

       double Account::WithDraw() {
           int theSum;
           cout << "Enter the withdrawal amount" << endl;
           cin >> theSum;
           if (theSum > sum)
               cout << "Mistake" << endl;
           else
               sum -= theSum;
           cout << "Ostatok = " << sum << endl;
       }

       double Account::AddTheAmount() {
           int theSum;
           cout << "Enter the amount to be credited" << endl;
           cin >> theSum;
           sum += theSum;
           cout << "Summa na vklade = " << sum << endl;
       }

       double Account::ChargeInterest() {
           sum = sum + ((sum * percent) / 100.0);
           cout << "Amount with interest = " << sum;
       }

       double Account::ConvertToDollar() {
           return (int dollar = sum / 73.0);
       }

       double Account::ConvertToEuro() {
           return (int euro = sum / 85.0);
       }
}