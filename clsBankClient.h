#pragma once
#include"clsPerson.h"
#include<string>
#include<vector>
#include<fstream>
#include"Global.h"
#include"clsString.h"
#include"clsUtil.h"
using namespace std;

const string CLientsFile = "Clients.txt";
class clsBankClient :public  clsPerson
{
private:
	enum enMode
	{
		EmptyMode = 0, UpdatMode = 1, AddNewMode = 2, DeleteClient = 3
	};


	enMode _Mode;

	string _AcountNumber;
	string _PinCode;

	double _AcountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLinetoClientOpject(string info)
	{
		vector<string>vstr = SplitString(info, "#//#");


		return clsBankClient(enMode::UpdatMode, vstr[0], vstr[1],
			vstr[2], vstr[3], vstr[4], clsUtil::PasswordDecryption(vstr[5]), stod(vstr[6]));

	}

	static clsBankClient _GetEmptyClientOpject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient>_LoadClientsDataFromFile()
	{
		vector<clsBankClient>vClient;
		fstream file;

		file.open(CLientsFile, ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsBankClient Clientinfo = _ConvertLinetoClientOpject(filecontent);

				vClient.push_back(Clientinfo);
			}
			file.close();
		}
		return vClient;
	}

	void _SaveClientsDataToFile(vector<clsBankClient>vstr)
	{
		fstream file;

		file.open(CLientsFile, ios::out);
		// we should always use this form ios::out will great a file if no one were saved,and ios::app will append date in the file.
		string DataLine;
		if (file.is_open())
		{
			for (clsBankClient s : vstr)
			{
				if (s._MarkForDelete != true)
				{
					DataLine = _ConvertClientObjectToString(s);
					file << DataLine << endl;
				}

			}file.close();//do not forget it.
		}
	}

	void _Update()
	{
		vector<clsBankClient>Clients;
		Clients = _LoadClientsDataFromFile();
		for (clsBankClient& c : Clients)
		{
			if (c.AcountNumber() == _AcountNumber)
			{
				c = *this;
				break;
			}
		}
		_SaveClientsDataToFile(Clients);


	}


	string _ConvertClientObjectToString(clsBankClient Client)
	{
		string st = Client.FirstName() + "#//#" + Client.LastName() + "#//#" +
			Client.Email() + "#//#" + Client.PhoneNumber() + "#//#" + Client._AcountNumber + "#//#" +
			clsUtil::PasswordEncryption(Client.PinCode()) + "#//#"
			+ to_string(Client.AcountBalance());
		return st;
	}
	void _AddDataLineToFile(string newline)
	{

		{
			fstream MyFile;
			MyFile.open("Clients.txt", ios::out | ios::app);

			if (MyFile.is_open())
			{

				MyFile << newline << endl;

				MyFile.close();
			}

		}



	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToString(*this));
	}


	static  void _TransferRegister(string TransferInfo)
	{
		fstream MyFile;
		MyFile.open("TransferRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << TransferInfo << endl;



			MyFile.close();
		}
	}



	string _PrpareTransfareAction(clsBankClient Receiver, double Amount, string separater = "#//#")
	{
		return clsDate::GetSystemDateTime() + separater +
			_AcountNumber + separater +
			Receiver.AcountNumber() + separater +
			to_string(Amount) + separater +
			to_string(_AcountBalance) + separater +
			to_string(Receiver.AcountBalance()) + separater +
			CurrentUser.UserName();
	}



	struct stTransferLog;

	static stTransferLog _ConvertLineToTransferInfo(string info)
	{
		vector<string>vstr = SplitString(info, "#//#");
		stTransferLog Action;
		Action.DateAndTime = vstr[0];
		Action.Sender = vstr[1];
		Action.Receiver = vstr[2];
		Action.Amount = stod(vstr[3]);
		Action.SenderBalance = stod(vstr[4]);
		Action.ReceiverBalance = stod(vstr[5]);
		Action.UserName = vstr[6];

		return Action;

	}

	static vector<stTransferLog>_LoadTransferDataFromFile()
	{
		vector<stTransferLog>vTransInfo;
		fstream file;

		file.open("TransferRegister.txt", ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				stTransferLog TransferInfo = _ConvertLineToTransferInfo(filecontent);

				vTransInfo.push_back(TransferInfo);
			}
			file.close();
		}
		return vTransInfo;
	}


