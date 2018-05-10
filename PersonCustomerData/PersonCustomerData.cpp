// PersonCustomerData.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class PersonData
{
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	int zip;
	int phone;

public:
	PersonData()
	{
		lastName = "";
		firstName = "";
		address = "";
		city = "";
		state = "";
		zip = 0;
		phone = 0;
	}
	PersonData(string lastName, string firstName, string fullAddress, string cityName, string stateName, int zipCode, int phoneNumber)
	{
		this->lastName = lastName;
		this->firstName = firstName;
		address = fullAddress;
		city = cityName;
		state = stateName;
		zip = zipCode;
		phone = phoneNumber;
	}
	void setLastName(string lastName)
	{
		this->lastName = lastName;
	}
	void setFirstName(string firstName)
	{
		this->firstName = firstName;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	void setCity(string city)
	{
		this->city = city;
	}
	void setState(string state)
	{
		this->state = state;
	}
	void setZipCode(int zip)
	{
		this->zip = zip;
	}
	void setPhoneNumber(int phone)
	{
		this->phone = phone;
	}
	string getLastName()
	{
		return lastName;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getAddress()
	{
		return address;
	}
	string getCity()
	{
		return city;
	}
	string getState()
	{
		return state;
	}
	int getZip()
	{
		return zip;
	}
	int getPhone()
	{
		return phone;
	}
};

class CustomerData : public PersonData
{
private:
	int customerNumber;
	bool mailingList;

public:
	CustomerData() : PersonData()
	{
		customerNumber = 0;
		mailingList = false;
	}
	CustomerData(string lastName, string firstName, string fullAddress, string cityName, string stateName, int zipCode, int phoneNumber, int customerNumber, bool mailingList)
	: PersonData(lastName, firstName, fullAddress, cityName, stateName, zipCode, phoneNumber)
	{
		this->customerNumber = customerNumber;
		this->mailingList = mailingList;
	}
	void setCustomerNumber(int customerNumber)
	{
		this->customerNumber = customerNumber;
	}
	void setMailingListStatus(bool mailingList)
	{
		this->mailingList = mailingList;
	}
	int getCustomerNumber()
	{
		return customerNumber;
	}
	bool getMailingListStatus()
	{
		return mailingList;
	}
};

class PreferredCustomer : public CustomerData
{
private:
	double purchasesAmount;
	double discountLevel;

public:
	PreferredCustomer() : CustomerData()
	{
		purchasesAmount = 0.0;
		discountLevel = 0.0;
	}
	PreferredCustomer(string lastName, string firstName, string fullAddress, string cityName, string stateName, int zipCode, int phoneNumber,
	int customerNumber, bool mailingList, double purchasesAmount)
	: CustomerData(lastName, firstName, fullAddress, cityName, stateName, zipCode, phoneNumber, customerNumber, mailingList)
	{
		if (purchasesAmount >= 0)
		{
			this->purchasesAmount = purchasesAmount;
			calculateDiscounts();
		}
		else
		{
			cout << "Woah there, pal! No negative sales figures here, bud. Because I'm nice, I'll make it positive for ya', but don't screw it up next time." << endl;
			this->purchasesAmount = fabs(purchasesAmount);
			calculateDiscounts();
		}
	}
	void purchase(double nextPurchase)
	{
		if (nextPurchase >= 0)
		{
			purchasesAmount += (nextPurchase - (nextPurchase * discountLevel));
			calculateDiscounts();
		}
		else
		{
			cout << "I thought I told you not to do that, buddy? I ain't fixin' your mistakes this time." << endl;
		}
	}
	void calculateDiscounts()
	{
		if (purchasesAmount > 2000.0)
		{
			discountLevel = 0.1;
		}
		else if (purchasesAmount > 1500.0)
		{
			discountLevel = 0.07;
		}
		else if (purchasesAmount > 1000.0)
		{
			discountLevel = 0.06;
		}
		else if (purchasesAmount > 500.0)
		{
			discountLevel = 0.05;
		}
		else
		{
			discountLevel = 0.0;
		}
	}
	double getTotalPurchases()
	{
		return purchasesAmount;
	}
	double getDiscountLevel()
	{
		return discountLevel;
	}

};

int main()
{
	double initialPurchases;

	cout << "Why, hello there. We're gonna make ourselves a preferred customer." << endl;
	cout << "Help us out by inputting a double value between 0 and 10." << endl;
	cin >> initialPurchases;

	if (initialPurchases > 10.0)
	{
		cout << "Ugh... so you're one of those people, eh? Well, let's try and make this work, shall we?" << endl;
		initialPurchases = 10.0;
	}

	PreferredCustomer prefCust = PreferredCustomer("Roberts", "Bob", "432 S. Ackhead Ave.", "San Francisco", "California", 86753, 9096364299, 42, true, initialPurchases);

	int x = 0;

	while (x < 5)
	{
		cout << "The customer, " << prefCust.getFirstName() << " " << prefCust.getLastName() << ", has spent $" << prefCust.getTotalPurchases() << "," << endl;
		cout << "Earning them a discount rate of " << (prefCust.getDiscountLevel() * 100) << "% off on all future purchases." << endl;

		prefCust.purchase(550.99);

		x++;
	}

	cout << "Whoops, looks like " << prefCust.getFirstName() << " " << prefCust.getLastName() << " mysteriously died. Guess the program's over." << endl;

    return 0;
}

