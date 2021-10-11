#include "Account.h"

int main()
{
	system("chcp 1251");
	system("cls");

	Account acc = Account("Иванова", 6.1, 150000);
	acc.toString();

	cout << endl << "Сменим владельца счета на \"Петрова\"." << endl;
	acc.changeOwner("Петрова");

	cout << endl << "Начислим проценты." << endl;
	acc.chargeInterest();

	cout << endl << "Снимем 15000 рублей со счета." << endl;
	acc.withDraw(15000);

	cout << endl << "Положим 12354 на счет." << endl;
	acc.makeDeposit(12354);

	cout << endl;
	acc.toString();
	cout << endl;

	system("pause");

	return 0;
}