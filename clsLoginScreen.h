#pragma once
#include<iostream>
#include"clsMainScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsUtil.h"
#include"clsScreen.h"
using namespace std;
class clsLoginScreen :protected clsScreen
{


	static bool _Login()
	{
		short Try = 0;
		string Username = clsUtil::ReadString("Please enter the User Name\n");

		string Password = clsUtil::ReadString("Please enter a vailed Password\n");


		CurrentUser = clsUser::Find(Username, Password);
		bool Loginfaild = CurrentUser.IsEmpty();

		while (Loginfaild)
		{

			Try++;
			cout << "User Name/Password was not found\n";
			cout << "Try number " << Try << " \nYou have " << 3 - Try << " Try more" << endl;
			Username = clsUtil::ReadString("Please enter a vailed User Name\n");
			Password = clsUtil::ReadString("Please enter a vailed Password\n");

			CurrentUser = clsUser::Find(Username, Password);
			Loginfaild = CurrentUser.IsEmpty();
			if (Try >= 2) { break; }


		}
		if (Try >= 2 && Loginfaild)
		{
			cout << "You have used 3 times invalid Username /Password\n Your Acount is locked. ";
			cout << "Please contact your Admin\n";
			return false;
		}
		else
		{
			CurrentUser.LoginRegister();
			clsMainScreen::ShowMainMenue();

		}
	}


public:
	static bool ShowLoginScreen()

	{
		system("cls");
		_DrawScreenHeader("Login Screen ");

		return _Login();

	}
};

