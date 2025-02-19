
#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;

class clsFindClient :protected clsScreen
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
	static void ShowFindClientScreen()
	{

		if (!_CheckAccesRichts(clsUser::enPermission::pFindCliente))
		{
			return;
		}
		_DrawScreenHeader("Find Client Screen");


		string Acountnumber = clsUtil::ReadString("Please enter the Acount Number\n");
		while (!clsBankClient::IsClientExist(Acountnumber))
		{
			cout << "Acount Number is not exist \n Please enter another Acount Number\n";
			Acountnumber = clsUtil::ReadString("Enter an Acount Number \n");

		}
		clsBankClient Client1 = clsBankClient::Find(Acountnumber);
		if (!Client1.IsEmpty())
		{
			cout << "Client found :-) \n";
		}
		else
		{
			cout << "Client was not found :-(\n";
		}
		_PrintClientInfo(Client1);
	}
};

