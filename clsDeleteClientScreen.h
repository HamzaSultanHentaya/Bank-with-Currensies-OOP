#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUtil.h"

#include"clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen :protected clsScreen
{
	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "\n\nClient Infos ";
		cout << "\n========================================\n";
		cout << "First Name    : " << Client.FirstName() << endl;
		cout << "Last Name     : " << Client.LastName() << endl;
		cout << "Full Name     : " << Client.FirstName() << " " << Client.LastName() << endl;
		cout << "Email         : " << Client.Email() << endl;
		cout << "Telefon       : " << Client.PhoneNumber() << endl;
		cout << "AcountNumber  :" << Client.AcountNumber() << endl;
		cout << "PinCode       :" << Client.PinCode() << endl;
		cout << "Balance       :" << Client.AcountBalance() << endl;
		cout << "===========================================\n";
	}


public:
	static void ShowDeleteClientScreen()
	{

		if (!_CheckAccesRichts(clsUser::enPermission::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("Delete Client Screen");


		string Acountnumber = clsUtil::ReadString("Please enter the Acount Number\n");
		while (!clsBankClient::IsClientExist(Acountnumber))
		{
			cout << "Acount Number is not exist \n Please enter another Acount Number\n";
			Acountnumber = clsUtil::ReadString("Enter an Acount Number \n");

		}
		clsBankClient DeleteClient1 = clsBankClient::Find(Acountnumber);
		_PrintClientInfo(DeleteClient1);

		char del = 'n';
		cout << "Are you sure you want to delete this Acount? Yes(Y)/ No(N)\n";
		cin >> del;
		if (del == 'y' || del == 'Y')
		{
			if (DeleteClient1.Delete())
			{
				cout << "Acount is successfully deleted\n ";
				_PrintClientInfo(DeleteClient1);
			}
			else {
				cout << "Acount was not deleted \n";
			}
		}
	}

};

