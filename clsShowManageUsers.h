#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include <iomanip>
#include "clsShowUsersList.h"
#include "clsAddNewUser.h"
#include "clsDeleteUser.h"
#include "clsUpdateUserInfo.h"
#include "clsFindUser.h"

using namespace std;

class clsShowManageUsers : protected clsScreen
{
	enum enManageUserOption {ListUser = 1, AddUser = 2, DeleteUser = 3, 
		UpdateUser = 4, FindUser = 5, MainMenu = 6};

	static void _ShowListUserScreen()
	{
		clsShowUsersList::ShowClientsList();
	}

	static void _ShowAddUserScreen()
	{
		clsAddNewUser::AddUser();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUser::DeleteClient();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserInfo::UpdateUser();
	}

	static void _FindUserScreen()
	{
		clsFindUser::ShowFindClientScreen();
	}

	static void _BackToManageMenu()
	{
		clsUtil::Pause("\n\nPress any key to go back to Main Menue...");
		ShowManageUsersScreen();
	}

	static void _PerformManageUsersScreen(enManageUserOption Option)
	{

		switch (Option)
		{
		case clsShowManageUsers::ListUser:
			system("cls");
			_ShowListUserScreen();
			_BackToManageMenu();
			break;


		case clsShowManageUsers::AddUser:
			system("cls");
			_ShowAddUserScreen();
			_BackToManageMenu();
			break;


		case clsShowManageUsers::DeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_BackToManageMenu();
			break;


		case clsShowManageUsers::UpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_BackToManageMenu();
			break;


		case clsShowManageUsers::FindUser:
			system("cls");
			_FindUserScreen();
			_BackToManageMenu();
			break;


		case clsShowManageUsers::MainMenu:
			break;
		}

	}

	static short _ReadManageUserMenueOption()
	{
		cout << setw(39) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValid::GetNumberIntInRange("\t\tChoose what do you want to do? [1 to 6]? ", 1, 8);
		return Choice;
	}

public:

	static void ShowManageUsersScreen()
	{
		if (!CheakAccesRight(clsUser::enAcces::ManageUserMenu))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("Manage User");

		cout << setw(39) << left << "" << "==================================" << endl;
		cout << setw(39) << left << "" << "\t\tManage User Screen" << endl;
		cout << setw(39) << left << "" << "==================================" << endl;
		cout << setw(39) << left << "" << "\t[1] Show Users List." << endl;
		cout << setw(39) << left << "" << "\t[2] Add New User." << endl;
		cout << setw(39) << left << "" << "\t[3] Delelte User." << endl;
		cout << setw(39) << left << "" << "\t[4] Edit User Info." << endl;
		cout << setw(39) << left << "" << "\t[5] Find a User." << endl;
		cout << setw(39) << left << "" << "\t[6] Main Menu Screen." << endl;
		cout << setw(39) << left << "" << "==================================" << endl;


		_PerformManageUsersScreen((enManageUserOption)_ReadManageUserMenueOption());

	}

};