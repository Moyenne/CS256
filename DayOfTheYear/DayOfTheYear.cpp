#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class DayOfYear
{
private:
	int dayOfYear;
	static int day;
	static string month;

	void translation()
	{
		if (dayOfYear < 32)
		{
			//std::string x = std::to_string(dayOfYear);
			//day = x;
			day = dayOfYear;
			month = "January";
		}
		else if (dayOfYear > 31 && dayOfYear < 60)
		{
			//std::string x = std::to_string(dayOfYear - 31);
			//day = x;
			day = dayOfYear - 31;
			month = "February";
		}
		else if (dayOfYear > 59 && dayOfYear < 91)
		{
			//std::string x = std::to_string(dayOfYear - 59);
			//day = x;
			day = dayOfYear - 59;
			month = "March";
		}
		else if (dayOfYear > 90 && dayOfYear < 121)
		{
			//std::string x = std::to_string(dayOfYear - 90);
			//day = x;
			day = dayOfYear - 90;
			month = "April";
		}
		else if (dayOfYear > 120 && dayOfYear < 152)
		{
			//std::string x = std::to_string(dayOfYear - 120);
			//day = x;
			day = dayOfYear - 120;
			month = "May";
		}
		else if (dayOfYear > 151 && dayOfYear < 182)
		{
			//std::string x = std::to_string(dayOfYear - 151);
			//day = x;
			day = dayOfYear - 151;
			month = "June";
		}
		else if (dayOfYear > 181 && dayOfYear < 213)
		{
			//std::string x = std::to_string(dayOfYear - 181);
			//day = x;
			day = dayOfYear - 181;
			month = "July";
		}
		else if (dayOfYear > 212 && dayOfYear < 244)
		{
			//std::string x = std::to_string(dayOfYear - 212);
			//day = x;
			day = dayOfYear - 212;
			month = "August";
		}
		else if (dayOfYear > 243 && dayOfYear < 274)
		{
			//std::string x = std::to_string(dayOfYear - 243);
			//day = x;
			day = dayOfYear - 243;
			month = "Sepember";
		}
		else if (dayOfYear > 273 && dayOfYear < 305)
		{
			//std::string x = std::to_string(dayOfYear - 273);
			//day = x;
			day = dayOfYear - 273;
			month = "October";
		}
		else if (dayOfYear > 304 && dayOfYear < 335)
		{
			//std::string x = std::to_string(dayOfYear - 273);
			//day = x;
			day = dayOfYear - 304;
			month = "November";
		}
		else
		{
			//std::string x = std::to_string(dayOfYear - 273);
			//day = x;
			day = dayOfYear - 334;
			month = "December";
		}
	}

	void translation2(string x, int y)
	{
		if (x == "January")
		{
			dayOfYear = y;
		}
		else if (x == "February")
		{
			if (y < 29)
			{
				dayOfYear = y + 31;
			}
			else
			{
				cout << "Day... heyyy, wait a second. This isn't right." << endl;
				dayOfYear = 0;
			}
		}
		else if (x == "March")
		{
				dayOfYear = y + 59;
		}
		else if (x == "April")
		{
			if (y < 30)
			{
				dayOfYear = y + 90;
			}
			else
			{
				cout << "Day... heyyy, wait a second. This isn't right." << endl;
				dayOfYear = 0;
			}
		}
		else if (x == "May")
		{
				dayOfYear = y + 120;
		}
		else if (x == "June")
		{
			if (y < 30)
			{
				dayOfYear = y + 151;
			}
			else
			{
				cout << "Day... heyyy, wait a second. This isn't right." << endl;
				dayOfYear = 0;
			}
		}
		else if (x == "July")
		{
				dayOfYear = y + 181;
		}
		else if (x == "August")
		{
				dayOfYear = y + 212;
		}
		else if (x == "September")
		{
			if (y < 30)
			{
				dayOfYear = y + 243;
			}
			else
			{
				cout << "Day... heyyy, wait a second. This isn't right." << endl;
				dayOfYear = 0;
			}
		}
		else if (x == "October")
		{
			dayOfYear = y + 273;
		}
		else if (x == "November")
		{
			if (y < 30)
			{
				dayOfYear = y + 304;
			}
			else
			{
				cout << "Day... heyyy, wait a second. This isn't right." << endl;
				dayOfYear = 0;
			}
		}
		else
		{
			dayOfYear = y + 334;
		}
	}

public:
	DayOfYear(int dayOfYear)
	{
		this->dayOfYear = dayOfYear;
		 
		if (this->dayOfYear > 0 && this->dayOfYear < 366)
		{
			translation();
		}
		else
		{
			cout << "Whoopsie daisy. You didn't put in a valid value for day of the year. Please input an int value between 1 and 365." << endl;
			this->dayOfYear = 0;
		}
	}

	DayOfYear(string monthInput, int dayInput)
	{
		if (day > 0 && day < 32)
		{
			translation2(monthInput, dayInput);
		}
		else
		{
			cout << "Whoopsie daisy. You didn't put in a valid value for day of the month. Please input an int value between 1 and 31." << endl;
		}
	}

	void print()
	{
		if (dayOfYear > 0)
		{
			cout << "Day " << dayOfYear << " would be " << month << " " << day << "." << endl;
		}
		else
		{
			cout << "Yeah, sorry bud. You screwed something up." << endl;
		}
	}
};

int DayOfYear::day = 0;
string DayOfYear::month = "";

int main()
{
	int input;
	string monthInput;
	int dayInput;

	cout << "Please input an int value between 1 and 365." << endl;

	cin >> input;

	DayOfYear day(input);

	day.print();

	cout << "Please input a string value for the month." << endl;

	cin >> monthInput;

	cout << "Please input an int value between 1 and 31." << endl;

	cin >> dayInput;

	DayOfYear day2(monthInput, dayInput);

	day2.print();

    return 0;
}