#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValid.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
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

    static void ShowWithdrawScreen()
    {

        _DrawScreenHeader("Withdraw Screen");

        string AccountNumber = clsInputValid::ReadString("Please enter Account Number ? ");

        while (!clsClient::IsClientExist(AccountNumber))
        {
            cout << "Client with Account number [" << AccountNumber << "] is NOT found, Try again." << endl;

            cout << "\n";

            AccountNumber = clsInputValid::ReadString("Please enter Account Number ? ");
        }

        clsClient Client = clsClient::Find(AccountNumber);

        _PrintClientCard(Client);

        int amount = 0;
        cout << "Please enter Withdraw amount ? " << endl;
        amount = clsInputValid::ReadIntNumber("Invalid value, Please enter Withdraw amount ? ");

        while (amount <= 0)
        {
            cout << "Invalid value, Please enter Withdraw amount ? " << endl;
            amount = clsInputValid::ReadIntNumber("Invalid value, Please enter Withdraw amount ? ");
        }

        char answer = 'n';
        cout << "Are you sure to complete this process ?, y/n ? ";
        cin >> answer;

        if (tolower(answer) == 'y')
        {
            if (Client.Withdraw(amount))
            {
                cout << "Amount Deposited succesfully. \n";
                cout << "New balance is : " << Client.Balance;
            } 
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << amount;
                cout << "\nYour Balance is: " << Client.Balance;
            }

        }
        else
        {
            cout << "\nOperation was cancelled. \n";
        }

    }



};

