#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include "clsBankUser.h"

using namespace std;

class clsDeleteUser : protected clsScreen
{

    static void _PrintUserCard(clsUser User)
    {
        cout << "         Client Card " << endl;
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

    static void DeleteClient()
    {
        _DrawScreenHeader("Delete User Screen");

        string Username = "";

        Username = clsInputValid::ReadString("\nPlease Enter Username : ");

        while (!clsUser::IsUserExist(Username))
        {
            Username = clsInputValid::ReadString("\nUsername is Not Found, try again : ");
        }

        clsUser User = clsUser::Find(Username);
        _PrintUserCard(User);

        char answer = 'n';
        cout << "Are You Sure you want to delete this User ? y/n ? " << endl;
        cin >> answer;

        if (tolower(answer) == 'y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";

                _PrintUserCard(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }


};