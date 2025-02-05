#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include "clsBankUser.h"

using namespace std;

class clsFindUser : protected clsScreen
{

    static void _PrintUserCard(clsUser User)
    {
        cout << "================================" << endl;
        cout << "         User Card " << endl;
        cout << "================================" << endl;
        cout << "First Name : " << User.FirstName << endl;
        cout << "Last Name  : " << User.LastName << endl;
        cout << "Full Name  : " << User.GetFullName() << endl;
        cout << "Phone      : " << User.Phone << endl;
        cout << "Email      : " << User.Email << endl;
        cout << "Password   : " << User.Password << endl;
        cout << "Username   : " << User.Username << endl;
        cout << "Acces      : " << User.Acces << endl;
        cout << "================================" << endl;
    }

public:

    static void ShowFindClientScreen()
    {

        _DrawScreenHeader("Find User Screen");

        string Username;

        Username = clsInputValid::ReadString("\nPlease Enter Username : ");

        while (!clsUser::IsUserExist(Username))
        {
            Username = clsInputValid::ReadString("\nUsername is not found, choose another one: ");
        }

        clsUser User = clsUser::Find(Username);

        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUserCard(User);

    }

};

