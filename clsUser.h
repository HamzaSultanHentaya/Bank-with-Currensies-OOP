
#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include<string>
#include<vector>
#include<fstream>
#include"clsUtil.h"
using namespace std;

const string UsersFile = "Users.txt";
class clsUser :public clsPerson
{
	enum enMode
	{
		EmptyMode = 0, UpdatMode = 1, AddNewMode = 2
	};
	enMode _Mode;
	string _LoginRegist;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;



	struct stLoginRegisterInfo;
	static clsUser _GetEmptyUserOpject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUser _ConvertLinetoUserOpject(string info)
	{
		vector<string>vstr = SplitString(info, "#//#");


		return clsUser(enMode::UpdatMode, vstr[0], vstr[1],
			vstr[2], vstr[3], vstr[4], clsUtil::PasswordDecryption(vstr[5]), stod(vstr[6]));

	}

	static stLoginRegisterInfo _ConvertLineToLoginRegister(string info)
	{
		vector<string>vstr = SplitString(info, "#//#");
		stLoginRegisterInfo log;
		log.DateAndTime = vstr[0];
		log.Name = vstr[1];
		clsUtil::PasswordDecryption(log.Password = vstr[2]);
		log.Permission = stoi(vstr[3]);

		return log;

	}

	static vector<clsUser>_LoadUsersDataFromFile()
	{
		vector<clsUser>vUsers;
		fstream file;

		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsUser Userinfo = _ConvertLinetoUserOpject(filecontent);

				vUsers.push_back(Userinfo);
			}
			file.close();
		}
		return vUsers;
	}




	string _ConvertUserObjectToString(clsUser User)
	{
		string st = User.FirstName() + "#//#" + User.LastName() + "#//#" +
			User.Email() + "#//#" + User.PhoneNumber() + "#//#" + User._UserName + "#//#" +
			clsUtil::PasswordEncryption(User._Password) + "#//#"
			+ to_string(User._Permissions);
		return st;
	}

	void _SaveUsersDataToFile(vector<clsUser>vstr)
	{
		fstream file;

		file.open(UsersFile, ios::out);
		// we should always use this form ios::out will great a file if no one were saved,and ios::app will append date in the file.
		string DataLine;
		if (file.is_open())
		{
			for (clsUser s : vstr)
			{
				if (s._MarkedForDelete != true)
				{
					DataLine = _ConvertUserObjectToString(s);
					file << DataLine << endl;
				}

			}file.close();//do not forget it.
		}
	}

	void _Update()
	{
		vector<clsUser>Users;
		Users = _LoadUsersDataFromFile();
		for (clsUser& c : Users)
		{
			if (c.UserName() == _UserName)
			{
				c = *this;
				break;
			}
		}
		_SaveUsersDataToFile(Users);


	}


	void _AddDataLineToFile(string newline)
	{

		{
			fstream MyFile;
			MyFile.open(UsersFile, ios::out | ios::app);

			if (MyFile.is_open())
			{

				MyFile << newline << endl;

				MyFile.close();
			}

		}



	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToString(*this));
	}

	string _PrpareLoginRecord(string separater = "#//#")
	{
		return clsDate::GetSystemDateTime() + separater + _UserName + separater +
			_Password + separater + to_string(_Permissions);
	}




	static vector<stLoginRegisterInfo>_LoadLoginRegisterDataFromFile()
	{
		vector<stLoginRegisterInfo>vUsers;
		fstream file;

		file.open("LoginRegister.txt", ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				stLoginRegisterInfo Userinfo = _ConvertLineToLoginRegister(filecontent);

				vUsers.push_back(Userinfo);
			}
			file.close();
		}
		return vUsers;
	}





public:



	static struct stLoginRegisterInfo {
		string DateAndTime, Name, Password;
		short Permission = 0;
	};

	enum enPermission {
		pAll = -1, pListOfClient = 1, pAddClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindCliente = 16, pTrnasAction = 32, pManageUsers = 64
		, pLoginRegister = 128,pCurrency=256
	};

	clsUser(enMode Mode, string firstName, string LastName, string Email,
		string telefon, string UserName, string Password, int Permissions) :
		clsPerson(firstName, LastName, Email, telefon)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;

	}



	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}
	bool MarkForDelete()
	{
		return _MarkedForDelete;
	}

	void SetUserName(string UserNumber)
	{
		_UserName = UserNumber;
	}
	string UserName()
	{
		return _UserName;
	}
	__declspec(property(get = UserName, put = SetUserName)) string userName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string Password()
	{
		return _Password;
	}
	__declspec(property(get = Password, put = SetPassword)) string password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int Permissions()
	{
		return _Permissions;
	}
	__declspec(property(get = Permissions, put = SetPermissions)) int permissions;



	static vector<string>  SplitString(string str, string delim)
	{
		vector<string> vWords;

		string word = "";
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


	static clsUser Find(string UserNumber)
	{
		/*vector<clsUser>vClient;*/
		fstream file;

		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsUser Userinfo = _ConvertLinetoUserOpject(filecontent);
				if (Userinfo._UserName == UserNumber)
				{
					file.close();
					return Userinfo;
				}
				/*	vClient.push_back(Clientinfo);*/
			}
			file.close();

		}
		return _GetEmptyUserOpject();
	}


	static clsUser Find(string UserNumber, string password)
	{
		fstream file;

		file.open(UsersFile, ios::in);

		if (file.is_open())
		{
			string filecontent;

			while (getline(file, filecontent))
			{
				clsUser Userinfo = _ConvertLinetoUserOpject(filecontent);
				if (Userinfo._UserName == UserNumber && Userinfo._Password == password)
				{
					file.close();
					return Userinfo;
				}
			}
			file.close();

		}
		return _GetEmptyUserOpject();
	}


	static bool IsUserExist(string Username)
	{
		clsUser User1 = clsUser::Find(Username);
		return(!User1.IsEmpty());
	}


	bool Delete()
	{
		vector<clsUser>vUser;
		vUser = _LoadUsersDataFromFile();
		for (clsUser& c : vUser)
		{
			if (c.UserName() == _UserName)
			{
				c._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUser);
		*this = _GetEmptyUserOpject();
		return true;

	}

	enum enSaveResults { svFaildEmptyObject = 0, svSacceeded = 1, svFaildAcountNumberExist = 2, svDeleteAcountSucceeded = 3 };

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
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
			if (clsUser::IsUserExist(_UserName))
			{
				return clsUser::enSaveResults::svFaildAcountNumberExist;

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

	static clsUser  GreatNewUserObject(string Usernumber)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", Usernumber, "", 0);

	}



	bool CheckAccesPermission(enPermission permission)
	{
		if (permission == enPermission::pAll)
			return true;
		else if ((this->permissions & permission) == permission)
			return true;
		else
		{
			return false;
		}
	}


	void LoginRegister()
	{
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << _PrpareLoginRecord() << endl;



			MyFile.close();
		}
	}




	static vector<stLoginRegisterInfo> GetLoginRegisterList()
	{
		return _LoadLoginRegisterDataFromFile();
	}


};

