#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsCurrancy.h"
#include"clsInputValidate.h"



class clsCurrenciesCalculateScreen :protected clsScreen

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

	static clsCurrancy _CheckCurrencyCode(string Code)
	{
		while (!clsCurrancy::IsCurrencyExist(Code))
		{
			cout << "Currency Code was not found !\n please enter a validate Code\n";
			Code = clsUtil::ReadString("");

		}
		clsCurrancy Currency = clsCurrancy::FindByCurrencyCode(Code);

		_Print(Currency);

		return Currency;
	}
	static void _PrintCalcultionResults(float Amount, clsCurrancy CurrencyFrom, clsCurrancy CurrencyTo)
	{
		cout << "\n\nCurrency1(" << CurrencyFrom.CurrencyCode() << ") to (USD) = "
			<< CurrencyFrom.ConfertToDollar(Amount) << endl;
		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}


		cout << "\n\n (USD) to Currency2(" << CurrencyTo.CurrencyCode() << ") = "
			<< CurrencyFrom.ConfertToAnotherCurrency(Amount, CurrencyTo) << endl;
	}


public:



	static void ShowCurrenciesCalculateScreen()
	{

		char countinue = 'y';
		while (countinue == 'y' || countinue == 'Y')
		{



			_DrawScreenHeader("Calculate Currency Screen ");
			cout << "  " << left << setw(33) << "";
			string CurrencyCode1 = clsUtil::ReadString("\nPlease enter the Currency1 Code (from)\n");
			clsCurrancy Currency1 = _CheckCurrencyCode(CurrencyCode1);

			cout << " Currency to change \n__________________\n";
			cout << "  " << left << setw(33) << "";
			string CurrencyCode2 = clsUtil::ReadString("\nPlease enter the Currency2 Code(to)\n");
			clsCurrancy Currency2 = _CheckCurrencyCode(CurrencyCode2);

			float Amount = clsInputValidate::ReadFloatNumberBetween("How much should calculate (Amount) ?\n", 0, 999999);

			_PrintCalcultionResults(Amount, Currency1, Currency2);


			cout << "\n Do you want to do another calculate ?\n";
			cin >> countinue;




		}


	}

};

