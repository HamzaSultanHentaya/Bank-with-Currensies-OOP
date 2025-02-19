#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;

class clsUpdateClientScreen :protected clsScreen

{
	static void _ReadClientInfo(clsBankClient& UpdateClient)
	{
		UpdateClient.setFirstName(clsUtil::ReadString("Please enter the First Name\n"));
		UpdateClient.setLastName(clsUtil::ReadString("Please enter the Last Name\n"));
		UpdateClient.setPhoneNumber(clsUtil::ReadString("Please enter the  Phone Number\n"));
		UpdateClient.setEmail(clsUtil::ReadString("Please enter the Email Adress\n"));
		UpdateClient.SetPinCode(clsUtil::ReadString("Please enter the PIN Code \n"));
		UpdateClient.SetAcountBalance(clsInputValidate::ReadFloatNumberBetween("Please enter the Balance\n", 0, 10000000));



	}


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
	static void ShowUpdateClientScreen()
	{

		if (!_CheckAccesRichts(clsUser::enPermission::pUpdateClient))
		{
			return;
		}
		_DrawScreenHeader("Update Client Screen");


		string Acountnumber = clsUtil::ReadString("Please enter the Acount Number\n");
		while (!clsBankClient::IsClientExist(Acountnumber))
		{
			cout << "Acount Number is not exist \n Please enter another Acount Number\n";
			Acountnumber = clsUtil::ReadString("Enter an Acount Number \n");

		}
		clsBankClient Client1 = clsBankClient::Find(Acountnumber);
		_PrintClientInfo(Client1);

		char del = 'n';
		cout << "Are you sure you want to Update this Acount? Yes(Y)/ No(N)\n";
		cin >> del;
		if (del == 'y' || del == 'Y')
		{




			_ReadClientInfo(Client1);


			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client1.Save();


			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSacceeded:

			{
				cout << "\n\nAcount update is succeeded :-)";
				_PrintClientInfo(Client1);
				break;
			}

			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "Acount update is not succeeded, becouse its empty :-( \n";
				break;
			}

			default:
				break;
			}
		}
		else {
			return;
		}
	}

};



