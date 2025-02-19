#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"

using namespace std;

class clsClientsListScreen :protected clsScreen
{
	static void _PrintClientInfoInLine(clsBankClient Client)
	{


		cout << "  " << left << setw(13) << " " + Client.AcountNumber();
		cout << "  " << left << setw(17) << "| " + Client.FirstName() + " " + Client.LastName();
		cout << "  " << left << setw(12) << "| " + Client.PinCode();
		cout << "  " << left << setw(27) << "| " + Client.Email();
		cout << "  " << left << setw(18) << "| " + Client.PhoneNumber();
		cout << "  " << left << setw(15) << "| " + to_string(Client.AcountBalance()) << endl;

	}
public:
	static void PrintListOfClients()
	{
		if (!_CheckAccesRichts(clsUser::enPermission::pListOfClient))
		{
			return;
		}
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		string Title = "\t  Client List Screen";
		string SubTitle = "\t  (" + to_string(vClients.size()) + ") Client(s). \n";
		_DrawScreenHeader(Title, SubTitle);
		if (vClients.size() == 0)
		{
			cout << "There are no Clients saved in File \n";
		}
		else {


			cout << "___________________________________________________________";
			cout << "___________________________________________________________\n";


			cout << "  " << left << setw(13) << "Acount Number";
			cout << "  " << left << setw(17) << "| Clint Name  ";
			cout << "  " << left << setw(12) << "| PIN Code";
			cout << "  " << left << setw(27) << "| Email adress ";
			cout << "  " << left << setw(18) << "| Phone Number ";
			cout << "  " << left << setw(15) << "| Balance" << endl;
			cout << "_________________________________________________________";
			cout << "_____________________________________________________________\n";



			for (clsBankClient client : vClients)
			{
				_PrintClientInfoInLine(client);
			}
		}
		cout << "\n________________________________________________________";
		cout << "_____________________________________________________________\n";



	}
};

