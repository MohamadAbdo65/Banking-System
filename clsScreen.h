#pragma once
#include <iostream>
#include "clsDate.h"
#include <iomanip>
#include "clsBankUser.h"
#include "Global.h"
#include "clsColorText.h"

using namespace std;

class clsScreen
{	
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		clsColors::SetTextColorForBrightYellow();
		cout << setw(35) << left << "" << "------------------------------------------" << endl;

		cout << endl;

		cout << setw(48) << left << "" << Title << endl;

		if (SubTitle != "")
			cout << setw(48) << left << "" << SubTitle << endl;


		cout << setw(35) << left << "" << "------------------------------------------" << endl;
		
		cout << endl;
		cout << setw(40) << left << "" << "User : " << CurrentUser.GetUsername() << endl;
		cout << setw(40) << left << "" << "Date : " << clsDate::DateToString(clsDate::GetSystemDate()) << endl;

		clsColors::SetTextColorForDefualte();
		cout << "\n";
	}

	static bool CheakAccesRight(clsUser::enAcces ScreenAcces)
	{
		if (!CurrentUser.CheakIsHaveAcces(ScreenAcces))
		{
			clsColors::SetTextColorForRed();

			cout << setw(33) << left << "" << "-----------------------------------------------------------" << endl;

			cout << endl;

			cout << setw(35) << left << "" << "You cannot access this page, contact the administrator" << endl;

			cout << endl;

			cout << setw(33) << left << "" << "-----------------------------------------------------------" << endl;

			cout << endl;
			cout << setw(40) << left << "" << "User : " << CurrentUser.GetUsername() << endl;
			cout << setw(40) << left << "" << "Date : " << clsDate::DateToString(clsDate::GetSystemDate()) << endl;

			clsColors::SetTextColorForDefualte();

			return false;
		}
		else
		{
			return true;
		}
	}

};