#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsInputValid
{

public:

	static bool IsNumberBetwen(int number, int from, int to)
	{
		if (number >= from && number <= to)
		{
			return true;
		}
		return false;
	}

	static bool IsNumberBetwen(double number, double from, double to)
	{
		if (number >= from && number <= to)
		{
			return true;
		}
		return false;
	}

	static bool ISDateBetwen(clsDate Date, clsDate from, clsDate to)
	{
		// swap Dates if to < from
		if (clsDate::Date1_isBefore_Date2(to, from))
		{
			clsUtil::Swap(to, from);
		}

		if ((clsDate::Date1_isAfter_Date2(Date , from) || clsDate::Date1_isEqual_Date2(Date, from)) 
		&& (clsDate::Date1_isBefore_Date2(Date, to) || clsDate::Date1_isEqual_Date2(Date , to)))
		{
			return true;
		}

		return false;
	}

	static string ReadString(string massege)
	{
		string St;

		cout << massege;
		getline(cin >> ws, St);

		return St;
	}

	static int ReadIntNumber(string MassegeError)
	{
		int number = 0;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << MassegeError << endl;

			cin >> number;
		}

		return number;

	}

	static double ReadDoubleNumber(string MassegeError)
	{
		double number = 0;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << MassegeError << endl;

			cin >> number;
		}

		return number;

	}

	static int GetNumberIntInRange(string MassegeError, short from, short to)
	{

		int Number = ReadIntNumber(MassegeError);
		
		while (!IsNumberBetwen(Number, from ,to))
		{
			cout << MassegeError << endl;
			Number = ReadIntNumber(MassegeError);
		}
		return Number;
	}

	static double GetNumberDoubleInRange(string MassegeError, double from, double to)
	{
		double Number = ReadIntNumber(MassegeError);

		while (!IsNumberBetwen(Number, from, to))
		{
			cout << MassegeError;
			Number = ReadIntNumber(MassegeError);
		}
		return Number;
	}

	static bool IsValidDate(short day, short month, short year)
	{
		return (clsDate::IsValidDate(day, month, year));
	}


};

