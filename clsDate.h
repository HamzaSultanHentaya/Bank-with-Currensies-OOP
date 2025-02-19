
#pragma once
#pragma warning(disable : 4996 )
#include<iostream>
#include<ctime>
#include<string>
#include<vector>
using namespace std;
class clsDate
{
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

protected:
	vector<string>  SplitString(string str, string delim)
	{
		vector<string> vWords;

		string word = " ";
		short pos = 0;
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
	enum eDateCompare { After = 1, Equal = 0, Before = -1 };

public:
	clsDate()
	{
		time_t t = time(0);//get time now.

		tm* now = localtime(&t);//pointer of structer tm.
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;

	}
	clsDate(string StDate)
	{
		vector<string>_vDate = SplitString(StDate, "/");

		_Day = stoi(_vDate[0]);
		_Month = stoi(_vDate[1]);
		_Year = stoi(_vDate[2]);
	}
	clsDate(short day, short month, short year)
	{

		_Day = day;
		_Month = month;
		_Year = year;
	}
	clsDate(short days, short year)
	{
		clsDate datee = CalculateDateWithDaysNumber(days, year);
		_Day = datee._Day;
		_Month = datee._Month;
		_Year = datee._Year;


	}

	void Print()
	{
		cout << DateToString((*this)) << endl;
	}

	static string DateToString(clsDate d)
	{
		string _date;
		_date = to_string(d._Day) + "/" + to_string(d._Month) + "/" + to_string(d._Year);
		return _date;

	}
	string DateToString()
	{
		DateToString((*this));
	}

	void SetDay(short day)
	{
		_Day = day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;


	void SetMonth(short month)
	{
		_Month = month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short year)
	{
		_Year = year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	static void GetSystemDate()
	{
		time_t t = time(0);//get time now.

		tm* now = localtime(&t);//pointer of structer tm.
		short day, month, year;
		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;

		cout << to_string(day) + "/" + to_string(month) + "/" + to_string(year) << endl;


	}
	static string GetSystemDateTime()
	{
		time_t t = time(0);//get time now.

		tm* now = localtime(&t);//pointer of structer tm.
		string day = to_string(now->tm_mday);
		string month = to_string(now->tm_mon + 1);
		string year = to_string(now->tm_year + 1900);
		string hours = to_string(now->tm_hour);
		string minuts = to_string(now->tm_min);
		string secounds = to_string(now->tm_sec);

		return day + "/" + month + "/" + year + "--" + hours + ":" + minuts + ":" + secounds;


	}

	static bool IsValidateDate(clsDate date)
	{
		if (date._Year < 0)
		{
			return false;
		}
		if (date._Month <= 1 || date._Month > 12)
		{
			return false;
		}
		if (date._Day > HowManyDaysInMonth(date._Month, date._Year) || date._Day <= 0)
		{
			return false;
		}
		else
		{
			return true;
		}
		/*return ((date._Month >= 1 && date._Month <= 12) &&
					(date._Day <= HowManyDaysInMonth(date._Month, date._Year) && date._Day > 0) &&
					(date._Year > 0));*/
	}

	bool IsValidateDate()
	{
		return (IsValidateDate(*this));
	}


	static void PrintMonthCalender(short Month, short Year)
	{

		short dayNumber = DayNumberInWeak(Year, Month, 1);

		short DaysOfMonth = HowManyDaysInMonth(Month, Year);
		//(c_str()) for Printing string in printf becouse printf can not print string text.
		printf("_______________%s___________________\n\n", PrintMonthName(Month).c_str());
		printf("  Sun  Mon  Tus  Win  Thu  Fri  Sat  \n");

		short i = 0;
		for (i; i < dayNumber; i++)
		{
			printf("     ");
		}

		for (short d = 1; d <= DaysOfMonth; d++)
		{
			printf("%5d", d);

			if (++i == 7)
			{
				printf("\n");
				i = 0;
			}



		}cout << "\n_______________________________________________" << endl;


	}
	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);
	}


	clsDate CalculateDateWithDaysNumber(short days, short year)
	{
		clsDate Date;
		Date._Year = year;
		Date._Month = 1;
		short remaindfromdays = 0, monthcounter = 0;
		while (true)
		{
			if (days > HowManyDaysInMonth(Date._Month, year))
			{
				days -= HowManyDaysInMonth(Date._Month, year);
				Date._Month++;
			}
			else
			{
				Date._Day = days;
				break;
			}

		}return Date;
	}

	static void PrintYearCalender(short year)
	{
		cout << "_____________________________________\n\n";
		cout << "________Calender of year " << year << "________\n";
		cout << "_____________________________________\n\n";
		for (short i = 1; i <= 12; i++)
		{

			PrintMonthCalender(i, year);
			cout << endl;
		}
	}
	void PrintYearCalender()
	{
		PrintYearCalender(_Year);
	}



	static bool IsLeapYear(int year)
	{

		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);


	}
	bool IsLeapYear()
	{
		IsLeapYear(_Year);
	}

