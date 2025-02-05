#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsUtil.h"

using namespace std;


const string FileLogName = "LogRegister.txt";

const string UsersFileName = "UsersData.txt";

class clsUser : public clsPerson
{

	enum enMode {Empty = 1,
		Update = 2, Add = 3};

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Acces;
	bool _MarkToDelete = false;

	struct stLoginRegisterRecord;


	//* Convert Methods
	static clsUser _ConvertLineToUserObject(string Line, string delim = "#//#")
	{
		vector <string> vUserData;
		vUserData = clsString::Split(Line, delim);


		return clsUser(enMode::Update, vUserData[0], vUserData[1],
			vUserData[2], vUserData[3], vUserData[4], clsUtil::Decryption(vUserData[5], 11), stoi(vUserData[6]));

	}

	static string _ConvertUserObjectToLine(clsUser User, string delim = "#//#")
	{		
		string Line = "";


		Line += User.FirstName + delim;
		Line += User.LastName + delim;
		Line += User.Email + delim;
		Line += User.Phone + delim;
		Line += User._UserName + delim;
		Line += clsUtil::Encryption(User._Password, 11) + delim;
		Line += to_string(User._Acces);

		return Line;
	}

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string line, string delim = "#//#")
	{
		vector <string> vDataLog;
		vDataLog = clsString::Split(line, delim);

		stLoginRegisterRecord Record;

		Record.DateTime = vDataLog[0];
		Record.UserName = vDataLog[1];
		Record.Password = clsUtil::Decryption(vDataLog[2], 11);
		Record.Permissions = stoi(vDataLog[3]);

		return Record;
	}
	
	//* To get a line of login history information
	string _PrepareLogInRecord(string delim = "#//#")
	{
		string Line = "";


		Line += clsDate::GetDate_TimeStringLine() + delim;
		Line += Username + delim;
		Line += clsUtil::Encryption(Password, 11) + delim;
		Line += to_string(Acces);

		return Line;
	}

	//for get Data from file
	static vector <clsUser> _LoadDataFromFile(string filename)
	{
		vector <clsUser> vDataFromFile;
		fstream UserData;

		UserData.open(filename, ios::in);

		if (UserData.is_open())
		{
			string line;


			while (getline(UserData, line))
			{
				if (!line.empty())
				{
					clsUser Data = _ConvertLineToUserObject(line);
					vDataFromFile.push_back(Data);
				}
			}

			UserData.close();
		}

		return vDataFromFile;
	}

	//this is Out Mode : for update or delete \/
	static vector <clsUser> _SaveClientDataToFile(string FileName, vector <clsUser> vData)
	{
		fstream FileData;
		FileData.open(FileName, ios::out);

		string DataLine;

		if (FileData.is_open())
		{
			for (clsUser& D : vData)
			{
				if (D._MarkToDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(D);
					FileData << DataLine << endl;
				}

			}
			FileData.close();
		}
		return vData;
	}

	//this is app Mode : for add new line data \/
	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::app | ios::out);


		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	//* for get empty object
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::Empty, "", "", "", "", "", "", 0);
	}

	//* for Update data
	void _Update()
	{
		vector <clsUser> vUserData;
		vUserData = _LoadDataFromFile(UsersFileName);

		for (clsUser& C : vUserData)
		{
			if (C._UserName == GetUsername())
			{
				C = *this;
				break;
			}


		}
		_SaveClientDataToFile(UsersFileName, vUserData);
	}

	//* for add new data
	void _Add()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}


