#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankCurrency.h"
#include "clsInputValid.h"
#include "clsString.h"

using namespace std;

class clsCurrencyCalculator : protected clsScreen
{

	static void _PrintCurrencyCard(clsBankCurrency Currency)
	{
		cout << "\n------------------------" << endl;
		cout << "Country    : " << Currency.GetCountry() << endl;
		cout << "Code       : " << Currency.GetCurrencyCode() << endl;
		cout << "Name       : " << Currency.GetCurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.GetRate() << endl;
		cout << "\n------------------------" << endl;
	}

	static string _GetExistCode(short NumberOfCunrrency)
	{
		string Code = clsInputValid::ReadString("\nPlease Enter Currency" + to_string(NumberOfCunrrency) + " code :\n");

		while (!clsBankCurrency::IsCurrencyExistByCode(Code))
		{
			Code = clsInputValid::ReadString("Code is not found, Please Enter Currency" + to_string(NumberOfCunrrency) + " code :\n");
		}

		return Code;
	}

	static float _GetAmountOfExchange()
	{
		float amount = 0;
		cout << "\nEnter amount of Exchange : ";
		amount = (float)clsInputValid::ReadDoubleNumber("Invalid Amount !, Try again : ");

		while (amount <= 0)
		{
			cout << "\nInvalid Number, Enter amount of Exchange : ";
			amount = (float)clsInputValid::ReadDoubleNumber("Invalid Amount !, Try again : ");
		}

		return amount;
	}

public:

	static void ShowCurrencyCalculateScreen()
	{
		system("cls");

		_DrawScreenHeader("Currency Calculater");

		string Code1 = _GetExistCode(1);
		string Code2 = _GetExistCode(2);

		clsBankCurrency Currency1 = clsBankCurrency::FindByCode(Code1);
		clsBankCurrency Currency2 = clsBankCurrency::FindByCode(Code2);

		float amount = _GetAmountOfExchange();
		float AmountUSD = Currency1.ConvertAmountToDollar(amount);
		float AmountNew = Currency1.ConvertDollarToAnyCurrency(amount, Currency2);


		if (!(clsString::UpperAllString(Code1) == "USD"))
		{
			cout << "\nConvert From : " << endl;
			_PrintCurrencyCard(Currency1);

			cout << "\n=> " << amount << " " << Code1 << " = " << AmountUSD << " USD" << endl;
		}


		if (!(clsString::UpperAllString(Code2) == "USD"))
		{
			cout << "\nConvert To : " << endl;
			_PrintCurrencyCard(Currency2);

			cout << "\n=> " << amount << " " << Code1 << " = " << AmountNew << " " << Code2 << endl;
		}


		char Answer = 'n';
		cout << "\nDo you want to perform another calculation ? y/n ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			ShowCurrencyCalculateScreen();
		}

	}
};

