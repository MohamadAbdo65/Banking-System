#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankCurrency.h"
#include "clsInputValid.h"

using namespace std;

class clsFindCurrency : protected clsScreen
{
	enum enFindBy {ByCode = 1, ByCountry = 2, Exit = 3};

	static void _PrintCurrencyCard(clsBankCurrency Currency)
	{
		cout << "\nCurrency Card" << endl;
		cout << "\n------------------------" << endl;
		cout << "Country  : " << Currency.GetCountry() << endl;
		cout << "Code     : " << Currency.GetCurrencyCode() << endl;
		cout << "Name     : " << Currency.GetCurrencyName() << endl;
		cout << "Rate(1$) : " << Currency.GetRate() << endl;
		cout << "\n------------------------" << endl;
	}

	static void _FindBYCode()
	{
		string Code = clsInputValid::ReadString("Please enter Code Currency : ");
		clsBankCurrency Currency = clsBankCurrency::FindByCode(Code);


		while (!clsBankCurrency::IsCurrencyExistByCode(Code))
		{
			Code = clsInputValid::ReadString("This code NOT found, Please enter Code Currency : ");
			Currency = clsBankCurrency::FindByCode(Code);
		}

		cout << "Currency Found :)" << endl;

		_PrintCurrencyCard(Currency);
	}

	static void _FindBYCountry()
	{
		string Country = clsInputValid::ReadString("Please enter County Name : ");
		clsBankCurrency Currency = clsBankCurrency::FindByCountry(Country);


		while (!clsBankCurrency::IsCurrencyExistByCountry(Country))
		{
			Country = clsInputValid::ReadString("This Country NOT found, Please enter County Name : ");
			Currency = clsBankCurrency::FindByCountry(Country);
		}

		cout << "\nCurrency Found :)" << endl;

		_PrintCurrencyCard(Currency);

	}


public:

	static void ShowFindCurrencyScreen()
	{
		system("cls");

		_DrawScreenHeader("Find Currency");

		cout << "Find by : [1] Code or [2] Country ? for Exit [3]. ";
		short choose = clsInputValid::GetNumberIntInRange("Invalid Number, Try again : ", 1, 3);


		switch ((enFindBy)choose)
		{
		case enFindBy::ByCode:
			_FindBYCode();
			break;

		case enFindBy::ByCountry:
			_FindBYCountry();
			break;

		case enFindBy::Exit:
			break;

		default:
			break;
		}
	}
};

