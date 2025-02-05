#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankCurrency.h"
#include "clsInputValid.h"

using namespace std;

class clsUpdateCurrencyRate : protected clsScreen
{
	static void _PrintCurrencyCard(clsBankCurrency Currency)
	{
		cout << "\nCurrency Card" << endl;
		cout << "\n------------------------" << endl;
		cout << "Country    : " << Currency.GetCountry() << endl;
		cout << "Code       : " << Currency.GetCurrencyCode() << endl;
		cout << "Name       : " << Currency.GetCurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.GetRate() << endl;
		cout << "\n------------------------" << endl;
	}

	static void _UpdateRateCurrency(clsBankCurrency Currency)
	{
		cout << "Update Currency Rate :" << endl;
		cout << "________________________" << endl;
		cout << "Enter New Rate : ";

		float NewRate = clsInputValid::ReadDoubleNumber("Invalid Number , Try again : ");

		Currency.SetRate(NewRate);

		cout << "Update Currency Rate done succesfully :)" << endl;
		_PrintCurrencyCard(Currency);

	}

public:

	static void ShowUpdateRateScreen()
	{

		_DrawScreenHeader("Update Rate Screen");

		string Code = clsInputValid::ReadString("Please enter Code Currency : ");
		clsBankCurrency Currency = clsBankCurrency::FindByCode(Code);


		while (!clsBankCurrency::IsCurrencyExistByCode(Code))
		{
			Code = clsInputValid::ReadString("This code NOT found, Please enter Code Currency : ");
			Currency = clsBankCurrency::FindByCode(Code);
		}

		cout << "Currency Found :)" << endl;
		_PrintCurrencyCard(Currency);


		char answer = 'n';
		cout << "Are you sure you want to update the rate of this Currency ? y/n ? ";
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			_UpdateRateCurrency(Currency);
		}

	}

};

