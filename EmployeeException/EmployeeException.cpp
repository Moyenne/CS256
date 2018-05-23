// EmployeeException.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class InvalidEmployeeNumber
{
private:
	int value;

public:
	InvalidEmployeeNumber(int x)
	{
		value = x;
	}

	int getValue()
	{
		return value;
	}
};

class InvalidShift
{
private:
	int value;

public:
	InvalidShift(int x)
	{
		value = x;
	}

	int getValue()
	{
		return value;
	}
};

class InvalidPayRate
{
private:
	double value;

public:
	InvalidPayRate(double x)
	{
		value = x;
	}

	double getValue()
	{
		return value;
	}
};

class Employee
{
private:
	string name;
	int number;
	string hireDate;

public:
	Employee()
	{
		name = "Bob";
		number = 0;
		hireDate = "January 1, 20XX";
	}

	Employee(string name, int number, string hireDate)
	{
		this->name = name;
		if (number >= 0 && number <= 9999)
		{
			this->number = number;
		}
		else
		{
			throw InvalidEmployeeNumber(number);
		}
		this->hireDate = hireDate;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setNumber(int number)
	{
		if (number >= 0 && number <= 9999)
		{
			this->number = number;
		}
		else
		{
			throw InvalidEmployeeNumber(number);
		}
	}
	void setHireDate(string hireDate)
	{
		this->hireDate = hireDate;
	}

	string getName()
	{
		return name;
	}
	int getNumber()
	{
		return number;
	}
	string getHireDate()
	{
		return hireDate;
	}
};

class ProductionWorker : public Employee
{
private:
	int shift;
	double hourlyPayRate;

public:
	ProductionWorker() : Employee()
	{
		shift = 1;
		hourlyPayRate = 10.00;
	}

	ProductionWorker(string name, int number, string hireDate, int shift, double hourlyPayRate) : Employee(name, number, hireDate)
	{
		if (shift > 0 && shift < 3)
		{
			this->shift = shift;
		}
		else
		{
			throw InvalidShift(shift);
		}

		if (hourlyPayRate >= 0.0)
		{
			this->hourlyPayRate = hourlyPayRate;
		}
		else
		{
			throw InvalidPayRate(hourlyPayRate);
		}
	}

	void setShift(int shift)
	{
		if (shift > 0 && shift < 3)
		{
			this->shift = shift;
		}
		else
		{
			throw InvalidShift(shift);
		}
	}
	void setHourlyPayRate(double hourlyPayRate)
	{
		if (hourlyPayRate >= 0.0)
		{
			this->hourlyPayRate = hourlyPayRate;
		}
		else
		{
			throw InvalidPayRate(hourlyPayRate);
		}
	}
	
	int getShift()
	{
		return shift;
	}
	double getHourlyPayRate()
	{
		return hourlyPayRate;
	}
};

int main()
{
	cout << "Welcome! Let's make ourselves a production worker, shall we?" << endl;
	cout << "C'mon, it's not that hard. Watch, I'll even guide you through it, step by step." << endl;

	string nameInput;
	int numberInput;
	string hireMonth;
	string hireDay;
	string hireYear;
	string hireDateInput;
	int shiftInput;
	double hourlyPayRateInput;

	cout << "First, let's start by giving our production worker a name. Go ahead, input a string value for the production worker's name." << endl;
	cin >> nameInput;

	cout << "Next, we need to give them a number. Sorta like an ID, ya' know? So go ahead and input an int value between 0 and 9999 for their number." << endl;
	cin >> numberInput;

	cout << "Next, we need to know when they were hired. Let's start with the month they were hired in, as a string value." << endl;
	cin >> hireMonth;
	cout << "Now for they day were hired on, as an int value." << endl;
	cin >> hireDay;
	cout << "Lastly, the year they were hired in, as an int value." << endl;
	cin >> hireYear;
	hireDateInput = hireMonth + " " + hireDay + ", " + hireYear;

	cout << "Alright, now we're on a roll! Now, we need to determine what shift they work. Input either a 1 if they work the day shift or a 2 if they work the night shift." << endl;
	cin >> shiftInput;

	cout << "Last thing, we need to pay them. Yeah, I know, I don't want to do it either, but go ahead and input a positive double value for their hourly pay rate." << endl;
	cin >> hourlyPayRateInput;

	try
	{
		ProductionWorker pw = ProductionWorker(nameInput, numberInput, hireDateInput, shiftInput, hourlyPayRateInput);

		cout << "Great! You created " << pw.getName() << endl;
		cout << "Who has an employee number of " << pw.getNumber() << endl;
		cout << "And was hired on " << pw.getHireDate() << "." << endl;
		cout << "They work shift number " << pw.getShift() << endl;
		cout << "And are payed $" << pw.getHourlyPayRate() << " per hour." << endl;
		cout << "Unfortunately, I'm going to need you to do a few tiiiny little changes. For... testing purposes." << endl;

		cout << "Let's start with their number. It just doesn't work, ya' know. So go ahead and change it, same rules as last time." << endl;
		cin >> numberInput;
		pw.setNumber(numberInput);

		cout << "Next is their shift. Listen, they've been complaining and need a time change, so go ahead and do that, will ya'?" << endl;
		cin >> shiftInput;
		pw.setShift(shiftInput);

		cout << "Of course, if they don't want to work the same hours, they ain't getting the same pay. Feel free to drop their pay like a hot rock." << endl;
		cin >> hourlyPayRateInput;
		pw.setHourlyPayRate(hourlyPayRateInput);

		cout << "Nice! Now their employee number is " << pw.getNumber() << endl;
		cout << "They work shift number " << pw.getShift() << endl;
		cout << "And they are getting paid $" << pw.getHourlyPayRate() << " per hour." << endl;

		cout << "Congratulations, and thanks for helping out. Now " << pw.getName() << " can get back to work!" << endl;
	}
	catch (InvalidEmployeeNumber e)
	{
		cout << "Whoops, sorry pal, but " << e.getValue() << " is not a valid employee number." << endl;
		cout << "You're going to have to try again." << endl;
	}
	catch (InvalidShift e)
	{
		cout << "Whoops, sorry pal, but " << e.getValue() << " is not a valid shift to work." << endl;
		cout << "You're going to have to try again." << endl;
	}
	catch (InvalidPayRate e)
	{
		cout << "Whoops, sorry pal, but " << e.getValue() << " is not a valid pay rate, although I wish it was." << endl;
		cout << "You're going to have to try again." << endl;
	}

	cout << "End of program." << endl;

    return 0;
}

