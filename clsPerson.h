#pragma once
#include<iostream>

using namespace std;
class clsPerson
{

	string _FirstName, _LastName, _Email, _phone;

public:
	clsPerson()
	{}
	clsPerson(string FirstName, string LastName, string Email, string phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_phone = phone;

	}
	void setFirstName(string name)
	{
		_FirstName = name;
	}
	void setLastName(string lastname)
	{
		_LastName = lastname;
	}
	void setEmail(string email)
	{
		_Email = email;
	}
	void setPhoneNumber(string telefon)
	{
		_phone = telefon;
	}


	string FirstName() { return _FirstName; }
	string LastName() { return _LastName; }
	string Email() { return _Email; }
	string PhoneNumber() { return _phone; }

	__declspec(property(get = FirstName, put = setFirstName)) string name;
	__declspec(property(get = LastName, put = setLastName)) string lastname;
	__declspec(property(get = Email, put = setEmail)) string email;
	__declspec(property(get = PhoneNumber, put = setPhoneNumber)) string phone;


};


