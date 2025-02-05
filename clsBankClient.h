#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsDate.h"

using namespace std;


const string ClientsFileName = "ClientsData.txt";

const string TransferLogFileName = "TransferLog.txt";

class clsClient : public clsPerson
{

	enum enMode { Empty = 0, Update = 1, Add = 2 };

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	int _Balance;
	bool _MarkToDelete = false;

	struct stTransferLogRecord;



	//* convert methods
	static clsClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);


		return clsClient(enMode::Update, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], clsUtil::Decryption(vClientData[5], 11), stoi(vClientData[6]));

	}
	static string _ConvertRecordtoLine(clsClient data, string delim = "#//#")
	{
		string LineString = "";

		string PincodeToEncryption = data.PinCode;

		LineString += data.FirstName + delim;
		LineString += data.LastName + delim;
		LineString += data.Email + delim;
		LineString += data.Phone + delim;
		LineString += data.AccountNumber + delim;
		LineString += clsUtil::Encryption(data.PinCode, 11) + delim;
		LineString += to_string(data.Balance);


		return LineString;
	}
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string delim = "#//#")
	{
		vector <string> vDataLog;
		vDataLog = clsString::Split(Line, delim);

		stTransferLogRecord Record;

		Record.DataTime = vDataLog[0];
		Record.AccountFrom = vDataLog[1];
		Record.AccountTo = vDataLog[2];
		Record.Amount = stoi(vDataLog[3]);
		Record.NewBalanceFrom = stoi(vDataLog[4]);
		Record.NewBalanceTo = stoi(vDataLog[5]);
		Record.Username = vDataLog[6];

		return Record;
	}

	//* for get data from file 
	static vector <clsClient> _LoadDataFromFile(string filename)
	{
		vector <clsClient> vDataFromFile;
		fstream ClientData;

		ClientData.open(filename, ios::in);

		if (ClientData.is_open())
		{
			string line;
			 

			while (getline(ClientData, line))
			{
				if (!line.empty())
				{
					clsClient Data = _ConvertLinetoClientObject(line);
					vDataFromFile.push_back(Data);
				}
			}

			ClientData.close();
		}

		return vDataFromFile;
	}
	
	//this is Out Mode : for update or delete \/
	static vector <clsClient> _SaveClientDataToFile(string FileName, vector <clsClient> vData)
	{
		fstream FileData;
		FileData.open(FileName, ios::out);

		string DataLine;

		if (FileData.is_open())
		{
			for (clsClient& D : vData)
			{
				if (D._MarkToDelete == false)
				{
					DataLine = _ConvertRecordtoLine(D);
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
		MyFile.open(ClientsFileName, ios::app | ios::out);


		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	//for save transfer log 
	string _PrepareTransferLogInRecord(clsClient AccountTo, int Amount, string delim = "#//#")
	{
		string Line = "";

		Line += clsDate::GetDate_TimeStringLine() + delim;
		Line += AccountNumber + delim;
		Line += AccountTo.AccountNumber + delim;
		Line += to_string(Amount) +delim;
		Line += to_string(Balance) + delim;
		Line += to_string(AccountTo.Balance) + delim;
		Line += CurrentUser.Username;

		return Line;
	}

    void _SaveTranferLogInFile(clsClient AccountTo, int Amount)
	{
		string LogLine = _PrepareTransferLogInRecord(AccountTo, Amount);

		fstream FileLog;

		FileLog.open(TransferLogFileName, ios::app | ios::out);

		if (FileLog.is_open())
		{
			FileLog << LogLine << endl;

			FileLog.close();
		}


	}

	//* for get empty object
	static clsClient _GetEmptyClientObject()
	{
		return clsClient(enMode::Empty, "", "", "", "", "", "", 0);
	}

	//* for Update data
    void _Update()
	{
		vector <clsClient> vClientData;
		vClientData = _LoadDataFromFile(ClientsFileName);

		for (clsClient &C : vClientData)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}


		}
		_SaveClientDataToFile(ClientsFileName, vClientData);
	}

	//* for add new data
	void _Add()
	{
		_AddDataLineToFile(_ConvertRecordtoLine(*this));
	}




public:

	struct stTransferLogRecord
	{
		string DataTime;
		string AccountFrom;
		string AccountTo;
		int Amount;
		int NewBalanceFrom;
		int NewBalanceTo;
		string Username;
	};

	clsClient(enMode mode ,string firstname, string lastname,string email,
	 string phone, string AccountNumber, string PinCode, int Balance)
		: clsPerson(firstname, lastname, phone, email)
	{
		_Mode = mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}

	//* this \/

	void SetAccountNumber(string St)
	{
		_AccountNumber = St;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;

	//*

	void SetPinCode(string St)
	{
		_PinCode = St;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	//*

	void SetBalance(int B)
	{
		_Balance = B;
	}

	int GetBalance()
	{
		return _Balance;
	}

	__declspec(property(get = GetBalance, put = SetBalance)) int Balance;

	//=============================================================

	//* find and get data

	static clsClient Find(string AccountNumber)
	{
		vector <clsClient> ClientData = _LoadDataFromFile(ClientsFileName);

		for (clsClient& C : ClientData)
		{
			if (C.AccountNumber == AccountNumber)
			{
				return C;
			}
		}

		return _GetEmptyClientObject();
	}

	static clsClient Find(string AccountNumber, string Pin)
	{

		vector <clsClient> ClientData = _LoadDataFromFile(ClientsFileName);

		for (clsClient& C : ClientData)
		{
			if (C.AccountNumber == AccountNumber && C.PinCode == Pin)
			{
				return C;
			}
		}

		return _GetEmptyClientObject();
	}

	//* empty or exist

	bool IsEmpty()
	{
		return (_Mode == enMode::Empty);
	}

   static  bool IsClientExist(string Acc)
	{
		clsClient Client = Find(Acc);


		return (!Client.IsEmpty());
	}

   //*  save methods

   enum enSaveResult {svFaildEmptyObject = 1, svSecceded = 2, svFaildAccountNumberExist = 3};

   enSaveResult Save()
   {
	   switch (_Mode)
	   {
	   case clsClient::Empty:
	   
		   return svFaildEmptyObject;
		   break;

	   case clsClient::Update:
	   
		   _Update();
		   return svSecceded;
		   break;

	   case clsClient::Add:

		   if (clsClient::IsClientExist(_AccountNumber))
		   {
			   return enSaveResult::svFaildAccountNumberExist;
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

   //* for get generet Account number

   static clsClient GetAddNewClientObject(string AccountNumber)
   {
	   return clsClient(enMode::Add, "", "", "", "", AccountNumber, "", 0);
   }

   //* for delete 

   bool Delete()
   {
	   vector <clsClient> vClientData;
	   vClientData = _LoadDataFromFile(ClientsFileName);

	   for (clsClient& C : vClientData)
	   {
		   if (C.AccountNumber == _AccountNumber)
		   {
			   C._MarkToDelete = true;
			   break;
		   }
	   }

	   _SaveClientDataToFile(ClientsFileName, vClientData);

	   *this = _GetEmptyClientObject();

	   return true;
   }

   //* for get all clients data
    
   static vector <clsClient> GetClientsList()
   {
	   return _LoadDataFromFile(ClientsFileName);
   }

   //* for Get total balances

   static int GetTotalBalances()
   {
	   vector <clsClient> vClient = _LoadDataFromFile(ClientsFileName);

	   int totalbalances = 0;

	   for (clsClient& C : vClient)
	   {
		   totalbalances += C.Balance;
	   }

	   return totalbalances;
   }


   //* for transaction 

   void Deposite(int amount)
   {
	   _Balance += amount;
	   Save();
   }

   bool Withdraw(int amount)
   {
	   if (amount > _Balance)
	   {
		   return false;
	   }
	   else
	   {
		   _Balance -= amount;
		   Save();
		   return true;
	   }
   }

   bool Transfer(int Amount, clsClient& AccountTo)
   {
	   if (Amount > Balance)
	   {
		   return false;
	   }

	   Withdraw(Amount);
	   AccountTo.Deposite(Amount);
	   _SaveTranferLogInFile(AccountTo, Amount);
	   return true;
   }

   static vector <stTransferLogRecord> GetTransferLogList()
   {
	   vector <stTransferLogRecord> vTransferLogList;

	   fstream MyFile;

	   MyFile.open(TransferLogFileName, ios::in);

	   if (MyFile.is_open())
	   {

		   string Line;

		   stTransferLogRecord TransferLogRecord;

		   while (getline(MyFile, Line))
		   {
			   TransferLogRecord = _ConvertTransferLogLineToRecord(Line);

			   vTransferLogList.push_back(TransferLogRecord);
		   }

		   MyFile.close();

	   }

	   return vTransferLogList;
   }


   //*



};