	static short HowManyDaysInMonth(short Month, short Year)
	{
		return (Month < 1 || Month>12) ? 0 : (Month == 2) && (IsLeapYear(Year)) ? 29 : (Month == 2) ? 28 :
			(Month == 1) || (Month == 3) || (Month == 5) || (Month == 7) || (Month == 8)
			|| (Month == 10) || (Month == 12) ? 31 : 30;


	}
	short HowManyDaysInMonth()
	{
		HowManyDaysInMonth(_Month, _Year);
	}

	static short DayNumberInWeak(short year, short Month, short day)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = year - a;
		m = Month + (12 * a) - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayNumberInWeak()
	{
		DayNumberInWeak(_Year, _Month, _Day);
	}


	static string DayName(short d)
	{
		string dayName[7] = { "Sunday","Monday","Tusday","Winsday","Thersday","Friday","Saturday" };

		return dayName[d];
	}
	string DayName()
	{
		return DayName(_Day);
	}

	static string PrintMonthName(short Month)
	{
		string arr[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep"," Okt","Nov","Dez" };
		return arr[Month];
	}
	string PrintMonthName()
	{
		PrintMonthName(_Month);
	}


	static short CalculateDaysFromBeginOfTheYear(clsDate date)
	{
		short alldays = 0;
		for (short i = 1; i <= date._Month - 1; i++)
		{
			alldays += HowManyDaysInMonth(i, date._Year);
		}return alldays + date._Day;
	}
	short CalculateDaysFromBeginOfTheYear()
	{
		return CalculateDaysFromBeginOfTheYear(*this);
	}

	static bool IsLastDayInMonth(clsDate Date1)
	{
		short MonthDays = HowManyDaysInMonth(Date1._Month, Date1._Year);
		return Date1._Day == MonthDays;
	}
	bool IsLastDayInMonth()
	{
		IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return Month == 12;
	}
	bool IsLastMonthInYear()
	{
		IsLastMonthInYear(_Month);
	}

	static clsDate AddOneDay(clsDate& Date1)
	{
		if (IsLastDayInMonth(Date1))
		{

			if (IsLastMonthInYear(Date1._Month))
			{
				Date1._Day = 1;
				Date1._Month = 1;
				Date1._Year++;
			}

			else
			{
				Date1._Month++;
				Date1._Day = 1;
			}
		}
		else Date1._Day++;

		return Date1;
	}
	void AddOneDay()
	{
		AddOneDay(*this);


	}

	static bool IsDateLessOrNot(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true :
			(Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}
	bool IsDateLessOrNot(clsDate Date2)
	{
		return IsDateLessOrNot(*this, Date2);
	}

	static void CalculateAgeWithDays(short day, short month, short year)
	{
		clsDate Date1;
		Date1._Day = day;
		Date1._Month = month;
		Date1._Year = year;
		clsDate Date2 = GetSDate();
		int days = 0;
		while (IsDateLessOrNot(Date1, Date2))
		{
			days++;
			Date1 = AddOneDay(Date1);
		}cout << "Your Age with days = " << days;
	}

	static clsDate GetSDate()
	{
		clsDate Date2;
		time_t t = time(0);//get time now.

		tm* now = localtime(&t);//pointer of structer tm.

		Date2._Year = now->tm_year + 1900;
		Date2._Month = now->tm_mon + 1;
		Date2._Day = now->tm_mday;

		return Date2;
	}

	static short DaysOfYear(short year)
	{
		return (IsLeapYear(year)) ? 366 : 365;
	}
	short DaysOfYear()
	{
		DaysOfYear(_Year);
	}

	static short HoursOfYear(short year)
	{
		return DaysOfYear(year) * 24;
	}
	short HoursOfYear()
	{
		HoursOfYear(_Year);
	}

	static int MinutesOfYear(short year)
	{
		return HoursOfYear(year) * 60;
	}
	int MinutesOfYear()
	{
		MinutesOfYear(_Year);
	}

	static int SecoundsOfYear(short year)
	{
		return MinutesOfYear(year) * 60;
	}
	int SecoundsOfYear()
	{
		SecoundsOfYear(_Year);
	}


	static clsDate DateAfterAddingDays(clsDate& Date, short days)
	{

		short RemainderDays = CalculateDaysFromBeginOfTheYear(Date) + days;
		Date._Month = 1;

		while (true)
		{
			if (RemainderDays > HowManyDaysInMonth(Date._Month, Date._Year))
			{
				RemainderDays -= HowManyDaysInMonth(Date._Month, Date._Year);
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}

			}
			else
			{
				Date._Day = RemainderDays;
				break;
			}

		}
		return Date;
	}
	void DateAfterAddingDays(short days)
	{
		DateAfterAddingDays(*this, days);

	}

	static bool IsDatesAreEqual(clsDate Date1, clsDate Date2)
	{
		return (Date1._Day == Date2._Day) ? ((Date1._Month == Date2._Month) ?
			((Date1._Year == Date2._Year) ? true : false) : false) : false;
	}
	bool IsDatesAreEqual(clsDate Date2)
	{
		IsDatesAreEqual(*this, Date2);
	}

	static void SwapTwodates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;

	}
	void SwapTwodates(clsDate Date2)
	{
		SwapTwodates(*this, Date2);

	}

