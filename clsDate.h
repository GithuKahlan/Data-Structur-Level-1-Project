
#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include<string>
#include"clsString.h"
using namespace std;

class clsDate
{
private:

	short Day = 1;
	short Month = 1;
	short Year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;
	}


	clsDate(string sDate)
	{
		vector<string>vDate;
		vDate = clsString::Split(sDate, "/");
		 
		Day = stoi(vDate[0]);
		Month = stoi(vDate[1]);
		Year = stoi(vDate[2]);
	}



	clsDate(short day, short month, short year)
	{
		Day = day;
		Month = month;
		Year = year;
	}
	
	clsDate(short DateOrderInYear, short year)
	{
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, year);
		Day = Date1.day;
		Month = Date1.month;
		Year = Date1.year;
	}


	void SetDay(short day)
	{
		Day = day;

	}
	short GetDay()
	{
		return Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short day;

	void SetMonth(short month)
	{
		Month = month;

	}
	short GetMonth()
	{
		return Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short month;


	void SetYear(short year)
	{
		Year = year;

	}
	short GetYear()
	{
		return Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short year;


	void Print()
	{
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		short day, month, year;

		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;

		return clsDate(day, month, year);

	}


	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}


	static bool IsValidDate(clsDate Date)
	{
		if (Date.day < 1 || Date.day>31)
			return false;
		if (Date.month < 1 || Date.month>12)
			return false;
		if (Date.month == 2)
		{
			if (IsLeapYear(Date.year))
			{
				if (Date.day > 29)
					return false;

			}

			else
			{
				if (Date.day > 28)
					return false;
			}


		}


		short DaysInMonth = NumberOfDaysInMonth(Date.month,Date.year);
		
		if (Date.day > DaysInMonth)
			return false;

		return true;
	}
	

	bool IsValid()
	{

		return IsValidDate(*this);

	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);

	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static bool IsLeapYear(short year)
	{
		// if year is divisible by 4 and not divisible by 100
		//Or if year is dividisble by 400
		// then it is a leap Year

		return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	}

	bool IsLeapYear()
	{
		return IsLeapYear(Year);
	}

	static short NumberOfDatsInYear(short year)
	{
		return IsLeapYear(year) ? 365 : 364;

	}

	short NumberOfDaysInYear()
	{
		return NumberOfDatsInYear(Year);
	}


	static short NumberOfHoursInYear(short year)
	{
		return NumberOfDatsInYear(year) * 24;
	}

	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(Year);
	}

	static int NumberOfMinutesInYear(short year)
	{
		return NumberOfHoursInYear(year)*60;
	}

	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(Year);
	}

	static int NumberOfSecondsInYear(short year)
	{
		return NumberOfMinutesInYear(year) * 60;
	}

	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(Year);
	}


	static short NumberOfDaysInMonth(short month,short year)
	{
		if (month < 1 || month>31)
			return 0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return(month == 2) ? (IsLeapYear(year) ? 29 : 28) : days[month - 1];

	}

	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(Month, Year);
	}

	 
	static short NumberOfHoursInMonth(short month, short year)
	{

		return NumberOfDaysInMonth(month, year) * 24;
	}

	short NumberOfHoursInMonth()
	{
		return NumberOfDaysInMonth(Month, Year)*24;
	}

	static int NumberOfMinutesInMonth(short month, short year)
	{
		return NumberOfHoursInMonth(month, year) * 60;

	}

	int NumberOfMinutesInMonth()
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}

	static int NumberOfSecondsInMonth(short month, short year)
	{
		return NumberOfMinutesInMonth(month, year) * 60;
	}

	int NumberOfSecondsInMonth()
	{
		return  NumberOfMinutesInMonth(Month, Year) * 60;
	}
	
	static short DayOfWeekOrder(short day,short month,short year)
	{
		short a, m, y;
		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	}

	short DayOfWeekOrder()
	{
		return  DayOfWeekOrder(Day, Month, Year);

	}

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder];

	}
	
	static string DayShortName(short day, short month, short year)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder(day, month, year)];

	}

	string DayShortName()
	{
		 	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };

			return arrDayNames[DayOfWeekOrder(Day, Month, Year)];

	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec" };

		return (Months[MonthNumber-1]);


	}

	string MonthShortName()
	{
		return MonthShortName(Month);
	}

	static void PrintMonthCalendar(short month, short year)
	{

		int NumberOfDays;

		// Index of the day from 0 to 6
		int Current = DayOfWeekOrder(1, month, year);

		NumberOfDays = NumberOfDaysInMonth(month, year);

		// Print the current month name
		printf("\n-------------------%s------------------\n\n", MonthShortName(month).c_str());

		//Print the Columns
		printf("  Sun  Mon  Tue  Wed  Thur  Fri  Sat\n");

		int i;
		for (i = 0; i < Current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");

			}

		}

		printf("\n---------------------------------------\n");
	}


	void PrintMonthCalendar()
	{
		PrintMonthCalendar(Month,Year);
	}


	static void PrintYearCalendar(int year)
	{


		printf("\n---------------------------------------\n\n");
		printf("                     Calendar-%d\n", year);
		printf("---------------------------------------\n");


		for (int i = 1; i <= 12; i++)
		{

			PrintMonthCalendar(i, year);

		}

		return;
	}

	void PrintYearCalendar()
	{

		printf("\n---------------------------------------\n\n");
		printf("                     Calendar-%d\n", year);
		printf("---------------------------------------\n");

		for (int i = 1; i <= 12; i++)
		{

			PrintMonthCalendar(i, Year);

		}

		return;	
	}



	static short DaysFromTheBeginingOfTheYear(short day, short month, short year)
	{

		short TotalDays = 0;

		for (int i = 1; i <= month-1; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, year);

		}

		TotalDays += day;
		return TotalDays;

	}

	short DaysFromTheBeginingOfTheYear()
	{
		short TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);

		}

		TotalDays += Day;
		return TotalDays;

	}


	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short year)
	{
		clsDate Date;
		
		if (DateOrderInYear <= 0)
		{
			Date.day = 0;
			Date.month = 0;
			Date.year = 0;
			return Date;
		}

		short RemainingDays = DateOrderInYear;
		Date.year = year;
		int i;
	
		for (i = 1; i <= 12; i++)
		{
			short MonthDays = NumberOfDaysInMonth(i, year);
			if (RemainingDays <= MonthDays)
			{
				Date.month = i;
				Date.day = RemainingDays;

				return Date;
			}
			RemainingDays -= MonthDays;
		}
	}

	void AddDays(short Days)
	{
		// This logic here is the same as the logic in the above function But there is a a small difierence in the secod if satement

		short RemainingDays = Days + DaysFromTheBeginingOfTheYear(Day, Month, Year);
		short MonthDays = 0;
		Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Month++;

				if (Month > 12)
				{
					Month = 1;
					Year++;
				}

			}
			else
			{
				Day = RemainingDays;
				break;

			}

		}
	}


	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{

		return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true :
			
			(Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);

	}


	bool IsDate1BeforeDate2(clsDate Date2)
	{
		IsDate1BeforeDate2(*this, Date2);

	}



	static bool IsDate1EqualDate2(clsDate Date1,clsDate Date2)
	{
		return(Date1.year == Date2.year) ? ((Date1.month == Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false) : false;
	}

	bool IsDate1EqualDate2(clsDate Date2)
	{

		return (IsDate1EqualDate2(*this, Date2));
	}


	static bool IsLastDayInMonth(clsDate Date)
	{
		return(Date.day == NumberOfDaysInMonth(Date.month, Date.year));

	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);

	}

	static bool IsLastMonthInYear(short month)
	{
		return (month == 12);
	}
  
	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.month))
			{
				Date.day = 1;
				Date.month=1;
				Date.year++;

			}

			else
			{
				Date.day = 1;
				Date.month++;

			}
		}

		else
		{
			Date.day++;

		}

		return Date;
	}


	void AddOneDay()
	{

		*this = AddOneDay(*this);

	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}


	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		//this will take care of negative diff

		int days = 0;

		short SwapFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{

			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{

			days++;

			Date1 = AddOneDay(Date1);

		}


		return IncludeEndDay ? ++days * SwapFlagValue : days * SwapFlagValue;
	}



	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{


		return GetDifferenceInDays(*this, Date2, IncludeEndDay);

	}


	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{

		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);


	}
	//above no need to have nonstatic function for the object because it does not depend on any data from it.

	
	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{

		for (int i = 1; i <= 7;i++)
		{
			
			Date = AddOneDay(Date);

		}
		return Date;

	}

	void IncreaseDateByOneWeek()
	{

		IncreaseDateByOneWeek(*this);

	}

	clsDate IncreaseDateByXWeeks(short weeks, clsDate& Date)
	{

		for (int i = 1; i <= weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);

		}

		return Date;
	}

	void IncreaseDateByXWeeks(short weeks)
	{

	   IncreaseDateByXWeeks(weeks, *this);

	}


	clsDate IncreaseDateByOneMonth(clsDate& Date)
	{

		if (Date.month == 12)
		{
			Date.month = 1;
			Date.year++;
		}

		else
		{
			Date.month++;

		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.month, Date.year);

		if (Date.day > NumberOfDaysInCurrentMonth)
		{
			Date.day = NumberOfDaysInCurrentMonth;

		}


		return Date;

	}

	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);

	}

	clsDate IncreaseDateByXDays(short days, clsDate& Date)
	{

		for (short i = 1; i <= days; i++)
		{

			Date = AddOneDay(Date);

		}

		return Date;
	}

	
	void IncreaseDateByXDays(short days)
	{
		IncreaseDateByXDays(days,*this);

	}


	clsDate  IncreaseDateByXMonths(short month, clsDate &Date)
	{

		for (short i = 1; i <= month; i++)
		{
          
			Date = IncreaseDateByOneMonth(Date);

		}
		return Date;
	}


	void IncreaseDateByXMonths(short months)
	{


		IncreaseDateByXMonths(months, *this);

	}


	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{

		Date.year++;
		return Date;

	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);

	}

	clsDate IncreaseDateByXYears(short years, clsDate& Date)
	{

		Date.year += years;
		return Date;

	}

	void IncreaseDateByXYears(short years)
	{
		
		IncreaseDateByXYears(years,*this);


	}


	clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		//period of 10 years;
		Date.year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);

	}


	clsDate IncreaseDateByXDecade(short Decade, clsDate& Date)
	{

		Date.year += Decade * 10;
		return Date;


	}

	void IncreaseDateByXDecade(short Decade)
	{
		IncreaseDateByXDecade(Decade, *this);

	}


	clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		//period of 100 years
		Date.year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);

	}

	clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		//period of 1000 years

		Date.year += 1000;
		return Date;

	}
	

	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);

	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{

		if (Date.day == 1)
		{
			if (Date.month == 1)
			{
				Date.year--;
				Date.month = 12;
				Date.day = 31;
			}

			else
			{
				Date.month--;
				Date.day = NumberOfDaysInMonth(Date.month, Date.year);
			}
		}

		else
		{
			Date.day--;
		}

		return Date;

	}

	void DecreaseDateByOneDay()
	{

		DecreaseDateByOneDay(*this);
	}


	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short weeks, clsDate& Date)
	{

		for (int i = 1; i <= weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);

		}
		return Date;

	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);

	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.month == 1)
		{
			Date.month = 12;
			Date.year--;
		}

		else
			Date.month--;

		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.month,Date.year);

		if (Date.day > NumberOfDaysInCurrentMonth)
		{
			Date.day = NumberOfDaysInCurrentMonth;
		}
		
		return Date;

	}

	void DecreaseDateByOneMonth()
	{

		DecreaseDateByOneMonth(*this);

	}

	static  clsDate DecreaseDateByXDays(short days, clsDate& Date)
	{

		for (short i = 1; i <= days; i++)
		{
			Date = DecreaseDateByOneDay(Date);

		}
		return Date;

	}

	void DecreaseDateByXDays(short days)
	{
		DecreaseDateByXDays(days, *this);
	}

	static clsDate DecreaseDateByXMonths(short months, clsDate& Date)
	{
		for (short i = 1; i < months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);


		}
		return Date;

	}

	void DecreaseDateByXMonths(short months)
	{
		DecreaseDateByXMonths(months, *this);
	}


	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date.year--;
		return Date;


	}


	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short years, clsDate& Date)
	{
		Date.year -= years;
		return Date;
	}

	void DecreaseDateByXYears(short years)
	{
		DecreaseDateByXYears(years, *this);

	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		//period of 10 years
		Date.year -= 10;
		return Date;
	}
	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
	{

		Date.year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);

	}


	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		//period of 100 years

		Date.year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}
	static clsDate DecreaseDateByOneMillennium(clsDate &Date)
	{
		//period of 1000 years
		Date.year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}


	static short IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date.day, Date.month, Date.year) == 6;

	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);

	}

	static bool IsWeekEnd(clsDate Date)
	{
		//Weekends are Friday and Satuarday

		short DayIndex = DayOfWeekOrder(Date.day, Date.month, Date.year);
		return(DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);

	}

	static bool IsBusinessDay(clsDate Date)
	{
		//Weekdays  are Sun,Mon,Tue,Wed, and Thur

		/*
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex >= 5 && DayIndex <= 4);
	   */

	   //shorter method is to invert the IsWeekEnd: this will save updating code.


		return !IsWeekEnd(Date); 
	}

	bool IsBusinessDay()
	{
		return !IsBusinessDay(*this);

	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date.day, Date.month,Date.year);

	}

	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);

	}

	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{

		clsDate EndOfMonthDate;
		EndOfMonthDate.day=NumberOfDaysInMonth(Date1.month, Date1.year);
		EndOfMonthDate.month = Date1.month;
		EndOfMonthDate.year = Date1.year;

		return GetDifferenceInDays(Date1, EndOfMonthDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);

	}


	static short DaysUntilTheEndOfYear(clsDate Date1)
	{

		clsDate EndOfYearDate;
		EndOfYearDate.day = 31;
		EndOfYearDate.month = 12;
		EndOfYearDate.year = Date1.year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);


	}


	short DaysUntilTheEndOfYear()
	{

		return DaysUntilTheEndOfYear(*this);

	}

	// I added this method to calculate business days between 2 dates
 

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{

		short Days = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);


		}
		return Days;
	}

	static short CalCulateVacationDays(clsDate DateFrom, clsDate DateTo)
	{

		/*short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}*/

		// Because The Vacation Days are the the Business Days without the Weekends 
		return CalculateBusinessDays(DateFrom, DateTo);

	}



	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		/*For Example I want to take 10 days vacation
		and the start of my vaction is Saturday 1/1/2025   I should start counting from Sunday 1/2/2025 because saturday is already my weekend
		
		
		*/

		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;


			DateFrom = AddOneDay(DateFrom);
		}

		//to add weekends

		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;

	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return(!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDate1AfterDate2(clsDate Date2)
	{

		return IsDate1AfterDate2(*this, Date2);

	}

	enum enDateCompare { Before = -1, Equal = 0, After=1};

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;


		return enDateCompare::After;

	}


	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}


};

