#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsBankUser.h"
#include "clsInputValid.h"
#include "clsDate.h"
#include <thread>
#include <fstream>

using namespace std;

class clsShowLoginScreen : protected clsScreen
{

	static bool _Login()
	{
		bool FaildLogin = false;
		string Username, Password;
		short attempt = 3;


		do

		{

			if (FaildLogin)
			{
				cout << "\nInvalid Username/Password ! , Try again : " << endl;
				attempt--;
				cout << "You Have " << attempt << " trials to login.\n" << endl;

				if (attempt == 0)
				{
					cout << "You are Locked after 3 faild trails." << endl;
					return false;
				}
			}


			Username = clsInputValid::ReadString("Enter Username ? ");

			Password = clsInputValid::ReadString("Enter Password ? ");

			CurrentUser = clsUser::Find(Username, Password);

			FaildLogin = CurrentUser.IsEmpty();

		} while (FaildLogin);

		cout << "\nSuccessful login :), Please Wait . . . \n";

		CurrentUser.SaveRegisterTime();

		this_thread::sleep_for(chrono::seconds(1));

		clsMainScreen::ShowMainMenu();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Welcome Back :)", "Login Screen");
		return _Login();

	}



};

