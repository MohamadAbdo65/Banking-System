#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include "clsBankClient.h"

using namespace std;

class clsFindClient : protected clsScreen
{
    static void _PrintClientCard(clsClient Client)
    {
        cout << "================================" << endl;
        cout << "         Client Card " << endl;
        cout << "================================" << endl;
        cout << "First Name : " << Client.FirstName << endl;
        cout << "Last Name  : " << Client.LastName << endl;
        cout << "Full Name  : " << Client.GetFullName() << endl;
        cout << "Phone      : " << Client.Phone << endl;
        cout << "Email      : " << Client.Email << endl;
        cout << "Pin Code   : " << Client.PinCode << endl;
        cout << "Acc Number : " << Client.AccountNumber << endl;
        cout << "Balance    : " << Client.Balance << endl;
        cout << "================================" << endl;
    }

public :

    static void ShowFindClientScreen()
    {

        if (!CheakAccesRight(clsUser::enAcces::FindClient))
        {
            return;
        }

        _DrawScreenHeader("Find Client Screen");

        string AccountNumber;

        AccountNumber = clsInputValid::ReadString("\nPlease Enter Account Number: ");

        while (!clsClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValid::ReadString("\nAccount number is not found, choose another one: ");
        }

        clsClient Client1 = clsClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClientCard(Client1);

    }


};

