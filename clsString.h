#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class clsString
{
private:

	string _ST;

public:

	clsString()
	{
		_ST = "";
	}

	clsString(string  st)
	{
		_ST = st;
	}

	//*

	void SetString(string st)
	{
		_ST = st;
	}

	string GetString()
	{
		return _ST;
	}

	__declspec(property(get = GetString, put = SetString)) string String;

	//*

	static vector <string> Split(string st, string delim = " ")
	{
		vector <string> saveword;

		short pos = 0;
		string word;

		while ((pos = st.find(delim)) != std::string::npos)
		{
			word = st.substr(0, pos);
			if (word != "")
			{
				saveword.push_back(word);
			}
			st.erase(0, pos + delim.length());
		}
		if (st != "")
		{
			saveword.push_back(st);
		}

		return saveword;
	}

	vector <string> Split(string delim = " ")
	{
		return Split(_ST, delim);
	}

	//*

	static short CountWord(string st, string delim = " ")
	{
		short count = 0;

		short pos = 0;
		string word;

		while ((pos = st.find(delim)) != std::string::npos)
		{
			word = st.substr(0, pos);
			if (word != "")
			{
				count++;
			}
			st.erase(0, pos + delim.length());
		}
		if (st != "")
		{
			count++;
		}

		return count++;
	}

	short CountWord(string delim = " ")
	{
		return CountWord(_ST, delim);
	}

	//*

	static string GetStringWithoutPunct(string st)
	{
		string newst = "";

		for (short i = 0; i < st.length(); i++)
		{
			if (!ispunct(st[i]))
			{
				newst += st[i];
			}
		}

		return newst;
	}

	void GetStringWithoutPunct()
	{
		_ST = GetStringWithoutPunct(_ST);
	}

	//*

	static short Lenght(string st)
	{
		return st.length();
	}

	short Lenght()
	{
		return Lenght(_ST);
	}

	//*

	static string UpperAllString(string st)
	{
		string newSt;
		for (short i = 0; i < st.length(); i++)
		{
			newSt += (isupper(st[i])) ? toupper(st[i]) : toupper(st[i]);
		}
		return  newSt;
	}

	void UpperAllString()
	{
		_ST = UpperAllString(_ST);
	}

	//*

	static string LowerAllString(string st)
	{
		string newSt;
		for (short i = 0; i < st.length(); i++)
		{
			newSt += (islower(st[i])) ? islower(st[i]) : islower(st[i]);
		}
		return newSt;
	}

	void LowerAllString()
	{
		_ST = LowerAllString(_ST);
	}

	//*

	enum enWhatToCount { Small = 0, Capital = 1, All = 3 };

	static short CountLetter(string st, enWhatToCount WhatToCount)
	{
		short CountSamall = 0;
		short CountCapital = 0;
		short CountAll = 0;

		for (int i = 0; i < st.length(); i++)
		{
			if (isspace(st[i]))
			{
				continue;
			}

			else if (islower(st[i]))
			{
				CountSamall++;
			}

			else if (isupper(st[i]))
			{
				CountCapital++;
			}
		}

		switch (WhatToCount)
		{
		case clsString::Small:
			return CountSamall;
		case clsString::Capital:
			return CountCapital;
		case clsString::All:
			return (CountCapital + CountSamall);

		}
	}

	short CountLetter(enWhatToCount WhatToCount)
	{
		return CountLetter(_ST, WhatToCount);
	}

	//*

	static string InvertLetter(string stt)
	{
		string st = stt;

		for (int i = 0; i < st.length(); i++)
		{
			if (islower(st[i]))
				toupper(st[i]);

			else
				tolower(st[i]);
		}
		return st;
	}

	void InvertLetter()
	{
		_ST = InvertLetter(_ST);
	}

	//*

	static string UpperFirstLetterOfEachWord(string S1, string delim = " ")
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	void UpperFirstLetterOfEachWord(string delim = " ")
	{
		_ST = UpperFirstLetterOfEachWord(_ST, delim);
	}

	//*

	static string LowerFirstLetterOfEachWord(string st, string delim = " ")
	{
		bool isFirstLetter = true;

		for (short i = 0; i < st.length(); i++)
		{

			if (st[i] != ' ' && isFirstLetter)
			{
				st[i] = tolower(st[i]);

			}

			isFirstLetter = (st[i] == ' ' ? true : false);

		}

		return st;
	}

	void LowerFirstLetterOfEachWord(string delim = " ")
	{
		_ST = LowerFirstLetterOfEachWord(_ST, delim);
	}

	//*

	static string ReplaceWordInString(string S1, string OldString, string NewString)
	{
		short pos = S1.find(OldString);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, OldString.length(), NewString);
			pos = S1.find(OldString);
			//find next  
		}

		return S1;
	}

	string ReplaceWordInString(string OldString, string NewString)
	{
		return ReplaceWordInString(_ST, OldString, NewString);
	}

};

