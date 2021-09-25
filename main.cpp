#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include "Account.h"
using namespace std;


int main()
{
    Account acc;
    acc.vvod();
    acc.ReplaceName();
    acc.WithDraw() << endl;
    acc.AddTheAmount() << endl;
    acc.ChargeInterest() << endl;
    cout << acc.ConvertToDollar() << endl;
    cout << acc.ConvertToEuro() << endl;
   
    system("Pause");
    return 0;
}