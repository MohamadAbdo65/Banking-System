#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"
#include <string>
#include "clsBankClient.h"

class clsUpdateClientInfo : protected clsScreen
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


   static void UpdateClient()
   {
       if (!CheakAccesRight(clsUser::enAcces::UpdateClient))
       {
           return;
       }

       _DrawScreenHeader("Update Client Screen");

        string AccountNumber = "";

        AccountNumber = clsInputValid::ReadString("\nPlease Enter client Account Number: ");

        while (!clsClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValid::ReadString("\nPlease Enter client Account Number: ");
        }

        clsClient Client1 = clsClient::Find(AccountNumber);
        _PrintClientCard(Client1);

        char answer = 'n';
        cout << "Are you sure you want to update this client ? y/n ? " << endl;
        cin >> answer;


        if (tolower(answer) == 'y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            _ReadClientInfo(Client1);

            clsClient::enSaveResult SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsClient::enSaveResult::svSecceded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClientCard(Client1);
                break;
            }
            case clsClient::enSaveResult::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }
        }            
        
   }



};