public:





	clsBankClient(enMode Mode, string firstName, string LastName, string Email,
		string telefon, string AcountNumber, string PinCode, float AcountBalance) :
		clsPerson(firstName, LastName, Email, telefon)
	{
		_Mode = Mode;
		_AcountNumber = AcountNumber;
		_PinCode = PinCode;
		_AcountBalance = AcountBalance;
	}



	static struct stTransferLog
	{
		string DateAndTime;
		string Sender;
		string Receiver;
		string UserName;
		double Amount = 0, SenderBalance = 0, ReceiverBalance = 0;
	};

	void SetAcountNumber(string AcountNumber)
	{
		_AcountNumber = AcountNumber;
	}
	string AcountNumber()
	{
		return _AcountNumber;
	}
	__declspec(property(get = AcountNumber, put = SetAcountNumber)) string acountNumber;

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string PinCode() { return _PinCode; }
	__declspec(property(get = PinCode, put = SetPinCode)) string pincode;

	void SetAcountBalance(float AcountBalance)
	{
		_AcountBalance = AcountBalance;
	}
	float AcountBalance() { return _AcountBalance; }
	__declspec(property(get = AcountBalance, put = SetAcountBalance)) float acountBalance;



	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	void Print()//Overriding base Function.
	{


		cout << "\n\nClient Infos ";
		cout << "\n========================================\n";
		cout << "First Name    : " << FirstName() << endl;
		cout << "Last Name     : " << LastName() << endl;
		cout << "Full Name     : " << FirstName() << " " << LastName() << endl;
		cout << "Email         : " << Email() << endl;
		cout << "Telefon       : " << PhoneNumber() << endl;
		cout << "AcountNumber  :" << _AcountNumber << endl;
		cout << "PinCode       :" << _PinCode << endl;
		cout << "Balance       :" << _AcountBalance << endl;
		cout << "===========================================\n";
	}

	static vector<string>  SplitString(string str, string delim)
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


	static clsBankClient Find(string acountNumber)
	{
		vector<clsBankClient>vClient;
		fstream file;

		file.open("Clients.txt", ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsBankClient Clientinfo = _ConvertLinetoClientOpject(filecontent);
				if (Clientinfo._AcountNumber == acountNumber)
				{
					file.close();
					return Clientinfo;
				}
				/*	vClient.push_back(Clientinfo);*/
			}
			file.close();

		}
		return _GetEmptyClientOpject();
	}


	static clsBankClient Find(string acountNumber, string pinCode)
	{
		vector<clsBankClient>vClient;
		fstream file;

		file.open("Clients.txt", ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsBankClient Clientinfo = _ConvertLinetoClientOpject(filecontent);
				if (Clientinfo._AcountNumber == acountNumber && Clientinfo._PinCode == pinCode)
				{
					file.close();
					return Clientinfo;
				}
				/*vClient.push_back(Clientinfo);*/
			}
			file.close();

		}
		return _GetEmptyClientOpject();
	}
	static bool IsClientExist(string AcountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AcountNumber);
		return(!Client1.IsEmpty());
	}



	bool Delete()
	{
		vector<clsBankClient>Clients;
		Clients = _LoadClientsDataFromFile();
		for (clsBankClient& c : Clients)
		{
			if (c.AcountNumber() == _AcountNumber)
			{
				c._MarkForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(Clients);
		*this = _GetEmptyClientOpject();
		return true;

	}


	enum enSaveResults { svFaildEmptyObject = 0, svSacceeded = 1, svFaildAcountNumberExist = 2, svDeleteAcountSucceeded = 3 };

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;

		}
		case enMode::UpdatMode:
		{
			_Update();
			return enSaveResults::svSacceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AcountNumber))
			{
				return clsBankClient::enSaveResults::svFaildAcountNumberExist;

			}
			else
			{
				_AddNew();
				//we need to set mode to Update after add new becouse if would be update after that.
				_Mode = enMode::UpdatMode;
				return enSaveResults::svSacceeded;
			}

		}
		}


	}

	static clsBankClient  GreatNewClientObject(string Acountnumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", Acountnumber, "", 0);

	}

	static double GetTotalBalance()
	{
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();


		double totalbalance = 0;
		for (clsBankClient client : vClients)
		{
			totalbalance += client.AcountBalance();

		}return totalbalance;
	}

	void Deposit(double Amount)
	{
		_AcountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AcountBalance)
		{
			return false;
		}

		else {
			_AcountBalance -= Amount;
			Save();
		}

	}

	bool Transfer(clsBankClient& Receiver, double Amount)
	{
		if (Amount > _AcountBalance)
		{
			return false;
		}
		else
		{
			Receiver.Deposit(Amount);
			//_AcountBalance -= Amount;
			this->Withdraw(Amount);
			_TransferRegister(_PrpareTransfareAction(Receiver, Amount));
		}
	}



	static vector<stTransferLog> GetTransferLogList()
	{
		return _LoadTransferDataFromFile();
	}



};  