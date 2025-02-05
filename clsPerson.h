#pragma once
#include <iostream>
using namespace std;

class clsPerson 
{

	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;

public:

	clsPerson(string firstname, string lastname, 
	 string phone, string email)
	{
		_FirstName = firstname;
		_LastName = lastname;
		_Phone = phone;
		_Email = email;
	}
	
	//*

	void SetFirstName(string St)
	{
		_FirstName = St;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	//*

	void SetLastName(string St)
	{
		_LastName = St;
	}

	string GetLastname()
	{
		return _LastName;
	}

	__declspec(property(get = GetLastname, put = SetLastName)) string LastName;

	//*

	void SetPhone(string St)
	{
		_Phone = St;
	}

	string GetPhone()
	{
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	//*

	void SetEmail(string St)
	{
		_Email = St;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	//*

	string GetFullName()
	{
		return (_FirstName + " " + _LastName);
	}



};