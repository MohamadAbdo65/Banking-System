#pragma once
#include <iostream>
#include "clsBankUser.h"
#include "clsScreen.h"
#include <iomanip>

using namespace std;

class clsShowUsersList : protected clsScreen
{

    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(12) << left << "";
        cout << "|" << setw(17) << left << User.Username;
        cout << "|" << setw(17) << left << User.GetFullName();
        cout << "|" << setw(17) << left << User.Phone;
        cout << "|" << setw(17) << left << User.Email;
        cout << "|" << setw(17) << left << User.Password;
        cout << "|" << setw(17) << left << User.Acces;
    }

public:

    static void ShowClientsList()
    {

        vector <clsUser> Users = clsUser::GetUsersList();

        _DrawScreenHeader("Users List Screen", "(" + to_string(Users.size()) + ") User(s).");


        cout << setw(12) << left << "" << "==================================================================================================\n";
        cout << setw(12) << left << "";
        cout << "|" << setw(17) << left << "Username";
        cout << "|" << setw(17) << left << "Full Name";
        cout << "|" << setw(17) << left << "Phone";
        cout << "|" << setw(17) << left << "Email";
        cout << "|" << setw(17) << left << "Password";
        cout << "|" << setw(17) << left << "Acces";
        cout << endl;
        cout << setw(12) << left << "" << "==================================================================================================\n\n";


        if (Users.size() == 0)
        {
            cout << "\t\t\t  No Users Available In the System!";
        }
        else
        {
            for (clsUser& C : Users)
            {
                _PrintUserRecordLine(C);
                cout << endl;
            }
        }
        cout << setw(12) << left << "";
        cout << "===================================================================================================\n";


    }

};

