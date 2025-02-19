#pragma once
#include<iostream>
#include"clsCurrencyExchageMainScreen.h"
#include"clsInputValidate.h"


class clsUpdateCurrencyScreen :protected clsScreen
{



	static void _Print(clsCurrancy CurrencyInfo)//Overriding base Function.
	{


		cout << "\n\nCurrency Infos ";
		cout << "\n========================================\n";
		cout << "Country Name     : " << CurrencyInfo.Country() << endl;
		cout << "Currency Code    : " << CurrencyInfo.CurrencyCode() << endl;
		cout << "Currency Namae   : " << CurrencyInfo.CurrencyName() << endl;
		cout << "Rate (1$)        : " << CurrencyInfo.Rate() << endl;

		cout << "===========================================\n";
	}

	static void _UpdateRate(clsCurrancy updateRate)
	{

		char answer = 'n';
		cout << "\nAre you sure you want to update the Rate\n";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			updateRate.UpdateRate(clsInputValidate::ReadFloatNumberBetween("\n\nPlease enter the new Rate\n", 0, 999999));
			cout << "\n\nCurrency was updated succefully. \n ";
			_Print(updateRate);
		}
		else
		{
			return;
		}
	}

	static void _ShowResults(clsCurrancy curr)
	{
		if (!curr.IsEmpty())
		{
			cout << "\n\nCurrency was found :-)\n";
			_Print(curr);
			_UpdateRate(curr);
		}
		else
		{
			cout << "\n\nCurrency was not found :-(\n";
			_Print(curr);
		}

	}







public:

	static void ShowUpdateCurrenciesScreen()
	{
		_DrawScreenHeader("Update Currency Screen ");
		cout << "  " << left << setw(33) << "";
		string CurrencyCode = clsUtil::ReadString("\nPlease enter the Currency Code\n");



		while (!clsCurrancy::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency Code was not found !\n please enter a validate Code\n";
			CurrencyCode = clsUtil::ReadString("");

		}
		clsCurrancy Currency = clsCurrancy::FindByCurrencyCode(CurrencyCode);

		_ShowResults(Currency);



	}



};

