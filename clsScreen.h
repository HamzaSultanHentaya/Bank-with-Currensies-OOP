#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"

using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitel = "")
	{
		system("cls");
		cout << "\n\n" << left << setw(37) << "" << "________________________________________________________\n\n";
		cout << left << setw(50) << "" << Title << endl;
		if (SubTitel != "")
		{
			cout << endl << left << setw(50) << "" << SubTitel << endl;
		}
		cout << left << setw(37) << "" << "________________________________________________________\n\n";
		cout << left << setw(37) << "" << "Today is  ";
		clsDate::GetSystemDate();
		cout << left << setw(37) << "" << "User: " << CurrentUser.UserName() << endl;

	}

	static bool _CheckAccesRichts(clsUser::enPermission Permission)
	{
		if (!CurrentUser.CheckAccesPermission(Permission))
		{
			_DrawScreenHeader("Acces is diened ", "Please contact your Admin\n");
			return false;

		}
		else
		{
			return true;
		}
	}
};