	static int CalculateDiffBetweenDates(clsDate Date1, clsDate Date2, bool IncludeLastDay = true)
	{
		int days = 0;
		if (IsDateLessOrNot(Date2, Date1))
		{
			SwapTwodates(Date1, Date2);
			IncludeLastDay = false;
		}
		while (IsDateLessOrNot(Date1, Date2))
		{
			days++;
			Date1 = AddOneDay(Date1);
		}

		return (IncludeLastDay) ? days + 1 : (days + 1) * -1;
	}
	int CalculateDiffBetweenDates(clsDate Date2, bool IncludeLastDay = true)
	{
		CalculateDiffBetweenDates(*this, Date2, IncludeLastDay = true);
	}

	static  clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (Date._Month == 12)
			{
				Date._Month = 1;
				Date._Year++;
				Date._Day = HowManyDaysInMonth(Date._Month, Date._Year);
			}


			else
			{
				Date._Month++;
				Date._Day = HowManyDaysInMonth(Date._Month, Date._Year);
			}
		}
		else
		{

			if (Date._Month == 12)
			{
				Date._Month = 1;
				Date._Year++;

			}
			else if (Date._Month == 1 && Date._Day >= 29)
			{
				Date._Month++;
				Date._Day = HowManyDaysInMonth(Date._Month, Date._Year);

			}
			else
			{
				Date._Month++;
			}
		}


		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);


	}

	static clsDate IncreaseDateByFiveMonth(clsDate& Date1)
	{
		for (short i = 0; i < 5; i++)
		{
			Date1 = IncreaseDateByOneMonth(Date1);
		}
		return Date1;
	}
	void IncreaseDateByFiveMonth()
	{
		IncreaseDateByFiveMonth(*this);

	}

	static clsDate IncreaseDateByOneYear(clsDate& Date1)
	{
		for (short i = 0; i < 12; i++)
		{
			Date1 = IncreaseDateByOneMonth(Date1);
		}
		return Date1;
	}
	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);

	}

	static clsDate IncreaseDateBy10Years(clsDate& Date1)
	{
		for (short i = 0; i < 10; i++)
		{
			Date1 = IncreaseDateByOneYear(Date1);
		}
		return Date1;
	}
	void IncreaseDateBy10Years()
	{
		IncreaseDateBy10Years(*this);

	}


	static clsDate IncreaseDateByOneDecade(clsDate& Date1)
	{
		for (short i = 0; i < 10; i++)
		{
			Date1 = IncreaseDateByOneYear(Date1);
		}
		return Date1;
	}
	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);

	}

	clsDate IncreaseDateByXDecade(clsDate Date, short num)
	{
		for (short i = 0; i < num; i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}return Date;
	}


	static clsDate IncreaseDateBy10DecadeFastWay(clsDate& Date1)
	{
		Date1._Year += 100;
		return Date1;
	}
	void IncreaseDateBy10DecadeFastWay()
	{
		IncreaseDateBy10DecadeFastWay(*this);

	}

	static clsDate IncreaseDateByOneCentcury(clsDate& Date1)
	{
		for (short i = 0; i < 10; i++)
		{
			Date1 = IncreaseDateByOneDecade(Date1);
		}
		return Date1;
	}
	void IncreaseDateByOneCentcury()
	{
		IncreaseDateByOneCentcury(*this);

	}

	static  clsDate IncreaseDateByOneMillennium(clsDate& Date1)
	{
		for (short i = 0; i < 10; i++)
		{
			Date1 = IncreaseDateByOneCentcury(Date1);
		}
		return Date1;
	}
	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);

	}


	static short DateCompareAfterOrEqualOrBefor(clsDate PereiodBeginn, clsDate PeriodEnde)
	{
		short AllmonthesPeriodEnd = PeriodEnde._Year * 12 + PeriodEnde._Month;
		short AllmonthesPeriodBeginn = PereiodBeginn._Year * 12 + PereiodBeginn._Month;
		if (AllmonthesPeriodEnd > AllmonthesPeriodBeginn || (AllmonthesPeriodEnd == AllmonthesPeriodBeginn && PeriodEnde._Day > PereiodBeginn._Day))
			return eDateCompare::After;
		else if (AllmonthesPeriodEnd == AllmonthesPeriodBeginn && PeriodEnde._Day == PereiodBeginn._Day)
			return eDateCompare::Equal;
		else return eDateCompare::Before;
	}

	static bool IsDatewithinPeriod(clsDate DateBeginn, clsDate DateEnd, clsDate Date)
	{
		return !(DateCompareAfterOrEqualOrBefor(DateEnd, Date) == eDateCompare::After
			|| DateCompareAfterOrEqualOrBefor(DateBeginn, Date) == eDateCompare::Before);

	}


	static bool IsPeriodsOverlap(clsDate DateStart1, clsDate DateEnd1, clsDate DateStart2, clsDate DateEnd2)
	{
		if (DateCompareAfterOrEqualOrBefor(DateEnd2, DateStart1) == eDateCompare::After
			|| DateCompareAfterOrEqualOrBefor(DateStart2, DateEnd1) == eDateCompare::Before)
			return false;
		else
			return true;
	}
	static short HowManyOverlapDaysInPeriods(clsDate DateStart1, clsDate DateEnd1, clsDate DateStart2, clsDate DateEnd2)
	{/*
		DateStart1 = ReadDate(1);
			DateEnd1= ReadDate(1);

			DateStart2= ReadDate(2);
			DateEnd2= ReadDate(2);*/
		if (!IsPeriodsOverlap(DateStart1, DateEnd1, DateStart2, DateEnd2))
		{
			return 0;

		}
		short Alldays1 = CalculateDiffBetweenDates(DateStart1, DateEnd1);
		short Alldays2 = CalculateDiffBetweenDates(DateStart2, DateEnd2);
		short counter = 0;
		if (IsDatewithinPeriod(DateStart2, DateEnd2, DateStart1))
		{
			counter++;
		}

		if (Alldays1 < Alldays2)
		{
			while (DateCompareAfterOrEqualOrBefor(DateStart1, DateEnd1) != eDateCompare::Equal)
			{
				DateStart1 = AddOneDay(DateStart1);
				if (IsDatewithinPeriod(DateStart2, DateEnd2, DateStart1))
				{
					counter++;


				}

			}

		}
		else
		{
			while (DateCompareAfterOrEqualOrBefor(DateStart2, DateEnd2) != eDateCompare::Equal)
			{
				DateStart2 = AddOneDay(DateStart2);
				if (IsDatewithinPeriod(DateStart1, DateEnd1, DateStart2))
				{
					counter++;


				}
			}
		}return counter;
	}




	static clsDate DecreaseDateWithOneDay(clsDate& Date1)
	{
		if (Date1._Day == 1 && Date1._Month == 1)
		{
			Date1._Day = 31;
			Date1._Month = 12;
			Date1._Year--;
		}
		else if (Date1._Day == 1)
		{
			Date1._Month--;
			Date1._Day = HowManyDaysInMonth(Date1._Month, Date1._Year);
		}
		else Date1._Day--;
		return Date1;
	}
	void DecreaseDateWithOneDay()
	{
		DecreaseDateWithOneDay((*this));
	}

	static  clsDate DecreaseDateWith10Days(clsDate& Date)
	{
		for (short i = 0; i < 10; i++)
		{
			Date = DecreaseDateWithOneDay(Date);
		}return Date;
	}
	void DecreaseDateWith10Days()
	{
		DecreaseDateWith10Days((*this));
	}

	static clsDate DecreaseDateWithOneWeek(clsDate& Date)
	{
		for (short i = 0; i < 7; i++)
		{
			Date = DecreaseDateWithOneDay(Date);
		}return Date;
	}
	void DecreaseDateWithOneWeek()
	{
		DecreaseDateWithOneWeek((*this));
	}

	static clsDate DecreaseDateWithWeeks(clsDate& Date, short num)
	{
		for (short i = 0; i < num; i++)
		{
			Date = DecreaseDateWithOneWeek(Date);
		}return Date;
	}
	void DecreaseDateWithWeeks(short num)
	{
		DecreaseDateWithWeeks((*this, num));
	}

	static clsDate DecreaseDateWithOneMonth(clsDate& Date1)
	{
		short CheckDays = Date1._Day;


		if (Date1._Month == 1)
		{

			Date1._Month = 12;
			Date1._Year--;
		}

		else Date1._Month--;

		if (CheckDays >= 28 && Date1._Month + 1 == 3)
		{
			Date1._Day = HowManyDaysInMonth(Date1._Month, Date1._Year);
		}


		else if (CheckDays == HowManyDaysInMonth(Date1._Month + 1, Date1._Year))
		{

			Date1._Day = HowManyDaysInMonth(Date1._Month, Date1._Year);
		}






		return Date1;
	}
	void DecreaseDateWithOneMonth()
	{
		DecreaseDateWithOneMonth((*this));
	}

	static clsDate DecreaseDateWithFiveMonth(clsDate& Date)
	{
		for (short i = 0; i < 5; i++)
		{
			Date = DecreaseDateWithOneMonth(Date);
		}return Date;
	}
	void DecreaseDateWithFiveMonth()
	{
		DecreaseDateWithFiveMonth((*this));
	}

	static clsDate DecreaseDateWithOneYear(clsDate& Date)
	{
		if (Date._Day >= 28 && Date._Month == 2)
		{
			Date._Year--;
			Date._Day = HowManyDaysInMonth(Date._Month, Date._Year);
		}
		else Date._Year--;
		return Date;
	}
	void DecreaseDateWithOneYear()
	{
		DecreaseDateWithOneYear((*this));
	}

	static clsDate DecreaseDateWith10Years(clsDate& Date)
	{
		for (short i = 0; i < 10; i++)
		{
			Date = DecreaseDateWithOneYear(Date);
		}return Date;
	}
	void DecreaseDateWith10Years()
	{
		DecreaseDateWith10Years((*this));
	}

	static clsDate DecreaseDateWith10YearsEasyWay(clsDate& Date)
	{
		Date._Year -= 10;
		return Date;
	}
	void DecreaseDateWith10YearsEasyWay()
	{
		DecreaseDateWith10YearsEasyWay((*this));
	}




	static bool IsLastDayInWeek(clsDate Date)
	{
		return(DayNumberInWeak(Date._Year, Date._Month, Date._Day) == 0) ? true : false;
	}
	bool IsLastDayInWeek()
	{
		return IsLastDayInWeek((*this));
	}

	static bool IsWeekendDay(clsDate Date)
	{
		short DayNumberInweek = DayNumberInWeak(Date._Year, Date._Month, Date._Day);
		return(DayNumberInweek == 6 || DayNumberInweek == 0) ? true : false;
	}
	bool IsWeekendDay()
	{
		return IsWeekendDay((*this));
	}

	static	bool IsBusinessDay(clsDate Date)
	{
		return(IsWeekendDay(Date)) ? false : true;
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay((*this));
	}

	static short DaysUntillTheEndOfYear(clsDate Date)
	{
		short days = HowManyDaysInMonth(Date._Month, Date._Year) - Date._Day;
		Date._Month++;
		for (Date._Month; Date._Month <= 12; Date._Month++)
		{
			days += HowManyDaysInMonth(Date._Month, Date._Year);
		}return days;
	}
	short DaysUntillTheEndOfYear()
	{
		return DaysUntillTheEndOfYear((*this));
	}


	static short CalculateVacationDays(clsDate Date1, clsDate Date2)
	{
		short counter = (IsWeekendDay(Date1)) ? 0 : 1;
		while (Date1._Day != Date2._Day || Date1._Month != Date2._Month || Date1._Year != Date2._Year)
		{
			Date1 = AddOneDay(Date1);
			if (!IsWeekendDay(Date1))
			{
				counter++;
			}

		}return counter;
	}


	static void CalculateVacationReturnDate(clsDate VacationStart, short days)
	{

		while (days != 0)
		{
			VacationStart = AddOneDay(VacationStart);
			if (!IsWeekendDay(VacationStart))
			{
				days--;
			}

		}
		while (IsWeekendDay(VacationStart))
		{
			VacationStart = AddOneDay(VacationStart);

		}
		cout << VacationStart._Day << "/" << VacationStart._Month << "/" << VacationStart._Year << endl;
	}





};