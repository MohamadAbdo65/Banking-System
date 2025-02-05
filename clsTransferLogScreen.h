#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

    static void _PrintTransferLogLine(clsClient::stTransferLogRecord Record)
    {
        cout << setw(12) << left << "";
        cout << "|" << setw(20) << left << Record.DataTime;
        cout << "|" << setw(12) << left << Record.AccountFrom;
        cout << "|" << setw(12) << left << Record.AccountTo;
        cout << "|" << setw(12) << left << Record.Amount;
        cout << "|" << setw(12) << left << Record.NewBalanceFrom;
        cout << "|" << setw(12) << left << Record.NewBalanceTo;
        cout << "|" << setw(12) << left << Record.Username;
    }

public :

	static void ShowTransferLogScreen()
	{

		vector <clsClient::stTransferLogRecord> TransferLog = clsClient::GetTransferLogList();

		_DrawScreenHeader("Transfer Log", to_string(TransferLog.size()));

        cout << setw(12) << left << "" << "==================================================================================================\n";
        cout << setw(12) << left << "";
        cout << "|" << setw(20) << left << "Data / Time";
        cout << "|" << setw(12) << left << "From";
        cout << "|" << setw(12) << left << "To";
        cout << "|" << setw(12) << left << "Amount";
        cout << "|" << setw(12) << left << "s.Balance";
        cout << "|" << setw(12) << left << "d.Balance";
        cout << "|" << setw(12) << left << "User";
        cout << endl;
        cout << setw(12) << left << "" << "==================================================================================================\n\n";


        if (TransferLog.size() == 0)
        {
            cout << "\t\t\t  No Users Available In the System!";
        }
        else
        {
            for (clsClient::stTransferLogRecord& L : TransferLog)
            {
                _PrintTransferLogLine(L);
                cout << endl;
            }
        }
        cout << setw(12) << left << "";
        cout << "===================================================================================================\n";


	}


};

