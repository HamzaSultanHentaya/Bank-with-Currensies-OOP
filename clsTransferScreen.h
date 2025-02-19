#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;
class clsTransferScreen :protected clsScreen

{
	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "\n\nClient Infos ";
		cout << "\n========================================\n";

		cout << "Full Name     : " << Client.FirstName() << " " << Client.LastName() << endl;

		cout << "AcountNumber  :" << Client.AcountNumber() << endl;

		cout << "Balance       :" << Client.AcountBalance() << endl;
		cout << "===========================================\n";
	}

	static clsBankClient _FindAndPrintClientInfo(string Acountnumber)
	{
		while (!clsBankClient::IsClientExist(Acountnumber))
		{
			cout << "Acount Number is not exist \n Please enter another Acount Number\n";
			Acountnumber = clsUtil::ReadString("");

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
		return Client1;
	}

	static void _TransferAction(clsBankClient& Sender, clsBankClient& Receiver)
	{

		double Amount = clsInputValidate::ReadDoubleNumberBetween("\n\nPlease enter how much you want to transfer\n", 0, 999000);
		while (Amount > Sender.AcountBalance())
		{
			cout << "The Amount is more than the Balance !!\n your Balance is " << Sender.AcountBalance() << endl;
			cout << "Please enter Amount, which is less than or equal to "
				<< Sender.AcountBalance() << endl;
			Amount = clsInputValidate::ReadDoubleNumberBetween("", 0, Sender.AcountBalance());

		}

		char del = 'n';
		cout << "Are you sure you want to transfer this Amount? Yes(Y)/ No(N)\n";
		cin >> del;
		if ((del == 'y' || del == 'Y') && Sender.Transfer(Receiver, Amount))
		{

			cout << "\n\nTransfer was succesfully\n\n";
			cout << "Acounts After Trasfer \n";
			_PrintClientInfo(Sender);
			cout << endl << endl;
			_PrintClientInfo(Receiver);

		}
		else
		{
			cout << "Transfer was cancelled\n";
		}
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screem");

		string Sender = clsUtil::ReadString("\n\nPlease enter the Acount Number to transfer from\n");

		clsBankClient SenderClient = _FindAndPrintClientInfo(Sender);

		string Receiver = clsUtil::ReadString("Please enter the Acount Number to transfer to\n");
		while (Sender == Receiver)
		{
			{
				cout << "Acount Number of Reciever is same Acount Number of Sender!! \n";
				Receiver = clsUtil::ReadString(" Please enter another Acount Number\n");

			}

		}
		clsBankClient ReceiverClient = _FindAndPrintClientInfo(Receiver);

		_TransferAction(SenderClient, ReceiverClient);

	}



};

