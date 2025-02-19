#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;


class clsAddNewClientScreen :protected clsScreen
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


	static void ShowAddClientScreen()
	{

		if (!_CheckAccesRichts(clsUser::enPermission::pAddClient))
		{
			return;
		}
		clsScreen::_DrawScreenHeader("Add New Client Screen");



		string Acountnumber = clsUtil::ReadString("Please enter the Acount Number\n");
		while (clsBankClient::IsClientExist(Acountnumber))
		{
			cout << "Acount Number is used \n Please enter another Acount Number\n";
			Acountnumber = clsUtil::ReadString("Enter an Acount Number \n");

		}


		clsBankClient NewClient = clsBankClient::GreatNewClientObject(Acountnumber);
		_ReadClientInfo(NewClient);



		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSacceeded:

		{
			cout << "\n\nAdding a new Client is succeeded :-)";
			_PrintClientInfo(NewClient);

			break;
		}

		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "Adding a new Client is not succeeded, becouse its empty :-( \n";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAcountNumberExist:
		{
			cout << "Acout Number is exist \n Adding a new Client faild \n";
			break;

		}

		default:
			break;
		}



	}
};

