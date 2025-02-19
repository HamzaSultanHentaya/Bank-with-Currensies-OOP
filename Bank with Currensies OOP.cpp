

#include<vector>
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsBankClient.h"
#include"clsUtil.h"
#include"clsLoginScreen.h"
using namespace std;


int main()
{


	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	return 0;

}