#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsMainScreen.h"
using namespace std;
class clsTotalBalanceScreen : protected clsScreen
{
	static void _PrintBalanceForm()
	{

		cout << left << setw(16) << " " << "__________________________________";
		cout << "_____________________________________________________\n\n";
		cout << left << setw(16) << " " << left << setw(16) << "| Acount Number";
		cout << left << setw(25) << "| Client Name  ";
		cout << left << setw(10) << "| Balance \n";
		cout << left << setw(16) << " " << "__________________________________";
		cout << "_____________________________________________________\n";
	}

	static void _PrintClientsBalanceInLine(clsBankClient Client)
	{
		cout << left << setw(16) << " " << left << setw(16) << "| " + Client.AcountNumber();
		cout << left << setw(25) << "| " + Client.FirstName() + " " + Client.LastName();

		cout << left << setw(10) << "| " + to_string(Client.AcountBalance()) << endl;

	}

public:

	static void ShowTotalBalanceScreen()
	{

		vector<clsBankClient>vClients = clsBankClient::GetClientsList();

		_DrawScreenHeader("Total Balance Screen", "Client(s) " + to_string(vClients.size()));
		_PrintBalanceForm();
		double totalbalance = 0;
		totalbalance = clsBankClient::GetTotalBalance();
		if (vClients.size() == 0)
		{
			cout << "No Clients are saved \n Balance = 0";
			return;
		}
		else {
			for (clsBankClient client : vClients)
			{
				_PrintClientsBalanceInLine(client);


			}
			cout << "\n___________________________________________________________";
			cout << "__________________________________________________________\n";
			cout << "              Total Balances = " << totalbalance << endl;
			cout << "              " << clsUtil::NumberToText(totalbalance) << endl;
		}

	}


};

