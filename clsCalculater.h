#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValid.h"

using namespace std;

class clsCalculater : protected clsScreen
{
	enum enOparetion { Multiplication = 1, Division = 2,
		Plus = 3, Minus = 4};

	static void _PerformCalculation()
	{

		double _Number1 = 0;
		double _Number2 = 0;

		string Oparetion = "";


		cout << setw(39) << left << "";

		_Number1 = clsInputValid::ReadDoubleNumber("Invalid Value ! , Try again.");
		

		cout << setw(39) << left << "";

		Oparetion = clsInputValid::ReadString("");


		cout << setw(39) << left << "";

		_Number2 = clsInputValid::ReadDoubleNumber("Invalid Value ! , Try again.");


		if (Oparetion == "+")
		{
			cout << setw(39) << left << "" << "= " << _Number1 + _Number2;

		}
		else if (Oparetion == "-")
		{
			cout << setw(39) << left << "" << "= " << _Number1 - _Number2;

		}
		else if (Oparetion == "*")
		{
			cout << setw(39) << left << "" << "= " << _Number1 * _Number2;

		}
		else if (Oparetion == "/")
		{
			cout << setw(39) << left << "" << "= " << _Number1 / _Number2;

		}
		else
		{
			cout << setw(39) << left << "" << "Error Math !" << endl;
		}

	}


public:


	static void ShowCalculator()
	{

		_DrawScreenHeader("  Calculater");

		cout << endl;

		cout << setw(39) << left << "" << "================================" << endl;
		cout << "\n";
		cout << setw(39) << left << "" << "     [7]       [8]       [9]    " << endl;
		cout << "\n";
		cout << setw(39) << left << "" << "     [4]       [5]       [6]    " << endl;
		cout << "\n";
		cout << setw(39) << left << "" << "     [1]       [2]       [3]    " << endl;
		cout << "\n";
		cout << setw(39) << left << "" << "================================" << endl;
		cout << "\n";
		cout << setw(39) << left << "" << "  [*]   [/]   [+]   [-]   [log] " << endl;
		cout << "\n";
		cout << setw(39) << left << "" << "================================" << endl;

		_PerformCalculation();
	}


};