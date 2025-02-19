#pragma once
#include<iostream>
#include"clsCurrencyExchageMainScreen.h"
#include"clsInputValidate.h"


class clsFindCurrencyScreen :protected clsScreen

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
	static void _ShowResults(clsCurrancy curr)
	{
		if (!curr.IsEmpty())
		{
			cout << "\n\nCurrency was found :-)\n";
			_Print(curr);
		}
		else
		{
			cout << "\n\nCurrency was not found :-(\n";
			_Print(curr);
		}

	}







public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen ");
		cout << "  " << left << setw(33)
			<< "Find Currency by : [1] Country  or [2] Currency Code (2)? \n";
		short num = clsInputValidate::ReadShortNumberBetween("", 1, 2);

		if (num == 1)
		{
			clsCurrancy Currency = clsCurrancy::FindByCountry
			(clsUtil::ReadString("\nPlease enter the Country Name\n "));
			_ShowResults(Currency);
		}
		else
		{
			clsCurrancy Currency = clsCurrancy::FindByCurrencyCode
			(clsUtil::ReadString("\nPlease enter the Currency Code\n"));
			_ShowResults(Currency);
		}


	}


};

