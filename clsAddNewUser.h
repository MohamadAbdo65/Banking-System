#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include "clsBankUser.h"

using namespace std;

class clsAddNewUser : protected clsScreen
{
    static void _ReadUserInfo(clsUser& User)
    {
        User.FirstName = clsInputValid::ReadString("\nEnter FirstName: ");
        
        User.LastName = clsInputValid::ReadString("\nEnter LastName: ");
        
        User.Email = clsInputValid::ReadString("\nEnter Email: ");
        
        User.Phone = clsInputValid::ReadString("\nEnter Phone: ");
        
        User.Password = clsInputValid::ReadString("\nEnter Password: ");

        User.Acces = ReadAcces();
    }

    static void _PrintUserCard(clsUser User)
    {
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

    static bool IsHaveAccesTo(char Answer)
    {
        return (tolower(Answer) == 'y');
    }

    static bool IsGiveFullAcces()
    {
        char Answer = 'n';

        cout << "\nDo you want to give full acces ?" << endl;
        cout << "[Y] or [N] ? ";

        cin >> Answer;

        return (tolower(Answer) == 'y');
    }

    static int ReadAcces()
    {

        cout << "\nEnter Acces : \n";

        int Acces = 0;

        if (IsGiveFullAcces())
        {
            Acces = -1;
        }
        else
        {
            char answer = 'n';

            cout << "\nDo you want to give acces to : \n" << endl;
            //*-*-*
            cout << "Show Client List ? [y] or [n] ? \n";
            cin >> answer;
            Acces += (IsHaveAccesTo(answer)) ? clsUser::enAcces::ListClient : 0;
            //*-*-*
            cout << "Add New Client ? [y] or [n] ? \n";
            cin >> answer;
            Acces += (IsHaveAccesTo(answer)) ? clsUser::enAcces::AddClient : 0;
            //*-*-*
            cout << "Delete Client ? [y] or [n] ? \n";
            cin >> answer;
            Acces += (IsHaveAccesTo(answer)) ? clsUser::enAcces::DeleteClient : 0;
            //*-*-*
            cout << "Update Client ? [y] or [n] ? \n";
            cin >> answer;
            Acces += (IsHaveAccesTo(answer)) ? clsUser::enAcces::UpdateClient : 0;
            //*-*-*
            cout << "Find Client ? [y] or [n] ? \n";
            cin >> answer;
            Acces += (IsHaveAccesTo(answer)) ? clsUser::enAcces::FindClient : 0;
            //*-*-*
            cout << "Transaction Menu ? [y] or [n] ? \n";
            cin >> answer;
            Acces += (IsHaveAccesTo(answer)) ? clsUser::enAcces::TransactionMenu : 0;
            //*-*-*
            cout << "Manage Users Menu ? [y] or [n] ? \n";
            cin >> answer;
            Acces += (IsHaveAccesTo(answer)) ? clsUser::enAcces::ManageUserMenu : 0;
            //*-*-   
            cout << "Log Register Screen ? [y] or [n] ? \n";
            cin >> answer;
            Acces += (IsHaveAccesTo(answer)) ? clsUser::enAcces::LoginRegister : 0;
            



        }

        return Acces;
    }

public:


    static void AddUser()
    {


        _DrawScreenHeader("Add New User Screen");

        string Username = "";

        Username = clsInputValid::ReadString("\nPlease Enter Username : ");

        while (clsUser::IsUserExist(Username))
        {
            Username = clsInputValid::ReadString("\nThis Username is Used, Please Try again : ");
        }

        clsUser User = clsUser::GetAddNewUserObject(Username);

        cout << "\n\nAdd User :";
        cout << "\n____________________\n";


        _ReadUserInfo(User);

        clsUser::enSaveResult SaveResult;

        SaveResult = User.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResult::svSecceded:
        {
            cout << "\nAdding Account Successfully :-)\n";
            _PrintUserCard(User);
            break;
        }
        case clsUser::enSaveResult::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResult::svFaildUsernameExist:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }

        }
    }

};