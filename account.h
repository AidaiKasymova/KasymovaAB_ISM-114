#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

/**
 * @brief ����� ��� ������ � ���������� ������
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
 * @brief ����������
 *
 */
    Account() { accNum = 0, percent = 0, sum = 0; }

    /**
 * @brief ����� ����� ������
 *
 */
    void input();

    /**
 * @brief ����� ��� ����� �������
 *
 */
    void ReplaceName();

    /**
     * @brief ����� ��� ������ ����� � �����
     *
     * @return double ���������� �������������� ��� ������
     */
    double WithDraw();

    /**
     * @brief ����� ��� �������� ����� �� ����
     *
     * @return double ���������� �������������� ��� ������
     */
    double AddTheAmount();

    /**
     * @brief ����� �� ���������� ��������� �� ����
     *
     * @return double ���������� �������������� ��� ������
     */
    double ChargeInterest();

    /**
     * @brief ����� �������� ����� � �������
     *
     * @return double ������������ �������������� ��� ������
     */
    double ConvertToDollar();

    /**
     * @brief ����� ��� �������� ����� � ����
     *
     * @return double ���������� �������������� ��� ������
     */
    double ConvertToEuro();

};


/** �������� ������ ����� ������
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
 * @brief ����������� ����� ����� ������� ���������
 *
 */
void Account::ReplaceName() {
    cout << "Enter a new last name" << endl;
    cin >> name;
}


/**
 * @brief ����������� ����� ������ ����� � ����� � ��������� �������
 *
 * @return double ������������ ��� ������
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
 * @brief ����������� ����� �������� ����� �� ����
 *
 * @return double ������������ ��� ������
 */
double Account::AddTheAmount() {
    int theSum;
    cout << "Enter the amount to be credited" << endl;
    cin >> theSum;
    return sum += theSum;
}

/**
   * @brief ����� ���������� ���������
   *
   * @return double ������������ ��� ������
   */
double Account::ChargeInterest() {
    return sum + ((sum * percent) / 100.0);
}

/**
 * @brief ����� �������� ����� � �������
 *
 * @return double ������������ ��� ������
 */
double Account::ConvertToDollar() {
    double dollar;
    return (dollar = sum / 73.0);
}

/**
 * @brief ����� �������� ����� � ����
 *
 * @return double ������������ ��� ������
 */
double Account::ConvertToEuro() {
    double euro;
    return (euro = sum / 85.0);
}