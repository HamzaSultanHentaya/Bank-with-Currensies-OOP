

#pragma once
#include<iostream>
#include<vector>
#include <iomanip>

using namespace std;


class clsString
{
	string _Value;
public:
	clsString()
	{
		_Value = "";
	}

	clsString(string value)
	{
		_Value = value;
	}

	void SetString(string value)
	{
		_Value = value;
	}

	string GetString()
	{
		return _Value;
	}

	__declspec(property(get = GetString, put = SetString)) string valuee;

	static	string UpperFirstLetter(string& str)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter == true)
			{
				str[i] = toupper(str[i]);
			}isFirstLetter = (str[i] == ' ') ? true : false;
		}return str;
	}
	void UpperFirstLetter()
	{
		_Value = UpperFirstLetter(_Value);
	}

	static void PrintStringLength(string str)
	{
		cout << str.length() << endl;
	}
	void PrintStringLength()
	{
		PrintStringLength(_Value);
	}


	static short CountAllLetters(string str)
	{
		short counter = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if ((str[i]) != ' ')
				counter++;
		}return counter;
	}
	short CountAllLetters()
	{
		return CountAllLetters(_Value);
	}


	static short countWordsInString(string str)
	{
		string delim = " ", word = " ";
		short pos = 0, counter = 0;
		while ((pos = str.find(delim)) != std::string::npos)
		{
			word = str.substr(0, pos);

			if (word != "")//no space,otherwise will be wrong.
			{
				counter++;
			}
			str.erase(0, pos + delim.length());
		}


		if (str != "")//no space,otherwise will be wrong.
			counter++;
		return counter;

	}
	short countWordsInString()
	{
		return countWordsInString(_Value);
	}

	static void PrintWordsVertically(string str)
	{
		string delim = " ", word = " ";
		short pos = 0;
		while ((pos = str.find(delim)) != std::string::npos)
		{
			word = str.substr(0, pos);
			if (word != "")
			{
				cout << word << endl;

			}
			str.erase(0, pos + delim.length());
			//str.replace(from,word.length(),newword)//it will replace words.
		}
		if (str != " ")
			cout << str << endl;
	}

	void PrintWordsVertically()
	{
		PrintWordsVertically(_Value);
	}



	static void PrintFirstLetter(string str)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter == true)
			{
				cout << str[i] << endl;
			}isFirstLetter = (str[i] == ' ') ? true : false;
		}
	}
	void PrintFirstLetter()
	{
		PrintFirstLetter(_Value);
	}



	static string LowerFirstLetter(string& str)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter == true)
			{
				str[i] = tolower(str[i]);
			}isFirstLetter = (str[i] == ' ') ? true : false;
		}return str;
	}
	void LowerFirstLetter()
	{
		_Value = LowerFirstLetter(_Value);

	}

	static	string AllLetterToUpper(string& str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		return str;
	}
	void AllLetterToUpper()
	{
		_Value = AllLetterToUpper(_Value);

	}

	static string AllLetterToLower(string& str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}return str;
	}
	void AllLetterToLower()
	{
		_Value = AllLetterToLower(_Value);

	}

	static char InvertLetterCase(char ch)
	{
		return (isupper(ch)) ? tolower(ch) : toupper(ch);
	}


	static string InvertStringCase(string& str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = InvertLetterCase(str[i]);

		}return str;
	}

	void  InvertStringCase()
	{
		_Value = InvertStringCase(_Value);
	}



	static short CountCapitalLetters(string str)
	{
		short counter = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (isupper(str[i]))
				counter++;
		}return counter;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string str)
	{
		short counter = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (islower(str[i]))
				counter++;
		}return counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountTimeIsCharackterRepeated(string str, char ch)
	{
		short counter = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] == ch)
				counter++;
		}return counter;
	}
	short CountTimeIsCharackterRepeated()
	{
		return CountTimeIsCharackterRepeated(_Value, ' ');
	}

	static short HowManyTimeIsLetterCapitalOrSmallRepeated(string str, char ch)
	{
		short counter = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (tolower(str[i]) == ch || toupper(str[i]) == ch)
				counter++;
		}return counter;
	}
	short HowManyTimeIsLetterCapitalOrSmallRepeated()
	{
		return HowManyTimeIsLetterCapitalOrSmallRepeated(_Value, ' ');
	}

	static bool IsVowelLetter(char ch)
	{
		char vowel[5] = { 'a','e','i','u','o' };
		for (short i = 0; i < 5; i++)
		{
			if (tolower(ch) == vowel[i])
				return true;
		}return 0;
	}


	static short CountVowelLetters(string str)
	{
		short counter = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (IsVowelLetter(str[i]))
				counter++;
		}return counter;
	}
	short CountVowelLetters()
	{
		return CountVowelLetters(_Value);
	}



	static void PrintvowelLetters(string str)
	{

		for (short i = 0; i < str.length(); i++)
		{
			if (IsVowelLetter(str[i]))
				cout << setw(5) << str[i];
		}
	}
	void PrintvowelLetters()
	{
		PrintvowelLetters(_Value);
		cout << endl;
	}

	static string PrintWordsWithoutSpace(string str)
	{
		string word;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
				word += str[i];

		}return word;
	}
	void PrintWordsWithoutSpace()
	{
		_Value = PrintWordsWithoutSpace(_Value);
	}


	static string  TrimLift(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				return str.substr(i, str.length() - i);
			}
		}
	}
	void  TrimLift()
	{
		_Value = TrimLift(_Value);
	}

	static string TrimRight(string str)
	{
		for (short i = str.length(); i > 0; i--)
		{
			if (str[i - 1] != ' ')
				return str.substr(0, i);
		}
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string str)
	{

		return TrimLift(TrimRight(str));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static vector<string>  SplitString(string str, string delim)
	{
		vector<string> vWords;

		string word = " ";
		short pos = 0, counter = 0;
		while ((pos = str.find(delim)) != std::string::npos)
		{
			word = str.substr(0, pos);

			if (word != "")
			{
				vWords.push_back(word);
			}
			str.erase(0, pos + delim.length());
		}


		if (str != "")
		{

			vWords.push_back(str);
		}


		return vWords;

	}
	vector<string>  SplitString()
	{
		return SplitString(_Value, " ");
	}

	static string ReverseString(string str)
	{
		vector<string> vstr = SplitString(str, " ");
		string strArr = "";
		vector<string>::iterator iter = vstr.end();
		while (iter != vstr.begin())
		{
			iter--;
			strArr = strArr + (*iter) + " ";
		}
		return strArr.substr(0, strArr.length() - 1);
	}
	void ReverseString()
	{
		_Value = ReverseString(_Value);
	}

	static string ReplaceWordsInString(string str, string changeword, string newword)
	{
		short pos = str.find(changeword);
		while (str.find(changeword) != std::string::npos)
		{
			str = str.replace(pos, changeword.length(), newword);
			pos = str.find(changeword);
		}return str;
	}
	string ReplaceWordsInString()
	{
		return ReplaceWordsInString(_Value, "Hamza", "Sultan");
	}

	static string RemovePauncuations(string str)
	{
		string s;
		for (short i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i]))
				s += str[i];
		}return s;
	}
	void RemovePauncuations()
	{
		_Value = RemovePauncuations(_Value);
	}


};









