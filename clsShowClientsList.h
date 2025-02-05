#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsBankUser.h"

using namespace std;

class clsShowClientsList : protected clsScreen
{

    static void _PrintClientRecordLine(clsClient Client)
    {
        cout << setw(12) << left << "";
        cout << "|" << setw(17) << left << Client.AccountNumber;
        cout << "|" << setw(17) << left << Client.GetFullName();
        cout << "|" << setw(17) << left << Client.Phone;
        cout << "|" << setw(17) << left << Client.Email;
        cout << "|" << setw(17) << left << Client.PinCode;
        cout << "|" << setw(17) << left << Client.Balance;
    }

public:

    static void ShowClientsList()
    {
        if (!CheakAccesRight(clsUser::enAcces::ListClient))
        {
            return;
        }

        vector <clsClient> Clients = clsClient::GetClientsList();

        string Title = "Client List Screen";
        string SubTitle = "(" + to_string(Clients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

     
        cout << setw(12) << left << "" <<"==================================================================================================\n";
        cout << setw(12) << left << "";
        cout << "|" << setw(17) << left << "Account Number";
        cout << "|" << setw(17) << left << "Full Name";
        cout << "|" << setw(17) << left << "Phone";
        cout << "|" << setw(17) << left << "Email";
        cout << "|" << setw(17) << left << "PinCode";
        cout << "|" << setw(17) << left << "Balance";
        cout << endl;
        cout <<setw(12) << left << "" << "==================================================================================================\n\n";


        if (Clients.size() == 0)
        {
            cout << "\t\t\t  No Clients Available In the System!";
        }
        else
        {
            for (clsClient& C : Clients)
            {
                _PrintClientRecordLine(C);
                cout << endl;
            }
        }
        cout << setw(12) << left << "";
        cout << "===================================================================================================\n";


    }

};

