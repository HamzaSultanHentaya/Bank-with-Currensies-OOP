
#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsMainScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsWithdrawScreen :protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");



		string Acountnumber = _ReadAcountNumber();


		while (!clsBankClient::IsClientExist(Acountnumber))
		{
			cout << "Acount Number is not exist \n Please enter another Acount Number\n";
			Acountnumber = clsUtil::ReadString("Enter an Acount Number \n");

		}
		clsBankClient Client1 = clsBankClient::Find(Acountnumber);
		_PrintClientInfo(Client1);
		double Amount = clsInputValidate::ReadDoubleNumberBetween("\n\nPlease enter how much you want to withdraw\n", 1, 990000);
		while (Amount > Client1.AcountBalance())
		{
			cout << "The Amount is more than the Balance !!\n your Balance is " << Client1.AcountBalance() << endl;
			cout << "Please enter Amount, which is less than or equal to "
				<< Client1.AcountBalance() << endl;
			Amount = clsInputValidate::ReadDoubleNumberBetween("", 1, Client1.AcountBalance());

		}

		char del = 'n';
		cout << "Are you sure you want to withdraw thie Amount? Yes(Y)/ No(N)\n";
		cin >> del;
		if ((del == 'y' || del == 'Y') && Client1.Withdraw(Amount))
		{
			cout << "withdraw was succesfully\n";
			cout << "Balance after withraw = " << Client1.acountBalance << endl;
		}
		else
		{
			cout << "Withraw was cancelled\n";
		}



	}
};



