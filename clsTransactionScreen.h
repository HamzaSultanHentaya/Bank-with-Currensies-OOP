#pragma once
#include<iostream>
#include"clsUtil.h"
#include"clsWithdrawScreen.h"
#include"clsDepositScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include"clsMainScreen.h"
using namespace std;
class clsTransactionScreen :protected clsScreen
{
	enum enTransation { Deposit = 1, Withdraw = 2, Showbalance = 3, Transfer = 4, TransferLog = 5, Gotomeinmenieu = 6 };


	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalanceScreen();
	}

	static void _ShowTransferScreen()
	{

		clsTransferScreen::ShowTransferScreen();
	}


	static void _ShowTranferLogScreen()
	{

		clsTranferLogScreen::ShowTranferLogScreen();
	}

	static void _DoingWhatChoisedInTransationMinue()
	{
		cout << left << setw(37) << "";
		short choice = clsInputValidate::ReadShortNumberBetween("Please choose what do you want to do \n", 1, 6);

		switch (choice)
		{
		case enTransation::Deposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;

		case enTransation::Withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		case enTransation::Showbalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionMenue();
			break;
		case enTransation::Transfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		case enTransation::TransferLog:
			system("cls");
			_ShowTranferLogScreen();
			_GoBackToTransactionMenue();
			break;


		case enTransation::Gotomeinmenieu:
			
		{ break; }
		default:
			system("cls");
			cout << " not a qultie number !! \n";
			_GoBackToTransactionMenue();
			break;

		}
	}

	static void _GoBackToTransactionMenue()
	{
		cout << "\npress any key to go to Transaction Menue...\n";
		cout << system("pause>0");
		ShowTransactionMenue();

	}

public:

	static void ShowTransactionMenue()
	{

		if (!_CheckAccesRichts(clsUser::enPermission::pTrnasAction))
		{

			cout << "\npress any key to go to Main menue\n";
			cout << system("pause>0");
			return;
		}
		system("cls");
		_DrawScreenHeader("Transaction Screen \n");


		cout << left << setw(37) << "" << "===============================================\n\n";
		cout << left << setw(37) << "" << "    T R N S A C T I O I N S   M E N U E            \n\n";
		cout << left << setw(37) << "" << "===============================================\n";
		cout << left << setw(37) << "" << "  [1] Deposit .\n";
		cout << left << setw(37) << "" << "  [2] Withdrew  \n";
		cout << left << setw(37) << "" << "  [3] Show The Balance.\n";
		cout << left << setw(37) << "" << "  [4] Transfer .\n";
		cout << left << setw(37) << "" << "  [5] Transfer Log .\n";
		cout << left << setw(37) << "" << "  [6] Go To Main Minue .\n";

		cout << left << setw(37) << "" << "=============================================\n\n\n";
		_DoingWhatChoisedInTransationMinue();

	}

};

