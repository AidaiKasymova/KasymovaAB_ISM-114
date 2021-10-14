#include "Account.h"
#include <sstream>

Account::Account(const string& sr, const double perc, const double am)
{
	// ������������� ����� ����
	createNewAcc();

	// ���� ���������� ������ � �������� ����� ��� ������� �� ���������� ��������, �� ��������� ����������
	surname = sr.find_first_not_of(' ') == sr.npos || sr.empty() 
		? throw new invalid_argument("������! ������ � �������� �� ����� ���� ������.") : sr;

	percent = perc < 0 ? throw new invalid_argument("������! ������� �� ����� ���� �������������.") : perc;

	amount = am < 0 ? throw new invalid_argument("������! ����� �� ����� ���� �������������.") : am;
}

void Account::changeOwner(const string& sr)
{
	createNewAcc();

	surname = sr.find_first_not_of(' ') == sr.npos || sr.empty()
		? throw new invalid_argument("������! ������ � �������� �� ����� ���� ������.") : sr;
}

void Account::withDraw(const double am)
{
	if (am < 0)
		throw new invalid_argument( "������������ ����� � ������!");
	else if (amount < am)
		throw new invalid_argument("����� � ������ ��������� ������� �� �����!");
	else
		amount -= am;
}

void Account::makeDeposit(const double am)
{
	if (am < 0)
		throw new invalid_argument("������������ ����� � ����������!");
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
	s << "������� ����: " << amount << " ������" << endl;
	s << "� ����: " << convertToEUR() << " �" << endl;
	s << "� ��������: " << convertToUSD() << " $" << endl;
	s << "�����: " << accNum << endl;
	s << "������� ���������: " << surname << endl;
	s << percent << "% ����������� ��������." << endl;
	return s.str();
}