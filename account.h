#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

/**
 * @brief класс для работы с банковским счетом
 *
 */
class Account
{
private: 
    string name;
    int accNum;
    double percent;
    double sum;

public:

    /**
 * @brief констуктор
 *
 */
    Account() { accNum = 0, percent = 0, sum = 0; }

    /**
 * @brief метод ввода данных
 *
 */
    void input();

    /**
 * @brief метод для смены фамилии
 *
 */
    void ReplaceName();

    /**
     * @brief метод для снятия суммы с счета
     *
     * @return double возвращает действительный тип данных
     */
    double WithDraw();

    /**
     * @brief метод для внесения суммы на счет
     *
     * @return double возвращает действительный тип данных
     */
    double AddTheAmount();

    /**
     * @brief метод дл начисления процентов на счет
     *
     * @return double возвращает действительный тип данных
     */
    double ChargeInterest();

    /**
     * @brief метод перевода суммы в доллары
     *
     * @return double возвращается действительный тип данных
     */
    double ConvertToDollar();

    /**
     * @brief метод для перевода суммы в евро
     *
     * @return double возвращает действительный тип данных
     */
    double ConvertToEuro();

};


/** Описание метода ввода данных
 *
 */
void Account::input() {

    cout << "Enter the last name of the owner" << endl;
    cin >> name;
    cout << "Enter the account number" << endl;
    cin >> accNum;
    cout << "Enter the account interest" << endl;
    cin >> percent;
    cout << "Enter the amount in rubles" << endl;
    cin >> sum;
};

/**
 * @brief расписываем метод смены фамилии владельца
 *
 */
void Account::ReplaceName() {
    cout << "Enter a new last name" << endl;
    cin >> name;
}


/**
 * @brief расписываем метод снятия суммы с счета с проверкой условий
 *
 * @return double вещественный тип данных
 */
double Account::WithDraw() {
    int theSum;
    cout << "Enter the withdrawal amount" << endl;
    cin >> theSum;
    if (theSum > sum)
        cout << "Mistake" << endl;
    else {
        return sum -= theSum;
        cout << "Remains = " << sum << endl;
    }
}

/**
 * @brief расписываем метод внесения денег на счет
 *
 * @return double вещественный тип данных
 */
double Account::AddTheAmount() {
    int theSum;
    cout << "Enter the amount to be credited" << endl;
    cin >> theSum;
    return sum += theSum;
}

/**
   * @brief метод начисления процентов
   *
   * @return double вещественный тип данных
   */
double Account::ChargeInterest() {
    return sum + ((sum * percent) / 100.0);
}

/**
 * @brief метод перевода суммы в доллары
 *
 * @return double вещественный тип данных
 */
double Account::ConvertToDollar() {
    double dollar;
    return (dollar = sum / 73.0);
}

/**
 * @brief метод перевода суммы в евро
 *
 * @return double вещественный тип данный
 */
double Account::ConvertToEuro() {
    double euro;
    return (euro = sum / 85.0);
}