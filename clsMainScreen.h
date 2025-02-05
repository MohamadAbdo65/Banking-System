#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include "clsShowClientsList.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClientInfo.h"
#include "clsFindClient.h"
#include "clsTransactionScreen.h"
#include "clsShowManageUsers.h"
#include "clsCalculater.h"
#include "Global.h"
#include "clsShowLoginScreen.h"
#include "clsLoginRegisterList.h"
#include "clsCurrencyExchangeMenu.h"

using namespace std;

class clsMainScreen : protected clsScreen
{

	enum enMainMenuOption {ShowClientList =1, AddClient =2, DeleteClient =3, EditClient = 4 , FindClient = 5, Calculater = 6,
		Transaction = 7, ManageUser = 8, LoginRegister = 9, CurrencyExchange = 10 ,LogOut = 11};

	static void _ShowClientListScreen()
	{
		clsShowClientsList::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClient::AddClient();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClient::DeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientInfo::UpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClient::ShowFindClientScreen();
	}

	static void _ShowCalculaterScreen()
	{
		clsCalculater::ShowCalculator();
	}

	static void _ShowTransactionScreen()
	{
		clsTransactionScreen::ShowTransactionMenu();
	}

	static void _ShowManageUsersScreen()
	{
		clsShowManageUsers::ShowManageUsersScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterList::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchange()
	{
		clsCurrencyExchangeMenu::ShowCurrencyExchangeMenu();
	}

	static void _ShowLogoutScreen()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _BackToMainMenu()
	{
		clsUtil::Pause("\n\nPress any key to go back to Main Menue...");
		ShowMainMenu();
	}

	static void _PerformMainMenuOption(enMainMenuOption Option)
	{
		switch (Option)
		{
		case clsMainScreen::ShowClientList:
			system("cls");
			_ShowClientListScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::AddClient:
			system("cls");
			_ShowAddNewClientScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::DeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::EditClient:
			system("cls");
			_ShowUpdateClientScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::FindClient:
			system("cls");
			_ShowFindClientScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::Calculater:
			system("cls");
			_ShowCalculaterScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::Transaction:
			system("cls");
			_ShowTransactionScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::ManageUser:
			system("cls");
			_ShowManageUsersScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::LoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_BackToMainMenu();
			break;

		case clsMainScreen::CurrencyExchange:
			system("cls");
			_ShowCurrencyExchange();
			_BackToMainMenu();
			break;

		case clsMainScreen::LogOut:
			system("cls");
			_ShowLogoutScreen();
			break;

		default:
			system("cls");
			ShowMainMenu();
			break;
		}

		

	}

	static short _ReadMainMenueOption()
	{
		cout << setw(39) << left << "" << "Choose what do you want to do? [1 to 11]? ";
		short Choice = clsInputValid::GetNumberIntInRange("\t\tChoose what do you want to do? [1 to 11]? " ,1, 11);
		return Choice;
	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << setw(39) << left << "" << "==================================" << endl;
		cout << setw(39) << left << "" << "\t\tMain Menue Screen" << endl;
		cout << setw(39) << left << "" << "==================================" << endl;
		cout << setw(39) << left << "" << "\t[1]  To Show Client List." << endl;
		cout << setw(39) << left << "" << "\t[2]  Add New Client." << endl;
		cout << setw(39) << left << "" << "\t[3]  Delelte Client." << endl;
		cout << setw(39) << left << "" << "\t[4]  Edit Client Info." << endl;
		cout << setw(39) << left << "" << "\t[5]  Find a Client." << endl;
		cout << setw(39) << left << "" << "\t[6]  Calculater." << endl;
		cout << setw(39) << left << "" << "\t[7]  Transaction." << endl;
		cout << setw(39) << left << "" << "\t[8]  Manage Users." << endl;
		cout << setw(39) << left << "" << "\t[9]  Login Register Screen." << endl;
		cout << setw(39) << left << "" << "\t[10] Currency Exchange." << endl;
		cout << setw(39) << left << "" << "\t[11] Logout." << endl;
		cout << setw(39) << left << "" << "==================================" << endl;


		_PerformMainMenuOption((enMainMenuOption)_ReadMainMenueOption());
	}


};

