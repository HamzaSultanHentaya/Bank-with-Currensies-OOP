#pragma once
#include<iostream>
#include"clsCurrencyExchageMainScreen.h"
#include<vector>
#include<fstream>
#include"clsCurrancy.h"


class clsCurrencyList :protected clsScreen

{


	static void _PrintCurrencyInfoInLine(clsCurrancy Currency)
	{


		cout << "  " << left << setw(25) << " " + Currency.Country();

		cout << "  " << left << setw(17) << "| " + Currency.CurrencyCode();
		cout << "  " << left << setw(33) << "| " + Currency.CurrencyName();
		cout << "  " << left << setw(18) << "| " + to_string(Currency.Rate()) << endl;

	}




public:

	static void ShowCurrencyListScreen()
	{
		vector<clsCurrancy>vCurrencies = clsCurrancy::GetCurrenciesList();
		string Title = "\t  Currency List Screen";
		string SubTitle = "\t  (" + to_string(vCurrencies.size()) + ") Currencie(s). \n";
		_DrawScreenHeader(Title, SubTitle);
		if (vCurrencies.size() == 0)
		{
			cout << "There are no Currencies saved in File \n";
		}
		else {


			cout << "___________________________________________________________";
			cout << "___________________________________________________________\n";


			cout << "  " << left << setw(25) << "Country ";

			cout << "  " << left << setw(17) << "| Currency Code";
			cout << "  " << left << setw(33) << "| Currency Name ";
			cout << "  " << left << setw(18) << "| Rate to 1$ " << endl;
			cout << "_________________________________________________________";
			cout << "_____________________________________________________________\n";



			for (clsCurrancy currency : vCurrencies)
			{
				_PrintCurrencyInfoInLine(currency);
			}
		}
		cout << "\n________________________________________________________";
		cout << "_____________________________________________________________\n";












	}





};

