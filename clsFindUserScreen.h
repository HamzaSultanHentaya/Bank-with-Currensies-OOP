#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsUtil.h"
using namespace std;

class clsFindUserScreen :protected clsScreen
{


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

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");
		string UserName = clsUtil::ReadString("Please enter User Name\n");
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "This Username is not found \n";
			UserName = clsUtil::ReadString("Please enter another username\n");
		}
		clsUser FindUser = clsUser::Find(UserName);
		if (!FindUser.IsEmpty())
		{
			cout << "User is found :-) \n";
			_PrintUserInfo(FindUser);
		}
		else
		{
			cout << "User was not found \n";
		}

	}


};

