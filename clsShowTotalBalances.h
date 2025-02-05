#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsUtil.h"

using namespace std;

class clsShowTotalBalances : protected clsScreen
{

    static void _PrintClientRecordLine(clsClient Client)
    {
        cout << setw(30) << left << "";
        cout << "|" << setw(17) << left << Client.AccountNumber;
        cout << "|" << setw(17) << left << Client.GetFullName();
        cout << "|" << setw(17) << left << Client.Balance;
    }

public:

    static void ShowClientsList()
    {

        vector <clsClient> Clients = clsClient::GetClientsList();

        _DrawScreenHeader("Total balances", "(" + to_string(Clients.size()) + ") Balance(s).");

        cout << setw(26) << left << "";
        cout << "============================================================================\n";
        cout << setw(30) << left << "";
        cout << "|" << setw(17) << left << "Account Number";
        cout << "|" << setw(17) << left << "Full Name";
        cout << "|" << setw(17) << left << "Balance";
        cout << endl;
        cout << setw(26) << left << "";
        cout << "============================================================================\n\n";

        int TotalBalances = clsClient::GetTotalBalances();

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
        cout << setw(26) << left << "";
        cout << "============================================================================\n\n";


        cout << setw(26) << left << "" << "\t\t \t  Total Balances : (" << TotalBalances << ") \n";
        cout << setw(26) << left << "" << "\t\t    (" << clsUtil::NumberToString(TotalBalances) << ")" << endl;

    }

};

