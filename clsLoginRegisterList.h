#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"

class clsLoginRegisterList : protected clsScreen
{

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord Record)
    {
        cout << setw(12) << left << "";
        cout << "|" << setw(25) << left << Record.DateTime;
        cout << "|" << setw(17) << left << Record.UserName;
        cout << "|" << setw(17) << left << Record.Password;
        cout << "|" << setw(17) << left << Record.Permissions; 
    }

public:

	static void ShowLoginRegisterScreen()
	{

        if (!CheakAccesRight(clsUser::enAcces::LoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> LogData = clsUser::GetLoginRegisterList();

        string Title = "Login Register List Screen";
        string SubTitle = "(" + to_string(LogData.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(12) << left << "" << "==================================================================================================\n";
        cout << setw(12) << left << "";
        cout << "|" << setw(25) << left << "Date/Time";
        cout << "|" << setw(17) << left << "Username";
        cout << "|" << setw(17) << left << "Password";
        cout << "|" << setw(17) << left << "Acces";
        cout << endl;
        cout << setw(12) << left << "" << "==================================================================================================\n\n";


        if (LogData.size() == 0)
        {
            cout << "\t\t\t  No Record Available In the System!";
        }
        else
        {
            for (clsUser::stLoginRegisterRecord& L : LogData)
            {
                _PrintLoginRegisterRecordLine(L);
                cout << endl;
            }
        }
        cout << setw(12) << left << "";
        cout << "===================================================================================================\n";




	}



};

