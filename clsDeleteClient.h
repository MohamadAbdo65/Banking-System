#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include "clsBankClient.h"
using namespace std;

class clsDeleteClient : protected clsScreen
{

    static void _PrintClientCard(clsClient Client)
    {
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

public:

	static void DeleteClient()
	{
        if (!CheakAccesRight(clsUser::enAcces::DeleteClient))
        {
            return;
        }

        _DrawScreenHeader("Delete Client Screen");

        string AccountNumber = "";

        AccountNumber = clsInputValid::ReadString("\nPlease Enter client Account Number: ");

        while (!clsClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValid::ReadString("\nPlease Enter client Account Number: ");
        }

        clsClient Client1 = clsClient::Find(AccountNumber);
        _PrintClientCard(Client1);

        char answer = 'n';
        cout << "Are You Sure you want to delete this Client ? y/n ? " << endl;
        cin >> answer;

        if (tolower(answer) == 'y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClientCard(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }


        
	}

};

