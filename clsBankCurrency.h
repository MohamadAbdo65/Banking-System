#pragma once
#include <iostream>
#include "clsString.h"
#include <fstream>

using namespace std;

const string FileNameCurrencies = "Currencies.txt";

class clsBankCurrency
{

	enum enMode {Empty = 0, Update = 1};

	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;

	//* convert methods

	static string _ConvertRecordToLine(clsBankCurrency Currency, string delim = "#//#")
	{
		string Line = "";

		Line += Currency.GetCountry() + delim;
		Line += Currency.GetCurrencyCode() + delim;
		Line += Currency.GetCurrencyName() + delim;
		Line += to_string(Currency.GetRate());

		return Line;
	}

	static clsBankCurrency _ConvertLineToRecord(string Line, string delim = "#//#")
	{
		vector <string> Record;

		Record = clsString::Split(Line, delim);

		return clsBankCurrency(enMode::Update, Record[0], Record[1], Record[2], stof(Record[3]));
	}


	//* load & save Date 

	static  vector <clsBankCurrency> _LoadCurrencysDataFromFile()
	{

		vector <clsBankCurrency> vCurrencys;

		fstream MyFile;
		MyFile.open(FileNameCurrencies, ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				clsBankCurrency Currency = _ConvertLineToRecord(Line);

				vCurrencys.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencys;

	}

	static void _SaveCurrencyDataToFile(vector <clsBankCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open(FileNameCurrencies, ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankCurrency C : vCurrencys)
			{
				DataLine = _ConvertRecordToLine(C);
				MyFile << DataLine << endl;



			}

			MyFile.close();

		}

	}


	//* update data and save in file

	void _Update()
	{
		vector <clsBankCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsBankCurrency& C : _vCurrencys)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencys);

	}


	//* get empty mode and empty opject

	static clsBankCurrency _GetEmptyCurrencyObject()
	{
		return clsBankCurrency(enMode::Empty, "", "", "", 0);
	}

public:

	clsBankCurrency(enMode Mode, string Country, string CurrencyCode,
		string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (enMode::Empty == _Mode);
	}

	string GetCountry()
	{
		return _Country;
	}

	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}

	string GetCurrencyName()
	{
		return _CurrencyName;
	}

	float GetRate()
	{
		return _Rate;
	}

	void SetRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static clsBankCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;

		MyFile.open(FileNameCurrencies, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankCurrency Currency = _ConvertLineToRecord(Line);
				if (clsString::UpperAllString(Currency.GetCurrencyCode()) == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static clsBankCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString( Country);

		fstream MyFile;

		MyFile.open(FileNameCurrencies, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankCurrency Currency = _ConvertLineToRecord(Line);
				if (clsString::UpperAllString(Currency.GetCountry()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExistByCode(string CurrencyCode)
	{
		clsBankCurrency C = FindByCode(CurrencyCode);

		return (!C.IsEmpty());
	}

	static bool IsCurrencyExistByCountry(string Country)
	{
		clsBankCurrency C = FindByCountry(Country);

		return (!C.IsEmpty());
	}

	static vector <clsBankCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

	 float ConvertAmountToDollar(float amount)
	 {
		return (float)(amount / GetRate());
	 }

	 float ConvertDollarToAnyCurrency(float Amount, clsBankCurrency CurrencyTo)
	 {
		 float AmountUSD = ConvertAmountToDollar(Amount);

		 if (CurrencyTo.GetCurrencyCode() == "USD")
		 {
			 return AmountUSD;
		 }

		return (AmountUSD * CurrencyTo.GetRate());
	 }


};