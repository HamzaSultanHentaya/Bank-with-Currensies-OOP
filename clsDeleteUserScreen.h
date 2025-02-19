#pragma once
#include<iostream>
#include"clsUser.h"
class clsDeleteUserScreen :protected clsScreen
{

	static void _PrintUserInfo(clsUser User1)
	{
		cout << "\n\nUser Infos ";
		cout << "\n========================================\n";
		cout << "First Name    : " << User1.FirstName() << endl;
		cout << "Last Name     : " << User1.LastName() << endl;
		cout << "Full Name     : " << User1.FirstName() << " " << User1.LastName() << endl;
		cout << "Email         : " << User1.Email() << endl;
		cout << "Telefon       : " << User1.PhoneNumber() << endl;
		cout << "User Name     :" << User1.UserName() << endl;
		cout << "Password       :" << User1.Password() << endl;
		cout << "Permissions       :" << User1.Permissions() << endl;
		cout << "===========================================\n";
	}




public:
	static void ShowDeleteUserScreen()
	{


		_DrawScreenHeader("Delete User Screen");


		string Acountnumber = clsUtil::ReadString("Please enter the User Name\n");
		while (!clsUser::IsUserExist(Acountnumber))
		{
			cout << "User Name is not exist \n Please enter another User Name\n";
			Acountnumber = clsUtil::ReadString(" ");

		}
		clsUser DeleteUser = clsUser::Find(Acountnumber);
		_PrintUserInfo(DeleteUser);

		char del = 'n';
		cout << "Are you sure you want to delete this User ? Yes(Y)/ No(N)\n";
		cin >> del;
		if (del == 'y' || del == 'Y')
		{
			if (DeleteUser.Delete())
			{
				cout << "User is successfully deleted\n ";
				_PrintUserInfo(DeleteUser);
			}
			else {
				cout << "User was not deleted \n";
			}
		}


	}


};

