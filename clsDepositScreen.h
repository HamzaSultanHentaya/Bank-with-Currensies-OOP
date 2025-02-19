#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsMainScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsDepositScreen :protected clsScreen
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
	static string _ReadAcountNumber()
	{
		return clsUtil::ReadString("Please enter the Acount Number\n");
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");



		string Acountnumber = _ReadAcountNumber();


		while (!clsBankClient::IsClientExist(Acountnumber))
		{
			cout << "Acount Number is not exist \n Please enter another Acount Number\n";
			Acountnumber = clsUtil::ReadString("Enter an Acount Number \n");

		}
		clsBankClient Client1 = clsBankClient::Find(Acountnumber);
		_PrintClientInfo(Client1);
		double Amount = clsInputValidate::ReadDoubleNumberBetween("\n\nPlease enter how much you want to deposit\n", 1, 1000000);
		char del = 'n';
		cout << "Are you sure you want to deposit thie Amount? Yes(Y)/ No(N)\n";
		cin >> del;
		if (del == 'y' || del == 'Y')
		{

			Client1.Deposit(Amount);
			cout << "Deposit was succesfully\n";
			cout << "Balance after deposit = " << Client1.acountBalance << endl;
		}
		else
		{
			cout << "Deposti was cancelled\n";
		}



	}
};

