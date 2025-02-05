#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include "clsBankClient.h"

using namespace std;

class clsAddNewClient : protected clsScreen
{
    static void _ReadClientInfo(clsClient& Client)
    {
        Client.FirstName = clsInputValid::ReadString("\nEnter FirstName: ");

        Client.LastName = clsInputValid::ReadString("\nEnter LastName: ");

        Client.Email = clsInputValid::ReadString("\nEnter Email: ");

        Client.Phone = clsInputValid::ReadString("\nEnter Phone: ");

        Client.PinCode = clsInputValid::ReadString("\nEnter PinCode: ");

        cout << "\nEnter Account Balance: ";
        Client.Balance = clsInputValid::ReadIntNumber("\nInvalid value !, Please try again : ");
    }

    static void _PrintClient(clsClient Client)
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

     static void AddClient()
    {
         if (!CheakAccesRight(clsUser::enAcces::AddClient))
         {
             return;
         }

         _DrawScreenHeader("Add New Client Screen");

        string AccountNumber = "";

        AccountNumber = clsInputValid::ReadString("\nPlease Enter client Account Number: ");

        while (clsClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValid::ReadString("\nPlease Enter client Account Number: ");
        }

        clsClient Client1 = clsClient::GetAddNewClientObject(AccountNumber);

        cout << "\n\nAdd Client :";
        cout << "\n____________________\n";


        _ReadClientInfo(Client1);

        clsClient::enSaveResult SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsClient::enSaveResult::svSecceded:
        {
            cout << "\nAdding Account Successfully :-)\n";
            _PrintClient(Client1);
            break;
        }
        case clsClient::enSaveResult::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsClient::enSaveResult::svFaildAccountNumberExist:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }

        }
    }


};

