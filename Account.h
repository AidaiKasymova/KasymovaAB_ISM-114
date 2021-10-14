#pragma once
#include <string>
#include <random>
#include <iostream>
using namespace std;

/// <summary>
/// Класс с представлением банковского счета
/// </summary>
class Account
{
private:
	/// <summary>
	/// Вспомогательная функция для закрытия текущего счета
	/// и открытия нового счета на то же имя (смена номера счета)
	/// </summary>
	void createNewAcc()
	{
		// Объявить объект класса генерации случ. чисел с равномерным распределением
		random_device rd;

		// Создать случайное беззнаковое число
		default_random_engine gen(rd());

		// Задать однородное распределение в указанном диапазоне (счет состоит из 8 цифр)
		uniform_int_distribution<long long unsigned> dist(10000000000000000, 99999999999999999);

		// Сгенерировать номер счета
		accNum = dist(gen);
	}

	/// <summary>
	/// Фамилия владельца
	/// </summary>
	string surname;

	/// <summary>
	/// Номер счета
	/// </summary>
	long long unsigned accNum;

	/// <summary>
	/// Процент начисления
	/// </summary>
	double percent;

	/// <summary>
	/// Сумма в рублях
	/// </summary>
	double amount;
public:
	/// <summary>
	/// Конструктор по умолчанию
	/// (осуществляет открытие нового счета)
	/// </summary>
	Account(const string& sr, const double perc, const double am);

	/// <summary>
	/// Сменить владельца счета
	/// </summary>
	/// <param name="sr"></param>
	void changeOwner(const string& sr);

	/// <summary>
	/// Снять некоторую сумму денег со счета
	/// </summary>
	void withDraw(const double am);

	/// <summary>
	/// Положить деньги на счет
	/// </summary>
	/// <param name="am"></param>
	void makeDeposit(const double am);

	/// <summary>
	/// Начислить проценты
	/// </summary>
	void chargeInterest();

	/// <summary>
	/// Перевести сумму в евро
	/// </summary>
	double convertToEUR();

	/// <summary>
	/// Перевести сумму в доллары
	/// </summary>
	double convertToUSD();

	/// <summary>
	/// Вывод информации о текущем счете
	/// </summary>
	string toString();
};