#pragma once
#include"clsUser.h"
#include<iostream>
#include"clsScreen.h"
class clsUsersListScreen : protected clsScreen
{

	static void _PrintUserInfoInLine(clsUser User)
	{


		cout << "  " << left << setw(13) << " " + User.UserName();
		cout << "  " << left << setw(17) << "| " + User.FirstName() + " " + User.LastName();
		cout << "  " << left << setw(12) << "| " + User.Password();
		cout << "  " << left << setw(27) << "| " + User.Email();
		cout << "  " << left << setw(18) << "| " + User.PhoneNumber();
		cout << "  " << left << setw(15) << "| " + to_string(User.Permissions()) << endl;

	}



public:
	static void ShowUsersListScreen()
	{



		vector<clsUser>vUser = clsUser::GetUsersList();
		string Title = "\t  User List Screen";
		string SubTitle = "\t  (" + to_string(vUser.size()) + ") Users(s). \n";
		_DrawScreenHeader(Title, SubTitle);
		if (vUser.size() == 0)
		{
			cout << "There are no Users saved in File \n";
		}
		else {


			cout << "___________________________________________________________";
			cout << "___________________________________________________________\n";


			cout << "  " << left << setw(13) << "User Name";
			cout << "  " << left << setw(17) << "| User Full Name";
			cout << "  " << left << setw(12) << "| Password";
			cout << "  " << left << setw(27) << "| Email adress";
			cout << "  " << left << setw(18) << "| Phone Number ";
			cout << "  " << left << setw(15) << "| Permission" << endl;
			cout << "_________________________________________________________";
			cout << "_____________________________________________________________\n";



			for (clsUser User : vUser)
			{
				_PrintUserInfoInLine(User);
			}
		}
		cout << "\n________________________________________________________";
		cout << "_____________________________________________________________\n";



	}







};

