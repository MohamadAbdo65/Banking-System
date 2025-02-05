#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankCurrency.h"

using namespace std;

class clsShowCurrencyList : protected clsScreen
{
    static void _PrintLineCurrency(clsBankCurrency Currency)
    {
        cout << setw(12) << left << "";
        cout << "|" << setw(26) << left << Currency.GetCountry();
        cout << "|" << setw(5) << left << Currency.GetCurrencyCode();
        cout << "|" << setw(30) << left << Currency.GetCurrencyName();
        cout << "|" << setw(10) << left << Currency.GetRate();
    }

public :

	static void ShowCurrencyList()
	{
		vector <clsBankCurrency> vCurrencyData = clsBankCurrency::GetCurrenciesList();

		_DrawScreenHeader("Currency List", "(" + to_string(vCurrencyData.size()) + ") Currency");

        cout << setw(12) << left << "" << "==================================================================================================\n";
        cout << setw(12) << left << "";
        cout << "|" << setw(26) << left << "Country";
        cout << "|" << setw(5) << left << "Code";
        cout << "|" << setw(30) << left << "Name";
        cout << "|" << setw(10) << left << "Rate/(1$)";
        cout << endl;
        cout << setw(12) << left << "" << "==================================================================================================\n\n";


        if (vCurrencyData.size() == 0)
        {
            cout << "\t\t\t  No Clients Available In the System!";
        }
        else
        {
            for(clsBankCurrency& C : vCurrencyData)
            {
                _PrintLineCurrency(C);
                cout << endl;
            }
        }
        cout << setw(12) << left << "";
        cout << "===================================================================================================\n";

	}

};

