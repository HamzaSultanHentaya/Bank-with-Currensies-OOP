#pragma once
#include<iostream>
#include"clsCurrancy.h"
#include"clsMainScreen.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsCurrencyList.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrenciesCalculateScreen.h"


class clsCurrencyExchageMainScreen :protected clsScreen
{

	enum enCurrencyOption { eShowCurrencyList = 1, eFindCurrency = 2, eUpdatCurrency = 3, eCurrencyCalculate = 4, eGoBach = 5 };


	static void _PrintShowScreen()
	{
		cout << left << setw(37) << "" << "=============================================\n";
		cout << left << setw(45) << "" << "  Currency Exchange Menue \n";
		cout << left << setw(37) << "" << "=============================================\n";

		cout << left << setw(37) << "" << "  [1] Show List Currencies .\n";
		cout << left << setw(37) << "" << "  [2] Find Currency . \n";
		cout << left << setw(37) << "" << "  [3] Update Rate .\n";
		cout << left << setw(37) << "" << "  [4] Currency Claculator .\n";
		cout << left << setw(37) << "" << "  [5] Go back to Main Menue .\n";
		cout << left << setw(37) << "" << "=============================================\n\n";
		cout << left << setw(37) << "" << "Chose what do you want to do..? [1 to 5]?";


	}

	static void _ShowCurrencyListScreen()
	{
		clsCurrencyList::ShowCurrencyListScreen();


	}
	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();


	}
	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyScreen::ShowUpdateCurrenciesScreen();


	}
	static void _ShowCurrencyClculatorScreen()
	{
		clsCurrenciesCalculateScreen::ShowCurrenciesCalculateScreen();


	}

	static void _GoBackToExchangeMainMenue()
	{
		cout << "\npress any key to go to Main menue\n";
		cout << system("pause>0");
		ShowCurrencyExchangeScreen();

	}

	static void _PerformCurrenciesMeinMenue(enCurrencyOption choice)
	{
		switch (choice)
		{
		case enCurrencyOption::eShowCurrencyList:
			system("cls");
			_ShowCurrencyListScreen();
			_GoBackToExchangeMainMenue();
			break;

		case enCurrencyOption::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToExchangeMainMenue();
			break;
		case enCurrencyOption::eUpdatCurrency:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToExchangeMainMenue();
			break;
		case enCurrencyOption::eCurrencyCalculate:
			system("cls");
			_ShowCurrencyClculatorScreen();
			_GoBackToExchangeMainMenue();
			break;

		case enCurrencyOption::eGoBach:

			break;

		default:
			system("cls");
			cout << " not a qultie number !! \n";

			break;

		}



	}



public:


	static void ShowCurrencyExchangeScreen()

	{

		if (!_CheckAccesRichts(clsUser::enPermission::pCurrency))
		{

			cout << "\npress any key to go to Main menue\n";
			cout << system("pause>0");
			return;
		}

		system("cls");
		_DrawScreenHeader("Currency Exchange Scrren");
		_PrintShowScreen();
		_PerformCurrenciesMeinMenue(enCurrencyOption(clsInputValidate::ReadShortNumberBetween("", 1, 5)));




	}

};

