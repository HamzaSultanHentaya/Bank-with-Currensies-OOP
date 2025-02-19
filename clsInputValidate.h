#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
class clsInputValidate
{
public:

    static bool IsNumberBetween(short num, short from, short to)
    {

        return (num <= to && num >= from);
    }
    static bool IsNumberBetween(int num, int from, int to)
    {
        return (num <= to && num >= from);
    }
    static bool IsNumberBetween(float num, float from, float to)
    {
        return (num <= to && num >= from);
    }
    static bool IsNumberBetween(double num, double from, double to)
    {
        return (num <= to && num >= from);
    }

    static bool IsDateBetween(clsDate date1, clsDate dateBeginn, clsDate dateEnd)
    {
        date1 = clsDate::clsDate();
        if (!clsDate::IsDateLessOrNot(dateBeginn, dateEnd))
        {
            clsDate::SwapTwodates(dateBeginn, dateEnd);
        }
        return (clsDate::IsDatewithinPeriod(dateBeginn, dateEnd, date1));


    }

    static int ReadIntegerNumber(string massege)
    {
        int num = 0;
        cout << massege << endl;
        cin >> num;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid number!\n Please enter a valid Number " << endl;
            cin >> num;
        }
        return num;
    }

    static int ReadIntegerNumberBetween(string massege, int from, int to)
    {
        int num = 0;
        cout << massege << endl;
        cin >> num;
        while (cin.fail() || !IsNumberBetween(num, from, to))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid number!\n Please enter a number between " << from << " and " << to << endl;
            cin >> num;
        }
        return num;
    }

    static short ReadShortNumberBetween(string massege, short from, short to)
    {
        short num = 0;
        cout << massege << endl;
        cin >> num;
        while (cin.fail() || !IsNumberBetween(num, from, to))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid number!\n Please enter a number between " << from << " and " << to << endl;
            cin >> num;
        }
        return num;
    }

    static float ReadFloatNumberBetween(string massege, float from, float to)
    {
        float num = 0;
        cout << massege << endl;
        cin >> num;
        while (cin.fail() || !IsNumberBetween(num, from, to))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid number!\n Please enter a number between " << from << " and " << to << endl;
            cin >> num;
        }
        return num;
    }

    static double ReadDoubleNumberBetween(string massege, double from, double to)
    {
        double num = 0;
        cout << massege << endl;
        cin >> num;
        while (cin.fail() || !IsNumberBetween(num, from, to))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid number!\n Please enter a number between " << from << " and " << to << endl;
            cin >> num;
        }
        return num;
    }

    static bool IsValideDate(clsDate date)
    {
        return clsDate::IsValidateDate(date);
    }


};

