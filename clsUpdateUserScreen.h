#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsUtil.h"
using namespace std;




class clsUpdateUserScreen :protected clsScreen
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
	static void ShowUpdateUserScreen()
	{


		_DrawScreenHeader("Update User Screen");
		string UserName = clsUtil::ReadString("Please enter User Name\n");
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "This Username is not found \n";
			UserName = clsUtil::ReadString("Please enter another username\n");
		}
		clsUser UpdateUser = clsUser::Find(UserName);
		_PrintUserInfo(UpdateUser);
		char del = 'n';
		cout << "Are you sure you want to update this User ? Yes(Y)/ No(N)\n";
		cin >> del;
		if (del == 'y' || del == 'Y')
		{
			_ReadUserInfo(UpdateUser);

		}
		else
		{
			cout << "User was not updated \n";
			return;
		}
		clsUser::enSaveResults SaveRasult;
		SaveRasult = UpdateUser.Save();

		switch (SaveRasult)
		{
		case clsUser::enSaveResults::svSacceeded:

		{
			cout << "\n\nUpdate User was succeeded :-)";
			_PrintUserInfo(UpdateUser);

			break;
		}

		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "Update User is not succeeded, becouse its empty :-( \n";
			break;
		}
		}


	}
};

