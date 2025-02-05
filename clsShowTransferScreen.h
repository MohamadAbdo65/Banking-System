#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValid.h"

using namespace std;

class clsShowTransferScreen : protected clsScreen
{

	static void _PrintClientCard(clsClient Client)
	{

		cout << "\nClient Card : \n" << endl;
		cout << "-----------------------\n" << endl;
		cout << "Full Name  : " << Client.GetFullName() << endl;
		cout << "Acc Number : " << Client.GetAccountNumber() << endl;
		cout << "Balance    : " << Client.GetBalance() << endl;
		cout << "\n-----------------------\n" << endl;

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = clsInputValid::ReadString("please enter account number to transfer From : ");

		while (!clsClient::IsClientExist(AccountNumber))
		{
			AccountNumber = clsInputValid::ReadString("Client is NOT found, please enter account number again : ");
		}
		return AccountNumber;
	}

	static int _ReadAmount(clsClient AccountFrom)
	{

		cout << "\nEnter Transfer Amount : ";
		int TransferAmount = clsInputValid::ReadIntNumber("Invalide Number ! , Try again : ");

		while (TransferAmount > AccountFrom.GetBalance())
		{
			cout << "\nAmount exeeds the available Balance, Enter Transfer Amount : ";
			TransferAmount = clsInputValid::ReadIntNumber("Invalide Number ! , Try again : ");
		}

		return TransferAmount;
	}

public:

	static void ShowTransferScreen()
	{

		_DrawScreenHeader("Transfer Screen");

		clsClient AccountFrom = clsClient::Find(_ReadAccountNumber());
		_PrintClientCard(AccountFrom);

		clsClient AccountTo = clsClient::Find(_ReadAccountNumber());
		_PrintClientCard(AccountTo);

		int Amount = _ReadAmount(AccountFrom);

		cout << "Are you sure you want to confirm this oparetion ? y/n ? ";
		char answer = 'n';
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			if (AccountFrom.Transfer(Amount, AccountTo))
			{
				cout << "\nTransfer done succesfully :)\n" << endl;
			}
			else
			{
				cout << "\nTransfer Fail :(\n" << endl;
			}
		}

		_PrintClientCard(AccountFrom);
		_PrintClientCard(AccountTo);
	}
};