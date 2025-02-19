#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsUser.h"
using namespace std;
class clsAddUserScreen :protected clsScreen
{
	static void _ReadUserInfo(clsUser& UserInfo)
	{
		UserInfo.setFirstName(clsUtil::ReadString("Please enter the First Name\n"));
		UserInfo.setLastName(clsUtil::ReadString("Please enter the Last Name\n"));
		UserInfo.setPhoneNumber(clsUtil::ReadString("Please enter the  Phone Number\n"));
		UserInfo.setEmail(clsUtil::ReadString("Please enter the Email Adress\n"));
		UserInfo.SetPassword(clsUtil::ReadString("Please enter the Password Code \n"));

		cout << "Do you want to allowe the User all permissions ? Y/N";
		if (_CheckAnswer())
		{
			UserInfo.permissions = clsUser::enPermission::pAll;
		}
		else
		{
			UserInfo.permissions = clsUser::enPermission(CalculateUserPremissions());
		}

	}




	static short CalculateUserPremissions()
	{
		short UserInfoPermissions = 0;

		cout << "Do you want to allowe the User to schow ClinetsList ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pListOfClient;


		cout << "Do you want to allowe the User to Add clients ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pAddClient;


		cout << "Do you want to allowe the User to delete clients ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pDeleteClient;


		cout << "Do you want to allowe the User to update client Info ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pUpdateClient;


		cout << "Do you want to allowe the User to find client ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pFindCliente;


		cout << "Do you want to allowe the User to Transaction ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pTrnasAction;


		cout << "Do you want to allowe the User to mange userers ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pManageUsers;

		cout << "Do you want to allowe the User to show the Login Register ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pLoginRegister;

		cout << "Do you want to allowe the User to show the Currencies ? Y/N";
		if (_CheckAnswer())
			UserInfoPermissions += clsUser::enPermission::pCurrency;





		return UserInfoPermissions;
	}

	static bool _CheckAnswer()
	{
		char answer = 'y';
		cin >> answer;
		return (answer == 'y' || answer == 'Y');
	}


	static void _PrintUserInfo(clsUser User1)
	{
		cout << "\n\nUser Infos ";
		cout << "\n========================================\n";
		cout << "First Name    : " << User1.FirstName() << endl;
		cout << "Last Name     : " << User1.LastName() << endl;
		cout << "Full Name     : " << User1.FirstName() << " " << User1.LastName() << endl;
		cout << "Email         : " << User1.Email() << endl;
		cout << "Telefon       : " << User1.PhoneNumber() << endl;
		cout << "User Name     :" << User1.UserName() << endl;
		cout << "Password       :" << User1.Password() << endl;
		cout << "Permissions       :" << User1.Permissions() << endl;
		cout << "===========================================\n";
	}



public:
	static void ShowAddUserScreen()
	{
		_DrawScreenHeader("Add User Screen");

		string UserName = clsUtil::ReadString("Please enter the User Name\n");

		while (clsUser::IsUserExist(UserName))
		{
			cout << "This Username is recerved \n";
			UserName = clsUtil::ReadString("Please enter another username\n");
		}
		clsUser NewUser = clsUser::GreatNewUserObject(UserName);
		_ReadUserInfo(NewUser);
		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSacceeded:

		{
			cout << "\n\nAdding a new User was succeeded :-)";
			_PrintUserInfo(NewUser);

			break;
		}

		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "Adding a new User is not succeeded, becouse its empty :-( \n";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAcountNumberExist:
		{
			cout << "User Name is exist \n Adding a new User faild \n";
			break;

		}
		}








	}


};

