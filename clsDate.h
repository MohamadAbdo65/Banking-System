#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include "clsString.h"
#include <chrono>

using namespace std;

class clsDate
{

	//stTime _Time;

	short _Day;
	short _Month;
	short _Year;

public:


	clsDate()
	{
		time_t t = time(0);

		tm* now = localtime(&t);

		_Year = now->tm_year + 1900;

		_Month = now->tm_mon + 1;

		_Day = now->tm_mday;
	}

	clsDate(string DateString)
	{

		vector <string> vDate;

		vDate = clsString::Split(DateString, "/");

		_Day = stoi(vDate.at(0));
		_Month = stoi(vDate.at(1));
		_Year = stoi(vDate.at(2));
	}

	clsDate(short day, short month, short year)
	{
		_Day = day;
		_Month = month;
		_Year = year;
	}

	clsDate(short DateOrderInYear, short year)
	{
		clsDate Date1 = GetDateFromDaysfromOrder(DateOrderInYear, year);

		_Day = Date1._Day;
		_Month = Date1._Month;
		_Year = Date1._Year;
	}

	struct stTime
	{
		short Hour;
		short Minute;
		short secound;
	};

	//* day \/

	void SetDay(short day)
	{
		_Day = day;
	}

	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	//* month \/

	void SetMonth(short month)
	{
		_Month = month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	//* year

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	//* 

	static void Print(short day, short month, short year)
	{
		cout << day << "/" << month << "/" << year;
	}

	void Print()
	{
		Print(_Day, _Month, _Year);
	}

	//*

	static bool IsValidDate(short day, short month, short year)
	{
		if (!(year >= 1))
			return false;

		if (month < 1 || month > 12)
			return false;

		short ValidDay = NumberOfDaysInAMonth(year, month);

		if (day < 1 || day > ValidDay)
			return false;


		return true;
	}

	bool IsValidDate()
	{
		return IsValidDate(_Day, _Month, _Year);
	}

	//*

	static void PrintMonthCalender(int year, short month)
	{
		int numberofdays = NumberOfDaysInAMonth(year, month);
		int orderday = GetDayOrder(year, month, 1);


		printf("\n  _______________%s_______________\n\n", GetMonthName(month).c_str());
		cout << "\n";
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < orderday; i++)
			printf("     ");

		for (int j = 1; j <= numberofdays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}

		}
		printf("\n  _________________________________\n");
	}

	void PrintMonthCalender()
	{
		PrintMonthCalender(_Year, _Month);
	}

	//*

	static void PrintYearCalender(short year)
	{
		cout << "\n  _________________________________\n";
		cout << "\n           Calender * " << year << endl;
		cout << "  _________________________________\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(year, i);
			cout << "\n";
		}
	}

	void PrintYearCalender()
	{
		PrintYearCalender(_Year);
	}

	//*

	static int CalculateAgeInDay(clsDate date1)
	{
		clsDate Date2 = clsDate();

		int days = 0;

		while (Date1_isBefore_Date2(date1, Date2))
		{
			days++;
			date1 = IncreaseDateByOneDay(date1);
		}

		return days;
	}

	//*

	static bool Date1_isBefore_Date2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date1._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}

	bool Date1_isBefore_Date2(clsDate Date2)
	{
		return Date1_isBefore_Date2(*this, Date2);
	}

	//*

	static clsDate IncreaseDateByOneDay(clsDate& Date)
	{
		if (isLastDayinMonth(Date))
		{
			if (isLastMonthinYear(Date._Month))
			{
				Date._Year++;
				Date._Month = 1;
				Date._Day = 1;
			}
			else
			{
				Date._Month++;
				Date._Day = 1;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}

	void IncreaseDateByOneDay()
	{
		IncreaseDateByOneDay(*this);
	}

	//* 

	static bool isLastMonthinYear(short month)
	{
		return (month == 12) ? true : false;
	}

	bool isLastMonthinYear()
	{
		return isLastMonthinYear(_Month);
	}

	//*

	static bool isLastDayinMonth(clsDate date)
	{
		short NumberOfday = NumberOfDaysInAMonth(date._Year, date._Month);

		return (NumberOfday == date._Day) ? true : false;

	}

	bool isLastDayinMonth()
	{
		return isLastDayinMonth(*this);
	}

	//*

	static string GetMonthName(short month)
	{
		string arrOfNameMonth[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Act", "Nov", "Dec" };

		return arrOfNameMonth[month];

	}

	string GetMonthName()
	{
		return GetMonthName(_Month);
	}

	//*

	static short GetDayOrder(int year, short month, short day)
	{
		short a = ((14 - month) / (12));

		short y = year - a;

		short m = month + 12 * a - 2;

		short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	short GetDayOrder()
	{
		return GetDayOrder(_Year, _Month, _Day);
	}

	//*

	static bool isLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	//*

	static short NumberOfDaysInAMonth(int year, short month)
	{
		if (month < 1 || month > 12)
			return 0;

		short NumebrOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : (NumebrOfDays[month]);

	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Year, _Month);
	}

	//*

	static clsDate GetDateFromDaysfromOrder(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date._Year = Year;
		Date._Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}

		}
		return Date;
	}

	void GetDateFromDaysfromOrder(short DateOrderInYear)
	{
		GetDateFromDaysfromOrder(DateOrderInYear, _Year);
	}

	//* 

	static string PrintFDate(clsDate Date, string format = "dd/mm/yyyy")
	{
		string DateFormat = "";

		DateFormat = clsString::ReplaceWordInString(format, "dd", to_string(Date._Day));
		DateFormat = clsString::ReplaceWordInString(DateFormat, "mm", to_string(Date._Month));
		DateFormat = clsString::ReplaceWordInString(DateFormat, "yyyy", to_string(Date._Year));

		return DateFormat;
	}

	string PrintFDate(string format = "dd/mm/yyyy")
	{
		return PrintFDate(*this, format);
	}

	//*

	static bool Date1_isAfter_Date2(clsDate Date1, clsDate Date2)
	{
		return (!Date1_isBefore_Date2(Date1, Date2) && !Date1_isEqual_Date2(Date1, Date2));
	}

	bool Date1_isAfter_Date2(clsDate Date2)
	{
		return Date1_isAfter_Date2(*this, Date2);
	}

	//*

	static bool Date1_isEqual_Date2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Day == Date2._Day && Date1._Month == Date2._Month && Date1._Year == Date2._Year);
	}

	bool Date1_isEqual_Date2(clsDate Date2)
	{
		return Date1_isEqual_Date2(*this, Date2);
	}

	//*

	static void SwapTwoDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate temp;

		temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}

	void SwapTwoDates(clsDate Date2)
	{
		SwapTwoDates(*this, Date2);
	}

	//*

	static clsDate GetSystemDate()
	{
		time_t t = time(0);

		tm* now = localtime(&t);

		short day, month, year;

		year = now->tm_year + 1900;

		month = now->tm_mon + 1;

		day = now->tm_mday;


		return clsDate(day, month, year);
	}

	static stTime GetTimeSystem()
	{

		time_t now_c = time(0);

		tm* ptm = localtime(&now_c);

		stTime SystemTime;

		SystemTime.Hour = ptm->tm_hour;
		SystemTime.Minute = ptm->tm_min;
		SystemTime.secound = ptm->tm_sec;

		return SystemTime;
	}

	//*

	static string DateToString(clsDate date)
	{
		return (to_string(date._Day) + "/" + to_string(date._Month) + "/" + to_string(date._Year));
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static string TimeToString(stTime Time)
	{
		return (to_string(Time.Hour)) + ":" + (to_string(Time.Minute)) + ":" + (to_string(Time.secound));
	}

	//*

	static string GetDate_TimeStringLine()
	{
		return (DateToString(GetSystemDate()) + " - " + TimeToString(GetTimeSystem()));
	}




};