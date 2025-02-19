#pragma once

#include<iostream>
#include"Global.h"
#include"clsScreen.h"
#include"vector"
#include"clsBankClient.h"
#include"clsTransactionScreen.h"
using namespace std;

class clsTranferLogScreen :protected clsScreen
{


	static void _PrintTransferLogInLine(clsBankClient::stTransferLog Action)
	{


		cout << "  " << left << setw(20) << Action.DateAndTime;
		cout << "  " << left << setw(12) << "| " + Action.Sender;
		cout << "  " << left << setw(12) << "| " + Action.Receiver;
		cout << "  " << left << setw(15) << "| " + to_string(Action.Amount);
		cout << "  " << left << setw(15) << "| " + to_string(Action.SenderBalance);
		cout << "  " << left << setw(15) << "| " + to_string(Action.ReceiverBalance);
		cout << "  " << left << setw(15) << "| " + Action.UserName << endl;



	}




public:








	static void ShowTranferLogScreen()
	{
		system("cls");

		vector<clsBankClient::stTransferLog>TransferLogList = clsBankClient::GetTransferLogList();
		string Title = "\t  Transfer Log Screen";
		string SubTitle = "\t  (" + to_string(TransferLogList.size()) + ") Transfer(s) Action. \n";
		_DrawScreenHeader(Title, SubTitle);
		if (TransferLogList.size() == 0)
		{
			cout << "There are no Transfers saved in File \n";
		}
		else
		{


			cout << "___________________________________________________________";
			cout << "___________________________________________________________\n";


			cout << "  " << left << setw(20) << "Date -- Time ";
			cout << "  " << left << setw(12) << "| Sender";
			cout << "  " << left << setw(12) << "| Receiver";
			cout << "  " << left << setw(15) << "| Amount";
			cout << "  " << left << setw(15) << "| S-Balance";
			cout << "  " << left << setw(15) << "| R-Balance";
			cout << "  " << left << setw(15) << "| User Name" << endl;

			cout << "_________________________________________________________";
			cout << "_____________________________________________________________\n";



			for (clsBankClient::stTransferLog TransferAct : TransferLogList)
			{
				_PrintTransferLogInLine(TransferAct);
			}
		}
		cout << "\n________________________________________________________";
		cout << "_____________________________________________________________\n";





	}







};

