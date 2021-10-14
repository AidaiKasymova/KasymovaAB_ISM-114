#include "Account.h"
#include <sstream>

Account::Account(const string& sr, const double perc, const double am)
{
	// Сгенерировать новый счет
	createNewAcc();

	// Если переданная строка с фамилией пуста или состоит из пробельных символов, то выбросить исключение
	surname = sr.find_first_not_of(' ') == sr.npos || sr.empty() 
		? throw new invalid_argument("Ошибка! Строка с фамилией не может быть пустой.") : sr;

	percent = perc < 0 ? throw new invalid_argument("Ошибка! Процент не может быть отрицательным.") : perc;

	amount = am < 0 ? throw new invalid_argument("Ошибка! Сумма не может быть отрицательной.") : am;
}

void Account::changeOwner(const string& sr)
{
	createNewAcc();

	surname = sr.find_first_not_of(' ') == sr.npos || sr.empty()
		? throw new invalid_argument("Ошибка! Строка с фамилией не может быть пустой.") : sr;
}

void Account::withDraw(const double am)
{
	if (am < 0)
		throw new invalid_argument( "Некорректная сумма к снятию!");
	else if (amount < am)
		throw new invalid_argument("Сумма к снятию превышает остаток на счете!");
	else
		amount -= am;
}

void Account::makeDeposit(const double am)
{
	if (am < 0)
		throw new invalid_argument("Некорректная сумма к пополнению!");
	else
		amount += am;
}

void Account::chargeInterest()
{
	double interest = amount * percent / 100.0;
	amount += interest;
}

double Account::convertToEUR()
{
	const double roubleEur = 83.12;
	return amount / roubleEur;
}

double Account::convertToUSD()
{
	const double roubleUSD = 71.75;
	return amount / roubleUSD;
}

string Account::toString()
{
	stringstream s;
	s << "Текущий счет: " << amount << " рублей" << endl;
	s << "В евро: " << convertToEUR() << " €" << endl;
	s << "В долларах: " << convertToUSD() << " $" << endl;
	s << "Номер: " << accNum << endl;
	s << "Фамилия владельца: " << surname << endl;
	s << percent << "% начисляется ежегодно." << endl;
	return s.str();
}
