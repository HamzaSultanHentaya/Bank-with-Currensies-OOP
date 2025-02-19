#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClient.h"	
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchageMainScreen.h"
using namespace std;



class clsMainScreen :protected clsScreen
{
	enum enMainMenueOption {
		showliste = 1, AddClient = 2, Deleteclient = 3
		, UpdateClient = 4, FindClient = 5, TransAction = 6,
		MagageUsers = 7, LoginRegister = 8, CurrencyExchange = 9, Logout = 10
	};



	static short _ReadMainMenueOption()
	{
		cout << left << setw(37) << "" << " Choose what do you want to do ..[1--10]\n";
		short Choice = clsInputValidate::ReadShortNumberBetween("", 1, 10);
		return Choice;
	}

	static void _ShowClientsListScreen()
	{
		clsClientsListScreen::PrintListOfClients();
	}
	static void _ShowAddClientsScreen()
	{
		clsAddNewClientScreen::ShowAddClientScreen();
	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClientInfoScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
		

	}
	static void _ShowFindClientScreen()
	{
		clsFindClient::ShowFindClientScreen();
	}
	static void _ShowTransActionsScreen()
	{
		clsTransactionScreen::ShowTransactionMenue();

	}

	static void _ShowManageUsersScreen()
	{
		clsManageUseresScreen::ShowManageUsersScreen();
	}

	static void _ShowLoginRegisterScreen()
	{

		clsLoginRegisterScreen::ShowLoginRegisterScreen();

	}
	
	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchageMainScreen::ShowCurrencyExchangeScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//clsLoginScreen::ShowLoginScreen(); We can not use this Code becaouse this code is allredy called
		// in MainScreen and the compiler will be in unendable circul. We call that (Circular Referance).
		//The solution for this problem is to write while loop in int main().
	}






public:

	/*static void GoToMainMenue(){}*/





	static void DoingWhatChoisedInMeinMenue(enMainMenueOption choice)
	{
		switch (choice)
		{
		case enMainMenueOption::showliste:
			system("cls");
			_ShowClientsListScreen();
			GoBackToMainMenue();
			break;

		case enMainMenueOption::AddClient:
			system("cls");
			_ShowAddClientsScreen();
			GoBackToMainMenue();
			break;
		case enMainMenueOption::Deleteclient:
			system("cls");
			_ShowDeleteClientScreen();
			GoBackToMainMenue();
			break;
		case enMainMenueOption::UpdateClient:
			system("cls");
			_ShowUpdateClientInfoScreen();
			GoBackToMainMenue();
			break;

		case enMainMenueOption::FindClient:
			system("cls");
			_ShowFindClientScreen();
			GoBackToMainMenue();
			break;
		case enMainMenueOption::TransAction:
			system("cls");
			_ShowTransActionsScreen();
			ShowMainMenue();
			break;
		case enMainMenueOption::MagageUsers:
			system("cls");
			_ShowManageUsersScreen();
			ShowMainMenue();
			break;
		case enMainMenueOption::LoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			GoBackToMainMenue();
			break;
		case enMainMenueOption::CurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			ShowMainMenue();
			break;
		case enMainMenueOption::Logout:
			_Logout();

			break;
		default:
			system("cls");
			cout << " not a qultie number !! \n";

			break;

		}



	}

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("Main Menue");
		cout << left << setw(37) << "" << "=============================================\n";
		cout << left << setw(55) << "" << "  Main Menue \n";
		cout << left << setw(37) << "" << "=============================================\n";

		cout << left << setw(37) << "" << "  [1] Show Clients list .\n";
		cout << left << setw(37) << "" << "  [2] Add a Client . \n";
		cout << left << setw(37) << "" << "  [3] Delete a Client .\n";
		cout << left << setw(37) << "" << "  [4] Update Client Data .\n";
		cout << left << setw(37) << "" << "  [5] Find Client .\n";
		cout << left << setw(37) << "" << "  [6] Transaction .\n";
		cout << left << setw(37) << "" << "  [7] Manage Users \n";
		cout << left << setw(37) << "" << "  [8] Login Register .\n";
		cout << left << setw(37) << "" << "  [9] Currency Exchange .\n";
		cout << left << setw(37) << "" << "  [10] Logout .\n";
		cout << left << setw(37) << "" << "=============================================\n";

		DoingWhatChoisedInMeinMenue(enMainMenueOption(_ReadMainMenueOption()));


	}


	static void GoBackToMainMenue()
	{
		cout << "\npress any key to go to Main menue\n";
		cout << system("pause>0");
		ShowMainMenue();

	}





};

