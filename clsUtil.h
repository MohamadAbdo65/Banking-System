#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:


	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int GetRandomNumber(int from, int to)
	{
		int randnumber = rand() % (to - from + 1) + from;

		return randnumber;

	}

	static string GenerateWord(short length)
	{
		string word = "";

		for (int i = 1; i <= length; i++)
		{
			word += char(GetRandomNumber(65, 90));
		}

		return word;
	}

	static string GenerateKey()
	{
		string key = "";

		key = GenerateWord(4) + "-";
		key += GenerateWord(4) + "-";
		key += GenerateWord(4) + "-";
		key += GenerateWord(4);

		return key;
	}

	static void GenerateKeys(int NumberofKeys)
	{
		for (int i = 1; i <= NumberofKeys ; i++)
		{
			cout << "key [" << i << "] : " << GenerateKey() << endl;
		}
	}

	static void Swap(int& Number1, int &Number2)
	{
		int Temp;

		Temp = Number1;
		Number1 = Number2;
		Number2 = Temp;
	}

	static void Swap(float& Number1, float& Number2)
	{
		float Temp;

		Temp = Number1;
		Number1 = Number2;
		Number2 = Temp;
	}

	static void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& St1, string &St2)
	{
		string Temp;

		Temp = St1;
		St1 = St2;
		St2 = Temp;
	}

	static void Swap(clsDate &Date1, clsDate &Date2)
	{
		clsDate::SwapTwoDates(Date1, Date2);
	}

	static void FillArrayWithRandomNumber(int arr[100], int length, int from , int to)
	{
		for (int i = 1; i <= length; i++)
		{
			arr[i] = GetRandomNumber(from, to);
		}
	}

	static string Tabs(int numberoftab = 1)
	{
		string tab;

		for (int i = 1; i <= numberoftab; i++)
		{
			tab += "\t";
		}
		return tab;
	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[GetRandomNumber(1, arrLength) - 1], arr[GetRandomNumber(1, arrLength) - 1]);
		}

	}

	static string NumberToString(int number)
	{
		if (number == 0)
			return "";

		//----------------

		if (number >= 1 && number <= 19)
		{
			string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[number] + " ";
		}

		//---------------

		if (number >= 20 && number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return arr[number / 10] + " " + NumberToString(number % 10);
		}

		//---------------

		if (number >= 100 && number <= 199)
		{
			return "One hundred " + NumberToString(number % 100);
		}

		//---------------

		if (number >= 200 && number <= 999)
		{
			return NumberToString(number / 100) + "hundred " + NumberToString(number % 100);
		}

		//---------------

		if (number >= 1000 && number <= 1999)
		{
			return "One thousand " + NumberToString(number % 1000);
		}

		//---------------

		if (number >= 2000 && number <= 999999)
		{
			return NumberToString(number / 1000) + "thousand " + NumberToString(number % 1000);
		}

		//---------------

		if (number >= 1000000 && number <= 1999999)
		{
			return"One Million " + NumberToString(number % 1000000);
		}

		//---------------

		if (number >= 2000000 && number <= 999999999)
		{
			return   NumberToString(number / 1000000) + "Millions " + NumberToString(number % 1000000);
		}

		//---------------

		if (number >= 1000000000 && number <= 1999999999)
		{
			return"One Billion " + NumberToString(number % 1000000000);
		}

		//---------------

		else
		{
			return   NumberToString(number / 1000000000) + "Billions " + NumberToString(number % 1000000000);
		}

	}

	static void Pause(string massege = "")
	{
		cout << massege;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin.get();
	}

	static string Encryption(string Text, short Key)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + Key);
		}

		return Text;
	}

	static string Decryption(string Text, short Key)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - Key);
		}

		return Text;
	}

};

