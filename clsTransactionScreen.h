#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUtil.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsShowTotalBalances.h"
#include "clsShowTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionScreen : protected clsScreen
{
	enum enTransactionMenuOption {Deposite = 1, Withdraw = 2, 
		TotalBalances = 3, TransferScreen = 4, TransferLog = 5, GoBackToMainScreen = 6};

	static void _ShowDepositeScreen()
	{
		clsDepositeScreen::ShowDepositeScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsShowTotalBalances::ShowClientsList();
	}

	static void _ShowTransferScreen()
	{
		clsShowTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _BackToTransactionMenu()
	{
		clsUtil::Pause("\n\nPress any key to go back to Transaction Menue...");
		ShowTransactionMenu();
	}

	static void _PerformTransactionMenuOption(enTransactionMenuOption option)
	{

		switch (option)
		{
		case clsTransactionScreen::Deposite:
			system("cls");
			_ShowDepositeScreen();
			_BackToTransactionMenu();
			break;

		case clsTransactionScreen::Withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_BackToTransactionMenu();
			break;

		case clsTransactionScreen::TotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_BackToTransactionMenu();
			break;

		case clsTransactionScreen::TransferScreen:
			system("cls");
			_ShowTransferScreen();
			_BackToTransactionMenu();
			break;

		case clsTransactionScreen::TransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_BackToTransactionMenu();
			break;

		case clsTransactionScreen::GoBackToMainScreen:

			break;
		};

	}

	static short _ReadTransactionMenueOption()
	{
		cout << setw(39) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValid::GetNumberIntInRange("\t\tChoose what do you want to do? [1 to 6]? ", 1, 6);
		return Choice;
	}

public:


	static void ShowTransactionMenu()
	{
		if (!CheakAccesRight(clsUser::enAcces::TransactionMenu))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("Transaction Screen");

		cout << setw(39) << left << "" << "=====================================" << endl;
		cout << setw(39) << left << "" << "\t\tTransaction Menue Screen" << endl;
		cout << setw(39) << left << "" << "=====================================" << endl;
		cout << setw(39) << left << "" << "\t[1] Deposite." << endl;
		cout << setw(39) << left << "" << "\t[2] Withdraw." << endl;
		cout << setw(39) << left << "" << "\t[3] Total balances." << endl;
		cout << setw(39) << left << "" << "\t[4] Transfer." << endl;
		cout << setw(39) << left << "" << "\t[5] Transfer Log." << endl;
		cout << setw(39) << left << "" << "\t[6] Back to Main menu." << endl;
		cout << setw(39) << left << "" << "=====================================" << endl;


		_PerformTransactionMenuOption((enTransactionMenuOption)_ReadTransactionMenueOption());
	}


};

