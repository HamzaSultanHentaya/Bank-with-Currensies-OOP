#pragma once
#include<iostream>
#include"clsUtil.h"
#include"clsUsersListScreen.h"
#include"clsAddUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

using namespace std;
class clsManageUseresScreen :protected clsScreen

{
	enum enManagerMenue { UserList = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, GoToMainMinue = 6 };

	static void _ShowUserListScreen()
	{
		clsUsersListScreen::ShowUsersListScreen();
	}
	static void _ShowAddUserScreen()
	{
		clsAddUserScreen::ShowAddUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();

	}


	static void _DoingWhatchoicedInManageUsers(enManagerMenue num)
	{


		switch (num)
		{
		case enManagerMenue::UserList:
			system("cls");
			_ShowUserListScreen();
			_GoBackToManageUseresMenue();

			break;

		case enManagerMenue::AddUser:
			system("cls");
			_ShowAddUserScreen();
			_GoBackToManageUseresMenue();
			break;
		case enManagerMenue::DeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUseresMenue();
			break;
		case enManagerMenue::UpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUseresMenue();
			break;

		case enManagerMenue::FindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUseresMenue();
			break;
		case enManagerMenue::GoToMainMinue:
			system("cls");
			break;

		default:
			system("cls");
			cout << " not a qultie number !! \n";
			_GoBackToManageUseresMenue();
			break;

		}
	}

	static void _GoBackToManageUseresMenue()
	{
		cout << "\npress any key to go to Transaction Menue...\n";
		cout << system("pause>0");
		ShowManageUsersScreen();
	}




public:

	static void ShowManageUsersScreen()
	{

		if (!_CheckAccesRichts(clsUser::enPermission::pManageUsers))
		{

			cout << "\npress any key to go to Main menue\n";
			cout << system("pause>0");
			return;
		}
		system("cls");

		_DrawScreenHeader("Manage Useres Screen");
		cout << left << setw(37) << "" << "===============================================\n\n";
		cout << left << setw(37) << "" << "         M A N A G E R   U S E R E S             \n\n";
		cout << left << setw(37) << "" << "===============================================\n";
		cout << left << setw(37) << "" << "  [1] List Users .\n";
		cout << left << setw(37) << "" << "  [2] Add a new User \n";
		cout << left << setw(37) << "" << "  [3] Delete User \n";
		cout << left << setw(37) << "" << "  [4] Update User \n";
		cout << left << setw(37) << "" << "  [5] Find User \n";
		cout << left << setw(37) << "" << "  [6] Go To Main Menue \n";

		cout << left << setw(37) << "" << "=============================================\n";
		cout << left << setw(37) << "";
		enManagerMenue choice = enManagerMenue(clsInputValidate::ReadShortNumberBetween("Please choose what do you want to do\n", 1, 6));
		_DoingWhatchoicedInManageUsers(choice);
	}

};

