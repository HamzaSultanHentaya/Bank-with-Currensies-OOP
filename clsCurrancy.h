#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include<vector>
#include<fstream>
#include"clsString.h"
using namespace std;

string CurrencyFile = "Currencies.txt";

class clsCurrancy

{
	enum enMode { Empty = 1, Update = 0 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;



	static vector<string>  _SplitString(string str, string delim)
	{
		vector<string> vWords;

		string word = " ";
		short pos = 0;
		while ((pos = short(str.find(delim))) != std::string::npos)
		{
			word = str.substr(0, pos);

			if (word != "")
			{
				vWords.push_back(word);
			}
			str.erase(0, pos + delim.length());
		}


		if (str != "")
		{

			vWords.push_back(str);
		}


		return vWords;

	}


	static clsCurrancy _ConvertLinetoCurrencyOpject(string info)
	{
		vector<string>vstr = _SplitString(info, "#//#");


		return clsCurrancy(enMode::Update, vstr[0], vstr[1],
			vstr[2], stod(vstr[3]));

	}


	string _ConvertCurrencyObjectToString(clsCurrancy CurrencyInfo)
	{
		string st = CurrencyInfo.Country() + "#//#" + CurrencyInfo.CurrencyCode() + "#//#" +
			CurrencyInfo.CurrencyName() + "#//#" + to_string(CurrencyInfo.Rate());
		return st;
	}


	static vector<clsCurrancy>_LoadCurrencyDataFromFile()
	{
		vector<clsCurrancy>vClient;
		fstream file;

		file.open(CurrencyFile, ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsCurrancy Clientinfo = _ConvertLinetoCurrencyOpject(filecontent);

				vClient.push_back(Clientinfo);
			}
			file.close();
		}
		return vClient;
	}

	void _SaveClurrencyDataToFile(vector<clsCurrancy>vstr)
	{
		fstream file;

		file.open(CurrencyFile, ios::out);
		// we should always use this form ios::out will great a file if no one were saved,and ios::app will append date in the file.
		string DataLine;
		if (file.is_open())
		{
			for (clsCurrancy s : vstr)
			{
				if (s._Mode == enMode::Update)
				{
					DataLine = _ConvertCurrencyObjectToString(s);
					file << DataLine << endl;
				}

			}file.close();//do not forget it.
		}
	}


	void _Update()
	{
		vector<clsCurrancy>vNewRate;
		vNewRate = _LoadCurrencyDataFromFile();
		for (clsCurrancy& c : vNewRate)
		{
			if (c.Country() == _Country)
			{
				c = *this;
				break;
			}
		}
		_SaveClurrencyDataToFile(vNewRate);


	}


	static clsCurrancy _GetEmptyOpject()
	{
		return clsCurrancy(enMode::Empty, "", "", "", 0);
	}







public:


	clsCurrancy(enMode Mode, string Country
		, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	bool IsEmpty()
	{
		return _Mode;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	float Rate()
	{
		return _Rate;
	}




	static clsCurrancy FindByCountry(string country)
	{

		fstream file;
		country = clsString::AllLetterToUpper(country);
		file.open(CurrencyFile, ios::in);

		string forAllettertoUper;

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsCurrancy CurrencyInfo = _ConvertLinetoCurrencyOpject(filecontent);
				forAllettertoUper = CurrencyInfo.Country();//I must to write this line becouse.
				//the compiler accept in AllLetterToUpper just a name of string. And I dont know way!!.
				if (clsString::AllLetterToUpper(forAllettertoUper) == country)
				{

					file.close();
					return CurrencyInfo;
				}

			}
			file.close();

		}
		return _GetEmptyOpject();
	}



	static clsCurrancy FindByCurrencyCode(string currencyCode)
	{
		vector<clsCurrancy>vClient;
		fstream file;
		currencyCode = clsString::AllLetterToUpper(currencyCode);

		file.open(CurrencyFile, ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsCurrancy CurrencyInfo = _ConvertLinetoCurrencyOpject(filecontent);
				if (CurrencyInfo.CurrencyCode() == currencyCode)
				{
					file.close();
					return CurrencyInfo;
				}

			}
			file.close();

		}
		return _GetEmptyOpject();
	}


	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrancy C1 = clsCurrancy::FindByCurrencyCode(CurrencyCode);
		return(!C1.IsEmpty());
	}

	static vector<clsCurrancy>GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}


	float ConfertToDollar(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConfertToAnotherCurrency(float Amount, clsCurrancy currency2)
	{
		Amount = ConfertToDollar(Amount);
		if (currency2.CurrencyCode() == "USD")
		{
			return Amount;
		}
		else
		{
			return float(Amount * currency2.Rate());
		}
	}

};

