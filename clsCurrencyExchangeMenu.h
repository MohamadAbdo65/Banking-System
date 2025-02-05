#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include "clsShowCurrencyList.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculator.h"

using namespace std;

class clsCurrencyExchangeMenu : protected clsScreen
{
	enum enOption {ListCurrency = 1, FindCurrency = 2, UpdateCurrency = 3, 
		CurrencyCalculater = 4, MainMenu = 5};

	static void _ShowListCurrencies()
	{
		clsShowCurrencyList::ShowCurrencyList();
	}

	static void _ShowFindCurrency()
	{
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRate()
	{
		clsUpdateCurrencyRate::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculater()
	{
		clsCurrencyCalculator::ShowCurrencyCalculateScreen();
	}

    static void _BackToCurrencyExchangeMenu()
	{
		clsUtil::Pause("\n\nPress any key to go back to Currency Exchange Menu...");
		ShowCurrencyExchangeMenu();
	}

	static void _PerformOptionCurrencyMenu(enOption option)
	{

		switch (option)
		{
		case clsCurrencyExchangeMenu::ListCurrency:
			system("cls");
			_ShowListCurrencies();
			_BackToCurrencyExchangeMenu();
			break;

		case clsCurrencyExchangeMenu::FindCurrency:
			system("cls");
			_ShowFindCurrency();
			_BackToCurrencyExchangeMenu();
			break;

		case clsCurrencyExchangeMenu::UpdateCurrency:
			system("cls");
			_ShowUpdateRate();
			_BackToCurrencyExchangeMenu();
			break;

		case clsCurrencyExchangeMenu::CurrencyCalculater:
			system("cls");
			_ShowCurrencyCalculater();
			_BackToCurrencyExchangeMenu();
			break;

		case clsCurrencyExchangeMenu::MainMenu:
			break;

		default:
			break;
		}

	}

	static short _ReadCurrencyExchangeMenuOption()
	{
		cout << setw(39) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValid::GetNumberIntInRange("\t\tChoose what do you want to do? [1 to 5]? ", 1, 5);
		return Choice;
	}


public:

	static void ShowCurrencyExchangeMenu()
	{
		system("cls");

		_DrawScreenHeader("Currency Exchange Screen");

		cout << setw(39) << left << "" << "=====================================" << endl;
		cout << setw(39) << left << "" << "\t\tCurrency Exchange Screen" << endl;
		cout << setw(39) << left << "" << "=====================================" << endl;
		cout << setw(39) << left << "" << "\t[1] List Currencies." << endl;
		cout << setw(39) << left << "" << "\t[2] Find Currency." << endl;
		cout << setw(39) << left << "" << "\t[3] Update Rate." << endl;
		cout << setw(39) << left << "" << "\t[4] Currency Calculater." << endl;
		cout << setw(39) << left << "" << "\t[5] Main menu." << endl;
		cout << setw(39) << left << "" << "=====================================" << endl;

		_PerformOptionCurrencyMenu((enOption)_ReadCurrencyExchangeMenuOption());

	}

};

