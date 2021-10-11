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
	Account(const string& sr, const double perc, const double am)
	{
		// Объявить объект класса генерации случ. чисел с равномерным распределением
		random_device rd;

		// Создать случайное беззнаковое число
		default_random_engine gen(rd());

		// Задать однородное распределение в указанном диапазоне (счет состоит из 8 цифр)
		uniform_int_distribution<long long unsigned> dist(10000000000000000, 99999999999999999);

		// Сгенерировать номер счета
		accNum = dist(gen);

		// Если переданная строка с фамилией пуста или состоит из пробельных символов, то фамилия - "unknown"
		surname = sr.find_first_not_of(' ') == sr.npos || sr.empty() ? "unknown" : sr;

		percent = perc < 0 ? 0 : perc;

		amount = am < 0 ? 0.0 : am;
	}

	/// <summary>
	/// Сменить владельца счета
	/// </summary>
	/// <param name="sr"></param>
	void changeOwner(const string& sr)
	{
		surname = sr.find_first_not_of(' ') == sr.npos || sr.empty() ? "unknown" : sr;
	}

	/// <summary>
	/// Снять некоторую сумму денег со счета
	/// </summary>
	void withDraw(const double am)
	{
		cout << "Текущий счет: " << amount <<
			" рублей; сумма к снятию: " << am << " рублей" << endl;
		if (am < 0)
			cerr << "Некорректная сумма к снятию!" << endl;
		else if (amount < am)
			cerr << "Сумма к снятию превышает остаток на счете!" << endl;
		else
		{
			amount -= am;
			cout << "Снятие произведено!" << endl;
			cout << "Остаток: " << amount << " рублей" << endl;
		}
	}

	/// <summary>
	/// Положить деньги на счет
	/// </summary>
	/// <param name="am"></param>
	void makeDeposit(const double am)
	{
		cout << "Текущий счет: " << amount << 
			" рублей; сумма к пополнению: " << am << " рублей" << endl;
		if (am < 0)
			cerr << "Некорректная сумма к пополнению!" << endl;
		else
		{
			amount += am;
			cout << "Пополнение произведено!" << endl;
			cout << "Остаток: " << amount << " рублей" << endl;
		}
	}

	/// <summary>
	/// Начислить проценты
	/// </summary>
	void chargeInterest()
	{
		double interest = amount * percent / 100.0;
		amount += interest;
		cout << "Проценты начислены!" << endl;
		cout << "Остаток: " << amount << " рублей" << endl;
	}

	/// <summary>
	/// Перевести сумму в евро
	/// </summary>
	void convertToEUR()
	{
		double eurAmount = amount / 83.12;
		cout << "В евро: " << eurAmount << " €" << endl;
	}

	/// <summary>
	/// Перевести сумму в доллары
	/// </summary>
	void convertToUSD()
	{
		double usdAmount = amount / 71.75;
		cout << "В долларах: " << usdAmount << " $" << endl;
	}

	/// <summary>
	/// Вывод информации о текущем счете
	/// </summary>
	void toString()
	{
		cout << "Текущий счет: " << amount << " рублей" << endl;
		convertToEUR(); convertToUSD();
		cout << "Номер: " << accNum << endl;
		cout << "Фамилия владельца: " << surname << endl;
		cout << percent << "% начисляется ежегодно." << endl;
	}
};