public:

	enum enAcces  
	{
	   All = -1,
	   ListClient = 1,
	   AddClient = 2,
	   DeleteClient = 4,
	   UpdateClient = 8,
	   FindClient = 16,
	   TransactionMenu = 32,
	   ManageUserMenu = 64,
	   LoginRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;

	};

	clsUser(enMode Mode, string Firstname, string Lastname, string Email, string Phone, 
	string Username, string Password, int Acces) 
		: clsPerson(Firstname, Lastname, Phone, Email)
	{
		_Mode = Mode;
		_UserName = Username;
		_Password = Password;
		_Acces = Acces;
	}

	//* a variable member - set & get \/

	void SetUsername(string St)
	{
		_UserName = St;
	}
	 
	string GetUsername()
	{
		return _UserName;
	}

	__declspec(property(get = GetUsername, put = SetUsername)) string Username;

	void SetPassword(string St)
	{
		_Password = St;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetAcces(int Ac)
	{
		_Acces = Ac;
	}

	int GetAcces()
	{
		return _Acces;
	}

	__declspec(property(get = GetAcces, put = SetAcces)) int Acces;

	//============================================================

	//* find and get data

	static clsUser Find(string Username)
	{
		vector <clsUser> ClientData = _LoadDataFromFile(UsersFileName);

		for (clsUser& C : ClientData)
		{
			if (C._UserName == Username)
			{
				return C;
			}
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string Username, string Password)
	{
		vector <clsUser> ClientData = _LoadDataFromFile(UsersFileName);

		for (clsUser& C : ClientData)
		{
			if (C.GetUsername() == Username && C.GetPassword() == Password)
			{
				return C;
			}
		}

		return _GetEmptyUserObject();
	}

	//* empty or exist

	 bool IsEmpty()
	{
		return (_Mode == enMode::Empty);
	}

	static  bool IsUserExist(string U)
	{
		clsUser User = Find(U);


		return (!User.IsEmpty());
	}

	//*  save methods

	enum enSaveResult { svFaildEmptyObject = 1, svSecceded = 2, svFaildUsernameExist = 3 };

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsUser::Empty:

			return svFaildEmptyObject;
			break;

		case clsUser::Update:

			_Update();
			return svSecceded;
			break;

		case clsUser::Add:

			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFaildUsernameExist;
			}
			else
			{
				_Add();
				_Mode = enMode::Update;
				return enSaveResult::svSecceded;
			}
			break;
		}
	}

	//* for get generet User name
	static clsUser GetAddNewUserObject(string Username)
	{
		return clsUser(enMode::Add, "", "", "", "", Username, "", 0);
	}

	//* for delete 

	bool Delete()
	{
		vector <clsUser> vClientData;
		vClientData = _LoadDataFromFile(UsersFileName);

		for (clsUser& C : vClientData)
		{
			if (C.GetUsername() == _UserName)
			{
				C._MarkToDelete = true;
				break;
			}
		}

		_SaveClientDataToFile(UsersFileName, vClientData);

		*this = _GetEmptyUserObject();

		return true;
	}

	//* for get all clients data

	static vector <clsUser> GetUsersList()
	{
		return _LoadDataFromFile(UsersFileName);
	}

	bool CheakIsHaveAcces(enAcces Acces)
	{
		if (this->Acces == enAcces::All)
			return true;

		if ((Acces & this->Acces) == Acces)
			return true;
		else
			return false;
	}

	//* for save date & time -> log register

	 void SaveRegisterTime()
	 {
		string LogLine = _PrepareLogInRecord();

		fstream FileLog;

		FileLog.open(FileLogName, ios::app | ios::out);

		if (FileLog.is_open())
		{
			FileLog << LogLine << endl;

			FileLog.close();
		}
	 }

	 //* for get login register data

	 static vector <stLoginRegisterRecord> GetLoginRegisterList()
	 {
		 vector <stLoginRegisterRecord> vLoginRegisterList;

		 fstream MyFile;

		 MyFile.open(FileLogName, ios::in);

		 if (MyFile.is_open())
		 {

			 string Line;

			 stLoginRegisterRecord LoginRegisterRecord;

			 while (getline(MyFile, Line))
			 {
				 LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				 vLoginRegisterList.push_back(LoginRegisterRecord);
			 }

			 MyFile.close();

		 }

		 return vLoginRegisterList;
	 }

	 

};